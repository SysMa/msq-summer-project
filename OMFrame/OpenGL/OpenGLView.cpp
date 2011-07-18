// OpenGLView.cpp : COpenGLView 类的实现
//

#include "stdafx.h"
#include "OpenGL.h"
#include <gl\GLUT.H>
#include "OpenGLDoc.h"
#include "OpenGLView.h"

#include "windows.h"
#include "stdio.h" 
#include"math.h"
#include "gl\gl.h"
#include "GL\glu.h"
#include "gl\glaux.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/*********************************************************
* openGL thins here
**********************************************************/

#pragma comment( lib, "glaux.lib" ) 
#pragma comment( lib, "glu32.lib" ) 
#pragma comment( lib, "OpenGL32.lib" ) 

void myinit(void);

void CALLBACK	display(void);
void CALLBACK	reshape(GLsizei w,GLsizei h);
void CALLBACK	stepDisplay(void);

static GLfloat year[8];
static GLfloat year0[8]={0.24,0.613,1,1.88 , 5 , 14 , 22 , 29.5};
static GLfloat day[8];
static GLfloat day0[8]={58.65 , 243 , 1, 1 ,0.375 , 0.426 , 0.65 ,0.67} ;
static GLfloat r1[8]={1.2,1.7,2,2.8,4,5.5,6.5,7.5};
static GLfloat r2[8]={0.076,0.19,0.2,0.106,0.5,0.5,0.3,0.29};
char *planetN[8]={"MERCURY.RAW","VENUS.RAW","EARTH.RAW","MARS.RAW","JUPITER.RAW","SATURN.RAW","URANUS.RAW","NEPTUNE.RAW"};
GLuint texture_id[8];

int load( char *file_name )
{
	GLubyte *Image;
	FILE *file;

	int width=640,  height=320;
	if (( file = fopen(file_name, "rb"))==NULL )
	{
	   return 1;
	}
	Image = (GLubyte *)malloc(width * height * 3 * (sizeof(GLubyte)));

	fread  ( Image , width * height * 3, 1 , file );
	fclose ( file);
   
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,  GL_NEAREST );
	glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,  GL_NEAREST);
	glTexEnvf ( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );

	gluBuild2DMipmaps ( GL_TEXTURE_2D, GL_RGB, width, height, GL_RGB, GL_UNSIGNED_BYTE, Image );
	free ( Image );
   
}

void LoadTextures(GLuint *texture_id)
{
	glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(8, texture_id);

	for(int i=0;i<8;i++)
	{
		glBindTexture(GL_TEXTURE_2D, texture_id[i]);
		load( planetN[i] );
	}
	
}

void myinit(void)
{
	auxInitDisplayMode(AUX_DOUBLE|AUX_RGBA);
	auxInitPosition(100,100,800,600);

	auxInitWindow((LPCWSTR)"Solar System");

	GLfloat light_ambient[]={0.3,0.5,0.3};
	GLfloat light_diffuse[]={1.0,1.0,1.0};
	GLfloat light_specular[]={0.8,0.8,0.0};
	GLfloat light_position[]={0.0,0.0,0.0};

	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular);
	glLightfv(GL_LIGHT0,GL_POSITION, light_position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearColor(0, 0, 0, 0);
	glShadeModel(GL_SMOOTH);

	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	LoadTextures(texture_id);

	for(int i = 0;i<8;i++){
		year[i]=(rand()%360);
		day[i]=0;
	}
		
}

void CALLBACK reshape(GLsizei w,GLsizei h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);   
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();
	gluPerspective(60,(GLfloat)w/(GLfloat)h,1.0,20);   
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	gluLookAt(9,5,5,0,0,0,0,1,0);
}


void CALLBACK display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glDisable(GL_LIGHTING);
	glColor3f (1, 1, 1);
	for(int j=0;j<8;j++)
	{
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 360; i++)
		{
			glVertex3f(cos(i*3.14/180)*r1[j] , 0, sin(i*3.14/180)*r1[j]);
		}
		glEnd();
	}
	glEnable(GL_LIGHTING);
	
	glPushMatrix();
	auxSolidSphere(0.9);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D);	
	for(int i=0;i<8;i++)
	{
		glPushMatrix(); 
		glRotatef(year[i],0,1,0); 	
		glTranslatef( r1[i]  ,0,0);
		glRotatef(day[i],0,1,0);  
		glBindTexture(GL_TEXTURE_2D, texture_id[i]);
		{
			GLUquadricObj*  p = gluNewQuadric();
			gluQuadricTexture (p, GL_TRUE);
			gluSphere(p, r2[i], 16, 16);
			gluDeleteQuadric(p);
		}
		glPopMatrix();
	}	
	glDisable(GL_TEXTURE_2D);
	
	glFlush();
	auxSwapBuffers();	
}

void CALLBACK stepDisplay(void)
{
	for(int i=0;i<8;i++)
	{
		year[i]=year[i]+(1 / year0[i]);
		if( year[i]>360 ) year[i]=year[i] - 360;

		day[i]=day[i] + ( 1 / day0[i] );
		if( day[i] >360 ) day[i]= day[i] -360 ;
	}	
	  display();
}

/********************************************************************
* end openGL thins
**********************************************************************/

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
			//Draw Sun
		glTranslatef(0.0f,0.0f,-5.0f);
		glRotatef(6,1.0f,0.0f,0.0f);

		glutWireSphere(1.0f,20,20);

		//Draw Planet
		glPushMatrix();
			glTranslatef(-1.2f,-0.5f,-2.0f);
			glRotatef(6,1.0f,0.0f,0.0f);

			glutWireSphere(0.5f,20,20);

			//Draw Moon
			glPushMatrix();

			glTranslatef(-1.2f,-0.5f,-2.0f);
			glRotatef(6,1.0f,0.0f,0.0f);

			glutWireSphere(0.05f,20,20);

		glPopMatrix();

	glPopMatrix();

	//myinit();
	//auxReshapeFunc(reshape);
	//auxIdleFunc(stepDisplay);			
	//auxMainLoop(display);

	SwapBuffers(m_pDC->GetSafeHdc());
	
}

// AAA.cpp : Defines the entry point for the console application.
//
