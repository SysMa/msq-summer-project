// Text.cpp: implementation of the CText class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "Text.h"
#include <stdio.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CText::CText()
{
	length=0;

	screenX=screenY=0;
	

}

CText::~CText()
{

}

void CText::Draw()
{

  this->Print(text);
	

}


	

	 
bool CText::OnLButtonUp(float x, float y)
{
	screenX=x;
	screenY=y;
    
	return true;

}
     
bool CText::Pick(float x,float y)
{

	if ((x>Field.TopLeft().x&&x<Field.BottomRight().x)&&(y>Field.TopLeft().y&&y<Field.BottomRight().y))
		return true;

	return false;
}

bool CText::GetTheFeildCrect()
{

	Field.SetRect(screenX,screenY-size,screenX+size*length/2,screenY);
  return 1;
}


void CText::GetPos(float& x, float& y)
{

}

void CText::Build(char *str, int size)
{
	char *name="Good";
	text=str;

	HFONT hFont;	// font ID
	HDC hDC;		// device context
	
	hDC = wglGetCurrentDC();
	callList = glGenLists(96);
	
	if (stricmp(name, "symbol") == 0)
	{
		hFont = CreateFont(-size, 0,0,0,FW_BOLD, FALSE, FALSE, FALSE, SYMBOL_CHARSET,
			OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY,
			FF_DONTCARE | DEFAULT_PITCH, name);
	}
	else
	{
		hFont = CreateFont(-size, 0,0,0,FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET,
			OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, 
			FF_DONTCARE | DEFAULT_PITCH, name);
	}
	
	SelectObject(hDC, hFont);
	wglUseFontBitmaps(hDC, 32, 96, callList);
}



void CText::ClearFont()
{
	glDeleteLists(callList, 96);

}

	
void CText::Print( char *str)
{
	char text[256];
	va_list args;
	
	if (str == NULL)
		return;
	
	va_start(args, str);
	vsprintf(text, str, args);
	va_end(args);
	
	glPushMatrix();
	glColor3f(this->color.r, this->color.g, this->color.b );
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -1.0f);	// translate one unit into the screen

	glRasterPos2i(screenX, screenY);
	
	
	
	glPushAttrib(GL_LIST_BIT);
	glListBase(callList - 32);
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
	glPopAttrib();
	glPopMatrix();
}

CText::CText(char *name, int size)
{
	screenX = 0;
	screenY = 0;
	this->size=size;

	Build(name, size);
}

void CText::OnKeyMove(UINT nChar)
{

	glEnable(GL_COLOR_LOGIC_OP); 
	glLogicOp(GL_XOR);
   // glColor3f(this->color.r,this->color.g,this->color.b);
	this->Print(text);
	

	glDisable(GL_COLOR_LOGIC_OP); 


	switch(nChar)
	{
	case 'W':
		screenY=screenY-1;
		break;
	case 'S':
		screenY=screenY+1;
		break;
	case 'A':
		screenX=screenX-1;
	    break;
	case 'D':
		screenX=screenX+1;
	    break;
	default:
	    break;
	}



}



bool   CText::  Read(CString str)
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
	this->screenX=para[4];
	this->screenY=para[5];
	this->size=para[6];
	this->length=para[7];
	
	CString * example=new CString(str);


    char *point =example->GetBuffer( example->GetLength() + 1);
	Build(point,size);

	return true;



}

CString  CText::Save()
{

    CString test="";
	CString str;
	str.Format(" %f %f %f %f %f %f %d %f ",this->color.r,this->color.g,this->color.b,this->Width,this->screenX,this->screenY,this->size,this->length);
	test=test+str;
	str.Format("%s",text);
	test=test+str;
	return test;


}


