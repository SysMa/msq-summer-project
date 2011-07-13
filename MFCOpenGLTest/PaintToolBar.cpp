// PaintToolBar.cpp : implementation file
//

#include "stdafx.h"
#include "PaintToolbar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaintToolbar

CPaintToolbar::CPaintToolbar()
{
}

CPaintToolbar::~CPaintToolbar()
{
}


BEGIN_MESSAGE_MAP(CPaintToolbar, CToolBar)
	//{{AFX_MSG_MAP(CPaintToolbar)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaintToolbar message handlers


void CPaintToolbar::SetColumns(UINT nColumns)
{
	m_nColumns = nColumns;
	int nCount = GetToolBarCtrl().GetButtonCount();

	for (int i = 0; i < nCount; i++)
	{
		UINT nStyle = GetButtonStyle(i);
		BOOL bWrap = (((i + 1) % nColumns) == 0);
		if (bWrap)
		{
			nStyle |= TBBS_WRAPPED;
		}
		else
		{
			nStyle &= ~TBBS_WRAPPED;
		}
		SetButtonStyle(i,nStyle);
	}
	Invalidate();
	GetParentFrame()->RecalcLayout();
}
