//*******************************************************************************
// COPYRIGHT NOTES
// ---------------
// This is a sample for BCGControlBar Library Professional Edition
// Copyright (C) 1998-2018 BCGSoft Ltd.
// All rights reserved.
//
// This source code can be used, distributed or modified
// only under terms and conditions 
// of the accompanying license agreement.
//*******************************************************************************
//
// BackStagePagePrint.cpp : implementation file
//

#include "stdafx.h"
#include "bcgporganizer.h"
#include "BackStagePagePrint.h"
#include "BCGPOrganizerDoc.h"
#include "Views/CalendarPlannerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackStagePagePrint

IMPLEMENT_DYNCREATE(CBackStagePagePrint, CBCGPRibbonBackstagePagePrint)

CBackStagePagePrint::CBackStagePagePrint(CWnd* pParent /*=NULL*/)
	: CBCGPRibbonBackstagePagePrint(CBackStagePagePrint::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBackStagePagePrint)
	//}}AFX_DATA_INIT

	m_bIsLocal = FALSE;
}

CBackStagePagePrint::~CBackStagePagePrint()
{
}

void CBackStagePagePrint::DoDataExchange(CDataExchange* pDX)
{
	CBCGPRibbonBackstagePagePrint::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBackStagePagePrint)
	DDX_Control(pDX, IDC_BS_PRINT_TYPE, m_wndType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBackStagePagePrint, CBCGPRibbonBackstagePagePrint)
	//{{AFX_MSG_MAP(CBackStagePagePrint)
	ON_COMMAND(IDC_BS_PRINT_TYPE, OnSelectType)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CBackStagePagePrint message handlers

BOOL CBackStagePagePrint::OnInitDialog() 
{
	CBCGPRibbonBackstagePagePrint::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBackStagePagePrint::InitializePrintInfo()
{
	CBCGPRibbonBackstagePagePrint::InitializePrintInfo();
	CBCGPRibbonBackstagePagePrint::s_BCGPrintInfo.lpParam = NULL;
}

BOOL CBackStagePagePrint::PreparePrintInfo()
{
	if (!CBCGPRibbonBackstagePagePrint::PreparePrintInfo())
	{
		return FALSE;
	}

	return TRUE;
}

void CBackStagePagePrint::OnInitPrintControls()
{
	CFrameWnd* pFrame = DYNAMIC_DOWNCAST(CFrameWnd, AfxGetApp ()->GetMainWnd ());
	if (pFrame != NULL)
	{
		if (pFrame->IsKindOf (RUNTIME_CLASS(CMDIFrameWnd)))
		{
			pFrame = ((CMDIFrameWnd*)pFrame)->GetActiveFrame ();
		}
	}

	CBCGPRibbonBackstagePagePrint::OnInitPrintControls();
}

void CBackStagePagePrint::OnSelectType()
{
	if (!m_wndType.IsWindowVisible ())
	{
		return;
	}

	switch (m_wndType.GetCurSel ())
	{
	case 0:
		CBCGPRibbonBackstagePagePrint::s_BCGPrintInfo.lpParam = (LPVOID)RUNTIME_CLASS(CBCGPPlannerPrintDay);
		break;
	case 1:
		CBCGPRibbonBackstagePagePrint::s_BCGPrintInfo.lpParam = (LPVOID)RUNTIME_CLASS(CBCGPPlannerPrintWeek);
		break;
	case 2:
		CBCGPRibbonBackstagePagePrint::s_BCGPrintInfo.lpParam = (LPVOID)RUNTIME_CLASS(CBCGPPlannerPrintMonth);
		break;
	case 3:
		CBCGPRibbonBackstagePagePrint::s_BCGPrintInfo.lpParam = (LPVOID)RUNTIME_CLASS(CBCGPPlannerPrintDual);
		break;
	}

	if (m_wndPreview->GetSafeHwnd () != NULL)
	{
		m_wndPreview->ChangeSettings ();
	}
}
