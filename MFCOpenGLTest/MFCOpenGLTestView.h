// MFCOpenGLTestView.h : interface of the CMFCOpenGLTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCOPENGLTESTVIEW_H__83B5B15E_8B1E_45A0_9700_E2EB45BCC055__INCLUDED_)
#define AFX_MFCOPENGLTESTVIEW_H__83B5B15E_8B1E_45A0_9700_E2EB45BCC055__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base.h"
#include "MFCOpenGLTestDoc.h"




class CMFCOpenGLTestView : public CView
{
protected: // create from serialization only
	CMFCOpenGLTestView();
	DECLARE_DYNCREATE(CMFCOpenGLTestView)

// Attributes
public:
	 

	CMFCOpenGLTestDoc* GetDocument();
	HGLRC m_hRC;    //Rendering Context
    CDC* m_pDC;        //Device Context
    BOOL InitializeOpenGL();    //Initialize OpenGL
    BOOL SetupPixelFormat();    //Set up the Pixel Format
    void RenderScene();            //Render the Scene

	void InitionTheView();

	CStatusBar * m_WndStatusBar;
	CString m_ptStr;

	CBase * elemList[100];
	CBase * clipelemList[100];
	int m_count;
	int selectIndex;
	int m_clipCount;
	CBase *m_currElem;
	CBase *m_choicedElem;

	Color currentColor;
	float width;

	Color LastSelectColor;


	

	int m_wWidth;
	int m_wHeight;



// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCOpenGLTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCOpenGLTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCOpenGLTestView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
	afx_msg void OnEditRestar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCOpenGLTestView.cpp
inline CMFCOpenGLTestDoc* CMFCOpenGLTestView::GetDocument()
   { return (CMFCOpenGLTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCOPENGLTESTVIEW_H__83B5B15E_8B1E_45A0_9700_E2EB45BCC055__INCLUDED_)
