//
// ShortcutsView.cpp : implementation file
//

#include "stdafx.h"
#include "../BCGPOrganizer.h"
#include "../BCGPOrganizerDoc.h"
#include "../mainfrm.h"

#include "ShortcutsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShortcutsView

IMPLEMENT_DYNCREATE(CShortcutsView, CView)

BEGIN_MESSAGE_MAP(CShortcutsView, CView)
	//{{AFX_MSG_MAP(CShortcutsView)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND ()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
    ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
	ON_REGISTERED_MESSAGE(BCGM_ON_CLICK_WINUI_UI_TILE, OnClickTile)
	ON_REGISTERED_MESSAGE(BCGM_CHANGEVISUALMANAGER, OnChangeVisualManager)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShortcutsView construction/destruction

CShortcutsView::CShortcutsView()
{
	m_bIsDarkTheme = FALSE;
}

CShortcutsView::~CShortcutsView()
{
}

BOOL CShortcutsView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CShortcutsView drawing

BOOL CShortcutsView::OnEraseBkgnd(CDC*)
{
	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CShortcutsView diagnostics

#ifdef _DEBUG
void CShortcutsView::AssertValid() const
{
	CView::AssertValid();
}

void CShortcutsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBCGPOrganizerDoc* CShortcutsView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBCGPOrganizerDoc)));
	return (CBCGPOrganizerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShortcutsView message handlers

void CShortcutsView::OnDraw(CDC* /*pDC*/)
{

}

int CShortcutsView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	
	CRect rectClient;
	GetClientRect (rectClient);

	m_wndTiles.Create(rectClient, this, 1);

	CBCGPWinUITiles* pTiles = m_wndTiles.GetWinUITiles();
	ASSERT_VALID(pTiles);

	CBCGPImage image(IDB_HOME);
	pTiles->SetFillBrush(CBCGPBrush(image, CBCGPColor::White, TRUE), FALSE);
	pTiles->SetCaptionForegroundColor(CBCGPColor::SteelBlue);

	pTiles->SetCaption(_T("BCGControlBar Pro for MFC"), 10.0);

	CBCGPWinUITile* pTile1 = new CBCGPWinUITile(_T("Report"), CBCGPWinUITile::BCGP_TILE_REGULAR,
		CBCGPColor::White, CBCGPBrush(CBCGPColor::SteelBlue));
	pTile1->SetHeader(_T("Mail"));
	pTile1->SetText(_T("Open view with Report Control"));
	pTile1->SetBadgeGlyph(CBCGPWinUITile::BCGP_NEW_MESSAGE);
	pTile1->SetUserData(ID_ACTIVATE_VIEW_1);

	pTiles->Add(pTile1);
	
	CBCGPWinUITile* pTile2 = new CBCGPWinUITile(_T("Calendar"), CBCGPWinUITile::BCGP_TILE_REGULAR,
		CBCGPColor::White, CBCGPBrush(CBCGPColor::Teal));
	pTile2->SetHeader(_T("Calendar"));
	pTile2->SetText(_T("Open view with Calendar Control"));
	pTile2->SetUserData(ID_ACTIVATE_VIEW_2);
	
	pTiles->Add(pTile2);

	CBCGPWinUITile* pTile3 = new CBCGPWinUITile(_T("Database"), CBCGPWinUITile::BCGP_TILE_REGULAR,
		CBCGPColor::White, CBCGPBrush(CBCGPColor::Crimson));
	pTile3->SetHeader(_T("Database"));
	pTile3->SetText(_T("Open view with Database Grid Control"));
	pTile3->SetUserData(ID_ACTIVATE_VIEW_3);
	
	pTiles->Add(pTile3);

	CBCGPWinUITile* pTile4 = new CBCGPWinUITile(_T("Editor"), CBCGPWinUITile::BCGP_TILE_REGULAR,
		CBCGPColor::White, CBCGPBrush(CBCGPColor::DeepPink));
	pTile4->SetHeader(_T("Editor"));
	pTile4->SetText(_T("Open view with advanced Edit Control"));
	pTile4->SetUserData(ID_ACTIVATE_VIEW_4);
	
	pTiles->Add(pTile4);

	CBCGPWinUITile* pTile5 = new CBCGPWinUITile(_T("Gantt"), CBCGPWinUITile::BCGP_TILE_REGULAR,
		CBCGPColor::White, CBCGPBrush(CBCGPColor::DodgerBlue));
	pTile5->SetHeader(_T("Gantt"));
	pTile5->SetText(_T("Open view with Gantt Chart Control"));
	pTile5->SetBadgeGlyph(CBCGPWinUITile::BCGP_ALERT);
	pTile5->SetUserData(ID_ACTIVATE_VIEW_5);
	
	pTiles->Add(pTile5);

	CBCGPWinUITile* pTile6 = new CBCGPWinUITile(_T("BCGSoft"), CBCGPWinUITile::BCGP_TILE_REGULAR,
		CBCGPColor::White, CBCGPBrush(CBCGPColor::DarkOrange));
	pTile6->SetHeader(_T("Home"));
	pTile6->SetText(_T("Visit BCGSoft.com home page"));
	pTile6->SetUserData(ID_SHORTCUTS_HOME);
	
	pTiles->Add(pTile6);

	OnChangeVisualManager(0, 0);

	return 0;
}

