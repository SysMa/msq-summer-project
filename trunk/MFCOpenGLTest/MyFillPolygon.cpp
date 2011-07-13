// MyFillPolygon.cpp: implementation of the CMyFillPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "MyFillPolygon.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyFillPolygon::CMyFillPolygon()
{

}

CMyFillPolygon::~CMyFillPolygon()
{

}
void CMyFillPolygon::Draw()
{

	glLogicOp(GL_COPY);
    glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_POLYGON);
	 for(int i=0; i<m_count; i++)
		  glVertex2f(m_points[i].m_x,m_points[i].m_y);
	glEnd();

}

