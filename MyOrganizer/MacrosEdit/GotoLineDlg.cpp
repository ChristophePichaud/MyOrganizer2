//
// GotoLineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "../BCGPOrganizer.h"
#include "GotoLineDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGotoLineDlg dialog


CGotoLineDlg::CGotoLineDlg(CWnd* pParent /*=NULL*/)
	: CBCGPDialog(CGotoLineDlg::IDD, pParent)
{
	EnableVisualManagerStyle (TRUE, TRUE);

	//{{AFX_DATA_INIT(CGotoLineDlg)
	m_nLineNumber = 1;
	//}}AFX_DATA_INIT
}


void CGotoLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CBCGPDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGotoLineDlg)
	DDX_Text(pDX, IDC_GOTO_LINE_LINE, m_nLineNumber);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGotoLineDlg, CBCGPDialog)
	//{{AFX_MSG_MAP(CGotoLineDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGotoLineDlg message handlers
