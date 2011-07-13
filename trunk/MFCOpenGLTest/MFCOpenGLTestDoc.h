// MFCOpenGLTestDoc.h : interface of the CMFCOpenGLTestDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCOPENGLTESTDOC_H__6CB3CDF6_0E6A_4ED7_9218_4B474F1B2F56__INCLUDED_)
#define AFX_MFCOPENGLTESTDOC_H__6CB3CDF6_0E6A_4ED7_9218_4B474F1B2F56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCOpenGLTestDoc : public CDocument
{
protected: // create from serialization only
	CMFCOpenGLTestDoc();
	DECLARE_DYNCREATE(CMFCOpenGLTestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCOpenGLTestDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCOpenGLTestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCOpenGLTestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCOPENGLTESTDOC_H__6CB3CDF6_0E6A_4ED7_9218_4B474F1B2F56__INCLUDED_)
