#include "palnetwidget.h"
#include "QWidget"
#include "call.h"
#include "arcball.h"
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

ArcBallT arcBall(1366,768);
ArcBallT* ArcBall =&arcBall;

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
    time_id = startTimer(17);

    solar = new Palnet();
    //qDebug()<<solar->mars_data_y[500];
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


/**
 *
 */
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

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    // texture

    for( int i = 0; i < 8 ; i++)
    {
        solar->loadTexture(solar->texture_id, solar->image[i], i);
    }
    solar->loadMoonTexture(solar->texture_id[8], solar->image[8]);

    //solar->loadTextures(solar->texture_id);
}

/**
 *
 */
void palnetWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_LIGHTING);
    glColor3f(1,1,1);

    glPushMatrix();
        glScalef(ArcBall->zoomRate, ArcBall->zoomRate, ArcBall->zoomRate);  //2. 缩放
        glMultMatrixf(ArcBall->Transform.M);                                //3. 旋转

        //lines
        glEnable(GL_LIGHTING);
        //qDebug()<<"begin to draw lines...";
        solar->drawLines();

        /*
        //glBindTexture(GL_TEXTURE_2D, )
        {
            GLUquadricObj* p = gluNewQuadric();
            gluSphere(p, 0.2, 20, 16);
            gluQuadricTexture(p, GL_TRUE);
            gluQuadricDrawStyle(p,GLU_FILL);
            gluDeleteQuadric(p);
        }
        */
        solar->drawSun();

        //draw eight planets
        //qDebug()<<"... begin to draw planets! ...";
        solar->drawPalnets();

        solar->drawMoon(solar->earth_data_x[solar->data_num],solar->earth_data_y[solar->data_num],
                        solar->earth_data_z[solar->data_num],solar->moon_solar_angle,
                        solar->moon_axis_angle);

    glPopMatrix();

    glLoadIdentity();

    gluLookAt(0.0,15.0,solar->neptune_data_z[0],0.0,0.0,0.0,0.0,1.0,0.0);

    glFlush();
}

/**
 *
 */
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

/**
 * the timer event to chang animation
 */
void palnetWidget::timerEvent(QTimerEvent *e)
{
    //solar->data_num++;
    //qDebug()<<year[4]<<"   "<<day[4]<<endl;
    solar->setNew();
    updateGL();
}

/*********************************************************
 * mouse event
 * learn from dashen provided by ligong
 *********************************************************/
//鼠标移动事件

void palnetWidget::mouseMoveEvent(QMouseEvent *e){
    ArcBall->MousePt.s.X = e->x();
    ArcBall->MousePt.s.Y = e->y();
    ArcBall->upstate();
    timerEvent(0);
}

//鼠标点击事件
void palnetWidget::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        ArcBall->isClicked = true;
        move(e->x(),e->y());
    }else{
        if(e->button() == Qt::RightButton)
        {
           ArcBall->isRClicked = true;
           move(e->x(),e->y());
        }
    }
    ArcBall->upstate();
    timerEvent(0);

}


//鼠标释放事件
void palnetWidget::mouseReleaseEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        ArcBall->isClicked = false;
    }
    else{
        if(e->button() == Qt::RightButton){
           ArcBall->isRClicked = false;
        }
    }

    ArcBall->upstate();
    timerEvent(0);
}

//移动鼠标
void palnetWidget::move(int x, int y)
{
    ArcBall->MousePt.s.X = x;
    ArcBall->MousePt.s.Y = y;
    ArcBall->upstate();
    timerEvent(0);
}


