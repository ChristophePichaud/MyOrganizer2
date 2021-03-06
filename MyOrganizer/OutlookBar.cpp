
//
// ShortcutsBar.cpp : implementation file
//

#include "stdafx.h"
#include "OutlookBar.h"
#include "BCGPOrganizer.h"
#include "BCGPOrganizerDoc.h"
#include "ShortcutsBar.h"
#include "mainfrm.h"

#ifndef _BCGSUITE_INC_
#include "BCGPOutlookBarDockingPane.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE (COutlookWnd, CBCGPOutlookWnd)

BOOL COutlookWnd::SetToolbarImageList (HIMAGELIST hImageList)
{
	if (!IsMode2003 ())
	{
		ASSERT (FALSE);
		return FALSE;
	}

	if (m_imagesToolbar.GetSafeHandle () != NULL)
	{
		m_imagesToolbar.DeleteImageList ();
	}

	CImageList* pImageList = CImageList::FromHandle (hImageList);
	if (pImageList == NULL)
	{
		ASSERT (FALSE);
		return FALSE;
	}

	m_imagesToolbar.Attach (hImageList);

	IMAGEINFO info;
	pImageList->GetImageInfo (0, &info);

	CRect rectImage = info.rcImage;
	m_sizeToolbarImage = rectImage.Size ();

	return TRUE;
}

BEGIN_MESSAGE_MAP (COutlookWnd, CBCGPOutlookWnd)
END_MESSAGE_MAP ()

/////////////////////////////////////////////////////////////////////////////
// COutlookBar

IMPLEMENT_DYNAMIC(COutlookBar, CBCGPOutlookBar)

COutlookBar::COutlookBar()
{
}

COutlookBar::~COutlookBar()
{
}

BOOL COutlookBar::Create (LPCTSTR lpszCaption, CWnd* pParentWnd, 
							const RECT& rect, UINT nID, DWORD dwStyle, 
							DWORD dwBCGStyle/* = CBRS_BCGP_RESIZE*/, 
							CCreateContext* pContext/* = NULL*/)
{
	CBCGPOutlookWnd::EnableAnimation (TRUE);

	SetMode2003 (TRUE);

	if (!CBCGPOutlookBar::Create (lpszCaption, pParentWnd, rect, 
		nID, dwStyle, dwBCGStyle, pContext))
	{
		TRACE0("Failed to create shortcut bar\n");
		return FALSE;      // fail to create
	}

	COutlookWnd* pShortcutsBarContainer = DYNAMIC_DOWNCAST (COutlookWnd, 
							GetUnderlinedWindow ());
	if (pShortcutsBarContainer == NULL)
	{
		TRACE0("Cannot get outlook bar container\n");
		return FALSE;
	}

	if (!m_wndTasksBar.Create (this, IDC_SHORTCUTSBAR_TASKS))
	{
		TRACE0("Failed to create tasks tab\n");
		return FALSE;      // fail to create
	}
	pShortcutsBarContainer->AddTab (&m_wndTasksBar, c_ViewNames[CBCGPOrganizerDoc::e_ModeTasks], CBCGPOrganizerDoc::e_ModeTasks, FALSE);

	if (!m_wndMacrosBar.Create (this, IDC_SHORTCUTSBAR_MACROS))
	{
		TRACE0("Failed to create macros tab\n");
		return FALSE;      // fail to create
	}
	pShortcutsBarContainer->AddTab (&m_wndMacrosBar, c_ViewNames[CBCGPOrganizerDoc::e_ModeMacros], CBCGPOrganizerDoc::e_ModeMacros, FALSE);
	
	SetButtonsFont (&globalData.fontBold);
	EnableSetCaptionTextToTabName (TRUE);

#ifndef _BCGSUITE_INC_
	pShortcutsBarContainer->UseAlphaBlendIcons ();
#endif

//	SetMode2003(TRUE);

	CBCGPPngImage pngLarge;
	if (pngLarge.Load (IDB_SHORTCUTS_LARGE))
	{
		CBCGPToolBarImages::PreMultiplyAlpha((HBITMAP)pngLarge.GetSafeHandle(), FALSE);

		CImageList il;
		il.Create (24, 22, ILC_COLOR32, 10, 1);
		il.Add (&pngLarge, (CBitmap*) NULL);
		pShortcutsBarContainer->SetImageList (il.Detach ());
	}

	CBCGPPngImage pngSmall;
	if (pngSmall.Load (IDB_SHORTCUTS_SMALL))
	{
		CBCGPToolBarImages::PreMultiplyAlpha((HBITMAP)pngSmall.GetSafeHandle(), FALSE);

		CImageList il;
		il.Create (16, 16, ILC_COLOR32, 10, 1);
		il.Add (&pngSmall, (CBitmap*) NULL);
		pShortcutsBarContainer->SetToolbarImageList (il.Detach ());
	}

	CRect rectBar;
	GetWindowRect (rectBar);
	SetMinSize (rectBar.Size ());
	RecalcLayout ();

	return TRUE;
}


BEGIN_MESSAGE_MAP(COutlookBar, CBCGPOutlookBar)
	//{{AFX_MSG_MAP(COutlookBar)
	ON_WM_CREATE()
	ON_REGISTERED_MESSAGE(BCGM_CALENDAR_ON_SELCHANGED, OnCalendarSelChanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutlookBar diagnostics

#ifdef _DEBUG
void COutlookBar::AssertValid() const
{
	CBCGPOutlookBar::AssertValid();
}

void COutlookBar::Dump(CDumpContext& dc) const
{
	CBCGPOutlookBar::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COutlookBar message handlers

int COutlookBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CBCGPBaseTabbedBar::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rectClient (0, 0, lpCreateStruct->cx, lpCreateStruct->cy);

	ASSERT (m_pTabWnd == NULL);
	m_pTabWnd = new COutlookWnd;

	COutlookWnd* pTabWnd = (COutlookWnd*) m_pTabWnd;

	// enable this before create,a s it may change inside for dialog applications
	pTabWnd->m_bEnableWrapping = TRUE;
	
	// Create tabs window:
	if (!pTabWnd->Create (rectClient, this, 101))
	{
		TRACE0("Failed to create tab window\n");
		delete m_pTabWnd;
		m_pTabWnd = NULL;
		return -1;      // fail to create
	}
	
#ifndef _BCGSUITE_INC_
	pTabWnd->SetDockingBarWrapperRTC (RUNTIME_CLASS (CBCGPOutlookBarDockingPane));
#endif

	if (CanFloat ())
	{
		pTabWnd->HideSingleTab ();
	}

	return 0;
}

LRESULT COutlookBar::OnCalendarSelChanged(WPARAM, LPARAM)
{
	return 0;
}
