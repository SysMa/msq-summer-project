// OpenGLView.h : COpenGLView ��Ľӿ�
//


#pragma once
#include "Camera.h"

class COpenGLView : public CView
{
protected: // �������л�����
	COpenGLView();
	DECLARE_DYNCREATE(COpenGLView)

// ����
public:
	COpenGLDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	CDC* m_pDC;
	HGLRC m_hRC;
	CCamera m_Camera;			// ������� [8/20/2010 foryond]
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	void SetupPixelFormat(CDC* m_pDC);
	void InitOpenGL();
	void RenderScene();

// ʵ��
public:
	virtual ~COpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // OpenGLView.cpp �еĵ��԰汾
inline COpenGLDoc* COpenGLView::GetDocument() const
   { return reinterpret_cast<COpenGLDoc*>(m_pDocument); }
#endif

