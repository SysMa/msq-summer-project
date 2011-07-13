// MyTriangle.h: interface for the CMyTriangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTRIANGLE_H__18B742B8_09CC_48FE_A143_ACD6D6D849F9__INCLUDED_)
#define AFX_MYTRIANGLE_H__18B742B8_09CC_48FE_A143_ACD6D6D849F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"

class CMyTriangle : public CBase  
{
public:
	CMyTriangle();
	virtual ~CMyTriangle();


	void Draw();
	void DrawCurrentOperation();
	void OnLButtonDown(float x, float y);
    bool OnLButtonUp(float x, float y);
    void OnMouseMove(float x, float );
	void OnKeyMove(UINT nChar);


	bool Pick(float x,float y);
	bool GetTheFeildCrect();


	bool     Read(CString str);
    CString  Save();
    CString GetClassName(){return "CMyTriangle";};





	float m_x0;
	float m_y0;
	float m_x1;
	float m_y1;
	float m_x2;
	float m_y2;
	float m_lastx;
	float m_lasty;


	int m_first;

};

#endif // !defined(AFX_MYTRIANGLE_H__18B742B8_09CC_48FE_A143_ACD6D6D849F9__INCLUDED_)
