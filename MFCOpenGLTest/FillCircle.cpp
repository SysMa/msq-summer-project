// FillCircle.cpp: implementation of the CFillCircle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "FillCircle.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFillCircle::CFillCircle()
{

}

CFillCircle::~CFillCircle()
{

}

void CFillCircle::Draw()
{
	glLogicOp(GL_COPY);
	glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_POLYGON);
	    for (int i=0;i<360;i=i+5)
			glVertex2f(m_x+r*cos(float(i)*pia/180),m_y+r*sin(float(i)*pia/180));
    glEnd();

    
	   
}
void CFillCircle::DrawCurrentOperation()
{

	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
 //   glColor3f(this->color.r,this->color.g,this->color.b);

	glColor3f(0,1,0);
	glLineWidth(this->Width);
	if (m_first == 1)
	{
		glBegin(GL_POLYGON);
			for (int i=0;i<360;i=i+5)
			  glVertex2f(m_x+r*cos(float(i)*pia/180),m_y+r*sin(float(i)*pia/180));
		glEnd();

		m_lastr=r;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_POLYGON);
		  for (int i=0;i<360;i=i+5)
			glVertex2f(m_x+m_lastr*cos(float(i)*pia/180),m_y+m_lastr*sin(float(i)*pia/180));
		glEnd();


		glBegin(GL_POLYGON);
		  for (int i=0;i<360;i=i+5)
			glVertex2f(m_x+r*cos(float(i)*pia/180),m_y+r*sin(float(i)*pia/180));
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 

}

