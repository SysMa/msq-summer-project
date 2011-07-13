#if !defined(AFX_SIZEDIALOG_H__F818AB76_799B_458D_A45C_1CF071FA16A0__INCLUDED_)
#define AFX_SIZEDIALOG_H__F818AB76_799B_458D_A45C_1CF071FA16A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SizeDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSizeDialog dialog

class CSizeDialog : public CDialog
{
// Construction
public:
	CSizeDialog(int * size,CWnd* pParent = NULL);   // standard constructor
	int size;
	int *point;

// Dialog Data
	//{{AFX_DATA(CSizeDialog)
	enum { IDD = IDD_DIALOG3 };
	CSliderCtrl	m_slider;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSizeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSizeDialog)
	afx_msg void OnButton();
	afx_msg void OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIZEDIALOG_H__F818AB76_799B_458D_A45C_1CF071FA16A0__INCLUDED_)