LRESULT CShortcutsView::OnClickTile(WPARAM /*wp*/, LPARAM lp)
{
	CBCGPWinUITile* pClickedTile = (CBCGPWinUITile*)lp;
	ASSERT_VALID(pClickedTile);

	AfxGetMainWnd ()->PostMessage(WM_COMMAND, pClickedTile->GetUserData());

	return 0;
}

void CShortcutsView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);

	if (m_wndTiles.GetSafeHwnd () != NULL)
	{
		m_wndTiles.SetWindowPos (NULL, -1, -1, cx, cy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
	}
}

void CShortcutsView::UpdateCaptionText ()
{
	CBCGPOrganizerDoc* pDoc = GetDocument ();
	if (pDoc == NULL)
	{
		return;
	}

	CMainFrame* pFrame = DYNAMIC_DOWNCAST(CMainFrame, AfxGetMainWnd ());

	if (pFrame != NULL)
	{
		pFrame->SetCaptionText (_T("Designed by Pic"));
	}
}

void CShortcutsView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView) 
{
	CView::OnActivateView(bActivate, pActivateView, pDeactiveView);

	if (bActivate)
	{
		UpdateCaptionText ();
		OnChangeVisualManager(0, 0);
	}
}

LRESULT CShortcutsView::OnChangeVisualManager(WPARAM, LPARAM)
{
#ifndef _BCGSUITE_INC_
	BOOL bIsDarkTheme = theApp.GetVisualTheme() == CBCGPWinApp::BCGP_VISUAL_THEME_OFFICE_2016_BLACK;
	if (m_bIsDarkTheme == bIsDarkTheme)
	{
		return 0;
	}

	m_bIsDarkTheme = bIsDarkTheme;

	CBCGPWinUITiles* pTiles = m_wndTiles.GetWinUITiles();
	ASSERT_VALID(pTiles);

	if (m_bIsDarkTheme)
	{
		CBCGPImage image(IDB_HOME_DARK);
		pTiles->SetFillBrush(CBCGPBrush(image, RGB(54, 54, 54), TRUE), FALSE);
		pTiles->SetCaptionForegroundColor(CBCGPColor::SteelBlue);

		CBCGPVisualScrollBarColorTheme theme(CBCGPColor::DimGray);
		pTiles->SetScrollBarColorTheme(theme);
	}
	else
	{
		CBCGPImage image(IDB_HOME);
		pTiles->SetFillBrush(CBCGPBrush(image, CBCGPColor::White, TRUE), FALSE);
		pTiles->SetCaptionForegroundColor(CBCGPColor::SteelBlue);

		CBCGPVisualScrollBarColorTheme theme(CBCGPColor::WhiteSmoke);
		pTiles->SetScrollBarColorTheme(theme);
	}

	m_wndTiles.RedrawWindow();
#endif
	return 0;
}

void CShortcutsView::OnNcPaint()
{
    if ((GetStyle() & WS_BORDER) == 0 && (GetExStyle() & WS_EX_CLIENTEDGE) == 0)
    {
        Default();
        return;
    }
	
    CBCGPVisualManager::GetInstance()->OnDrawControlBorder(this);
}
