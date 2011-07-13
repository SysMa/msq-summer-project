#if !defined(AFX_CHARACTERDIALOG_H__F22C2CC3_AA13_45C9_AACA_24AD00EA03FA__INCLUDED_)
#define AFX_CHARACTERDIALOG_H__F22C2CC3_AA13_45C9_AACA_24AD00EA03FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CharacterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCharacterDialog dialog

class CCharacterDialog : public CDialog
{
// Construction
public:
	CCharacterDialog(CString * str,int * size,CWnd* pParent = NULL);   // standard constructor
	CString * str;
	int * size;
	int nPos;

// Dialog Data
	//{{AFX_DATA(CCharacterDialog)
	enum { IDD = IDD_DIALOG2 };
	CSliderCtrl	m_slider;
	CString	m_string;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharacterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCharacterDialog)
	afx_msg void OnButton();
	afx_msg void OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARACTERDIALOG_H__F22C2CC3_AA13_45C9_AACA_24AD00EA03FA__INCLUDED_)
