// MFCOpenGLTest.h : main header file for the MFCOPENGLTEST application
//

#if !defined(AFX_MFCOPENGLTEST_H__9E5493F7_A268_4DC9_ACF8_F4376911EF89__INCLUDED_)
#define AFX_MFCOPENGLTEST_H__9E5493F7_A268_4DC9_ACF8_F4376911EF89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Base.h"

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestApp:
// See MFCOpenGLTest.cpp for the implementation of this class
//

class CMFCOpenGLTestApp : public CWinApp
{
public:
	CMFCOpenGLTestApp();
	UINT m_currentTool;
	COLORREF color;
	Color   currentColor; 

	


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCOpenGLTestApp)
	public:
	virtual BOOL InitInstance();
	
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCOpenGLTestApp)
	afx_msg void OnAppAbout();

	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);

	afx_msg void OnDrawPoint();
	afx_msg void OnUpdateDrawPoint(CCmdUI* pCmdUI);

	afx_msg void OnDrawSelect();
	afx_msg void OnUpdateDrawSelect(CCmdUI* pCmdUI);

	afx_msg void OnDrawRect();
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);

	afx_msg void OnDrawTriangle();
	afx_msg void OnUpdateDrawTriangle(CCmdUI* pCmdUI);

	afx_msg void OnDrawPolygon();
	afx_msg void OnUpdateDrawPolygon(CCmdUI* pCmdUI);

	afx_msg void OnDrawCircle();
	afx_msg void OnUpdateDrawCircle(CCmdUI* pCmdUI);

	afx_msg void OnDrawText();
	afx_msg void OnUpdateDrawText(CCmdUI* pCmdUI);

	afx_msg void OnDrawColor();
	afx_msg void OnUpdateDrawColor(CCmdUI* pCmdUI);

	afx_msg void OnDrawFillRect();
	afx_msg void OnUpdateDrawFillRect(CCmdUI* pCmdUI);

	afx_msg void OnDrawFillTriangle();
	afx_msg void OnUpdateDrawFillTriangle(CCmdUI* pCmdUI);

	afx_msg void OnDrawFillPolygon();
	afx_msg void OnUpdateDrawFillPolygon(CCmdUI* pCmdUI);

	afx_msg void OnDrawLineWidth();
	afx_msg void OnUpdateDrawLineWidth(CCmdUI* pCmdUI);


	afx_msg void OnDrawFillCircle();
	afx_msg void OnUpdateDrawFillCircle(CCmdUI* pCmdUI);
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCOPENGLTEST_H__9E5493F7_A268_4DC9_ACF8_F4376911EF89__INCLUDED_)
