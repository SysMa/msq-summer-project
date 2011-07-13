#if !defined(AFX_PAINTTOOLBAR_H__96EA849E_7CE4_437A_A0BD_18D70D855F2C__INCLUDED_)
#define AFX_PAINTTOOLBAR_H__96EA849E_7CE4_437A_A0BD_18D70D855F2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaintToolbar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaintToolbar window

class CPaintToolbar : public CToolBar
{
// Construction
public:
	CPaintToolbar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaintToolbar)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetColumns(UINT nColumns);			//设置工具箱烈数
	UINT GetColumns() {return m_nColumns;}	//得到工具箱列数
	virtual ~CPaintToolbar();

	// Generated message map functions
protected:
	UINT m_nColumns;
	//{{AFX_MSG(CPaintToolbar)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAINTTOOLBAR_H__96EA849E_7CE4_437A_A0BD_18D70D855F2C__INCLUDED_)
