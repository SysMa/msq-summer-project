// Circle.cpp: implementation of the CCircle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "Circle.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCircle::CCircle()
{
       m_x=0;
	   m_y=0;

	   r=0;

	  
	   m_first=m_lastr=0;
}

CCircle::~CCircle()
{

}
void CCircle::Draw()
{
	glLogicOp(GL_COPY);
	glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_LINE_LOOP);
	    for (int i=0;i<360;i=i+5)
			glVertex2f(m_x+r*cos(float(i)*pia/180),m_y+r*sin(float(i)*pia/180));
    glEnd();

    
	   
}
void CCircle::DrawCurrentOperation()
{

	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
 //   glColor3f(this->color.r,this->color.g,this->color.b);

	glColor3f(0,1,0);
	glLineWidth(this->Width);
	if (m_first == 1)
	{
		glBegin(GL_LINE_LOOP);
			for (int i=0;i<360;i=i+5)
			  glVertex2f(m_x+r*cos(float(i)*pia/180),m_y+r*sin(float(i)*pia/180));
		glEnd();

		m_lastr=r;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_LINE_LOOP);
		  for (int i=0;i<360;i=i+5)
			glVertex2f(m_x+m_lastr*cos(float(i)*pia/180),m_y+m_lastr*sin(float(i)*pia/180));
		glEnd();


		glBegin(GL_LINE_LOOP);
		  for (int i=0;i<360;i=i+5)
			glVertex2f(m_x+r*cos(float(i)*pia/180),m_y+r*sin(float(i)*pia/180));
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 

}

	

	 
bool CCircle::OnLButtonUp(float x, float y)
{

	if (!m_first)
	{
		m_x = x;
		m_y = y;
		
		m_first =1;

		return false;
	}

   r=sqrt((x-m_x)*(x-m_x)+(y-m_y)*(y-m_y));

	return true;

}
void CCircle::OnMouseMove(float x, float y)
{
	if (m_first==2) 
	{
		r=sqrt((x-m_x)*(x-m_x)+(y-m_y)*(y-m_y));
	}

}
bool CCircle::Pick(float x,float y)
{
   if ((x>Field.TopLeft().x&&x<Field.BottomRight().x)&&(y>Field.TopLeft().y&&y<Field.BottomRight().y))
		return true;

	return false;
}
bool CCircle::GetTheFeildCrect()
{
	Field.SetRect(m_x-r,m_y-r,m_x+r,m_y+r);

	return true;

}
void CCircle::GetPos(float& x, float& y)
{


}

void CCircle::OnKeyMove(UINT nChar)
{

	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
    glColor3f(this->color.r,this->color.g,this->color.b);

//	glColor3f(0,1,0);
	glLineWidth(this->Width);
		glBegin(GL_LINE_LOOP);
			for (int i=0;i<360;i=i+5)
			  glVertex2f(m_x+r*cos(float(i)*pia/180),m_y+r*sin(float(i)*pia/180));
		glEnd();	
	glDisable(GL_COLOR_LOGIC_OP); 


	switch(nChar)
	{
	case 'W':
		m_x=m_x;
		m_y=m_y-1;
		break;
	case 'S':
		m_x=m_x;
		m_y=m_y+1;
		break;
	case 'A':
		m_x=m_x-1;
		m_y=m_y;
	    break;
	case 'D':
		m_x=m_x+1;
		m_y=m_y;
	    break;
	default:
	    break;
	}


}


bool  CCircle:: Read(CString str)
{
	int pos=0;
	float para[7];
	int i=0;
	while (i<7)
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
	this->m_x=para[4];
	this->m_y=para[5];
	this->r=para[6];
	


	return true;

}


CString  CCircle::Save()

{

    CString test="";
	CString str;
	str.Format(" %f %f %f %f %f %f %f ",this->color.r,this->color.g,this->color.b,this->Width,this->m_x,this->m_y,this->r);
	test=test+str;
	return test;



}
