// FillCircle.h: interface for the CFillCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILLCIRCLE_H__1DDEEDAC_72E2_4E57_A6B0_6AF75732EE87__INCLUDED_)
#define AFX_FILLCIRCLE_H__1DDEEDAC_72E2_4E57_A6B0_6AF75732EE87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Circle.h"

class CFillCircle : public CCircle  
{
public:
	CFillCircle();
	virtual ~CFillCircle();
	void Draw();
	void DrawCurrentOperation();
	CString GetClassName(){return "CFillCircle";};

};

#endif // !defined(AFX_FILLCIRCLE_H__1DDEEDAC_72E2_4E57_A6B0_6AF75732EE87__INCLUDED_)
