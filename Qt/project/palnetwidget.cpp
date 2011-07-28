#include "palnetwidget.h"
#include "QWidget"
#include "call.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <QKeyEvent>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>
#include <QImage>
#include <qdebug.h>
#include <QDebug>

/**
 * this is the widget init
 * parent is the parent-window
 * name is the name of the window
 * fs is a var that determine if it is fullscreen
 */
palnetWidget::palnetWidget(QWidget *parent, const char *name, bool fs) :
    QGLWidget(parent)
{
    fullscreen = fs;

    // set the window position, from 100,100 to 800,600
    this->setGeometry(100,100,800,600);

    // set the name of the title
    //this->setCaption("Solar System");

    // deal with full screen
    if(fullscreen)
    {
        showFullScreen();
    }

    //set time function
    time_id = startTimer(10);

    solar = new Palnet();
    qDebug()<<solar->mars_data_y[500];
}

/**
 * this is a func to deal with all the delete
 */
palnetWidget::~palnetWidget()
{
    // now we can do nothing here
    // its existence is due to the pointer-things
    // don't forget to get the mem back, and it will be ok

    if( time_id != 0)
    {
        killTimer(time_id);
    }
}


void palnetWidget::initializeGL()
{
    GLfloat light_ambient[] = {0.3,0.5,0.3};
    GLfloat light_diffuse[] = {1.0,1.0,1.0};
    GLfloat light_specular[]= {0.8,0.8,0.0};
    GLfloat light_position[]= {0.0,0.0,0.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_CULL_FACE);

    // texture
    solar->loadTexture(solar->texture_id);
}

void palnetWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_LIGHTING);
    glColor3f(1,1,1);

    //lines
    glEnable(GL_LIGHTING);
    solar->drawLines();


    glPushMatrix();
    //glBindTexture(GL_TEXTURE_2D, )
    {
        GLUquadricObj* p = gluNewQuadric();
        gluSphere(p, 0.8, 20, 16);
        gluQuadricTexture(p, GL_TRUE);
        gluQuadricDrawStyle(p,GLU_FILL);
        gluDeleteQuadric(p);
    }
    glPopMatrix();

    //draw eight planets
    glEnable(GL_TEXTURE_2D);
    solar->drawPalnets();
    glDisable(GL_TEXTURE_2D);

    glFlush();
}

void palnetWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60,(GLfloat)width/(GLfloat)height, 1.0, 20);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(0.0,15.0,solar->neptune_data_z[0],0.0,0.0,0.0,0.0,1.0,0.0);
}
