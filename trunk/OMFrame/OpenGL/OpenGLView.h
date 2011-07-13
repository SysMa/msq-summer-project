// OpenGLView.h : COpenGLView 类的接口
//


#pragma once
#include "Camera.h"

class COpenGLView : public CView
{
protected: // 仅从序列化创建
	COpenGLView();
	DECLARE_DYNCREATE(COpenGLView)

// 属性
public:
	COpenGLDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	CDC* m_pDC;
	HGLRC m_hRC;
	CCamera m_Camera;			// 相机控制 [8/20/2010 foryond]
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	void SetupPixelFormat(CDC* m_pDC);
	void InitOpenGL();
	void RenderScene();

// 实现
public:
	virtual ~COpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // OpenGLView.cpp 中的调试版本
inline COpenGLDoc* COpenGLView::GetDocument() const
   { return reinterpret_cast<COpenGLDoc*>(m_pDocument); }
#endif

