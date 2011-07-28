#include "palnet.h"
#include <iostream>
#include <fstream>
#include <QImage>
#include <QGLWidget>

/*
 * for debug
 */
#include <QDebug>
 /*
 */

using namespace std;

/**
 * do some init things and more
 */
Palnet::Palnet()
{
    // default: draw all the lines
    mercury_line = true;
    venus_line   = true;
    earth_line   = true;
    mars_line    = true;
    jupiter_line = true;
    saturn_line  = true;
    uranus_line  = true;
    neptune_line = true;

    // default: draw all the palnets
    mercury = true;
    venus   = true;
    earth   = true;
    mars    = true;
    jupiter = true;
    saturn  = true;
    uranus  = true;
    neptune = true;

    // default: copy
    mercury_cycle = 87.662;
    venus_cycle   = 226.459;
    earth_cycle   = 365.2564;
    mars_cycle    = 693.987;
    jupiter_cycle = 4346.551;
    saturn_cycle  = 10775.064;
    uranus_cycle  = 30827.640;
    neptune_cycle = 60194.255;
    moon_cycle    = 27.321;

    // the size of palnets
    // used to draw
    mercury_size = 0.076;
    venus_size   = 0.19;
    earth_size   = 0.2;
    mars_size    = 0.106;
    jupiter_size = 0.5;
    saturn_size  = 0.5;
    uranus_size  = 0.3;
    neptune_size = 0.29;
    moon_size    = 0.090;

    // rotate angle
    // used to self rotate
    mercury_angle = 10;
    venus_angle   = 10;
    earth_angle   = 10;
    mars_angle    = 10;
    jupiter_angle = 10;
    saturn_angle  = 10;
    uranus_angle  = 10;
    neptune_angle = 10;
    moon_angle    = 10;

    // default: begin from 0
    data_num = 0;

    // default: speed from 1
    speed = 1;

    // texture files
    image[0] = "mercury.jpg";
    image[1] = "venus.jpg",
    image[2] = "earth.png",
    image[3] = "mars.jpg",
    image[4] = "jupiter.jpg",
    image[5] = "saturn.jpg",
    image[6] = "uranus.jpg",
    image[7] = "neptune.jpg";

    // init data
    if(!readData())
    {
        //qDebug()<<"Load data failed!";
    }
    //qDebug()<<"Init successful!";
}


/**
 * read data from file using getData() eight times
 */
bool Palnet::readData()
{
    bool success = true;
    // mercury
    if(!getData("mercury.txt", mercury_data_x, mercury_data_y, mercury_data_z))
    {
        return (!success);
    }

    // venus
    if(!getData("venus.txt", venus_data_x, venus_data_y, venus_data_z))
    {
        return (!success);
    }

    // earth
    if(!getData("earth.txt", earth_data_x, earth_data_y, earth_data_z))
    {
        return (!success);
    }

    // mars
    if(!getData("mars.txt", mars_data_x, mars_data_y, mars_data_z))
    {
        return (!success);
    }

    // jupiter
    if(!getData("jupiter.txt", jupiter_data_x, jupiter_data_y, jupiter_data_z))
    {
        return (!success);
    }

    // saturn
    if(!getData("saturn.txt", saturn_data_x, saturn_data_y, saturn_data_z))
    {
        return (!success);
    }

    // uranus
    if(!getData("uranus.txt", uranus_data_x, uranus_data_y, uranus_data_z))
    {
        return (!success);
    }

    // neptune
    if(!getData("neptune.txt", neptune_data_x, neptune_data_y, neptune_data_z))
    {
        return (!success);
    }

    return success;
}

/**
 * get data from files
 */
bool Palnet::getData(char *filename,double data_x[],
                     double data_y[], double data_z[])
{
    qDebug()<<filename<<"    ";
    int i = 0;
    ifstream read;
    read.open(filename,ios::in);
    if(read.is_open()){
        qDebug()<<" open successful ";
        while(!read.eof())
        {
            read>>data_x[i];
            read>>data_y[i];
            read>>data_z[i];
            i++;
        }
        qDebug()<<" read successful: "<<i;
    }
    else
    {
        qDebug()<<"Soory, open file failed.";
        return false;
    }
    read.close();
    return true;
}

/**
 * draw the lines
 */
bool Palnet::drawLines()
{
    bool success = true;
    if(mercury_line)
    {
        drawLine(mercury_data_x,
                 mercury_data_y,
                 mercury_data_z,
                 mercury_cycle);
        return (!success);
    }

    if(venus_line)
    {
        drawLine(venus_data_x,
                venus_data_y,
                venus_data_z,
                venus_cycle);
        return (!success);
    }

    if(earth_line)
    {
        drawLine(earth_data_x,
                earth_data_y,
                earth_data_z,
                earth_cycle);
        return (!success);
    }

    if(mars_line)
    {
        drawLine(mars_data_x,
                mars_data_y,
                mars_data_z,
                mars_cycle);
        return (!success);
    }

    if(jupiter_line)
    {
        drawLine(jupiter_data_x,
                jupiter_data_y,
                jupiter_data_z,
                jupiter_cycle);
        return (!success);
    }

    if(saturn_line)
    {
        drawLine(saturn_data_x,
                saturn_data_y,
                saturn_data_z,
                saturn_cycle);
        return (!success);
    }

    if(uranus_line)
    {
        drawLine(uranus_data_x,
                uranus_data_y,
                uranus_data_z,
                uranus_cycle);
        return (!success);
    }

    if(neptune_line)
    {
        drawLine(neptune_data_x,
                neptune_data_y,
                neptune_data_z,
                neptune_cycle);
        return (!success);
    }

    /*
    if(moon_line){
        drawLine(moon_data_x,
                moon_data_y,
                moon_data_z,
                moon_cycle);
        return (!success);
    }
    */
}


