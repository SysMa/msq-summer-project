// MyFillTriangle.cpp: implementation of the CMyFillTriangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "MyFillTriangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyFillTriangle::CMyFillTriangle()
{

}

CMyFillTriangle::~CMyFillTriangle()
{

}

void CMyFillTriangle::Draw()
{

	glLogicOp(GL_COPY);
	glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_POLYGON);
	  glVertex2f(m_x0,m_y0);
	  glVertex2f(m_x1,m_y1);
   	  glVertex2f(m_x2,m_y2);
	glEnd();



}
void CMyFillTriangle::DrawCurrentOperation()
{

		glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
 //   glColor3f(this->color.r,this->color.g,this->color.b);

	glColor3f(0,1,0);
	glLineWidth(this->Width);
	if (m_first == 1)
	{
		glBegin(GL_POLYGON);
			glVertex2f(m_x0,m_y0);
	        glVertex2f(m_x1,m_y1);
	        glVertex2f(m_x2,m_y2);
		glEnd();

		m_lastx = m_x1, m_lasty = m_y1;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_POLYGON);
		  glVertex2i(m_x0,m_y0);
		  glVertex2i(m_lastx,m_lasty);
		  glVertex2i(m_x0-(m_lastx-m_x0),m_lasty);
		glEnd();

		glBegin(GL_POLYGON);
		    glVertex2f(m_x0,m_y0);
	        glVertex2f(m_x1,m_y1);
	        glVertex2f(m_x2,m_y2);
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 



}
