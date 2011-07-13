// SizeDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "SizeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSizeDialog dialog


CSizeDialog::CSizeDialog(int * size,CWnd* pParent /*=NULL*/)
	: CDialog(CSizeDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSizeDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	this->size=4;
	point=size;
}


void CSizeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSizeDialog)
	DDX_Control(pDX, IDC_SLIDER, m_slider);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSizeDialog, CDialog)
	//{{AFX_MSG_MAP(CSizeDialog)
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, OnCustomdrawSlider)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSizeDialog message handlers

void CSizeDialog::OnButton() 
{
	// TODO: Add your control notification handler code here
	* point=size;
	OnOK();
	
}

void CSizeDialog::OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	size = m_slider.GetPos(); //获得滑块的当前位置
	
	
	//另外做一个编辑框 显示所调节的数据；
	CString str="";
	str.Format("%d",size);
	SetDlgItemText(IDC_EDIT,str);
	
	*pResult = 0;
}



BOOL CSizeDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here


	m_slider.SetRange(1,40);
	m_slider.SetPos(4);
	CMenu*   pTopMenu   = this->GetSystemMenu(FALSE); 

    pTopMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
