// MyRect.cpp: implementation of the CMyRect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "MyRect.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyRect::CMyRect()
{

	m_first = 0;

}

CMyRect::~CMyRect()
{

}
void CMyRect::Draw()
{
	glLogicOp(GL_COPY);
    glColor3f(color.r,color.g,color.b);
	glLineWidth(this->Width);
	glBegin(GL_LINES);
		glVertex2f(xmin, ymin);
		glVertex2f(xmin, ymax);
		glVertex2f(xmin, ymin);
		glVertex2f(xmax, ymin);

		glVertex2f(xmin, ymax);
		glVertex2f(xmax, ymax);
		glVertex2f(xmax, ymin);
		glVertex2f(xmax, ymax);
	glEnd();
	
}
void CMyRect::DrawCurrentOperation()
{
	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
	glColor3f(0,1,0);
//	 glColor3f(color.r,color.g,color.b);
	glLineWidth(this->Width);
	if (m_first == 1)
	{
		glBegin(GL_LINES);
			glVertex2f(xmin, ymin);
			glVertex2f(xmin, ymax);
			glVertex2f(xmin, ymin);
			glVertex2f(xmax, ymin);

			glVertex2f(xmin, ymax);
			glVertex2f(xmax, ymax);
			glVertex2f(xmax, ymin);
			glVertex2f(xmax, ymax);
		glEnd();

		m_lastx = xmax, m_lasty = ymax;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_LINES);
			glVertex2f(xmin, ymin);
			glVertex2f(xmin, m_lasty);
			glVertex2f(xmin, ymin);
			glVertex2f(m_lastx, ymin);

			glVertex2f(xmin, m_lasty);
			glVertex2f(m_lastx, m_lasty);
			glVertex2f(m_lastx, ymin);
			glVertex2f(m_lastx, m_lasty);
		glEnd();

		glBegin(GL_LINES);
			glVertex2f(xmin, ymin);
			glVertex2f(xmin, ymax);
			glVertex2f(xmin, ymin);
			glVertex2f(xmax, ymin);

			glVertex2f(xmin, ymax);
			glVertex2f(xmax, ymax);
			glVertex2f(xmax, ymin);
			glVertex2f(xmax, ymax);
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 
}
bool CMyRect::OnLButtonUp(float x,float y)
{
	if (!m_first)
	{
		xmin = x;
		ymin = y;
		xmax = x;
		ymax = y;
		m_first =1;

		return false;
	}

	xmax = x;
	ymax = y;

	float x0 = min(xmin,xmax);
	float x1 = max(xmin,xmax);
	float y0 = min(ymin,ymax);
	float y1 = max(ymin,ymax);

	xmin = x0, ymin = y0, xmax = x1, ymax = y1;

	return true;
}
void CMyRect::OnMouseMove(float x,float y)
{
	if (m_first==2) 
	{
		xmax = x;
		ymax = y;
	}
}
bool CMyRect::Pick(float x,float y)
{
	if ((x>Field.TopLeft().x&&x<Field.BottomRight().x)&&(y>Field.TopLeft().y&&y<Field.BottomRight().y))
		return true;

	return false;


}
bool CMyRect::GetTheFeildCrect()
{
	Field.SetRect(min(xmax,xmin),min(ymax,ymin),max(xmax,xmin),max(ymax,ymin));

  return true;


}
    
void CMyRect::GetPos(float& x, float& y)
{

}

void CMyRect::OnKeyMove(UINT nChar)
{

	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
//	glColor3f(0,1,0);
	glColor3f(color.r,color.g,color.b);
	glLineWidth(this->Width);
		glBegin(GL_LINES);
			glVertex2f(xmin, ymin);
			glVertex2f(xmin, ymax);
			glVertex2f(xmin, ymin);
			glVertex2f(xmax, ymin);

			glVertex2f(xmin, ymax);
			glVertex2f(xmax, ymax);
			glVertex2f(xmax, ymin);
			glVertex2f(xmax, ymax);
		glEnd();
	glDisable(GL_COLOR_LOGIC_OP); 	

	switch(nChar)
		{
		case 'W':
			
			ymin=ymin-1;
			ymax=ymax-1;
			break;
		case 'S':
			ymin=ymin+1;
			ymax=ymax+1;
			break;
		case 'A':
			xmin=xmin-1;
			xmax=xmax-1;

		    break;
		case 'D':
			xmin=xmin+1;
			xmax=xmax+1;
		    break;
		default:
		    break;
		}




}


bool  CMyRect:: Read(CString str)
{
	int pos=0;
	float para[8];
	int i=0;
	while (i<8)
	{
		pos=str.Find(' ');
		para[i]=atof(str.Left(pos));
		str=str.Mid(pos+1,str.GetLength());
		i++;
			

	}

	this->color.r=para[0];
	this->color.g=para[1];
	this->color.b=para[2];
	this->Width=para[3];
	this->xmin=para[4];
	this->ymin=para[5];
	this->xmax=para[6];
	this->ymax=para[7];
	


	return true;

}


CString  CMyRect::Save()

{

    CString test="";
	CString str;
	str.Format(" %f %f %f %f %f %f %f %f ",this->color.r,this->color.g,this->color.b,this->Width,this->xmin,this->ymin,this->xmax,this->ymax);
	test=test+str;
	return test;



}