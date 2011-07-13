// OpenGLView.cpp : COpenGLView ���ʵ��
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// COpenGLView ����/����

COpenGLView::COpenGLView()
{
	// TODO: �ڴ˴���ӹ������
	m_pDC = NULL;						// DCָ���ʼ�� [8/20/2010 foryond]
}

COpenGLView::~COpenGLView()
{
}

BOOL COpenGLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS); // ����������� [8/20/2010 foryond]

	return CView::PreCreateWindow(cs);
}

// COpenGLView ����

void COpenGLView::OnDraw(CDC* /*pDC*/)
{
	COpenGLDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	RenderScene();												// ���ƺ��� [8/20/2010 foryond]
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// COpenGLView ��ӡ

BOOL COpenGLView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void COpenGLView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void COpenGLView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// COpenGLView ���

#ifdef _DEBUG
void COpenGLView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLDoc* COpenGLView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLDoc)));
	return (COpenGLDoc*)m_pDocument;
}
#endif //_DEBUG

void COpenGLView::SetupPixelFormat(CDC* m_pDC)		// �������ظ�ʽ [8/20/2010 foryond]
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

// COpenGLView ��Ϣ�������

int COpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pDC = new CClientDC(this);						// ���򴴽�ʱ������RC [8/20/2010 foryond]
	SetupPixelFormat(m_pDC);
	this->m_hRC = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC);

	InitOpenGL();												//��ʼ������

	return 0;
}

void COpenGLView::OnDestroy()			// �رճ���ʱ����RC [8/20/2010 foryond]
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_hRC);
	m_hRC = NULL;
}

void COpenGLView::OnSize(UINT nType, int cx, int cy)		// �ӿڡ��Ӿ��崦�� [8/20/2010 foryond]
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	glViewport(0, 0, cx, cy);												
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0, (GLfloat)cx/(GLfloat)cy, 0.1f, 100.0f);   
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void COpenGLView::InitOpenGL()		// OpenGL������ʼ������ [8/20/2010 foryond]
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glShadeModel (GL_SMOOTH);

	glClearColor (0.0, 0.0, 0.0, 0.5);		//����ɫ����Ϊ��ɫ
	glClearDepth(1.0);

	glEnable(GL_DEPTH_TEST);			//������Ȳ���
	glDepthFunc(GL_LEQUAL);				//��Ȳ�������
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void COpenGLView::RenderScene()	// ���ƺ��� [8/20/2010 foryond]
{
// 	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
// 	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//m_Camera.DisplayScene();
	
	//---------------------------------------------------------------------
	// �˴���ӻ��ƴ��� [8/20/2010 foryond]

	SwapBuffers(m_pDC->GetSafeHdc());
	
}