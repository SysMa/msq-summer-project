// CharacterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFCOpenGLTest.h"
#include "CharacterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCharacterDialog dialog


CCharacterDialog::CCharacterDialog(CString * str,int * size,CWnd* pParent /*=NULL*/)
	: CDialog(CCharacterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCharacterDialog)
	m_string = _T("hello");
	
	//}}AFX_DATA_INIT
	nPos=20;

	this->str=str;
	this->size=size;
}


void CCharacterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharacterDialog)
	DDX_Control(pDX, IDC_SLIDER, m_slider);
	DDX_Text(pDX, IDC_EDIT, m_string);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCharacterDialog, CDialog)
	//{{AFX_MSG_MAP(CCharacterDialog)
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, OnCustomdrawSlider)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharacterDialog message handlers

void CCharacterDialog::OnButton() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	* size=nPos;
	* str=m_string;

	OnOK();
	
}

void CCharacterDialog::OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	 nPos = m_slider.GetPos(); //获得滑块的当前位置
	
	
	//另外做一个编辑框 显示所调节的数据；
	CString str="";
	str.Format("%d",nPos);
	SetDlgItemText(IDC_EDITSIZE,str);



	
	*pResult = 0;
}

BOOL CCharacterDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_slider.SetRange(2,40);
	m_slider.SetPos(20);
	CMenu*   pTopMenu   = this->GetSystemMenu(FALSE); 

    pTopMenu->ModifyMenu(SC_CLOSE,MF_BYCOMMAND | MF_GRAYED );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


