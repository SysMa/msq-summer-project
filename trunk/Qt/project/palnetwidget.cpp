#include "palnetwidget.h"
#include "QWidget"
#include "call.h"
#include "arcball.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <QKeyEvent>
#include <QDate>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/qgl.h>
#include <QImage>
#include <QMessageBox>

/**
  * for debug and reuse
  */
#include <qdebug.h>
#include <QDebug>
#include <QApplication>
  /*
  */

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

    // don't watch some phenomenets.
    watchEclipse = false;
    watchStars   = false;

    // set the window position, from 100,100 to 800,600
    this->setGeometry(0,0,1366,600);

    // set the name of the title
    //this->setCaption("Solar System");

    // deal with full screen
    if(fullscreen)
    {
        showFullScreen();
    }

    //set time function
    time_id = startTimer(40);

    solar = new Palnet();
    if(!solar->readData())
    {
        //qDebug()<<" Sorry! the data is out of use.";
    }
    //qDebug()<<solar->mars_data_y[500];

    // new light
    glLightfv(GL_LIGHT1, GL_AMBIENT, solar->LightAmbient);	// 设置环境光
    glLightfv(GL_LIGHT1, GL_DIFFUSE, solar->LightDiffuse);	// 设置漫反射光
    // new light

    // view port
    from_x  = 0;
    from_y  = solar->neptune_data_y[0];
    from_z  = 5;
    to_x    = solar->center_x;
    to_y    = solar->center_y;
    to_z    = solar->center_z;
    up_x    = 0;
    up_y    = 0;
    up_z    = 1;

    // focus
    // setFocusPolicy(Qt::StrongFocus);

    changeModel = true;

    // draw son or not
    sun = true;
    /*
    label = new QLabel(this);
    label->setGeometry(0,0,200,50);
    //label->setEnabled(true);
    label->setMargin(10);
    label->setAttribute(Qt::WA_TranslucentBackground,true);
    label->show();
    */

    // the model of eclipse
    eclipse_model = new Eclipse();

    // to show messages here
    showMessage = new QMessageBox();

    // jduge if the message has shown
    flag = false;

    camera_from_default = true;
    camera_from_sun     = false;
    camera_from_moon    = false;
    camera_from_mercury  = false;
    camera_from_venus   = false;
    camera_from_earth   = false;
    camera_from_mars    = false;
    camera_from_jupiter = false;
    camera_from_saturn  = false;
    camera_from_uranus  = false;
    camera_from_neptune = false;

    view_to_default     = true;
    view_to_moon        = false;
    view_to_mercury      = false;
    view_to_venus       = false;
    view_to_earth       = false;
    view_to_mars        = false;
    view_to_jupiter     = false;
    view_to_saturn      = false;
    view_to_uranus      = false;
    view_to_neptune     = false;

    camera_changed      = false;
    view_changed        = false;
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

        for( int i = 0; i < 11 ; i++)
        {
            solar->loadTexture(solar->texture_id, solar->image[i], i);
        }

        //solar->loadMoonTexture(solar->texture_id[8], solar->image[8]);

        //solar->loadTextures(solar->texture_id);


        glLightfv(GL_LIGHT1, GL_AMBIENT, solar->LightAmbient);						// 设置环境光
        glLightfv(GL_LIGHT1, GL_DIFFUSE, solar->LightDiffuse);						// 设置漫反射光
        glEnable(GL_LIGHTING);												// 打开光照
        glEnable(GL_LIGHT1);


        /***************************************************************
          *
          * here are some eclipse model init
          *
         ****************************************************************/
}

/**
 * paint things
 */
void palnetWidget::paintGL()
{
    if(changeModel)
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

        /*
        QDate begin(2000,1,1);
        label->setText(begin.addDays(solar->data_num).toString());
        */
        glPushMatrix();
            glScalef(ArcBall->zoomRate, ArcBall->zoomRate, ArcBall->zoomRate);  //2. 缩放
            glMultMatrixf(ArcBall->Transform.M);                                //3. 旋转

            solar->drawBackground();

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
            if(sun)
            {
                solar->drawSun();
            }

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
    else    // view the eclipse model
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
            // begin to draw
            eclipse_model->drawSun();
            eclipse_model->drawMoon();
        glPopMatrix();
        glLoadIdentity();

        gluLookAt(0, 0, 0, eclipse_model->sun_dis, 0, 0, 0, 1, 0);

        glFlush();
    }
}

/**
 * resize gl
 */
