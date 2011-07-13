// MyTriangle.cpp: implementation of the CMyTriangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "MyTriangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyTriangle::CMyTriangle()
{
		m_first = 0;

}

CMyTriangle::~CMyTriangle()
{

}

void CMyTriangle::Draw()
{
	glLogicOp(GL_COPY);
	glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_LINES);
	  glVertex2f(m_x0,m_y0);
	  glVertex2f(m_x1,m_y1);

	  glVertex2f(m_x1,m_y1);
      glVertex2f(m_x2,m_y2);

	  glVertex2f(m_x2,m_y2);
	  glVertex2f(m_x0,m_y0);
	  
	glEnd();

}
void CMyTriangle::DrawCurrentOperation()
{

	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
//    glColor3f(this->color.r,this->color.g,this->color.b);

	glColor3f(0,1,0);
	glLineWidth(this->Width);
	if (m_first == 1)
	{
		glBegin(GL_LINES);
			glVertex2f(m_x0,m_y0);
	        glVertex2f(m_x1,m_y1);

	        glVertex2f(m_x1,m_y1);
            glVertex2f(m_x2,m_y2);

	        glVertex2f(m_x2,m_y2);
	        glVertex2f(m_x0,m_y0);
		glEnd();

		m_lastx = m_x1, m_lasty = m_y1;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_LINES);
		  glVertex2i(m_x0,m_y0);
		  glVertex2i(m_lastx,m_lasty);

		  glVertex2i(m_lastx,m_lasty);
		  glVertex2i(m_x0-(m_lastx-m_x0),m_lasty);

		  glVertex2i(m_x0-(m_lastx-m_x0),m_lasty);
		  glVertex2i(m_x0,m_y0);
		glEnd();

		glBegin(GL_LINES);
		    glVertex2f(m_x0,m_y0);
	        glVertex2f(m_x1,m_y1);

	        glVertex2f(m_x1,m_y1);
            glVertex2f(m_x2,m_y2);

	        glVertex2f(m_x2,m_y2);
	        glVertex2f(m_x0,m_y0);
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 

}
void CMyTriangle::OnLButtonDown(float x, float y)
{

}
bool CMyTriangle::OnLButtonUp(float x, float y)
{

	if (!m_first)
	{
		m_x0 = x;
		m_y0 = y;
		m_x1 =m_x2=x;
		m_y1 =m_y2=y;
		m_first =1;

		return false;
	}

	m_x1 = x;
	m_y1 = y;
	m_x2=m_x0-(m_x1-m_x0);
	m_y2=m_y1;

	return true;

}
void CMyTriangle::OnMouseMove(float x, float y)
{

	if (m_first==2) 
	{
		m_x1 = x;
		m_y1 = y;
		m_x2=m_x0-(m_x1-m_x0);
		m_y2=m_y1;

	}

}

bool CMyTriangle::Pick(float x,float y)
{

	if ((x>Field.TopLeft().x&&x<Field.BottomRight().x)&&(y>Field.TopLeft().y&&y<Field.BottomRight().y))
		return true;

	return false;

}
bool CMyTriangle::GetTheFeildCrect()
{
	if (m_x1>m_x0)
	   Field.SetRect(m_x2,min(m_y0,m_y2),m_x2+2*(m_x1-m_x0),max(m_y0,m_y2));
	 
	else
		Field.SetRect(m_x1,min(m_y0,m_y1),m_x1+2*(m_x0-m_x1),max(m_y0,m_y1));
      
	return true;
	

}

void CMyTriangle::OnKeyMove(UINT nChar)
{


		switch(nChar)
		{
		case 'W':
			m_x0=m_x0;
			m_y0=m_y0-1;

			m_x1=m_x1;
			m_y1=m_y1-1;

			m_x2=m_x2;
			m_y2=m_y2-1;
			break;
		case 'S':
			m_x0=m_x0;
			m_y0=m_y0+1;

			m_x1=m_x1;
			m_y1=m_y1+1;

			m_x2=m_x2;
			m_y2=m_y2+1;
			break;
		case 'A':
			m_x0=m_x0-1;
			m_y0=m_y0;

			m_x1=m_x1-1;
			m_y1=m_y1;

			m_x2=m_x2-1;
			m_y2=m_y2;
		    break;
		case 'D':
			m_x0=m_x0+1;
			m_y0=m_y0;

			m_x1=m_x1+1;
			m_y1=m_y1;

			m_x2=m_x2+1;
			m_y2=m_y2;
		    break;
		default:
		    break;
		}

     

}


bool  CMyTriangle::Read(CString str)
{
	int pos=0;
	float para[10];
	int i=0;
	while (i<10)
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
	this->m_x0=para[4];
	this->m_y0=para[5];
	this->m_x1=para[6];
	this->m_y1=para[7];
	this->m_x2=para[8];
	this->m_y2=para[9];
	


	return true;

}


CString  CMyTriangle::Save()

{

    CString test="";
	CString str;
	str.Format(" %f %f %f %f %f %f %f %f %f %f ",this->color.r,this->color.g,this->color.b,this->Width,this->m_x0,this->m_y0,this->m_x1,this->m_y1,this->m_x2,this->m_y2);
	test=test+str;
	return test;



}


