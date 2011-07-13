// MyFillPolygon.h: interface for the CMyFillPolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILLPOLYGON_H__AE328F1D_65D0_4DBC_9F41_A0D9E37C7FD2__INCLUDED_)
#define AFX_MYFILLPOLYGON_H__AE328F1D_65D0_4DBC_9F41_A0D9E37C7FD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyPolygon.h"

class CMyFillPolygon : public CMyPolygon  
{
public:
	CMyFillPolygon();
	virtual ~CMyFillPolygon();
	void Draw();
	CString GetClassName(){return "CMyFillPolygon";};

};

#endif // !defined(AFX_MYFILLPOLYGON_H__AE328F1D_65D0_4DBC_9F41_A0D9E37C7FD2__INCLUDED_)
