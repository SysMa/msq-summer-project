/*********************************************************************
        Author : Ma Shiqing
        DT     : 2011-06 ~ 2011-07
        Intro  : This is my summer project.
**********************************************************************/
/*
#include "data.h"
#include "call.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void myinit(void);

int load( char *file_name )
{
        GLubyte *Image;
        FILE *file;

        int width=640,  height=320;
        if (( file = fopen(file_name, "rb"))==NULL )
        {
           return 1;
        }
        Image = (GLubyte *)malloc(width * height * 3 * (sizeof(GLubyte)));

        fread  ( Image , width * height * 3, 1 , file );
        fclose ( file);

        glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,  GL_NEAREST );
        glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,  GL_NEAREST);
        glTexEnvf ( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

        gluBuild2DMipmaps ( GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, Image );
        free ( Image );

        return 0;
}

void LoadTextures(GLuint *texture_id)
{
        glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
        glGenTextures(8, texture_id);

        for(int i=0;i<8;i++)
        {
                glBindTexture(GL_TEXTURE_2D, texture_id[i]);
                load( planetN[i] );
        }

}

//init the green and so on.
void myinit(void)
{
        GLfloat light_ambient[]={0.3,0.5,0.3};
        GLfloat light_diffuse[]={1.0,1.0,1.0};
        GLfloat light_specular[]={0.8,0.8,0.0};
        GLfloat light_position[]={0.0,0.0,0.0};

        glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
        glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
        glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
        glLightfv(GL_LIGHT0,GL_POSITION, light_position);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        glClearColor(0, 0, 0, 0);
        glShadeModel(GL_SMOOTH);

        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_CULL_FACE);
        LoadTextures(texture_id);

        for(int i = 0;i<8;i++){
                year[i]=(rand()%360);
                day[i]=0;
        }

}

//reshape : when the  screen was resized.
void reshape(GLsizei w,GLsizei h)
{
        glViewport(0,0,(GLsizei)w,(GLsizei)h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,20);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(r1[7],3,r1[7],0,0,0,0,1,0);
}

//display the screen
void display(void)
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glDisable(GL_LIGHTING);
        glColor3f (1, 1, 1);
        for(int j=0;j<8;j++)
        {
                glBegin(GL_LINE_LOOP);
                for (int i = 0; i < 360; i++)
                {
                        glVertex3f(cos(i*3.14/180)*r1[j] , 0, sin(i*3.14/180)*r1[j]);
                }
                glEnd();
        }
        glEnable(GL_LIGHTING);

        //需要改动的代码，可以改成是和下面的一样的方法进行贴图处理。
        //希望这里的太阳球体也是可以作为一个可大可小的存在。。。
        glPushMatrix();
        //glutSolidSphere(1.8,20,16);
        glPopMatrix();

        glEnable(GL_TEXTURE_2D);
        for(int i=0;i<8;i++)
        {
                glPushMatrix();
                glRotatef(year[i],0,1,0);
                glTranslatef( r1[i]  ,0,0);
                glRotatef(day[i],0,1,0);
                glBindTexture(GL_TEXTURE_2D, texture_id[i]);
                {
                        GLUquadricObj*  p = gluNewQuadric();
                        gluQuadricTexture (p, GL_TRUE);
                        gluSphere(p, r2[i], 16, 16);
                        gluDeleteQuadric(p);
                }
                glPopMatrix();
        }
        glDisable(GL_TEXTURE_2D);

        glFlush();
        //glutSwapBuffers();
}

void stepDisplay(void)
{
        for(int i=0;i<8;i++)
        {
                year[i]=year[i]+(1 / year0[i]);
                if( year[i]>360 ) year[i]=year[i] - 360;

                day[i]=day[i] + ( 1 / day0[i] );
                if( day[i] >360 ) day[i]= day[i] -360 ;
        }
        display();
}


//This is just a test for the keyboard press.
void keyboard(unsigned char key, int x, int y) {
        int i;
        switch (key){
        case 'f':
                printf("you just pressed f\n");
                for( i = 0; i < 8;i++) {
                        year0[i] = year0[i] /2;
                        day0[i] = day0[i] / 2;
                }
                break;
        case 's':
                printf("you just pressed s\n");
                for(i = 0; i < 8;i++) {
                        year0[i] = year0[i] * 2;
                        day0[i] = day0[i] * 2;
                }
                break;
        case '+':
                printf("you just pressed the plus button.\n");
                for(i = 0; i < 8;i++) {
                        r1[i] = r1[i] * 2;
                        r2[i] = r2[i] * 2;
                        sun = sun * 2;
                }
                //display();
                break;
        case '-':
                printf("you just pressed the minius button.\n");
                for(i = 0; i < 8;i++) {
                        r1[i] = r1[i] / 2;
                        r2[i] = r2[i] / 2;
                        sun = sun * 2;
                }
                //display();
                break;
        default:
                break;
        }
}
*/

/**
 * this is the old windows-project-funciton
 * should be deleted but i need to change funciton to the qt class
 */
//int main(int argc,char** argv)
//{
//      glutInit(&argc,argv);
//      glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
//      glutInitWindowPosition(100,100);
//      glutInitWindowSize(500,500);
//      glutCreateWindow(argv[0]);
//      myinit();
//
//      glutDisplayFunc(display);
//      glutIdleFunc(stepDisplay);
//      glutReshapeFunc(reshape);
//      glutKeyboardFunc(keyboard);
//      glutMainLoop();
//
//      return 0;
//}
