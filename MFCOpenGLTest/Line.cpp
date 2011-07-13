// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "Line.h"
#include <math.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{
	m_first = 0;
	this->Width=1;
	this->color.r=0;
	this->color.g=0;
	this->color.b=0;
	this->Field.SetRectEmpty();
}

CLine::~CLine()
{

}
void CLine::DrawCurrentOperation()
{
	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
 //   glColor3f(this->color.r,this->color.g,this->color.b);

	glColor3f(0,1,0);
	glLineWidth(this->Width);
	if (m_first == 1)
	{
		glBegin(GL_LINES);
			glVertex2i(m_x0, m_y0);
			glVertex2i(m_x1, m_y1);
		glEnd();

		m_lastx = m_x1;
		m_lasty = m_y1;
		m_first = 2;
	}
	else if (m_first == 2)
	{
		glBegin(GL_LINES);
		  glVertex2i(m_x0,m_y0);
		  glVertex2i(m_lastx,m_lasty);
		glEnd();

		glBegin(GL_LINES);
		  glVertex2i(m_x0,m_y0);
		  glVertex2i(m_x1,m_y1);
		glEnd();
	}

	glDisable(GL_COLOR_LOGIC_OP); 
}

void CLine::Draw()
{
	glLogicOp(GL_COPY);
	glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
	glBegin(GL_LINES);
	  glVertex2i(m_x0,m_y0);
	  glVertex2i(m_x1,m_y1);
	glEnd();
}
bool CLine::Pick(float x,float y)
{
	if ((x>Field.TopLeft().x&&x<Field.BottomRight().x)&&(y>Field.TopLeft().y&&y<Field.BottomRight().y))
		return true;

	return false;
	      

}
bool CLine::GetTheFeildCrect()
{

	if (abs(m_x0-m_x1)<5)
	{

		Field.SetRect(min(m_x0,m_x1),min(m_y0,m_y1),min(m_x0,m_x1)+5,min(m_y0,m_y1)+abs(m_y0-m_y1));
		return true;

	}

	if (abs(m_y0-m_y1)<5)
	{

		Field.SetRect(min(m_x0,m_x1),min(m_y0,m_y1),min(m_x0,m_x1)+abs(m_x0-m_x1),min(m_y0,m_y1)+5);
		return true;

	}
    

	Field.SetRect(min(m_x0,m_x1),min(m_y0,m_y1),max(m_x0,m_x1),max(m_y0,m_y1));

  return true;

}
void CLine::OnLButtonDown(float x, float y)
{

}

bool CLine::OnLButtonUp(float x, float y)
{
	if (!m_first)
	{
		m_x0 = x;
		m_y0 = y;
		m_x1 = x;
		m_y1 = y;
		m_first =1;

		return false;
	}

	m_x1 = x;
	m_y1 = y;

	return true;
}

void CLine::OnMouseMove(float x, float y)
{
	if (m_first==2) 
	{
		m_x1 = x;
		m_y1 = y;
	}
}

void CLine::OnKeyMove(UINT nChar)
{


	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
   // glColor3f(this->color.r,this->color.g,this->color.b);

	glColor3f(this->color.r,this->color.g,this->color.b);
	glLineWidth(this->Width);
		glBegin(GL_LINES);
		  glVertex2i(m_x0,m_y0);
		  glVertex2i(m_x1,m_y1);
	    glEnd();
	

	glDisable(GL_COLOR_LOGIC_OP); 
	
		switch(nChar)
		{
		case 'W':
			m_x0=m_x0;
			m_y0=m_y0-1;

			m_x1=m_x1;
			m_y1=m_y1-1;
			break;
		case 'S':
			m_x0=m_x0;
			m_y0=m_y0+1;

			m_x1=m_x1;
			m_y1=m_y1+1;
			break;
		case 'A':
			m_x0=m_x0-1;
			m_y0=m_y0;

			m_x1=m_x1-1;
			m_y1=m_y1;
		    break;
		case 'D':
			m_x0=m_x0+1;
			m_y0=m_y0;

			m_x1=m_x1+1;
			m_y1=m_y1;
		    break;
		default:
		    break;
		}



}



