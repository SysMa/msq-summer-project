// MyFillRect.h: interface for the CMyFillRect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILLRECT_H__07416157_E122_4A4E_B553_5C1C22B09668__INCLUDED_)
#define AFX_MYFILLRECT_H__07416157_E122_4A4E_B553_5C1C22B09668__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyRect.h"

class CMyFillRect : public CMyRect  
{
public:
	CMyFillRect();
	virtual ~CMyFillRect();

	void Draw();
	void DrawCurrentOperation();

	CString GetClassName(){return "CMyFillRect";};

};

#endif // !defined(AFX_MYFILLRECT_H__07416157_E122_4A4E_B553_5C1C22B09668__INCLUDED_)
