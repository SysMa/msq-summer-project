// OpenGLDoc.cpp : COpenGLDoc 类的实现
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


// COpenGLDoc 构造/析构

COpenGLDoc::COpenGLDoc()
{
	// TODO: 在此添加一次性构造代码

}

COpenGLDoc::~COpenGLDoc()
{
}

BOOL COpenGLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// COpenGLDoc 序列化

void COpenGLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// COpenGLDoc 诊断

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


// COpenGLDoc 命令
