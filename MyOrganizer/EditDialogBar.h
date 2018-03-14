#if !defined(AFX_EDITDIALOGBAR_H__AD5DA710_5842_45F5_88FB_8D8F27936E97__INCLUDED_)
#define AFX_EDITDIALOGBAR_H__AD5DA710_5842_45F5_88FB_8D8F27936E97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditDialogBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditDialogBar window

class CEditDialogBar: public CBCGPDialogBar
{
	DECLARE_SERIAL(CEditDialogBar)

public:
	CEditDialogBar ();
	virtual ~CEditDialogBar ();

protected:
	virtual BOOL OnInitDialogBar();

protected:
	afx_msg LRESULT HandleInitDialog(WPARAM wParam, LPARAM lParam);
	afx_msg void OnUpdateDummy(CCmdUI* /*pCmdUI*/) {}
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDIALOGBAR_H__AD5DA710_5842_45F5_88FB_8D8F27936E97__INCLUDED_)
