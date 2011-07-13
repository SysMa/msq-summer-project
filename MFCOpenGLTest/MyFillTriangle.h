// MyFillTriangle.h: interface for the CMyFillTriangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILLTRIANGLE_H__674CAC3B_CC7E_4DF0_9ABA_6492D5DFC2E8__INCLUDED_)
#define AFX_MYFILLTRIANGLE_H__674CAC3B_CC7E_4DF0_9ABA_6492D5DFC2E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyTriangle.h"

class CMyFillTriangle : public CMyTriangle  
{
public:
	CMyFillTriangle();
	virtual ~CMyFillTriangle();
	void Draw();
	void DrawCurrentOperation();
	CString GetClassName(){return "CMyFillTriangle";};

};

#endif // !defined(AFX_MYFILLTRIANGLE_H__674CAC3B_CC7E_4DF0_9ABA_6492D5DFC2E8__INCLUDED_)
