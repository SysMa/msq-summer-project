#include "mywidget.h"
#include "QWidget"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <QKeyEvent>
#include <GL/glut.h>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>

/*********************************************
 *
 * need for the layout and the buttons

#include <qlayout.h>
#include <QPushButton>
#include <qpushbutton.h>

***********************************************/


/**
 * this is the widget init
 * parent is the parent-window
 * name is the name of the window
 * fs is a var that determine if it is fullscreen
 */
myWidget::myWidget(QWidget *parent, const char *name, bool fs) :
    QGLWidget(parent)
{
    fullscreen = fs;

    // set the window position, from 100,100 to 800,600
    setGeometry(100,100,800,600);

    // set the name of the title
    //setCaption( "Solar System !");

    // deal with full screen
    if(fullscreen)
    {
        showFullScreen();
    }

    //set time function
    time_id = startTimer(10);

    /***********************************************************
     * these lines are test
     * they try to draw some planets, but unlucky
     *
    QGridLayout* layout = new QGridLayout(this);
    QPushButton* pb1 = new QPushButton("Button 1", this);
    QPushButton* pb2 = new QPushButton("Button 2", this);
    QPushButton* pb3 = new QPushButton("Button 3", this);
    QPushButton* pb4 = new QPushButton("Button 4", this);
    QPushButton* pb5 = new QPushButton("Button 5", this);

    layout->addWidget(pb1, 0, 0);
    layout->addWidget(pb2, 1, 0);
    layout->addWidget(pb3, 2, 0);
    layout->addWidget(pb4, 3, 0);
    layout->addWidget(pb5, 4, 0);
    *
    *************************************************************/
}

/**
 * this is a func to deal with all the delete
 */
myWidget::~myWidget()
{
    // now we can do nothing here
    // its existence is due to the pointer-things
    // don't forget to get the mem back, and it will be ok

    if( time_id != 0)
    {
        killTimer(time_id);
    }
}


/***********************************************************
 * here insert some funcs to help
 **********************************************************/
int Loads ( char* file_name)
{
    GLubyte * Image;
    FILE * file;
    int width = 640;
    int height = 320;

    if((file = fopen(file_name,"rb")) == NULL )
    {
        return 1;
    }
    Image = (GLubyte *)malloc(width * height * 3 * (sizeof(GLubyte)));
    fread (Image, width*height*3,1,file);
    fclose(file);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, Image);
    free(Image);

    return 0;
}

void LoadTex(GLuint* texture_id)
{
    int i;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(8, texture_id);

    for(i=0; i < 8; i ++)
    {
        glBindTexture(GL_TEXTURE_2D,texture_id[i]);
        Loads( planetN[i]);
    }
}


/**
 * this is the func that can deal with the inti things
 *******************************************************
 *
 * it is obviously that i want to separate the init of the window or the widget
 * from the init of the things todo with the openGL
 */
void myWidget::initializeGL()
{
    int i;
    // here we can do nothing now
    // but later we may deal with some paremeters and determine which mode to choose
    // and which mode widget to show here.
    // myinit();

    //light parameters
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

    //laod texture here
    LoadTex(texture_id);

    //the orignal position
    for(i = 0; i < 8; i++)
    {
        year[i] = (rand() % 360);
        day[i] = 0;
    }

    //view port
    view_x = r1[7];
    view_y = 3;
    view_z = r1[7];

}

/**
 * this is the painting func
 * **********************************************************
 *
 * it is obviously that i also want to separate painting things apart
 */
void myWidget::paintGL()
{
    // now here we do nothing
    // it is requred to be the same with the init func
    // some mode are required here, may deal with some parameteres
    int i,j;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_LIGHTING);
    glColor3f(1,1,1);

    //lines
    for(j = 0; j < 8; j++)
    {
        double radius = r1[j];
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            glVertex3f(radius * cos(i * PI / 180), 0.0, radius * sin(i * PI / 180));
        }
        glEnd();
    }
    glEnable(GL_LIGHTING);

    glPushMatrix();
    glRotatef(1.0, 0, 1, 0);
    //glBindTexture(GL_TEXTURE_2D, )
    {
        GLUquadricObj* p = gluNewQuadric();
        gluQuadricTexture(p, GL_TRUE);
        gluSphere(p, sun, 20, 16);
        gluDeleteQuadric(p);
    }
    glPopMatrix();

    //draw eight planets
    glEnable(GL_TEXTURE_2D);
    for(i=0; i < 8; i++)
    {
        glPushMatrix();
        glRotatef(year[i], 0, 1, 0);
        glTranslatef(r1[i], 0, 0);
        glRotatef(day[i], 0, 1, 0);
        glBindTexture(GL_TEXTURE_2D,texture_id[i]);
        {
            GLUquadricObj* p = gluNewQuadric();
            gluQuadricTexture(p,GL_TRUE);
            gluSphere(p, r2[i], 16, 16);
            gluDeleteQuadric(p);
        }
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);

    glFlush();
}


/**
  * this is the func of the resize func
  ************************************************************
  * mode separate are also required here
  * may deal with some parameters
  */
void myWidget::resizeGL(int width, int height)
{
    // also may need some mode here
    //
    //
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60,(GLfloat)width/(GLfloat)height, 1.0, 20);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(view_x,view_y,view_z,0,0,0,0,1,0);
}

/**
 * this is key prewwed func which deal with the event of key pressing
 * we need a framework and some deaing function
 */
void myWidget::keyPressEvent(QKeyEvent *e)
{
    // here is the framework and it need to be filled
    switch ( e->key() )
    {
    // this is a model with the full screen exchange
    // an example
    case Qt::Key_F11:
        fullscreen = !fullscreen;
        if( fullscreen)
        {
            showFullScreen();
        }
        else
        {
            showNormal();
            setGeometry(0,0,800,600);
        }
        updateGL();
        break;
    case Qt::Key_Up:
        // up
        view_x -= view_x * cos(1 * PI / 180);
        //view_y -=
        view_z -= view_z * sin(1 * PI / 180);
        glLoadIdentity();
        gluLookAt(view_x,view_y,view_z,0,0,0,0,1,0);
        updateGL();
        break;
    case Qt::Key_Down:
        // down
        view_x += view_x * cos(1 * PI / 180);
        // view_y +=
        view_z += view_z * sin(1 * PI / 180);
        glLoadIdentity();
        gluLookAt(view_x,view_y,view_z,0,0,0,0,1,0);
        updateGL();
        break;
    case Qt::Key_F2:
        // larger
        for( int i=0; i < 8; i++)
        {
            r1[i] = 2 * r1[i];
            r2[i] = 2 * r2[i];
            //sun = 2 * sun;
        }
        updateGL();
        break;
    case Qt::Key_F3:
        for(int i=0; i < 8; i++)
        {
            r1[i] = r1[i] / 2;
            r2[i] = r2[i] / 2;
        }
        updateGL();
        break;
    case Qt::Key_Escape:
        close();
        break;
    default:
        break;
    }
}

/**
 * the timer event to chang animation
 */
void myWidget::timerEvent(QTimerEvent *e)
{
    for(int i=0;i<8;i++)
    {
            year[i]=year[i]+(1 / year0[i]);
            if( year[i]>360 ) year[i]=year[i] - 360;

            day[i]=day[i] + ( 1 / day0[i] );
            if( day[i] >360 ) day[i]= day[i] -360 ;
    }
    updateGL();
}
