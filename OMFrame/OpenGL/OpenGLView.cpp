// OpenGLView.cpp : COpenGLView 类的实现
//

#include "stdafx.h"
#include "OpenGL.h"

#include "OpenGLDoc.h"
#include "OpenGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLView

IMPLEMENT_DYNCREATE(COpenGLView, CView)

BEGIN_MESSAGE_MAP(COpenGLView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// COpenGLView 构造/析构

COpenGLView::COpenGLView()
{
	// TODO: 在此处添加构造代码
	m_pDC = NULL;						// DC指针初始化 [8/20/2010 foryond]
}

COpenGLView::~COpenGLView()
{
}

BOOL COpenGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS); // 窗体绘制设置 [8/20/2010 foryond]

	return CView::PreCreateWindow(cs);
}

// COpenGLView 绘制

void COpenGLView::OnDraw(CDC* /*pDC*/)
{
	COpenGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	RenderScene();												// 绘制函数 [8/20/2010 foryond]
	// TODO: 在此处为本机数据添加绘制代码
}


// COpenGLView 打印

BOOL COpenGLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void COpenGLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void COpenGLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清除过程
}


// COpenGLView 诊断

#ifdef _DEBUG
void COpenGLView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLDoc* COpenGLView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLDoc)));
	return (COpenGLDoc*)m_pDocument;
}
#endif //_DEBUG

void COpenGLView::SetupPixelFormat(CDC* m_pDC)		// 设置像素格式 [8/20/2010 foryond]
{
	PIXELFORMATDESCRIPTOR pfd = 
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		//PFD_SUPPORT_GDI|
		PFD_DOUBLEBUFFER|
		PFD_SUPPORT_OPENGL |
		PFD_DRAW_TO_WINDOW, 
		PFD_TYPE_RGBA,
		24,
		0, 0, 0, 0, 0, 0,
		0, 
		0, 
		0, 
		0, 0, 0, 0,
		32,
		0, 
		0, 
		PFD_MAIN_PLANE,
		0, 
		0, 0, 0
	};
	int m_iPFIndex = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);
	SetPixelFormat(m_pDC->GetSafeHdc(), m_iPFIndex, &pfd);
}

// COpenGLView 消息处理程序

int COpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_pDC = new CClientDC(this);						// 程序创建时，生成RC [8/20/2010 foryond]
	SetupPixelFormat(m_pDC);
	this->m_hRC = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);

	InitOpenGL();												//初始化函数

	return 0;
}

void COpenGLView::OnDestroy()			// 关闭程序时销毁RC [8/20/2010 foryond]
{
	CView::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_hRC);
	m_hRC = NULL;
}

void COpenGLView::OnSize(UINT nType, int cx, int cy)		// 视口、视景体处理 [8/20/2010 foryond]
{
	CView::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	glViewport(0, 0, cx, cy);												
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, (GLfloat)cx/(GLfloat)cy, 0.1f, 100.0f);   
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void COpenGLView::InitOpenGL()		// OpenGL环境初始化函数 [8/20/2010 foryond]
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel (GL_SMOOTH);

	glClearColor (0.0, 0.0, 0.0, 0.5);		//背景色设置为黑色
	glClearDepth(1.0);

	glEnable(GL_DEPTH_TEST);			//开启深度测试
	glDepthFunc(GL_LEQUAL);				//深度测试类型
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void COpenGLView::RenderScene()	// 绘制函数 [8/20/2010 foryond]
{
// 	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
// 	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//m_Camera.DisplayScene();
	
	//---------------------------------------------------------------------
	// 此处添加绘制代码 [8/20/2010 foryond]

	SwapBuffers(m_pDC->GetSafeHdc());
	
}