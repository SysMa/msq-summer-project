// MyPolygon.cpp: implementation of the CMyPolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "MyPolygon.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyPolygon::CMyPolygon()
{
	m_count=0;
	m_first=0;
	Flag=false;


	rectMinX=10000;
    rectMaxX=-1;
	rectMinY=10000;
	rectMaxY=-1;

}

CMyPolygon::~CMyPolygon()
{

}
void CMyPolygon::Draw()
{
	glLogicOp(GL_COPY);
    glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_LINE_LOOP);
	 for(int i=0; i<m_count; i++)
		  glVertex2f(m_points[i].m_x,m_points[i].m_y);
	glEnd();

}
void CMyPolygon::DrawCurrentOperation() 
{
	glLogicOp(GL_COPY);
    glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<m_count; i++)
		  glVertex2f(m_points[i].m_x,m_points[i].m_y);
	glEnd();

	glEnable(GL_COLOR_LOGIC_OP); 
	glLineWidth(this->Width);
	glLogicOp(GL_XOR);
	glColor3f(0,1,0);
	if (m_first == 1)
	{
		glBegin(GL_LINES);
			glVertex2f(m_points[m_count-1].m_x, m_points[m_count-1].m_y);
			glVertex2f(m_x1, m_y1);
		glEnd();

		m_lastx = m_x1, m_lasty = m_y1;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_LINES);
		  glVertex2f(m_points[m_count-1].m_x, m_points[m_count-1].m_y);
		  glVertex2f(m_lastx,m_lasty);
		glEnd();

		glBegin(GL_LINES);
		  glVertex2f(m_points[m_count-1].m_x, m_points[m_count-1].m_y);
		  glVertex2f(m_x1,m_y1);
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 

}
void CMyPolygon::OnRButtonUp(float x, float y) 
{
	Flag=true;


}
bool CMyPolygon::OnLButtonUp(float x, float y) 
{
	if (Flag)
		return true;

	if (x<rectMinX)
       rectMinX=x;
	if (x>rectMaxX)
	   rectMaxX=x;
	if (y<rectMinY)
       rectMinY=y;
	if (y>rectMaxY)
	   rectMaxY=y;
       

	m_points[m_count].m_x=x;
	m_points[m_count++].m_y=y;

	m_first = 1;
	m_x1 = x;
	m_y1 = y;

	return false;

}
void CMyPolygon::OnMouseMove(float x, float y) 
{

	if (m_first==2) 
	{
		m_x1 = x, m_y1 = y;
	}
	
}


bool CMyPolygon::Pick(float x,float y)
{
   if ((x>Field.TopLeft().x&&x<Field.BottomRight().x)&&(y>Field.TopLeft().y&&y<Field.BottomRight().y))
		return true;

	return false;
}
    
bool CMyPolygon::GetTheFeildCrect()
{
   Field.SetRect(rectMinX,rectMinY,rectMaxX,rectMaxY);	
   return true;


}
    
void CMyPolygon::OnKeyMove(UINT nChar)
{
     int i=0;
	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
    glColor3f(this->color.r,this->color.g,this->color.b);

	//glColor3f(0,1,0);
	glLineWidth(this->Width);
	  glBegin(GL_LINE_LOOP);
	     for(i=0; i<m_count; i++)
		     glVertex2f(m_points[i].m_x,m_points[i].m_y);
	  glEnd();


	
	switch(nChar)
	{
	
	case 'W':
		for( i=0;i<m_count;i++)
			m_points[i].m_y=m_points[i].m_y-1;
		break;
	case 'S':
	for( i=0;i<m_count;i++)
			m_points[i].m_y=m_points[i].m_y+1;
		break;
	case 'A':
		for(i=0;i<m_count;i++)
			m_points[i].m_x=m_points[i].m_x-1;
	    break;
	case 'D':
		for( i=0;i<m_count;i++)
			m_points[i].m_x=m_points[i].m_x+1;
	    break;
	default:
	    break;
	}



}

bool  CMyPolygon:: Read(CString str)
{
	int pos=0;
	float para[10];
	int i=0;
	pos=str.Find(' ');
	para[i]=atoi(str.Left(pos));
	str=str.Mid(pos+1,str.GetLength());

	i++;
	m_count=para[0];
		

	while (i<5)
	{

		pos=str.Find(' ');
		para[i]=atof(str.Left(pos));
		str=str.Mid(pos+1,str.GetLength());
		i++;
	}
	this->color.r=para[1];
	this->color.g=para[2];
	this->color.b=para[3];
	this->Width=para[4];

	i=0;
	while (i<m_count*2)
	{
       
		pos=str.Find(' ');
		if (i%2==0)
			m_points[i/2].m_x=atof(str.Left(pos));
		else
			m_points[i/2].m_y=atof(str.Left(pos));
		
		
		str=str.Mid(pos+1,str.GetLength());
		i++;
	}

	return true;

}

CString  CMyPolygon::Save()

{

    CString test="";
//	CString str;
//	str.Format(" %f %f %f %f %f %f ",this->color.r,this->color.g,this->color.b,this->Width,this->m_x,this->m_y);
	CString temp;
	temp.Format(" %d",m_count);
	test=test+temp;

	temp.Format(" %f %f %f %f",this->color.r,this->color.g,this->color.b,this->Width);
	test=test+temp;

    for (int i=0;i<m_count;i++)
    {

	   temp.Format(" %f %f",m_points[i].m_x,m_points[i].m_y);
	   test=test+temp;
		
    }
	test=test+" ";

	return test;



}
