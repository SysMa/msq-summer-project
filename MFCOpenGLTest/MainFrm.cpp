// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MFCOpenGLTest.h"

#include "MainFrm.h"
#include "MFCOpenGLTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_PAINTTOOL, OnPainttool)
	ON_UPDATE_COMMAND_UI(ID_PAINTTOOL, OnUpdatePainttool)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/*atic UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};*/

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_SEPARATOR, 
	ID_SEPARATOR
};
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}


	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
   if (!myPaintToolBar.Create(this, WS_CHILD | WS_VISIBLE | 
		CBRS_SIZE_FIXED	| CBRS_LEFT | CBRS_TOOLTIPS) ||
		!myPaintToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	myPaintToolBar.SetWindowText(_T("工具箱"));
	myPaintToolBar.EnableDocking(CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT);
	myPaintToolBar.SetColumns(2);
	
	/*int a=0;
	UINT b;
	int c;
	UINT d;
	for (;a<24;a++)
	{   
		myPaintToolBar.GetButtonInfo(a,b,d,c);
		CString test;
		test.Format("%d",b);
		AfxMessageBox(test); 
	}*/
	
//	myPaintToolBar.SetButtonInfo(0,ID_DRAW_POINT,TBBS_BUTTON,0);
 //   myPaintToolBar.SetButtonInfo(1,ID_DRAW_LINE,TBBS_BUTTON,1);
	   



	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndStatusBar.SetPaneInfo(2,2,SBPS_NOBORDERS,30);
	m_wndStatusBar.SetPaneText(2,"陈赢峰");

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&myPaintToolBar);
	DockControlBar(&m_wndToolBar);
	myPaintToolBar.EnableWindow(TRUE);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	

	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnPainttool() 
{
	// TODO: Add your command handler code here
	BOOL bVisible = ((myPaintToolBar.GetStyle() & WS_VISIBLE)!=0);
	ShowControlBar(&myPaintToolBar, !bVisible, FALSE);
	RecalcLayout();

	GetMenu()->CheckMenuItem(ID_PAINTTOOL, 
		(bVisible ? MF_UNCHECKED : MF_CHECKED | MF_BYCOMMAND));
}

void CMainFrame::OnUpdatePainttool(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bVisible = ((myPaintToolBar.GetStyle() & WS_VISIBLE) != 0);
	pCmdUI->SetCheck(bVisible);
}






void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	CMFCOpenGLTestView*   pView   =   (CMFCOpenGLTestView*)(((CMainFrame*)(AfxGetApp()-> m_pMainWnd))-> GetActiveView());

	if (pView->m_count>0)
	{
		switch (AfxMessageBox("要保存修改吗？！",MB_YESNOCANCEL|MB_ICONQUESTION))
		{
		case IDYES:
			
			break;
		case IDCANCEL:
			return;
		default:
			;
		}
	}
	if (IDNO==AfxMessageBox("真的要退出吗？",MB_YESNO|MB_ICONQUESTION))
	{
		return;
	}
//	EndDialog(IDCANCEL);
	
	CFrameWnd::OnClose();
}
