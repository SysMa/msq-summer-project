// MFCOpenGLTestView.cpp : implementation of the CMFCOpenGLTestView class
//

#include "stdafx.h"
#include "MFCOpenGLTest.h"

#include "MFCOpenGLTestDoc.h"
#include "MFCOpenGLTestView.h"
#include "MFCOpenGLTest.h"
#include "Line.h"
#include "Point.h"
#include "MyRect.h"
#include "MyTriangle.h"
#include "MyPolygon.h"
#include "Circle.h"
#include "Text.h"
#include "CharacterDialog.h"
#include "MyFillRect.h"
#include "MyFillTriangle.h"
#include "MyFillPolygon.h"
#include "FillCircle.h"



//(CDrawApp *)AfxGetApp()->m_CurrentTool


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestView

IMPLEMENT_DYNCREATE(CMFCOpenGLTestView, CView)

BEGIN_MESSAGE_MAP(CMFCOpenGLTestView, CView)
	//{{AFX_MSG_MAP(CMFCOpenGLTestView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_EDIT_RESTAR, OnEditRestar)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestView construction/destruction

CMFCOpenGLTestView::CMFCOpenGLTestView()
{
	// TODO: add construction code here
	 m_count = 0;
	 m_currElem = 0;
 

	 m_clipCount = 0;
	 m_choicedElem = 0;

	 selectIndex=-1;

	 
    width=1;
	currentColor.r=0;
	currentColor.g=0;
	currentColor.b=0;

	LastSelectColor.r=0;
	LastSelectColor.g=0;
	LastSelectColor.b=0;

}

CMFCOpenGLTestView::~CMFCOpenGLTestView()
{
}

BOOL CMFCOpenGLTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
   
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestView drawing

void CMFCOpenGLTestView::OnDraw(CDC* pDC)
{
	CMFCOpenGLTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	::glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    RenderScene();
    // Tell OpenGL to flush its pipeline
	if (m_currElem) m_currElem->DrawCurrentOperation();
	if (m_choicedElem) m_choicedElem->Draw();
    ::glFinish();
    // Now Swap the buffers
    ::SwapBuffers( m_pDC->GetSafeHdc() );

}

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestView printing

BOOL CMFCOpenGLTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCOpenGLTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCOpenGLTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestView diagnostics

#ifdef _DEBUG
void CMFCOpenGLTestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCOpenGLTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCOpenGLTestDoc* CMFCOpenGLTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCOpenGLTestDoc)));
	return (CMFCOpenGLTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestView message handlers

int CMFCOpenGLTestView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	InitializeOpenGL();

	
	return 0;
}

BOOL CMFCOpenGLTestView::InitializeOpenGL()
{
    //Get a DC for the Client Area
    m_pDC = new CClientDC(this);
    //Failure to Get DC
    if(m_pDC == NULL)
    {
        MessageBox("Error Obtaining DC");
        return FALSE;
    }
    //Failure to set the pixel format
    if(!SetupPixelFormat())
    {
        return FALSE;
    }
    //Create Rendering Context
    m_hRC = ::wglCreateContext (m_pDC->GetSafeHdc ());
    //Failure to Create Rendering Context
    if(m_hRC == 0)
    {
        MessageBox("Error Creating RC");
        return FALSE;
    }
    //Make the RC Current
    if(::wglMakeCurrent (m_pDC->GetSafeHdc (), m_hRC)==FALSE)
    {
        MessageBox("Error making RC Current");
        return FALSE;
    }
    ::glClearColor(1.0f,1.0f,1.0f,0.0f);
//	::glClearColor(1,0,0,0);
    //Specify the back of the buffer as clear depth
    ::glClearDepth(1.0f);
    //Enable Depth Testing
 //   ::glEnable(GL_DEPTH_TEST);
    return TRUE;
}

BOOL CMFCOpenGLTestView::SetupPixelFormat()
{
  static PIXELFORMATDESCRIPTOR pfd = 
    {
        sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
        1,                              // version number
        PFD_DRAW_TO_WINDOW |            // support window
        PFD_SUPPORT_OPENGL |            // support OpenGL
        PFD_DOUBLEBUFFER,                // double buffered
        PFD_TYPE_RGBA,                  // RGBA type
        24,                             // 24-bit color depth
        0, 0, 0, 0, 0, 0,               // color bits ignored
        0,                              // no alpha buffer
        0,                              // shift bit ignored
        0,                              // no accumulation buffer
        0, 0, 0, 0,                     // accum bits ignored
        16,                             // 16-bit z-buffer
        0,                              // no stencil buffer
        0,                              // no auxiliary buffer
        PFD_MAIN_PLANE,                 // main layer
        0,                              // reserved
        0, 0, 0                         // layer masks ignored
    };
    int m_nPixelFormat = ::ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd);
    if ( m_nPixelFormat == 0 )
    {
       return FALSE;
    }
    if ( ::SetPixelFormat(m_pDC->GetSafeHdc(), m_nPixelFormat, &pfd) == FALSE)
    {
       return FALSE;
    }
    return TRUE;
}




