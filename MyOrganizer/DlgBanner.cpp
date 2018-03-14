//
// DlgBanner.cpp : implementation file
//

#include "stdafx.h"
#include "BCGPOrganizer.h"
#include "DlgBanner.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBanner

CDlgBanner::CDlgBanner()
{
}

CDlgBanner::~CDlgBanner()
{
}


BEGIN_MESSAGE_MAP(CDlgBanner, CBCGPStatic)
	//{{AFX_MSG_MAP(CDlgBanner)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBanner message handlers

void CDlgBanner::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect rect;
	GetClientRect (rect);

	CFont* pOldFont = dc.SelectObject (&globalData.fontBold);
	ASSERT (pOldFont != NULL);

#ifdef _BCGSUITE_INC_
	dc.SetTextColor (CMFCVisualManager::GetInstance ()->OnDrawMenuLabel (&dc, rect));
#else
	dc.SetTextColor (CBCGPVisualManager::GetInstance ()->OnDrawMenuLabel (&dc, rect));
#endif
	dc.SetBkMode (TRANSPARENT);

	rect.DeflateRect (5, 0);

	CString strText;
	GetWindowText (strText);

	dc.DrawText (strText, rect, DT_LEFT | DT_SINGLELINE | DT_VCENTER);

	dc.SelectObject (pOldFont);
}