/**
 * draw a singal line
 */
bool Palnet::drawLine(double data_x[], double data_y[], double data_z[], double cycle)
{
    int i = 0;
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < cycle + 1; i++) {
        glVertex3f(data_x[i],data_y[i],data_z[i]);
    }
    glEnd();
}


/**
 * draw planets
 */
bool Palnet::drawPalnets()
{
    bool success = true;

    // mercury
    if(mercury)
    {
        if(drawPalnet(mercury_data_x[data_num],
                      mercury_data_y[data_num],
                      mercury_data_z[data_num],
                      mercury_size,
                      mercury_angle,
                      texture_id[0]))
        {
            return (!success);
        }
    }

    // venus
    if(venus)
    {
        if(drawPalnet(	venus_data_x[data_num],
                        venus_data_y[data_num],
                        venus_data_z[data_num],
                        venus_size,
                        venus_angle,
                        texture_id[1]))
        {
            return (!success);
        }
    }

    // earth
    if(earth)
    {
        if(drawPalnet(	earth_data_x[data_num],
                        earth_data_y[data_num],
                        earth_data_z[data_num],
                        earth_size,
                        earth_angle,
                        texture_id[2]))
        {
            return (!success);
        }
    }

    // mars
    if(mars)
    {
        if(drawPalnet(	mars_data_x[data_num],
                        mars_data_y[data_num],
                        mars_data_z[data_num],
                        mars_size,
                        mars_angle,
                        texture_id[3]))
        {
            return (!success);
        }
    }

    // jupiter
    if(jupiter)
    {
        if(drawPalnet(	jupiter_data_x[data_num],
                        jupiter_data_y[data_num],
                        jupiter_data_z[data_num],
                        jupiter_size,
                        jupiter_angle,
                        texture_id[4]))
        {
            return (!success);
        }
    }

    // saturn
    if(saturn)
    {
        if(drawPalnet(	saturn_data_x[data_num],
                        saturn_data_y[data_num],
                        saturn_data_z[data_num],
                        saturn_size,
                        saturn_angle,
                        texture_id[5]))
        {
            return (!success);
        }
    }

    // uranus
    if(uranus)
    {
        if(drawPalnet(	uranus_data_x[data_num],
                        uranus_data_y[data_num],
                        uranus_data_z[data_num],
                        uranus_size,
                        uranus_angle,
                        texture_id[6]))
        {
            return (!success);
        }
    }

    // neptune
    if(neptune)
    {
        if(drawPalnet(	neptune_data_x[data_num],
                        neptune_data_y[data_num],
                        neptune_data_z[data_num],
                        neptune_size,
                        neptune_angle,
                        texture_id[7]))
        {
            return (!success);
        }
    }

    // moon
    /*
    if(moon)
    {
        if(drawPalnet(	moon_data_x[data_num],
                        moon_data_y[data_num],
                        moon_data_z[data_num],
                        moon_size,
                        moon_angle))
        {
            return (!success);
        }
    }
    */
}
/**
 * draw planet
 */
bool Palnet::drawPalnet(double point_x, double point_y,
                        double point_z, double size,
                        double angle,GLuint texture_id)
{
    glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            GLUquadricObj* p = gluNewQuadric();
            glTranslatef(point_x, point_y, point_z);
            glRotatef(angle, 0.0, 1.0, 0.0);
            glBindTexture(GL_TEXTURE_2D,texture_id);
            {
                gluQuadricTexture(p,GL_TRUE);
                gluSphere(p, size, 320, 160);
                gluDeleteQuadric(p);
            }
        glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

/**
 * load textures just for eight palnets
 */
bool Palnet::loadTexture(GLuint *texture_id)
{
    int i;

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glGenTextures(8, texture_id);

    for(i=0; i < 8; i ++)
    {
        QImage tex, buf;
        if ( !buf.load( image[i] ) )
        {
                qWarning( "Could not read image file, using single-color instead." );
                QImage dummy( 128, 128, QImage::Format_ARGB32 );
                dummy.fill( Qt::green );
                buf = dummy;
        }
        tex = QGLWidget::convertToGLFormat( buf );
        glBindTexture( GL_TEXTURE_2D, texture_id[i] );
        glTexImage2D( GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
                GL_RGBA, GL_UNSIGNED_BYTE, tex.bits() );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    }
}
