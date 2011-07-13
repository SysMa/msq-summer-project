// MFCOpenGLTestDoc.cpp : implementation of the CMFCOpenGLTestDoc class
//

#include "stdafx.h"
#include "MFCOpenGLTest.h"

#include "MFCOpenGLTestDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestDoc

IMPLEMENT_DYNCREATE(CMFCOpenGLTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCOpenGLTestDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCOpenGLTestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestDoc construction/destruction

CMFCOpenGLTestDoc::CMFCOpenGLTestDoc()
{
	// TODO: add one-time construction code here

}

CMFCOpenGLTestDoc::~CMFCOpenGLTestDoc()
{
}

BOOL CMFCOpenGLTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestDoc serialization

void CMFCOpenGLTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestDoc diagnostics

#ifdef _DEBUG
void CMFCOpenGLTestDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCOpenGLTestDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestDoc commands
