// OpenGLDoc.cpp : COpenGLDoc ���ʵ��
//

#include "stdafx.h"
#include "OpenGL.h"

#include "OpenGLDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLDoc

IMPLEMENT_DYNCREATE(COpenGLDoc, CDocument)

BEGIN_MESSAGE_MAP(COpenGLDoc, CDocument)
END_MESSAGE_MAP()


// COpenGLDoc ����/����

COpenGLDoc::COpenGLDoc()
{
	// TODO: �ڴ����һ���Թ������

}

COpenGLDoc::~COpenGLDoc()
{
}

BOOL COpenGLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// COpenGLDoc ���л�

void COpenGLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// COpenGLDoc ���

#ifdef _DEBUG
void COpenGLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COpenGLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COpenGLDoc ����
