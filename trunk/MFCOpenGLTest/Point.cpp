// Point.cpp: implementation of the CPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "Point.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyPoint::CMyPoint()
{
	m_y=m_x=0;
	this->Width=2;
	this->color.r=0;
	this->color.g=0;
	this->color.b=0;


}

CMyPoint::~CMyPoint()
{

}
void CMyPoint::Draw()
{
   glPointSize(Width*3);
	glColor3f(color.r,color.g,color.b);
	glBegin(GL_POINTS);
		glVertex2f(m_x,m_y);
	glEnd();


}
void CMyPoint::OnLButtonDown(float x, float y)
{


}
bool CMyPoint::OnLButtonUp(float x, float y)
{
	m_x = x;
	m_y = y;

	return true;


}
void CMyPoint::OnMouseMove(float x, float )
{
	
}
void CMyPoint::Clip(CBase*elem,CBase*list[],int& count)
{
	
}

bool CMyPoint::Pick(float x,float y)
{
   if ((x>Field.TopLeft().x&&x<Field.BottomRight().x)&&(y>Field.TopLeft().y&&y<Field.BottomRight().y))
		return true;

	return false;
	
}
bool CMyPoint::GetTheFeildCrect()
{
   Field.SetRect(m_x-5,m_y-5,m_x+5,m_y+5);
   return true;


}
void CMyPoint::Translate(float x, float y)
{

	m_x += x;
    m_y += y;

}

void CMyPoint::GetPos(float& x, float& y)
{
	x = m_x; 
	y = m_y;

}
void CMyPoint::OnKeyMove(UINT nChar)
{

	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
    glColor3f(this->color.r,this->color.g,this->color.b);

//	glColor3f(0,1,0);
	glLineWidth(this->Width*3);
		glBegin(GL_POINTS);
			glVertex2f(m_x,m_y);
		glEnd();	
	glDisable(GL_COLOR_LOGIC_OP); 
	switch(nChar)
	{
	case 'W':
		m_y=m_y-1;
		break;
	case 'S':
		m_y=m_y+1;
		break;
	case 'A':
		m_x=m_x-1;
	    break;
	case 'D':
		m_x=m_x+1;
	    break;
	default:
	    break;
	}
    

}

bool  CMyPoint:: Read(CString str)
{
	int pos=0;
	float para[6];
	int i=0;
	while (i<6)
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
	


	return true;

}


CString  CMyPoint::Save()

{

	CString test="";
	CString str;
	str.Format(" %f %f %f %f %f %f ",this->color.r,this->color.g,this->color.b,this->Width,this->m_x,this->m_y);
	test=test+str;
	return test;



}
