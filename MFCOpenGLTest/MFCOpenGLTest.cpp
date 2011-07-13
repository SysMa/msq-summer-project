// MFCOpenGLTest.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFCOpenGLTest.h"

#include "MainFrm.h"
#include "MFCOpenGLTestDoc.h"
#include "MFCOpenGLTestView.h"
#include "SizeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestApp

BEGIN_MESSAGE_MAP(CMFCOpenGLTestApp, CWinApp)
	//{{AFX_MSG_MAP(CMFCOpenGLTestApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_DRAW_LINE, OnDrawLine)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE, OnUpdateDrawLine)

	ON_COMMAND(ID_DRAW_POINT, OnDrawPoint)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POINT, OnUpdateDrawPoint)

	ON_COMMAND(ID_DRAW_SELECT, OnDrawSelect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_SELECT, OnUpdateDrawSelect)

	ON_COMMAND(ID_DRAW_RECT, OnDrawRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_RECT, OnUpdateDrawRect)

	ON_COMMAND(ID_DRAW_TRIANGLE, OnDrawTriangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TRIANGLE, OnUpdateDrawTriangle)

	ON_COMMAND(ID_DRAW_POLYGON, OnDrawPolygon)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYGON, OnUpdateDrawPolygon)

	ON_COMMAND(ID_DRAW_CIRCLE, OnDrawCircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE, OnUpdateDrawCircle)

	
	ON_COMMAND(ID_DRAW_TEXT, OnDrawText)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TEXT, OnUpdateDrawText)

	ON_COMMAND(ID_SELECT_COLOR, OnDrawColor)
	ON_UPDATE_COMMAND_UI(ID_SELECT_COLOR, OnUpdateDrawColor)


	ON_COMMAND(ID_DRAW_FILL_RECT, OnDrawFillRect)
	ON_UPDATE_COMMAND_UI(ID_DRAW_FILL_RECT, OnUpdateDrawFillRect)


	ON_COMMAND(ID_DRAW_FILL_TRIANGLE, OnDrawFillTriangle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_FILL_TRIANGLE, OnUpdateDrawFillTriangle)


	ON_COMMAND(ID_DRAW_FILL_POLYGON, OnDrawFillPolygon)
	ON_UPDATE_COMMAND_UI(ID_DRAW_FILL_POLYGON, OnUpdateDrawFillPolygon)

	ON_COMMAND(ID_DRAW_LINE_WIDTH, OnDrawLineWidth)
	ON_UPDATE_COMMAND_UI(ID_DRAW_LINE_WIDTH, OnUpdateDrawLineWidth)

	ON_COMMAND(ID_DRAW_FILL_CIRCLE, OnDrawFillCircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_FILL_CIRCLE, OnUpdateDrawFillCircle)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestApp construction

CMFCOpenGLTestApp::CMFCOpenGLTestApp()
{
	// TODO: add construction code here,

	m_currentTool = ID_DRAW_SELECT;
	color=0;
	currentColor.r=currentColor.g=currentColor.b=0;

	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMFCOpenGLTestApp object

CMFCOpenGLTestApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestApp initialization

BOOL CMFCOpenGLTestApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMFCOpenGLTestDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CMFCOpenGLTestView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMFCOpenGLTestApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CMFCOpenGLTestApp::OnDrawLine() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_LINE;
}

void CMFCOpenGLTestApp::OnUpdateDrawLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_LINE ? 1:0);
	pCmdUI->Enable(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCOpenGLTestApp message handlers
void CMFCOpenGLTestApp::OnDrawPoint() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_POINT;
}

void CMFCOpenGLTestApp::OnUpdateDrawPoint(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_POINT ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawSelect() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_SELECT;
}

void CMFCOpenGLTestApp::OnUpdateDrawSelect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_SELECT ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawRect() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_RECT;
}

void CMFCOpenGLTestApp::OnUpdateDrawRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_RECT ? 1:0);
	pCmdUI->Enable(TRUE);
}


void CMFCOpenGLTestApp::OnDrawTriangle() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_TRIANGLE;
}

void CMFCOpenGLTestApp::OnUpdateDrawTriangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_TRIANGLE ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawPolygon() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_POLYGON;
}

void CMFCOpenGLTestApp::OnUpdateDrawPolygon(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_POLYGON ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawCircle() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_CIRCLE;
}

void CMFCOpenGLTestApp::OnUpdateDrawCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_CIRCLE ? 1:0);
	pCmdUI->Enable(TRUE);
}
void CMFCOpenGLTestApp::OnDrawText() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_TEXT;
}

void CMFCOpenGLTestApp::OnUpdateDrawText(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_TEXT ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawColor()
{
   m_currentTool = ID_SELECT_COLOR;
   CColorDialog *dlg=new CColorDialog;
   if(dlg->DoModal()==IDOK)
   color=dlg->GetColor();
   BYTE r,g,b;
   r=GetRValue(color);
   g=GetGValue(color);
   b=GetBValue(color);
   currentColor.r=float(r)/255;
   currentColor.g=float(g)/255;
   currentColor.b=float(b)/255;


   CMainFrame   *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;   
   CMFCOpenGLTestView   *pView=(CMFCOpenGLTestView *)pMain->GetActiveView();
   pView->currentColor=currentColor;

   delete dlg;



}
void CMFCOpenGLTestApp::OnUpdateDrawColor(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_currentTool == ID_SELECT_COLOR ? 1:0);
	pCmdUI->Enable(TRUE);

}


void CMFCOpenGLTestApp::OnDrawFillRect() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_FILL_RECT;
}

void CMFCOpenGLTestApp::OnUpdateDrawFillRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_FILL_RECT ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawFillTriangle() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_FILL_TRIANGLE;
}

void CMFCOpenGLTestApp::OnUpdateDrawFillTriangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_FILL_TRIANGLE ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawFillPolygon() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_FILL_POLYGON;
}

void CMFCOpenGLTestApp::OnUpdateDrawFillPolygon(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_FILL_POLYGON ? 1:0);
	pCmdUI->Enable(TRUE);
}


void CMFCOpenGLTestApp::OnDrawLineWidth() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_LINE_WIDTH;
	int size=4;


   CSizeDialog *dlg=new CSizeDialog(&size);
   dlg->DoModal();
   


   CMainFrame   *pMain=(CMainFrame *)AfxGetApp()->m_pMainWnd;   
   CMFCOpenGLTestView   *pView=(CMFCOpenGLTestView *)pMain->GetActiveView();
   pView->width=size;

   delete dlg;
}

void CMFCOpenGLTestApp::OnUpdateDrawLineWidth(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_LINE_WIDTH ? 1:0);
	pCmdUI->Enable(TRUE);
}

void CMFCOpenGLTestApp::OnDrawFillCircle() 
{
	// TODO: Add your command handler code here
	m_currentTool = ID_DRAW_FILL_CIRCLE;
}

void CMFCOpenGLTestApp::OnUpdateDrawFillCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_currentTool == ID_DRAW_FILL_CIRCLE ? 1:0);
	pCmdUI->Enable(TRUE);
}