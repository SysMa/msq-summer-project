// MyFillRect.cpp: implementation of the CMyFillRect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "MyFillRect.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyFillRect::CMyFillRect()
{

}

CMyFillRect::~CMyFillRect()
{

}

void  CMyFillRect:: Draw()
{

	glLogicOp(GL_COPY);
    glColor3f(color.r,color.g,color.b);
	glLineWidth(this->Width);
	glBegin(GL_POLYGON);
		glVertex2f(xmin, ymin);
		glVertex2f(xmax, ymin);
		glVertex2f(xmax, ymax);
		glVertex2f(xmin, ymax);
		
	glEnd();

}
void   CMyFillRect::DrawCurrentOperation()

{


	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
	glColor3f(0,1,0);
//	glColor3f(color.r,color.g,color.b);
	glLineWidth(this->Width);
	if (m_first == 1)
	{
		glBegin(GL_POLYGON);
            glVertex2f(xmin, ymin);
		    glVertex2f(xmax, ymin);
		    glVertex2f(xmax, ymax);
	    	glVertex2f(xmin, ymax);
		glEnd();

		m_lastx = xmax, m_lasty = ymax;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_POLYGON);
			glVertex2f(xmin, ymin);
			glVertex2f(m_lastx, ymin);
			glVertex2f(m_lastx, m_lasty);
			glVertex2f(xmin, m_lasty);
		glEnd();

		glBegin(GL_POLYGON);
            glVertex2f(xmin, ymin);
		    glVertex2f(xmax, ymin);
		    glVertex2f(xmax, ymax);
	    	glVertex2f(xmin, ymax);
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 

}