void palnetWidget::resizeGL(int width, int height)
{
    if(changeModel)
    {
        glViewport(0, 0, (GLsizei)width, (GLsizei)height);
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();
        gluPerspective(45,(GLfloat)width/(GLfloat)height, 1.0, 20000);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();
        gluLookAt(from_x,from_y,from_z,to_x,to_y,to_z,up_x,up_y,up_z);
    }
    else        // the eclipse model
    {
        glViewport(0, 0, (GLsizei)width, (GLsizei)height);
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();
        gluPerspective(45,(GLfloat)width/(GLfloat)height, 1.0, 20000);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();
        gluLookAt(0, 0, 0, eclipse_model->sun_dis, 0, 0, 0, 1, 0);
    }
}

/**
 * the timer event to chang animation
 */
void palnetWidget::timerEvent(QTimerEvent *e)
{
    if(changeModel)
    {
        //qDebug()<<solar->data_num;

        // normal update
        if(!watchEclipse && !watchStars)
        {
            solar->setNew();
            if(solar->speed != 0)
            {
                emit date_updated(solar->data_num);
            }
        }
        if( watchEclipse)
        {
            solar->setNew();
            //qDebug()<<" still here...";
            if(solar->speed != 0)
            {
                emit date_updated(solar->data_num);
            }
            if(solar->isEclipse() && !flag)
            {
                //qDebug()<<"god, eclipse happen...";
                showMessage->setText("Watch Eclipse: slow down and be careful.");
                showMessage->show();
                solar->setSpeed(0);
                flag = !flag;
            }
        }
        if( watchStars)
        {
            solar->setNew();
            if(solar->speed != 0)
            {
                emit date_updated(solar->data_num);
            }

            if(solar->isInline() && !flag)
            {
                showMessage->setText("Watch the Stars: slow down and be careful.");
                showMessage->show();
                solar->setSpeed(0);
                flag = !flag;
            }
        }

        //qDebug()<<solar->earth_data_x[solar->data_num]<<" "<<solar->earth_data_y[solar->data_num]<<" "<<solar->earth_data_z[solar->data_num];
        this->sun = !this->camera_from_sun;

        // change the view port
        if(camera_changed)
        {
            if(camera_from_sun)
            {
                from_x  = 0;
                from_y  = 0;
                from_z  = 0;
            }
            else if(camera_from_moon)
            {
                //qDebug()<<" view from moon...";
                solar->moon = false;
                from_x = solar->earth_data_x[solar->data_num] + solar->distance * cos(solar->moon_solar_angle * solar->pie / 180);
                from_y = solar->earth_data_y[solar->data_num] + solar->distance * sin(solar->moon_solar_angle * solar->pie / 180);
                from_z = solar->earth_data_z[solar->data_num];
            }
            else if(camera_from_mercury)
            {
                solar->mercury = false;
                from_x = solar->mercury_data_x[solar->data_num];
                from_y = solar->mercury_data_y[solar->data_num];
                from_z = solar->mercury_data_z[solar->data_num];
            }
            else if(camera_from_venus)
            {
                solar->venus = false;
                from_x = solar->venus_data_x[solar->data_num];
                from_y = solar->venus_data_y[solar->data_num];
                from_z = solar->venus_data_z[solar->data_num];
            }
            else if(camera_from_earth)
            {
                solar->earth = false;
                from_x = solar->earth_data_x[solar->data_num];
                from_y = solar->earth_data_y[solar->data_num];
                from_z = solar->earth_data_z[solar->data_num];
            }
            else if(camera_from_mars)
            {
                solar->mars = false;
                from_x = solar->mars_data_x[solar->data_num];
                from_y = solar->mars_data_y[solar->data_num];
                from_z = solar->mars_data_z[solar->data_num];
            }
            else if(camera_from_jupiter)
            {
                solar->jupiter = false;
                from_x = solar->jupiter_data_x[solar->data_num];
                from_y = solar->jupiter_data_y[solar->data_num];
                from_z = solar->jupiter_data_z[solar->data_num];
            }
            else if(camera_from_saturn)
            {
                solar->saturn = false;
                from_x = solar->saturn_data_x[solar->data_num];
                from_y = solar->saturn_data_y[solar->data_num];
                from_z = solar->saturn_data_z[solar->data_num];
            }
            else if(camera_from_uranus)
            {
                solar->uranus = false;
                from_x = solar->uranus_data_x[solar->data_num];
                from_y = solar->uranus_data_y[solar->data_num];
                from_z = solar->uranus_data_z[solar->data_num];
            }
            else if(camera_from_neptune)
            {
                solar->neptune = false;
                from_x = solar->neptune_data_x[solar->data_num];
                from_y = solar->neptune_data_y[solar->data_num];
                from_z = solar->neptune_data_z[solar->data_num];
            }
        }

        if(view_changed)
        {
            if(view_to_moon)
            {
                solar->moon = true;
                to_x = solar->earth_data_x[solar->data_num] + solar->distance * cos(solar->moon_solar_angle * solar->pie / 180);
                to_y = solar->earth_data_y[solar->data_num] + solar->distance * sin(solar->moon_solar_angle * solar->pie / 180);
                to_z = solar->earth_data_z[solar->data_num];
            }
            else if(view_to_mercury)
            {
                solar->mercury = true;
                to_x = solar->mercury_data_x[solar->data_num];
                to_y = solar->mercury_data_y[solar->data_num];
                to_z = solar->mercury_data_z[solar->data_num];
            }
            else if(view_to_venus)
            {
                solar->venus = true;
                to_x = solar->venus_data_x[solar->data_num];
                to_y = solar->venus_data_y[solar->data_num];
                to_z = solar->venus_data_z[solar->data_num];
            }
            else if(view_to_earth)
            {
                //qDebug()<<"view to earth.";
                solar->earth = true;
                to_x = solar->earth_data_x[solar->data_num];
                to_y = solar->earth_data_y[solar->data_num];
                to_z = solar->earth_data_z[solar->data_num];
            }
            else if(view_to_mars)
            {
                solar->mars = true;
                to_x = solar->mars_data_x[solar->data_num];
                to_y = solar->mars_data_y[solar->data_num];
                to_z = solar->mars_data_z[solar->data_num];
            }
            else if(view_to_jupiter)
            {
                solar->jupiter = true;
                to_x = solar->jupiter_data_x[solar->data_num];
                to_y = solar->jupiter_data_y[solar->data_num];
                to_z = solar->jupiter_data_z[solar->data_num];
            }
            else if(view_to_saturn)
            {
                solar->saturn = true;
                to_x = solar->saturn_data_x[solar->data_num];
                to_y = solar->saturn_data_y[solar->data_num];
                to_z = solar->saturn_data_z[solar->data_num];
            }
            else if(view_to_uranus)
            {
                solar->uranus = true;
                to_x = solar->uranus_data_x[solar->data_num];
                to_y = solar->uranus_data_y[solar->data_num];
                to_z = solar->uranus_data_z[solar->data_num];
            }
            else if(view_to_neptune)
            {
                solar->neptune = true;
                to_x = solar->neptune_data_x[solar->data_num];
                to_y = solar->neptune_data_y[solar->data_num];
                to_z = solar->neptune_data_z[solar->data_num];
            }
        }
    }
    else
    {
        eclipse_model->step();
    }

    updateGL();

}

