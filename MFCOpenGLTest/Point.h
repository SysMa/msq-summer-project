// Point.h: interface for the CPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT_H__92E53094_CDB7_4627_85BA_B1F61CB7DBAC__INCLUDED_)
#define AFX_POINT_H__92E53094_CDB7_4627_85BA_B1F61CB7DBAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"

class CMyPoint : public CBase  
{
public:
	CMyPoint();
	virtual ~CMyPoint();

	float m_x;
	float m_y;



	void Draw();
    void OnLButtonDown(float x, float y);
	bool OnLButtonUp(float x, float y);
	void OnMouseMove(float x, float );
	void Clip(CBase*elem,CBase*list[],int& count);

	bool Pick(float x,float y);
	bool GetTheFeildCrect();
	void OnKeyMove(UINT nChar);

	bool     Read(CString str);
    CString  Save();


	CString GetClassName(){return "CMyPoint";};

	
	

	void Translate(float x, float y);

	void GetPos(float& x, float& y);

};

#endif // !defined(AFX_POINT_H__92E53094_CDB7_4627_85BA_B1F61CB7DBAC__INCLUDED_)