void CMFCOpenGLTestView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	//Make the RC non-current
    if(::wglMakeCurrent (0,0) == FALSE)
    {
        MessageBox("Could not make RC non-current");
    }
    
    //Delete the rendering context
    if(::wglDeleteContext (m_hRC)==FALSE)
    {
        MessageBox("Could not delete RC");
    }
    //Delete the DC
    if(m_pDC)
    {
        delete m_pDC;
    }
    //Set it to NULL
    m_pDC = NULL;

	
}

void CMFCOpenGLTestView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	GLdouble aspect_ratio; // width/height ratio
    if ( 0 >= cx || 0 >= cy )
    {
        return;
    }
    // select the full client area
    ::glViewport(0, 0, cx, cy);
    // compute the aspect ratio
    // this will keep all dimension scales equal
    aspect_ratio = (GLdouble)cx/(GLdouble)cy;
    // select the projection matrix and clear it
    ::glMatrixMode(GL_PROJECTION);
    ::glLoadIdentity();
    // select the viewing volume
    //::gluPerspective(45.0f, aspect_ratio, .01f, 200.0f);
    ::gluOrtho2D(0, cx, cy, 0);    
    // switch back to the modelview matrix and clear it
    ::glMatrixMode(GL_MODELVIEW);
    ::glLoadIdentity();
    m_wWidth = cx;
	m_wHeight = cy;


	
	// TODO: Add your message handler code here
	
}

BOOL CMFCOpenGLTestView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return CView::OnEraseBkgnd(pDC);
}



void CMFCOpenGLTestView::RenderScene()
{   
  //   glColor3f(0,0,0);
	for (int i=0; i<m_count; i++)
		elemList[i]->Draw();

//	glColor3f(0,1,0);
	for (int i=0; i<m_clipCount; i++)
	    clipelemList[i]->Draw();
}


void CMFCOpenGLTestView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

   
  	float x=point.x;
	float y=point.y;

	
	m_WndStatusBar=(CStatusBar *)AfxGetApp()->GetMainWnd()->GetDescendantWindow(AFX_IDW_STATUS_BAR);
	m_ptStr.Format("X坐标:%4d  mm, Y坐标:%4d  mm",point.x,point.y);
	m_WndStatusBar->SetPaneText(1,m_ptStr);


	if (m_currElem)
		m_currElem->OnMouseMove(x,y);

	Invalidate(false);
	
	CView::OnMouseMove(nFlags, point);
}

