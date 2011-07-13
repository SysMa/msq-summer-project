// MyPolygon.h: interface for the CMyPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPOLYGON_H__BDE504DE_F57B_41B1_A2DC_8EC26249A976__INCLUDED_)
#define AFX_MYPOLYGON_H__BDE504DE_F57B_41B1_A2DC_8EC26249A976__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"
#include "Point.h"

class CMyPolygon : public CBase  
{
public:
	CMyPolygon();
	virtual ~CMyPolygon();

	void Draw();
	void DrawCurrentOperation() ;
	void OnRButtonUp(float x, float y) ;
	bool OnLButtonUp(float x, float y) ;
	void OnMouseMove(float x, float ) ;

    bool Pick(float x,float y);
    bool GetTheFeildCrect();
    void OnKeyMove(UINT nChar);

	bool     Read(CString str);
    CString  Save();


	CString GetClassName(){return "CMyPolygon";};

	CMyPoint  m_points[100];
	int       m_count;
	bool      Flag;

	float rectMinX;
	float rectMaxX;
	float rectMinY;
	float rectMaxY;

private:
	int m_first;
	float m_x1;
	float m_y1;
	float m_lastx;
	float m_lasty;

};

#endif // !defined(AFX_MYPOLYGON_H__BDE504DE_F57B_41B1_A2DC_8EC26249A976__INCLUDED_)