/*********************************************************
 * mouse event
 * learn from dashen provided by ligong
 *********************************************************/

/**
 * move the mouse
 */
void palnetWidget::mouseMoveEvent(QMouseEvent *e){
    ArcBall->MousePt.s.X = e->x();
    ArcBall->MousePt.s.Y = e->y();
    ArcBall->upstate();
    timerEvent(0);
}

/**
 * click button of the mouse
 */
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


/**
 * reenable the button
 */
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

/**
 * move the mouse
 */
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
    if(changeModel)
    {
        // here first do somethig with two-or-more buttons
        if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_0)
        {
            if( solar->moon_line_width < 5)
            {
                solar->moon_line_width += 0.1;
            }
            else
            {
                solar->moon_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_1)
        {
            if( solar->mercury_line_width < 5)
            {
                solar->mercury_line_width += 0.1;
            }
            else
            {
                solar->mercury_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_2)
        {
            if( solar->venus_line_width < 5)
            {
                solar->venus_line_width += 0.1;
            }
            else
            {
                solar->venus_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_3)
        {
            if( solar->earth_line_width < 5)
            {
                solar->earth_line_width += 0.1;
            }
            else
            {
                solar->earth_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_4)
        {
            if( solar->mars_line_width < 5)
            {
                solar->mars_line_width += 0.1;
            }
            else
            {
                solar->mars_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_5)
        {
            if( solar->jupiter_line_width < 5)
            {
                solar->jupiter_line_width += 0.1;
            }
            else
            {
                solar->jupiter_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_6)
        {
            if( solar->saturn_line_width < 5)
            {
                solar->saturn_line_width += 0.1;
            }
            else
            {
                solar->saturn_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_7)
        {
            if( solar->uranus_line_width < 5)
            {
                solar->uranus_line_width += 0.1;
            }
            else
            {
                solar->uranus_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_8)
        {
            if( solar->neptune_line_width < 5)
            {
                solar->neptune_line_width += 0.1;
            }
            else
            {
                solar->neptune_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::ControlModifier && e->key() == Qt::Key_9)
        {
            if( solar->neptune_line_width < 5)
            {
                solar->mercury_line_width += 0.1;
                solar->venus_line_width += 0.1;
                solar->earth_line_width += 0.1;
                solar->mars_line_width += 0.1;
                solar->jupiter_line_width += 0.1;
                solar->saturn_line_width += 0.1;
                solar->uranus_line_width += 0.1;
                solar->neptune_line_width += 0.1;
                solar->moon_line_width += 0.1;
            }
            else
            {
                solar->mercury_line_width = 1;
                solar->venus_line_width = 1;
                solar->earth_line_width = 1;
                solar->mars_line_width = 1;
                solar->jupiter_line_width = 1;
                solar->saturn_line_width = 1;
                solar->uranus_line_width = 1;
                solar->neptune_line_width = 1;
                solar->moon_line_width = 1;
            }
            updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_0)
        {
                    solar->moon = !(solar->moon);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_1)
        {
            //qDebug()<<" shift and 1 entered.";
                    solar->mercury = !(solar->mercury);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_2)
        {
                    solar->venus = !(solar->venus);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_3)
        {
                    solar->earth = !(solar->earth);
                    solar->moon  = !(solar->moon);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_4)
        {
                    solar->mars = !(solar->mars);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_5)
        {
                    solar->jupiter = !(solar->jupiter);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_6)
        {
                    solar->saturn= !(solar->saturn);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_7)
        {
                    solar->uranus = !(solar->uranus);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_8)
        {
                    solar->neptune = !(solar->neptune);
                    updateGL();
        }
        else if(e->modifiers() == Qt::AltModifier && e->key() == Qt::Key_9)
        {
                    /*
                    solar->mercury = !(solar->mercury);
                    solar->venus = !(solar->venus);
                    solar->earth = !(solar->earth);
                    solar->mars = !(solar->mars);
                    solar->jupiter = !(solar->jupiter);
                    solar->saturn= !(solar->saturn);
                    solar->uranus = !(solar->uranus);
                    solar->neptune = !(solar->neptune);
                    solar->moon = !(solar->moon);
                    */
                    solar->stars = !(solar->stars);
                    updateGL();
        }
        else
        {
            switch ( e->key() )
            {
            // this is a model with the full screen exchange
            // an example
            /*
            case Qt::Key_F11:
                fullscreen = !fullscreen;
                if( fullscreen)
                {
                    //qDebug()<<" debug model...";
                    QWidget* temp = (QWidget*)this->parent();
                    temp->hide();
                    this->setParent(0,Qt::Window);
                    //showFullScreen();
                    //main_window->setGeometry( 0, 0, QApplication::desktop()->width(), QApplication::desktop()->height() );
                    //this->setGeometry();
                    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                    //this->setWindowFlags(Qt::Dialog);
                    this->showFullScreen();
                }
                else
                {
                    //this->setParent();
                    this->setWindowFlags(Qt::SubWindow);
                    this->resize(800,600);
                }
                updateGL();
                break;
            */
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
                this->parentWidget()->close();
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
            case Qt::Key_9:
                solar->moon = !(solar->moon);
                solar->mercury = !(solar->mercury);
                solar->venus = !(solar->venus);
                solar->earth = !(solar->earth);
                solar->mars = !(solar->mars);
                solar->jupiter = !(solar->jupiter);
                solar->saturn= !(solar->saturn);
                solar->uranus = !(solar->uranus);
                solar->neptune = !(solar->neptune);
                solar->stars = !(solar->stars);

                solar->moon_line = !(solar->moon_line);
                solar->mercury_line = !(solar->mercury_line);
                solar->venus_line = !(solar->venus_line);
                solar->earth_line = !(solar->earth_line);
                solar->mars_line = !(solar->mars_line);
                solar->jupiter_line = !(solar->jupiter_line);
                solar->saturn_line = !(solar->saturn_line);
                solar->uranus_line = !(solar->uranus_line);
                solar->neptune_line = !(solar->neptune_line);
                updateGL();
                break;
            case Qt::Key_F4:
                changeModel = !changeModel;
                updateGL();
                break;
            case Qt::Key_F5:
                solar->setSpeed(1);
                solar->center_x = 0;
                solar->center_y = 0;
                solar->center_z = 0;
                from_x  = 0;
                from_y  = solar->neptune_data_y[0];
                from_z  = 0;
                to_x    = solar->center_x;
                to_y    = solar->center_y;
                to_z    = solar->center_z;
                up_x    = 0;
                up_y    = 0;
                up_z    = 1;
                updateGL();
                break;
            case Qt::Key_F6:
                watchEclipse = !watchEclipse;
                solar->setSpeed(0);
                //qDebug()<<" watch Eclipse "<< watchEclipse;
                if(watchEclipse)
                {
                    showMessage->setText("We will stop when eclipse happen.");
                    showMessage->show();
                }
                else
                {
                    showMessage->setText("We will not stop when eclipse happen.");
                    showMessage->show();
                }
                updateGL();
                break;
            case Qt::Key_F7:
                watchStars = !watchStars;
                solar->setSpeed(0);
                if(watchStars)
                {
                    showMessage->setText("We will stop when stars happen to appear in a line.");
                    showMessage->show();
                }
                else
                {
                    showMessage->setText("We will not stop when stars happen to appear in a line.");
                    showMessage->show();
                }
                updateGL();
                break;
            case Qt::Key_Space:
                solar->pause();
                updateGL();
                break;
            case Qt::Key_F8:
                solar->setSpeed(1);
                updateGL();
                break;
            // be careful about the eclipse restore.
            case Qt::Key_F9:
                flag = false;
                solar->setSpeed(1);
                updateGL();
                break;
            default:
                break;
            }
        }
    }
    else        // the eclipse model
    {
        switch(e->key())
        {
        case Qt::Key_Escape:
            close();
            this->parentWidget()->close();
            break;
        case Qt::Key_F4:
            //qDebug()<<" you pressed the button f4...";
            changeModel = !changeModel;
            updateGL();
            break;
        case Qt::Key_F2:
            eclipse_model->speed += 0.01;
            updateGL();
            break;
        case Qt::Key_F3:
            if(eclipse_model->speed >= 0.01)
            {
                eclipse_model->speed -= 0.01;
            }
            else
            {
                eclipse_model->speed = 0;
            }
            updateGL();
            break;
        case Qt::Key_F5:
            eclipse_model->sun_dis += 1;
            updateGL();
            break;
        case Qt::Key_F6:
            if( eclipse_model->sun_dis - eclipse_model->sun_r > 3)
            {
                eclipse_model->sun_dis -= 1;
            }
            else
            {
                // do nothing and return
            }
            updateGL();
            break;
        case Qt::Key_F7:
            if( eclipse_model->sun_dis - eclipse_model->sun_r > 2)
            {
                eclipse_model->sun_r += 0.5;
            }
            else
            {
                // do nothing and return
            }
            updateGL();
            break;
        case Qt::Key_F8:
            if( eclipse_model->sun_r > 1.5)
            {
                eclipse_model->sun_r -= 0.5;
            }
            updateGL();
            break;
        case Qt::Key_F9:
            if((eclipse_model->sun_dis - eclipse_model->moon_dis) >
                    (eclipse_model->sun_r + eclipse_model->moon_r + 2))
            {
                eclipse_model->moon_dis += 1;
            }
            updateGL();
            break;
        case Qt::Key_F10:
            if( eclipse_model->moon_dis - eclipse_model->moon_r > 2)
            {
                eclipse_model->moon_dis -= 1;
            }
            else
            {
                // do nothing and return
            }
            updateGL();
            break;
        case Qt::Key_F11:
            if( eclipse_model->moon_dis - eclipse_model->moon_r > 2)
            {
                eclipse_model->moon_r += 0.5;
            }
            else
            {
                // do nothing and return
            }
            updateGL();
            break;
        case Qt::Key_F12:
            if( eclipse_model->moon_r > 1.5)
            {
                eclipse_model->moon_r -= 0.5;
            }
            updateGL();
            break;
        default:
            break;
        }

    }
}

/**
 * get focus
 */
void palnetWidget::enterEvent(QEvent *e)
{
   this->setFocus();
}
