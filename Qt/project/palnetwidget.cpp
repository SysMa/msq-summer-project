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
#include <QDate>

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
    this->setGeometry(0,0,800,600);

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

    // new light
    glLightfv(GL_LIGHT1, GL_AMBIENT, solar->LightAmbient);						// 设置环境光
    glLightfv(GL_LIGHT1, GL_DIFFUSE, solar->LightDiffuse);						// 设置漫反射光
    // new light

    // view port
    from_x  = 0;
    from_y  = 15;
    from_z  = solar->neptune_data_z[0];
    to_x    = solar->center_x;
    to_y    = solar->center_y;
    to_z    = solar->center_z;
    up_x    = 0;
    up_y    = 1;
    up_z    = 0;
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
 * init things here
 */
void palnetWidget::initializeGL()
{
    /********************************************************
      * old light
      */
/*
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
*/

    // new light


    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT1, GL_AMBIENT, solar->LightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, solar->LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION,solar->LightPosition);
    glEnable(GL_LIGHT1);

/*
    glLightfv(GL_LIGHT2, GL_AMBIENT, solar->LightAmbient2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, solar->LightDiffuse2);
    glLightfv(GL_LIGHT2, GL_POSITION,solar->LightPosition2);
    glEnable(GL_LIGHT2);
*/

    // end of new light
    glClearColor(0,0,0,0);
    glClearDepth(1.0f);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_NORMALIZE);
    // texture

    for( int i = 0; i < 10 ; i++)
    {
        solar->loadTexture(solar->texture_id, solar->image[i], i);
    }

    //solar->loadMoonTexture(solar->texture_id[8], solar->image[8]);

    //solar->loadTextures(solar->texture_id);


    glLightfv(GL_LIGHT1, GL_AMBIENT, solar->LightAmbient);						// 设置环境光
    glLightfv(GL_LIGHT1, GL_DIFFUSE, solar->LightDiffuse);						// 设置漫反射光
    glEnable(GL_LIGHTING);												// 打开光照
    glEnable(GL_LIGHT1);

}

/**
 * paint things
 */
void palnetWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //solar->renderscreen();
    //glEnable(GL_LIGHT0);
    //glDisable(GL_LIGHTING);
    glColor3f(1,1,1);


    /*
    GLfloat light_ambient[] = {0.3,0.5,0.3};
    GLfloat light_diffuse[] = {1.0,1.0,1.0};
    GLfloat light_specular[]= {0.8,0.8,0.0};
    GLfloat light_position[]= {0.0,0.0,0.0,1.0};
    glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
    glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    */

    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT1, GL_AMBIENT, solar->LightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, solar->LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION,solar->LightPosition);
    glEnable(GL_LIGHT1);

    /*
    glLightfv(GL_LIGHT2, GL_AMBIENT, solar->LightAmbient2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, solar->LightDiffuse2);
    glLightfv(GL_LIGHT2, GL_POSITION,solar->LightPosition2);
    glEnable(GL_LIGHT2);
    */

    glPushMatrix();
        glScalef(ArcBall->zoomRate, ArcBall->zoomRate, ArcBall->zoomRate);  //2. 缩放
        glMultMatrixf(ArcBall->Transform.M);                                //3. 旋转


        //lines
        glEnable(GL_LIGHTING);
        //qDebug()<<"begin to draw lines...";
        solar->drawLines();
        solar->drawMoonLine();

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
        //glLightfv(GL_LIGHT1, GL_POSITION, solar->LightPosition);

        //draw eight planets
        //qDebug()<<"... begin to draw planets! ...";
        solar->drawPalnets();

        solar->drawMoon(solar->earth_data_x[solar->data_num],solar->earth_data_y[solar->data_num],
                        solar->earth_data_z[solar->data_num],solar->moon_solar_angle,
                        solar->moon_axis_angle);

        solar->drawStars();
    glPopMatrix();

    glLoadIdentity();

    gluLookAt(from_x,from_y,from_z,to_x,to_y,to_z,up_x,up_y,up_z);

    glFlush();

}

/**
 * resize gl
 */
void palnetWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(60,(GLfloat)width/(GLfloat)height, 1.0, 20000);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    gluLookAt(from_x,from_y,from_z,to_x,to_y,to_z,up_x,up_y,up_z);
}

/**
 * the timer event to chang animation
 */
void palnetWidget::timerEvent(QTimerEvent *e)
{
    //solar->data_num++;
    //qDebug()<<year[4]<<"   "<<day[4]<<endl;

    solar->setNew();
    //qDebug()<<solar->data_num;
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


/**
 * this is key prewwed func which deal with the event of key pressing
 * we need a framework and some deaing function
 */
void palnetWidget::keyPressEvent(QKeyEvent *e)
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
    case Qt::Key_Backspace:
        solar->center_x = solar->earth_data_x[solar->data_num];
        solar->center_y = solar->earth_data_y[solar->data_num];
        solar->center_z = solar->earth_data_z[solar->data_num];
        updateGL();
        break;
    case Qt::Key_Up:
        from_y += 1;
        to_y   += 1;
        updateGL();
        break;
    case Qt::Key_Down:
        from_y -= 1;
        to_y   -= 1;
        updateGL();
        break;
    case Qt::Key_Left:
        from_x -= 1;
        to_x   -= 1;
        updateGL();
        break;
    case Qt::Key_Right:
        from_x += 1;
        to_x   += 1;
        updateGL();
        break;
    case Qt::Key_W:
        from_z += 1;
        updateGL();
        break;
    case Qt::Key_S:
        from_z -= 1;
        updateGL();
        break;
    case Qt::Key_A:
        from_x -= 1;
        updateGL();
        break;
    case Qt::Key_D:
        from_x += 1;
        updateGL();
        break;
    case Qt::Key_Q:
        from_y -= 1;
        updateGL();
        break;
    case Qt::Key_E:
        from_y += 1;
        updateGL();
        break;
    case Qt::Key_Enter:
        if(solar->speed == 0)
        {
            solar->setSpeed(1);
        }
        else
        {
            solar->setSpeed(0);
        }
        updateGL();
        break;
    case Qt::Key_F2:
        solar->setSpeed(solar->speed + 1);
        updateGL();
        break;
    case Qt::Key_F3:
        solar->setSpeed(solar->speed - 1);
        updateGL();
        break;
    case Qt::Key_Escape:
        close();
        break;
    case Qt::Key_0:
        solar->moon_line = !(solar->moon_line);
        updateGL();
        break;
    case Qt::Key_1:
        solar->mercury_line = !(solar->mercury_line);
        updateGL();
        break;
    case Qt::Key_2:
        solar->venus_line = !(solar->venus_line);
        updateGL();
        break;
    case Qt::Key_3:
        solar->earth_line = !(solar->earth_line);
        updateGL();
        break;
    case Qt::Key_4:
        solar->mars_line = !(solar->mars_line);
        updateGL();
        break;
    case Qt::Key_5:
        solar->jupiter_line = !(solar->jupiter_line);
        updateGL();
        break;
    case Qt::Key_6:
        solar->saturn_line = !(solar->saturn_line);
        updateGL();
        break;
    case Qt::Key_7:
        solar->uranus_line = !(solar->uranus_line);
        updateGL();
        break;
    case Qt::Key_8:
        solar->neptune_line = !(solar->neptune_line);
        updateGL();
        break;
    default:
        break;
    }
}
