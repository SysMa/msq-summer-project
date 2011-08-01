#include "palnet.h"
#include <iostream>
#include <fstream>
#include <math.h>
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
    // PI
    pie = 3.14159265357;

    // stars in line jduge angle
    required_angle = pie / 9;

    // set speed;
    setSpeed(1);

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
    stars   = true;

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
    sun_size     = 0.20f;
    mercury_size = 0.08f;
    venus_size   = 0.18f;
    earth_size   = 0.18f;
    mars_size    = 0.14f;
    jupiter_size = 0.52f;
    saturn_size  = 0.44f;
    uranus_size  = 0.36f;
    neptune_size = 0.40f;
    moon_size    = 0.03f;

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


    // texture files
    image[0] = "mercury.bmp";
    image[1] = "venus.bmp",
    image[2] = "earth.bmp",
    image[3] = "mars.bmp",
    image[4] = "jupiter.bmp",
    image[5] = "saturn.bmp",
    image[6] = "uranus.bmp",
    image[7] = "neptune.bmp";
    image[8] = "moon.bmp";
    image[9] = "sun.bmp";
    image[10]= "back.bmp";

    // line width
    // default: 1
    mercury_line_width  = 0.5;
    venus_line_width    = 0.5;
    earth_line_width    = 0.5;
    mars_line_width     = 0.5;
    jupiter_line_width  = 0.5;
    saturn_line_width   = 0.5;
    uranus_line_width   = 0.5;
    neptune_line_width  = 0.5;
    moon_line_width     = 0.5;

    // solar angle
    mercury_solar_angle = 0.0f;
    venus_solar_angle   = 255.0f;
    earth_solar_angle   = 45.0f;
    mars_solar_angle    = 60.0f;
    jupiter_solar_angle = 90.0f;
    saturn_solar_angle  = 115.0f;
    uranus_solar_angle  = 135.0f;
    neptune_solar_angle = 0.0f;
    moon_solar_angle    = 0.0f;


    // axis angle
    mercury_axis_angle  = 0.0f;
    venus_axis_angle    = 0.0f;
    earth_axis_angle    = 0.0f;
    mars_axis_angle     = 0.0f;
    jupiter_axis_angle  = 0.0f;
    saturn_axis_angle   = 0.0f;
    uranus_axis_angle   = 0.0f;
    neptune_axis_angle  = 0.0f;
    moon_axis_angle     = 0.0f;


    // distance form earth to moon
    distance = earth_size * 1.25;

    // init light
    LightAmbient[0] = LightAmbient[1] = LightAmbient[2] = 0.5f;
    LightAmbient[3] = LightDiffuse[0] = LightDiffuse[1] = LightDiffuse[2] = LightDiffuse[3] = LightPosition[3] = 1.0f;
    LightPosition[0]= LightPosition[1]= LightPosition[2]= 0.0f;

    LightAmbient2[0]= LightAmbient2[1]= LightAmbient2[2]= 0.2f;
    LightAmbient2[3]= LightDiffuse2[3]= LightDiffuse2[3]= 1.0f;
    LightDiffuse2[0]= LightDiffuse2[1]= LightDiffuse2[2]= 0.5f;
    LightPosition2[0]=LightPosition2[1]=0.0f;
    LightPosition2[2]=2.0f;

    // init global position
    globalPosition.fPosX = 0;
    globalPosition.fPosY = 0;
    globalPosition.iDegreesX = 20;
    globalPosition.iDegreesY = 25;
    globalPosition.bRotationOn = true;

    glRotatef((float)globalPosition.iDegreesX, 0.0, 1.0, 0.0);
    glRotatef((float)globalPosition.iDegreesY, 1.0, 0.0, 0.0);

    center_x = 0.0;
    center_y = 0.0;
    center_z = 0.0;

    mercury_line_color[0]
  = venus_line_color[0]
  = earth_line_color[0]
  = mars_line_color[0]
  = jupiter_line_color[0]
  = saturn_line_color[0]
  = uranus_line_color[0]
  = neptune_line_color[0]
  = moon_line_color[0]
  = 0;

    mercury_line_color[1]
  = venus_line_color[1]
  = earth_line_color[1]
  = mars_line_color[1]
  = jupiter_line_color[1]
  = saturn_line_color[1]
  = uranus_line_color[1]
  = neptune_line_color[1]
  = moon_line_color[1]
  = 1;

    mercury_line_color[2]
  = venus_line_color[2]
  = earth_line_color[2]
  = mars_line_color[2]
  = jupiter_line_color[2]
  = saturn_line_color[2]
  = uranus_line_color[2]
  = neptune_line_color[2]
  = moon_line_color[2]
  = 0;

    mercury_line_color[3]
  = venus_line_color[3]
  = earth_line_color[3]
  = mars_line_color[3]
  = jupiter_line_color[3]
  = saturn_line_color[3]
  = uranus_line_color[3]
  = neptune_line_color[3]
  = moon_line_color[3]
  = 0;

    // init data
    //if(!readData())
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
        //qDebug()<<" open successful ";
        while(!read.eof())
        {
            read>>data_x[i];
            read>>data_y[i];
            read>>data_z[i];
            i++;
        }
        //qDebug()<<" read successful: "<<i;
    }
    else
    {
        //qDebug()<<"Soory, open file failed.";
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
        if(!drawLine(mercury_data_x,
                     mercury_data_y,
                     mercury_data_z,
                     mercury_cycle,
                     mercury_line_width,
                     mercury_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" mercury line successful ...";
        }
    }

    if(venus_line)
    {
        if(!drawLine(venus_data_x,
                     venus_data_y,
                     venus_data_z,
                     venus_cycle,
                     venus_line_width,
                     venus_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" venus line successful ...";
        }

    }

    if(earth_line)
    {
        if(!drawLine(earth_data_x,
                     earth_data_y,
                     earth_data_z,
                     earth_cycle,
                     earth_line_width,
                     earth_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" earth line successful ...";
        }
    }

    if(mars_line)
    {
        if(!drawLine(mars_data_x,
                     mars_data_y,
                     mars_data_z,
                     mars_cycle,
                     mars_line_width,
                     mars_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" mars line successful ...";
        }
    }

    if(jupiter_line)
    {
        if(!drawLine(jupiter_data_x,
                     jupiter_data_y,
                     jupiter_data_z,
                     jupiter_cycle,
                     jupiter_line_width,
                     jupiter_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" jupiter line successful ...";
        }
    }

    if(saturn_line)
    {
        if(!drawLine(saturn_data_x,
                     saturn_data_y,
                     saturn_data_z,
                     saturn_cycle,
                     saturn_line_width,
                     saturn_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" saturn line successful ...";
        }
    }

    if(uranus_line)
    {
        if(!drawLine(uranus_data_x,
                     uranus_data_y,
                     uranus_data_z,
                     uranus_cycle,
                     uranus_line_width,
                     uranus_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" uranus line successful ...";
        }
    }

    if(neptune_line)
    {
        if(!drawLine(neptune_data_x,
                     neptune_data_y,
                     neptune_data_z,
                     neptune_cycle,
                     neptune_line_width,
                     neptune_line_color))
        {
            return (!success);
        }
        else
        {
            //qDebug()<<" neptune line successful ...";
        }
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
    return true;
}


/**
 * draw a singal line
 */
bool Palnet::drawLine(double data_x[], double data_y[],
                      double data_z[], double cycle,
                      double line_width, double line_color[])
{
    int i = 0;
    glDisable(GL_LIGHTING);
    glLineWidth(line_width);
    glBegin(GL_LINE_LOOP);

    glColor3f(line_color[0], line_color[1], line_color[2]);
    for (i = 0; i < cycle + 1; i++) {
        glVertex3f(data_x[i] - center_x, data_y[i] - center_y, data_z[i] - center_z);
    }
    glEnd();
    glEnable(GL_LIGHTING);
    return true;
}


/**
 * draw planets
 */
bool Palnet::drawPalnets()
{
    bool success = true;

    // mercury
    //qDebug()<<" mercury : "<<mercury;
    if(mercury)
    {
        //qDebug()<<mercury_data_x[data_num];
        //qDebug()<<" ...Draw mercury ...";
        if(!drawPalnet(mercury_data_x[data_num],
                      mercury_data_y[data_num],
                      mercury_data_z[data_num],
                      mercury_size,
                      mercury_solar_angle,
                      mercury_axis_angle,
                      texture_id[0]))
        {
            return (!success);
        }
    }

    // venus
    if(venus)
    {
        //qDebug()<<" ... Draw venus ...";
        if(!drawPalnet(	venus_data_x[data_num],
                        venus_data_y[data_num],
                        venus_data_z[data_num],
                        venus_size,
                        venus_solar_angle,
                        venus_axis_angle,
                        texture_id[1]))
        {
            return (!success);
        }
    }

    // earth
    if(earth)
    {
        if(!drawPalnet(	earth_data_x[data_num],
                        earth_data_y[data_num],
                        earth_data_z[data_num],
                        earth_size,
                        earth_solar_angle,
                        earth_axis_angle,
                        texture_id[2]))
        {
            return (!success);
        }
    }

    // mars
    if(mars)
    {
        if(!drawPalnet(	mars_data_x[data_num],
                        mars_data_y[data_num],
                        mars_data_z[data_num],
                        mars_size,
                        mars_solar_angle,
                        mars_axis_angle,
                        texture_id[3]))
        {
            return (!success);
        }
    }

    // jupiter
    if(jupiter)
    {
        if(!drawPalnet(	jupiter_data_x[data_num],
                        jupiter_data_y[data_num],
                        jupiter_data_z[data_num],
                        jupiter_size,
                        jupiter_solar_angle,
                        jupiter_axis_angle,
                        texture_id[4]))
        {
            return (!success);
        }
    }

    // saturn
    if(saturn)
    {
        if(!drawPalnet(	saturn_data_x[data_num],
                        saturn_data_y[data_num],
                        saturn_data_z[data_num],
                        saturn_size,
                        saturn_solar_angle,
                        saturn_axis_angle,
                        texture_id[5]))
        {
            return (!success);
        }
    }

    // uranus
    if(uranus)
    {
        if(!drawPalnet(	uranus_data_x[data_num],
                        uranus_data_y[data_num],
                        uranus_data_z[data_num],
                        uranus_size,
                        uranus_solar_angle,
                        uranus_axis_angle,
                        texture_id[6]))
        {
            return (!success);
        }
    }

    // neptune
    if(neptune)
    {
        if(!drawPalnet(	neptune_data_x[data_num],
                        neptune_data_y[data_num],
                        neptune_data_z[data_num],
                        neptune_size,
                        neptune_solar_angle,
                        neptune_axis_angle,
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
    return true;
}
/**
 * draw planet
 */
bool Palnet::drawPalnet(double point_x, double point_y,
                        double point_z, double size,
                        double solar_angle,
                        double axis_angle,
                        GLuint texture)
{
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();

        /*
            GLUquadricObj* p = gluNewQuadric();
            glTranslatef(point_x, point_y, point_z);
            glRotatef(angle, 0.0, 1.0, 0.0);
            glBindTexture(GL_TEXTURE_2D,texture_id);
            {
                gluQuadricTexture(p,GL_TRUE);
                gluSphere(p, size, 320, 160);
                gluDeleteQuadric(p);
            }
         */

            // rotate
            //glRotatef(solar_angle, 0, -1, 0);

            // translate to the position
            glTranslatef(point_x - center_x, point_y - center_y, point_z - center_z);

            // rotate
            glRotatef(axis_angle, 0, 0, 1);

            // to deal with the texture
            glRotatef(180.0, 1.0, 0.0, 0.0);

            /*
            // bind to the texture
            glBindTexture(GL_TEXTURE_2D, texture_id);

            // texutre and draw
            GLUquadricObj*  q = gluNewQuadric();
            //gluQuadricDrawStyle(q, GLU_FILL);
            //gluQuadricNormals (q, GLU_SMOOTH);
            gluQuadricTexture (q, GL_TRUE);
            gluSphere(q, size, 16, 16);
            gluDeleteQuadric(q);

            */
            glBindTexture(GL_TEXTURE_2D, texture);//绑定纹理

            // new light
            // glEnable(GL_LIGHTING);
            /*
            GLfloat planet_ambient[] = { 0.01 , 0.01 , 0.01 , 1.0 };
            GLfloat planet_diffuse[] = { 0.7 , 0.7 , 0.7 , 1.0 };
            glMaterialfv(GL_FRONT , GL_AMBIENT ,planet_ambient);
            glMaterialfv(GL_FRONT , GL_DIFFUSE ,planet_diffuse);
            */

            //绘制二次曲面
            glBegin(GL_QUADS);
                    GLUquadric* quadricObj=gluNewQuadric();
                    gluQuadricTexture(quadricObj,GL_TRUE);
                    gluSphere(quadricObj,size,50,50);
                    gluDeleteQuadric(quadricObj);
            glEnd();

            if(texture == texture_id[5]){
                glDisable(GL_TEXTURE_2D);
                glDisable(GL_LIGHTING);
                glBegin(GL_TRIANGLE_STRIP);
                    glColor3f(0.5,0.4,0.3);
                    for(int i =0;i < 361;i++){
                        glColor3f(1.0,1.0,1.0);
                        glVertex3d((size * 1.5)*cos( i * pie/180),(size * 1.5)*sin(i * pie/180),0);
                        glColor3f(205.0/255.0,149.0/255.0,12.0/255.0);
                        glVertex3d(size * 1.25 * cos((i+1)* pie/180),size * 1.25 * sin((i+1) * pie/180),0);
                    }
                glEnd();
                glEnable(GL_TEXTURE_2D);
                glEnable(GL_LIGHTING);
            }

            glLoadIdentity();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    return true;
}

/**
 * load textures just for eight palnets
 */
/*
bool Palnet::loadTextures(GLuint *texture_id)
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
*/

/**
 * load the moon texture
 */
/*
bool Palnet::loadMoonTexture(GLuint moon_id, char* path)
{
    int Status = false;
    AUX_RGBImageRec *TextureImage[1];
    memset(TextureImage,0,sizeof(void *)*1);

    if (TextureImage[0]=LoadBMP(path)){
        //qDebug()<<"Load image "<<path;
        Status = true;
        glGenTextures(1, &moon_id);
        glBindTexture(GL_TEXTURE_2D, moon_id);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX,
                     TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    }

    return Status;
}
*/

/**
 * load one texture
 */
bool Palnet::loadTexture(GLuint *texture,char* path,int i)
{
    int Status = false;
    AUX_RGBImageRec *TextureImage[1];
    memset(TextureImage,0,sizeof(void *)*1);

    if (TextureImage[0]=LoadBMP(path)){
        //qDebug()<<"Load image "<<path;
        Status = true;
        glGenTextures(1, &texture[i]);
        glBindTexture(GL_TEXTURE_2D, texture[i]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX,
                     TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    }

    return Status;
}

/**
 * help load texture
 */
AUX_RGBImageRec* Palnet::LoadBMP(char *Filename){
    FILE *File = 0;
    if (!Filename){
        return 0;
    }

    File = fopen(Filename, "r");

    if (File){
        fclose(File);
        return auxDIBImageLoadA((LPCSTR)Filename);
    }

    return 0;
}

/**
 * update
 */
void Palnet::setNew()
{
    /*
    if(data_num < 109574 && data_num >= 0 && speed )
    {
        data_num += speed;
        //qDebug()<<speed;
    }
    else if(data_num == 0 && speed < 0)
    {

    }
    else
    {
        //speed = 1;
        data_num = 0;
        return ;
    }*/
    if( data_num + speed >= 10957 && speed > 0)
    {
        data_num = 0;
    }
    else if( data_num + speed <= 0 && speed < 0)
    {
        data_num = 10957;
    }
    else
    {
        data_num += speed;
    }


    mercury_axis_angle += mercury_axis_speed;
    if( mercury_axis_angle > 360)
    {
        mercury_axis_angle -= 360;
    }

    venus_axis_angle += venus_axis_speed;
    if( venus_axis_angle > 360){
        venus_axis_angle -= 360;
    }

    earth_axis_angle += earth_axis_speed;
    if( earth_axis_angle > 360)
    {
        earth_axis_angle -= 360;
    }

    moon_axis_angle += moon_axis_speed;
    if( moon_axis_angle > 360)
    {
        moon_axis_angle -= 360;
    }

    mars_axis_angle += mars_axis_speed;
    if( mars_axis_angle > 360){
        mars_axis_angle -= 360;
    }

    jupiter_axis_angle += jupiter_axis_speed;
    if( jupiter_axis_angle > 360){
        jupiter_axis_angle -= 360;
    }

    uranus_axis_angle += uranus_axis_speed;
    if( uranus_axis_angle > 360){
        uranus_axis_angle -= 360;
    }

    saturn_axis_angle += saturn_axis_speed;
    if( saturn_axis_angle > 360){
        saturn_axis_angle -= 360;
    }

    neptune_axis_angle += neptune_axis_speed;
    if( neptune_axis_angle > 360){
        neptune_axis_angle -= 360;
    }

    // soalr speed
    mercury_solar_angle += mercury_solar_speed;
    if( mercury_solar_angle > 360)
    {
        mercury_solar_angle -= 360;
    }

    venus_solar_angle += venus_solar_speed;
    if( venus_solar_angle > 360){
        venus_solar_angle -= 360;
    }

    earth_solar_angle += earth_solar_speed;
    if( earth_solar_angle > 360)
    {
        earth_solar_angle -= 360;
    }

    moon_solar_angle += moon_solar_speed;
    if( moon_solar_angle > 360)
    {
        moon_solar_angle -= 360;
    }

    mars_solar_angle += mars_solar_speed;
    if( mars_solar_angle > 360){
        mars_solar_angle -= 360;
    }

    jupiter_solar_angle += jupiter_solar_speed;
    if( jupiter_solar_angle > 360){
        jupiter_solar_angle -= 360;
    }

    uranus_solar_angle += uranus_solar_speed;
    if( uranus_solar_angle > 360){
        uranus_solar_angle -= 360;
    }

    saturn_solar_angle += saturn_solar_speed;
    if( saturn_solar_angle > 360){
        saturn_solar_angle -= 360;
    }

    neptune_solar_angle += neptune_solar_speed;
    if( neptune_solar_angle > 360){
        neptune_solar_angle -= 360;
    }
}

/**
 * draw sun
 */
void Palnet::drawSun()
{
   glEnable(GL_TEXTURE_2D);
   glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, texture_id[9]);
        // added new to make the sun-s
        /*
        glEnable(GL_BLEND);
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glBlendFunc(GL_SRC_ALPHA,GL_ONE);
        glColor4f(1.0f,1.0f,1.0f,0.4);
        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_LIGHTING);
        // end of the new lines
*/

        GLfloat m_materialEmi[4]={0.2f,0.2f,0.2f,0.8f};
        glMaterialfv(GL_FRONT,GL_EMISSION,m_materialEmi);


        glTranslatef(center_x, center_y, center_z);
        glBegin(GL_QUADS);
            GLUquadric* quadricObj=gluNewQuadric();
            gluQuadricTexture(quadricObj,GL_TRUE);
            gluSphere(quadricObj,sun_size,50,50);
            gluDeleteQuadric(quadricObj);
       glEnd();
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
}

/**
 * draw moon
 */
bool Palnet::drawMoon(double earth_x, double earth_y, double earth_z,
                      double solar_angle, double axis_angle)
{
    if(moon)
    {
        //qDebug()<<"begin to draw the moon";
        //qDebug()<<earth_x<<" "<<earth_y<<" "<<earth_z<<" ";
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
            // translate to the position
            glTranslatef(earth_x + distance * cos(solar_angle * pie / 180),
                         earth_y + distance * sin(solar_angle * pie / 180),
                         earth_z );
            //qDebug()<<distance<<"  "<<solar_angle;

            // rotate
            glRotatef(axis_angle, 0, 0, 1);
            // to deal with the texture
            glRotatef(180.0, 1.0, 0.0, 0.0);

            glBindTexture(GL_TEXTURE_2D, texture_id[8]);
            glBegin(GL_QUADS);
                    GLUquadric* quadricObj=gluNewQuadric();
                    gluQuadricTexture(quadricObj,GL_TRUE);
                    gluSphere(quadricObj,moon_size,50,50);
                    gluDeleteQuadric(quadricObj);
            glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        return true;
    }
    else
    {
        return false;
    }
}

/**
 * draw the moonline
 */
bool Palnet::drawMoonLine()
{
    if(moon_line)
    {
        int i = 0;
        glLineWidth(moon_line_width);
        glBegin(GL_LINE_LOOP);

        glColor3f(moon_line_color[0], moon_line_color[1], moon_line_color[2]);
        for (i = 0; i < 360 + 1; i++) {
            glVertex3f(earth_data_x[data_num] + distance * cos(i * pie / 180),
                       earth_data_y[data_num] + distance * sin(i * pie / 180),
                       earth_data_z[data_num] );
        }
        glEnd();
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * render screen
 */
bool Palnet::renderscreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glTranslatef(globalPosition.fPosX, 0.0, 0.0);
    glTranslatef(0.0, globalPosition.fPosY, 0.0);
    LightPosition[0]		= LightPosition[0]  + globalPosition.fPosX;
    LightPosition[1]		= LightPosition[1]  + globalPosition.fPosX;
    LightPosition2[0]		= LightPosition2[0] + globalPosition.fPosX;
    LightPosition2[1]		= LightPosition2[1] + globalPosition.fPosX;
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);
    //glLightfv(GL_LIGHT2, GL_POSITION,LightPosition2);
    globalPosition.fPosX	= 0;
    globalPosition.fPosY	= 0;
    return TRUE;
}

/**
 * draw stars
 */
bool Palnet::drawStars()
{
    if(stars)
    {
        glDisable(GL_LIGHTING);
        glColor3f(0,1.0,0);
        glBegin(GL_POINTS);
           for(int i = 0;i < 5;i++){
               double z = i*0.01;
               for(int j =0;j < 120;j++){
                   double dis = sqrt(mars_data_x[0] * mars_data_x[0]
                                     + mars_data_y[0] * mars_data_y[0]
                                     + mars_data_z[0] * mars_data_z[0]);
                   double r = dis * 1.2 + 0.75*qrand()/9999;
                   double temp = (rand()+0.0)/9999*360;
                   //qDebug()<<temp<<endl;
                   double x = r*sin(temp);
                   double y = r*cos(temp);
                   glVertex3d(x,y,z);
               }
           }
        glEnd();
        glEnable(GL_LIGHTING);
        return true;
    }
    else
    {
        return false;
    }

}


/**
 * set all the speed
 */
bool Palnet::setSpeed(int desire_speed)
{
    // speed of the day
    speed = 0 + desire_speed;


    // speed of angles
    //
    mercury_axis_speed  = 0.1f * desire_speed;
    venus_axis_speed    = 0.2f * desire_speed;
    earth_axis_speed    = 0.6f * desire_speed;
    mars_axis_speed     = 0.5f * desire_speed;
    jupiter_axis_speed  = 2.6f * desire_speed;
    saturn_axis_speed   = 2.5f * desire_speed;
    uranus_axis_speed   = 1.5f * desire_speed;
    neptune_axis_speed  = 1.7f * desire_speed;
    moon_axis_speed     = 3.0f * desire_speed;

    // speed of the solar angles
    mercury_solar_speed = 1.6f * desire_speed;
    venus_solar_speed   = 1.2f * desire_speed;
    earth_solar_speed   = 1.1f * desire_speed;
    mars_solar_speed    = 1.0f * desire_speed;
    jupiter_solar_speed = 0.2f * desire_speed;
    saturn_solar_speed  = 0.1f * desire_speed;
    uranus_solar_speed  = 0.06f * desire_speed;
    neptune_solar_speed = 0.03f * desire_speed;
    moon_solar_speed    = 0.8f * desire_speed;
}

/**
 * pause
 */
bool Palnet::pause()
{
    // speed of the day
    speed = 0;
    // speed of the solar angles
    mercury_solar_speed = 0;
    venus_solar_speed   = 0;
    earth_solar_speed   = 0;
    mars_solar_speed    = 0;
    jupiter_solar_speed = 0;
    saturn_solar_speed  = 0;
    uranus_solar_speed  = 0;
    neptune_solar_speed = 0;
    moon_solar_speed    = 0;
}

/**
 * judge the eclipset
 */
bool Palnet::isEclipse()
{
    double moon_data_x = earth_data_x[data_num] + distance * cos(moon_solar_angle * pie / 180);
    double moon_data_y = earth_data_y[data_num] + distance * sin(moon_solar_angle * pie / 180);

    double sun_data_x = 0 - center_x;
    double sun_data_y = 0 - center_y;

    if(true)
    {
        //qDebug()<<"moon :"<<moon_data_x<<" "<<moon_data_y;
        //qDebug()<<"earth:"<<earth_data_x[data_num]<<" "<<earth_data_y[data_num];
        return true;
    }
    else
    {
        return false;
    }
}


/**
 * find the rang between nums
 */
double findRange(double nums[], int count)
{
    double max,min;
    max = nums[0];
    min = nums[0];
    for(int i = 0; i < count; i++)
    {
        max = max >= nums[i] ? max : nums[i];
        min = min <= nums[i] ? min : nums[i];
    }
    return (max - min);
}

/**
 * stars in line
 */
bool Palnet::isInline()
{
    double ranges[8];
    ranges[0] = atan(mercury_data_y[data_num]/mercury_data_x[data_num]);
    ranges[1] = atan(venus_data_y[data_num]/venus_data_x[data_num]);
    ranges[2] = atan(earth_data_y[data_num]/earth_data_x[data_num]);
    ranges[3] = atan(mars_data_y[data_num]/mars_data_x[data_num]);
    ranges[4] = atan(jupiter_data_y[data_num]/jupiter_data_x[data_num]);
    ranges[5] = atan(saturn_data_y[data_num]/saturn_data_x[data_num]);
    ranges[6] = atan(uranus_data_y[data_num]/uranus_data_x[data_num]);
    ranges[7] = atan(neptune_data_y[data_num]/neptune_data_x[data_num]);

    if(findRange(ranges,8) <= required_angle)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 *
 */
bool Palnet::drawBackground()
{
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        double r = sqrt(neptune_data_x[data_num] * neptune_data_x[data_num]
                        + neptune_data_y[data_num] * neptune_data_y[data_num]
                        + neptune_data_z[data_num] * neptune_data_z[data_num]);

        glBindTexture(GL_TEXTURE_2D, texture_id[10]);
        glBegin(GL_QUADS);
                GLUquadric* quadricObj=gluNewQuadric();
                gluQuadricTexture(quadricObj,GL_TRUE);
                gluSphere(quadricObj,r  * 1.05 ,50,50);
                gluDeleteQuadric(quadricObj);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);

    return true;
}
