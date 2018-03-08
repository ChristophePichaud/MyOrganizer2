// TaskAndCode.h : main header file for the TaskAndCode application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CTaskAndCodeApp:
// See TaskAndCode.cpp for the implementation of this class
//

class CTaskAndCodeApp : public CBCGPWinApp
{
public:
	CTaskAndCodeApp();

	// Override from CBCGPWorkspace
	virtual void PreLoadState ();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	virtual BOOL SaveAllModified();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTaskAndCodeApp theApp;