/**************************************************************
  *
  * this is the model of eclipse
  * Author: shiqingma@gmail.com
  * Date  : 2011-07 ~ 2011-08
  *************************************************************/

#include "eclipse.h"
#include "math.h"
#include <QDebug>

Eclipse::Eclipse()
{
    // init
    sun_dis = 3;
    sun_r   = 1;
    moon_dis= 1;
    moon_r  = 0.5;
    speed   = 0.01f;
    angle   = 0;
    pause   = false;
}

void Eclipse::drawSun()
{
    glDisable(GL_LIGHTING);
    glColor3f(1.0,0.0,0.0);

    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
         //glBindTexture(GL_TEXTURE_2D, texture_id[9]);
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

         //GLfloat m_materialEmi[4]={0.2f,0.2f,0.2f,0.8f};
         //glMaterialfv(GL_FRONT,GL_EMISSION,m_materialEmi);


         glTranslatef(sun_dis, 0, 0);
         glBegin(GL_QUADS);
             GLUquadric* quadricObj=gluNewQuadric();
             gluQuadricTexture(quadricObj,GL_TRUE);
             gluSphere(quadricObj,sun_r,50,50);
             gluDeleteQuadric(quadricObj);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_LIGHTING);
}

void Eclipse::drawMoon()
{
    glColor3f(1.0,1.0,1.0);
    glDisable(GL_LIGHTING);
    //qDebug()<<"begin to draw the moon";
    //qDebug()<<earth_x<<" "<<earth_y<<" "<<earth_z<<" ";
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
        // translate to the position
        glTranslatef(moon_dis * cos(angle)
                     ,0
                     ,moon_dis * sin(angle));
        //qDebug()<<"sun :"<<sun_dis<<" 0 0";
        //qDebug()<<"moon:"<<moon_dis * cos(angle)<<" 0 "<<moon_dis * sin(angle);
        //qDebug()<<distance<<"  "<<solar_angle;

        // rotate
        //glRotatef(axis_angle, 0, 0, 1);
        // to deal with the texture
        //glRotatef(180.0, 1.0, 0.0, 0.0);

        //glBindTexture(GL_TEXTURE_2D, texture_id[8]);
        glBegin(GL_QUADS);
                GLUquadric* quadricObj=gluNewQuadric();
                gluQuadricTexture(quadricObj,GL_TRUE);
                gluSphere(quadricObj,moon_r,320,320);
                gluDeleteQuadric(quadricObj);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}

/**
  * step up
  */
void Eclipse::step()
{
    if(!pause)
    {
        angle += speed;
    }
}
