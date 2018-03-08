// TaskAndCodeView.h : interface of the CTaskAndCodeView class
//


#pragma once


class CTaskAndCodeView : public CView
{
protected: // create from serialization only
	CTaskAndCodeView();
	DECLARE_DYNCREATE(CTaskAndCodeView)

// Attributes
public:
	CTaskAndCodeDoc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTaskAndCodeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg void OnFilePrintPreview();
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnChangeVisualManager(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TaskAndCodeView.cpp
inline CTaskAndCodeDoc* CTaskAndCodeView::GetDocument() const
   { return reinterpret_cast<CTaskAndCodeDoc*>(m_pDocument); }
#endif

