//
// TasksBar.cpp : implementation file
//

#include "stdafx.h"
#include "BCGPOrganizer.h"
#include "TasksBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTasksBar

CTasksBar::CTasksBar()
{
}

CTasksBar::~CTasksBar()
{
}

BOOL CTasksBar::Create(CWnd* pParentWnd, UINT nID)
{
	if (CBCGPTasksPane::Create (_T("Tasks"), pParentWnd, CRect (0, 0, 0, 0), FALSE, nID, WS_CHILD | WS_VISIBLE))
	{
		return TRUE;
	}

	return FALSE;
}


BEGIN_MESSAGE_MAP(CTasksBar, CBCGPTasksPane)
	//{{AFX_MSG_MAP(CTasksBar)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTasksBar message handlers

int CTasksBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CBCGPTasksPane::OnCreate(lpCreateStruct) == -1)
		return -1;

	SetIconsList (IDB_TASKS_ICONS, 16, (COLORREF)-1, TRUE);
	
	CRect rectDummy;
	rectDummy.SetRectEmpty ();

	const int nPage = 0;

	//------------
	// Add filter:
	//------------
	int nGroup1 = AddGroup (nPage, _T("Current View:"));

	AddTask (nGroup1, _T("Show Tasks"), 1, ID_TASKS_SHOW_TASKS);
	AddTask (nGroup1, _T("Show ToDo List"), 0, ID_TASKS_SHOW_TODO);
	AddTask (nGroup1, _T("Show All"), -1, ID_TASKS_SHOW_ALL);

	return 0;
}