/*bool CLine::CohenSutherLandLineClip(CRectangle *rect,float *xx0, float *yy0,float *xx1,float *yy1)
//P0(x0,y0)P1(x1,y1)为带裁剪线段
//rect为裁剪窗口
{ 
	float x0 = m_x0;
	float y0 = m_y0;
	float x1 = m_x1;
	float y1 = m_y1;

	//用于计算端点的编码
	boolean accept,done;
	OutCode outCode0,outCode1;
	OutCode *outCodeOut;
	float x,y;

	accept=FALSE;
	done=FALSE;
	CompOutCode(x0,y0,rect,&outCode0);
	CompOutCode(x1,y1,rect,&outCode1);
	do
	{
		if(outCode0.all==0&&outCode1.all==0)  //完全可见
		{ 
			accept=TRUE;
			done=TRUE;
		}
		else if(outCode0.all & outCode1.all!=0) //显然不可见
			done=TRUE;
		else //进行求交测试
		{ 
			if (outCode0.all!=0)  //判断哪一点位于窗口之外
				outCodeOut=&outCode0;
			else 
				outCodeOut=&outCode1;

			if (outCodeOut->left)   //线段与窗口的左边求交
			{ 
				y=y0+(y1-y0)*(rect->xmin-x0)/(x1-x0);
				x=(float)rect->xmin;
			}
			else if(outCodeOut->top)   //线段与窗口的上边求交
			{
				x=x0+(x1-x0)*(rect->ymax-y0)/(y1-y0);
				y=(float)rect->ymax;
			}
			else if(outCodeOut->right)   //线段与窗口的右边求交
			{
				y=y0+(y1-y0)*(rect->xmax-x0)/(x1-x0);
				x=(float)rect->xmax;
			}
			else if (outCodeOut->bottom)  //线段与窗口的下边求交
			{
				x=x0+(x1-x0)*(rect->ymin-x0)/(y1-y0);
				y=(float)rect->ymin;
			}

			if (outCodeOut->all==outCode0.all)   //以交点为界,将线段位于窗口边所在
			{ 
				x0=x;                              //的直线的外侧的部分丢弃.对剩余的部分继续裁剪
				y0=y;
				CompOutCode(x0,y0,rect,&outCode0);
			}
			else
			{
				x1=x;
				y1=y;
				CompOutCode(x1,y1,rect,&outCode1);
			}
			   
		}
			
	}while(!done);
		
	if(accept) //显示线段的可见部分
	{
		*xx0 = x0, *yy0 = y0, *xx1 = x1, *yy1 = y1;
	}

	return accept;

}*/
//end of CohenSutherLandLineClip()

/*void CLine::CompOutCode(float x,float y,CRectangle *rect,OutCode *outCode)
//计算点(x,y)的编码
{ 
	outCode->all=0;
	outCode->top=outCode->bottom=0;
	if(y>(float)rect->ymax)
	{  
		outCode->top=1;
		outCode->all+=1;
	}
	else if(y<(float)rect->ymin)
	{ 
		outCode->bottom=1;
		outCode->all+=1;
	}
	outCode->right=outCode->left=0;
	if(x>(float)rect->xmax)
	{
		outCode->right=1;
		outCode->all+1;
	}
	else if(x<(float)rect->xmin)
	{ 
		outCode->left=1;
		outCode->all+=1;
	}
}//end of CompOutCode()*/


bool  CLine:: Read(CString str)
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
	this->m_x0=para[4];
	this->m_y0=para[5];
	this->m_x1=para[6];
	this->m_y1=para[7];
	


	return true;

}


CString  CLine::Save()

{

    CString test="";;
	CString str;
	str.Format(" %f %f %f %f %f %f %f %f ",this->color.r,this->color.g,this->color.b,this->Width,this->m_x0,this->m_y0,this->m_x1,this->m_y1);
	test=test+str;
	return test;



}