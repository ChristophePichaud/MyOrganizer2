//
// BCGPOrganizer.h : main header file for the BCGPORGANIZER application
//

#if !defined(AFX_BCGPORGANIZER_H__657998E0_5998_44A5_9B2F_4973B19BCEF9__INCLUDED_)
#define AFX_BCGPORGANIZER_H__657998E0_5998_44A5_9B2F_4973B19BCEF9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class CPlannerOptions
{
public:
	CPlannerOptions();

	COLORREF			m_clrBackground;
	CBCGPPlannerManagerCtrl::BCGP_PLANNER_TYPE
						m_Type;
	int					m_ShowToolTip;	// 0 - don't show, 1 - standard, 2 - advanced
	DWORD				m_DrawFlags;
	BOOL				m_DefaultImages;
	BOOL				m_DefaultClockIcons;
	BOOL				m_DefaultUpDownIcons;
	int					m_WorkFirstDayOfWeek;
	double				m_WorkHourFirst;
	double				m_WorkHourLast;
	int 				m_ViewHourFirst;
	int 				m_ViewHourLast;
	CBCGPPlannerView::BCGP_PLANNER_TIME_DELTA
						m_DayTimeDelta;
	BOOL				m_WeekDrawTimeFinish;
	BOOL				m_WeekDrawTimeIcons;
	BOOL				m_MonthDrawTimeFinish;
	BOOL				m_MonthDrawTimeIcons;
	BOOL				m_MonthCompressWeekend;

	BOOL				m_CalendarGradientFill;
	BOOL				m_CalendarWeekNumbers;

	BOOL				m_bImagesChanged;
	BOOL				m_bClockIconsChanged;
	BOOL				m_bUpDownIconsChanged;

	void Load ();
	void Save ();
};

class CGanttOptions
{
public:
	CGanttOptions();

	COLORREF			m_clrBackground;
	int					m_ShowToolTip;	// 0 - don't show, 1 - standard, 2 - advanced

	void Load ();
	void Save ();
};

/////////////////////////////////////////////////////////////////////////////
// CBCGPOrganizerApp:
// See BCGPOrganizer.cpp for the implementation of this class
//

class CBCGPOrganizerApp : public CBCGPWinApp
{
public:
	CBCGPOrganizerApp();

	// Override from CBCGPWorkspace
	virtual void PreLoadState ();

	BOOL	m_bShowFloaty;
	BOOL	m_bShowToolTips;
	BOOL	m_bShowToolTipDescr;
	BOOL	m_bShowKeyTips;	
	int		m_nBackgroundImage;

	const CBCGPAppOptions& GetAppOptions() const
	{
		return m_AppOptions;
	}

// Overrides
	virtual void OnBeforeChangeVisualTheme(CBCGPAppOptions& appOptions, CWnd* pMainWnd);
	virtual void OnAfterChangeVisualTheme(CWnd* pMainWnd);

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBCGPOrganizerApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBCGPOrganizerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CPlannerOptions	m_OptionsPlanner;
	CGanttOptions	m_OptionsGantt;
};


extern CBCGPOrganizerApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BCGPORGANIZER_H__657998E0_5998_44A5_9B2F_4973B19BCEF9__INCLUDED_)