void CMFCOpenGLTestView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

		float x=point.x;
     	float y=point.y ;
	CMFCOpenGLTestApp * pApp= (CMFCOpenGLTestApp *)AfxGetApp();

	if (pApp->m_currentTool==ID_DRAW_LINE )
	{

		if (!m_currElem) 
		{
			CLine *line = new CLine;
	
		     line->color=currentColor;
		     line->Width=width;
		     m_currElem = line;
			
		}
		

	}
	if (pApp->m_currentTool ==ID_DRAW_POINT)
	{
		CMyPoint *point = new CMyPoint;
		point->Width=width;
		point->color=currentColor;
		m_currElem = point;
	}

	if (pApp->m_currentTool ==ID_DRAW_RECT)
	{
		if (!m_currElem) 
		{	
			CMyRect *rect = new CMyRect;
		    rect->Width=width;
	     	rect->color=currentColor;
	    	m_currElem = rect;

		}
	
	}


	if (pApp->m_currentTool==ID_DRAW_TRIANGLE )
	{

		if (!m_currElem) 
		{
			CMyTriangle *angle = new CMyTriangle;
	
		     angle->color=currentColor;
		     angle->Width=width;
		     m_currElem = angle;
			
		}
		

	}



	if (pApp->m_currentTool==ID_DRAW_POLYGON )
	{

		if (!m_currElem) 
		{
			CMyPolygon *polygon = new CMyPolygon;
	
		     polygon->color=currentColor;
		     polygon->Width=width;
		     m_currElem = polygon;
			
		}
		

	}

	if (pApp->m_currentTool==ID_DRAW_CIRCLE )
	{

		if (!m_currElem) 
		{
			CCircle *circle = new CCircle;
	
		     circle->color=currentColor;
		     circle->Width=width;
		     m_currElem = circle;
			
		}
		

	}

	if (pApp->m_currentTool==ID_DRAW_TEXT )
	{

		if (!m_currElem) 
		{
			
			CString  * cstr=new CString("good");
			
			int size=20;
            CCharacterDialog * example=new CCharacterDialog(cstr,&size);
			example->DoModal();
		    char *ch =cstr->GetBuffer( cstr->GetLength() + 1);
	     //   	char *ch ="hello";
				

         //   cstr.ReleaseBuffer();
			
		//	CString test;
		//	test="hello";
		//	char *ch=(LPSTR)(LPCTSTR)test;
		//	test.Format("%d",size);
		//	AfxMessageBox(test);


			
			CText *text= new CText(ch,size);
	
		     text->color=currentColor;
		     text->Width=width;
			 text->length=cstr->GetLength();
			 
		     m_currElem = text;
			 delete example;
			 //delete cstr;
			
		}
		

	}

	if (pApp->m_currentTool==ID_DRAW_FILL_RECT )
	{

		if (!m_currElem) 
		{
			CMyFillRect *fillRect = new CMyFillRect;
	
		     fillRect->color=currentColor;
		     fillRect->Width=width;
		     m_currElem = fillRect;
			
		}
		

	}

		if (pApp->m_currentTool==ID_DRAW_FILL_TRIANGLE )
	{

		if (!m_currElem) 
		{
			CMyFillTriangle *fillTriangle = new CMyFillTriangle;
	
		     fillTriangle->color=currentColor;
		     fillTriangle->Width=width;
		     m_currElem = fillTriangle;
			
		}
		

	}

		if (pApp->m_currentTool==ID_DRAW_FILL_CIRCLE)
	{

		if (!m_currElem) 
		{
			CFillCircle *fillCircle = new CFillCircle;
	
		     fillCircle->color=currentColor;
		     fillCircle->Width=width;
		     m_currElem = fillCircle;
			
		}
		

	}

		if (pApp->m_currentTool==ID_DRAW_FILL_POLYGON)
	{

		if (!m_currElem) 
		{
			CMyFillPolygon *fillPolygon = new CMyFillPolygon;
	
		     fillPolygon->color=currentColor;
		     fillPolygon->Width=width;
		     m_currElem = fillPolygon;
			
		}
		

	}



	if (!m_currElem) return;
 	if (m_currElem->OnLButtonUp(x,y)) 
	{
		if (pApp->m_currentTool== ID_DRAW_SELECT)
		{
			for (int i=0; i< m_count; i++)
			{
				elemList[i]->Clip(m_currElem,clipelemList,m_clipCount);	
			}
			pApp->m_currentTool= ID_DRAW_SELECT;
			clipelemList[m_clipCount++] = m_currElem;
		}
		else 
			elemList[m_count++] = m_currElem;
		
		m_currElem = 0;
	}

	Invalidate(false);
	
	CView::OnLButtonUp(nFlags, point);
}





void CMFCOpenGLTestView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	float x=point.x;
    float y=point.y ;
	CMFCOpenGLTestApp * pApp= (CMFCOpenGLTestApp *)AfxGetApp();
	if (pApp->m_currentTool==ID_DRAW_POLYGON )
	{

		if (m_currElem) 
		{
			m_currElem->OnRButtonUp(x,y);


			OnLButtonUp(x,y);
		}
		

	}

	if (pApp->m_currentTool==ID_DRAW_FILL_POLYGON )
	{

		if (m_currElem) 
		{
			m_currElem->OnRButtonUp(x,y);


			OnLButtonUp(x,y);
		}
		

	}
	
	CView::OnRButtonUp(nFlags, point);
}

void CMFCOpenGLTestView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	float x=point.x;
    float y=point.y ;
	CMFCOpenGLTestApp * pApp= (CMFCOpenGLTestApp *)AfxGetApp();

   if (pApp->m_currentTool==ID_DRAW_SELECT)
   {
         int i;
		for (i=0; i< m_count; i++)
		{
			elemList[i]->GetTheFeildCrect();
			if(elemList[i]->Pick(x,y))
			{
				selectIndex=i;
				if (m_choicedElem)
				{
					m_choicedElem->color.r=LastSelectColor.r;
					m_choicedElem->color.g=LastSelectColor.g;
				    m_choicedElem->color.b=LastSelectColor.b;
				}
				

				m_choicedElem = elemList[i];

				LastSelectColor.r=m_choicedElem->color.r;
				LastSelectColor.g=m_choicedElem->color.g;
                LastSelectColor.b=m_choicedElem->color.b;

				

				m_choicedElem->color.r=1;
				m_choicedElem->color.g=0; //选中的图形用红色显示
				m_choicedElem->color.b=0;



				break;
			}
		}

		if (i==m_count&&m_choicedElem) 
		{
			
			m_choicedElem->color.r=LastSelectColor.r;
			m_choicedElem->color.g=LastSelectColor.g;
			m_choicedElem->color.b=LastSelectColor.b;
            m_choicedElem = 0;

		}
		

	}



	
	
	CView::OnRButtonDown(nFlags, point);
}

void CMFCOpenGLTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	CMFCOpenGLTestApp * pApp= (CMFCOpenGLTestApp *)AfxGetApp();
 	if (pApp->m_currentTool==ID_DRAW_SELECT)
	{
		if (nChar==VK_DELETE)
		{
			CBase * deleteElement;
			deleteElement=elemList[selectIndex];
			for (int i=selectIndex;i<m_count-1;i++)
				elemList[i]=elemList[i+1];
			m_count--;
			delete deleteElement;
			m_choicedElem=NULL;
			

			


		}
		if (m_choicedElem)
		{
			m_choicedElem->OnKeyMove(nChar);
		}
	}
	
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMFCOpenGLTestView::OnFileSave() 
{
	// TODO: Add your command handler code here
	CFileDialog fdlg(FALSE,"c",NULL,OFN_OVERWRITEPROMPT,
		" 图形文件(*.cg)|*.cg|所有文件(*.*)|*.*||",this);
	fdlg.m_ofn.lpstrTitle="保存图形文件";
	if (fdlg.DoModal()==IDOK)
	{
		CString m_strCurFile=fdlg.GetPathName();

		
		CStdioFile f;
		f.Open(m_strCurFile,CFile::typeText|CFile::modeCreate|CFile::modeReadWrite| CFile::shareDenyWrite);
		for (int i=0;i<m_count;i++)
		{
			CString classname;
			classname=elemList[i]->GetClassName();
			f.WriteString(classname+elemList[i]->Save()+"\n");
		}
		f.Close();
	
	}
	
}

void CMFCOpenGLTestView::OnFileOpen() 
{
	// TODO: Add your command handler code here

	if (m_count>0)
	{
		switch (AfxMessageBox("要保存修改吗？！",MB_YESNOCANCEL|MB_ICONQUESTION))
		{
		case IDYES:
			OnFileSave();
			
			return;
		case IDCANCEL:
			break;
		default:
			;
		}
	}
	
	InitionTheView();
	CFileDialog fdlg(TRUE,"cg",NULL,OFN_FILEMUSTEXIST,"图形文件(*.cg)|*.cg|所有文件(*.*)|*.*||",this);
		
    fdlg.m_ofn.lpstrTitle="打开图形文件";


	  
	  
	if (fdlg.DoModal()==IDOK)
	{
	    CString	m_strCurFile=fdlg.GetPathName();
		CStdioFile f;
		f.Open(m_strCurFile,CFile::modeRead);

		CString content;
		int i=0;

		while (f.ReadString(content))
		{



     		int pos=content.Find(' ');
       	
      		CString str=content.Mid(0,pos);
			int length=content.GetLength();

		
			if (str=="CMyPoint")
			{   CMyPoint * point=new  CMyPoint();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}
			if (str=="CMyRect")
			{   CMyRect * point=new  CMyRect();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}

			if (str=="CLine")
			{   CLine * point=new  CLine();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}
			if (str=="CMyTriangle")
			{   CMyTriangle * point=new  CMyTriangle();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}
			if (str=="CCircle")
			{   CCircle * point=new  CCircle();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}

			if (str=="CMyPolygon")
			{   CMyPolygon * point=new  CMyPolygon();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}
			 

			if (str=="CText")
			{   CText * point=new  CText();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}

			if (str=="CMyFillRect")
			{   CMyFillRect * point=new  CMyFillRect();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}

			if (str=="CMyFillTriangle")
			{   CMyFillTriangle * point=new  CMyFillTriangle();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}
			if (str=="CMyFillPolygon")
			{   CMyFillPolygon * point=new  CMyFillPolygon();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}

			if (str=="CMyFillCircle")
			{   CFillCircle * point=new  CFillCircle();
				point->Read(content.Mid(pos+1,length));
				elemList[i]=point;
				i++;
		        m_count++;
                  
			}
			 
				  
			
		
		  
			

		}
		
	    f.Close();
	}
	
	

	
	
	
}

void CMFCOpenGLTestView::InitionTheView()
{
    int num=m_count;
	for (int i=0;i<num;i++)
	{
		delete elemList[i];
		m_count--;
	}

   

	 m_currElem = 0;
	 
	 
	 m_clipCount = 0;
	 m_choicedElem = 0;
	 
	 selectIndex=-1;


}
	


void CMFCOpenGLTestView::OnEditRestar() 
{
	// TODO: Add your command handler code here
	InitionTheView();
	
}
