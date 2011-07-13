// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__9D589493_3BF7_4CBD_AD4C_3161B9F516E4__INCLUDED_)
#define AFX_LINE_H__9D589493_3BF7_4CBD_AD4C_3161B9F516E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"
#include <gl/gl.h>

class CLine : public CBase  
{
public:
	CLine();
	virtual ~CLine();

	void Draw();
	void DrawCurrentOperation();
	void OnLButtonDown(float x, float y);
	void OnMouseMove(float x, float y);
	bool OnLButtonUp(float x, float y);
	bool GetTheFeildCrect();
	bool Pick(float x,float y);
	void OnKeyMove(UINT nChar);




	bool     Read(CString str);
    CString  Save();
    CString GetClassName(){return "CLine";};






	float m_x0;
	float m_y0;
	float m_x1;
	float m_y1;
	float m_lastx;
	float m_lasty;

private:
	int m_first;

//	void CompOutCode(float x,float y,CRectangle *rect,OutCode *outCode);
};

#endif // !defined(AFX_LINE_H__9D589493_3BF7_4CBD_AD4C_3161B9F516E4__INCLUDED_)
