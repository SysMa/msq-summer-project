// MyRect.h: interface for the CMyRect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYRECT_H__9AFF8A33_0B24_4EEB_AB3D_4C236B7529A4__INCLUDED_)
#define AFX_MYRECT_H__9AFF8A33_0B24_4EEB_AB3D_4C236B7529A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"

class CMyRect : public CBase  
{
public:
	CMyRect();
	virtual ~CMyRect();

	void Draw() ;
	void DrawCurrentOperation() ;
	bool OnLButtonUp(float x, float y);
	void OnMouseMove(float x, float ) ;
    bool Pick(float x,float y);
    bool GetTheFeildCrect();
    void GetPos(float& x, float& y);
	void OnKeyMove(UINT nChar);
	bool     Read(CString str);
    CString  Save();
    CString GetClassName(){return "CMyRect";};

	float xmin;
	float ymin;
	float xmax;
	float ymax;


	int m_first;
	float m_lastx;
	float m_lasty;

};

#endif // !defined(AFX_MYRECT_H__9AFF8A33_0B24_4EEB_AB3D_4C236B7529A4__INCLUDED_)
