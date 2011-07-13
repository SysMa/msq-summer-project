// Circle.h: interface for the CCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLE_H__02327413_B609_44E3_AAC9_D11255D3397E__INCLUDED_)
#define AFX_CIRCLE_H__02327413_B609_44E3_AAC9_D11255D3397E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"
#define  pia    3.14159

class CCircle : public CBase  
{
public:
	CCircle();
	virtual ~CCircle();

	
	float m_x;
	float m_y;

	float r;

	float m_lastr;


	int m_first;



	 void Draw();
     void DrawCurrentOperation();
	 void OnKeyMove(UINT nChar);

	

	 
     bool OnLButtonUp(float x, float y);
     void OnMouseMove(float x, float y);
	 bool Pick(float x,float y);
     bool GetTheFeildCrect();
     void GetPos(float& x, float& y);

	 bool     Read(CString str);
     CString  Save();
     CString GetClassName(){return "CCircle";};


	 

};

#endif // !defined(AFX_CIRCLE_H__02327413_B609_44E3_AAC9_D11255D3397E__INCLUDED_)
