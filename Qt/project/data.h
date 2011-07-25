/************************************************************
 *
 * I would like to define some orignal data here
 * This file may be not exit if i chose to read data from a file
 */

#ifndef DATA_H
#define DATA_H

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//to do here

//sun
static GLfloat sun = 0.9;

//year is the bgi circle
static GLfloat year[8];
static GLfloat year0[8]={0.24,0.613,1,1.88 , 5 , 14 , 22 , 29.5};

//day is the small circle
static GLfloat day[8];
static GLfloat day0[8]={58.65 , 243 , 1, 1 ,0.375 , 0.426 , 0.65 ,0.67} ;

//r1 is the big circle r
static GLfloat r1[8]={1.2,1.7,2,2.8,4,5.5,6.5,7.5};

//r2 is  the small circle r
static GLfloat r2[8]={0.076,0.19,0.2,0.106,0.5,0.5,0.3,0.29};

//planet are about the texture
char *planetN[8]={"MERCURY.RAW","VENUS.RAW","EARTH.RAW","MARS.RAW","JUPITER.RAW","SATURN.RAW","URANUS.RAW","NEPTUNE.RAW"};
GLuint texture_id[8];

#endif // DATA_H
