// AAA.cpp : Defines the entry point for the console application.
//

#include "windows.h"
#include "stdio.h" 
#include"math.h"
#include "gl\gl.h"
#include "GL\glu.h"
#include "gl\glaux.h"

#pragma comment( lib, "glaux.lib" ) 
#pragma comment( lib, "glu32.lib" ) 
#pragma comment( lib, "OpenGL32.lib" ) 

void myinit(void);

void CALLBACK	display(void);
void CALLBACK	reshape(GLsizei w,GLsizei h);
void CALLBACK	stepDisplay(void);

static GLfloat year[8];
static GLfloat year0[8]={0.24,0.613,1,1.88 , 5 , 14 , 22 , 29.5};
static GLfloat day[8];
static GLfloat day0[8]={58.65 , 243 , 1, 1 ,0.375 , 0.426 , 0.65 ,0.67} ;
static GLfloat r1[8]={1.2,1.7,2,2.8,4,5.5,6.5,7.5};
static GLfloat r2[8]={0.076,0.19,0.2,0.106,0.5,0.5,0.3,0.29};
char *planetN[8]={"MERCURY.RAW","VENUS.RAW","EARTH.RAW","MARS.RAW","JUPITER.RAW","SATURN.RAW","URANUS.RAW","NEPTUNE.RAW"};
GLuint texture_id[8];

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

void myinit(void)
{
	auxInitDisplayMode(AUX_DOUBLE|AUX_RGBA);
	auxInitPosition(100,100,800,600);

	auxInitWindow((LPCWSTR)"Solar System");

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

void CALLBACK reshape(GLsizei w,GLsizei h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);   
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();
	gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,20);   
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluLookAt(9,5,5,0,0,0,0,1,0);
}


void CALLBACK display(void)
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
	
	glPushMatrix();
	auxSolidSphere(0.9);
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
	auxSwapBuffers();	
}

void CALLBACK stepDisplay(void)
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

void main(void)
{
		myinit();
		auxReshapeFunc(reshape);
		auxIdleFunc(stepDisplay);			
		auxMainLoop(display);
}
