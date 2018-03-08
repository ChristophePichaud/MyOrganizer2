// TaskAndCodeView.cpp : implementation of the CTaskAndCodeView class
//

#include "stdafx.h"
#include "TaskAndCode.h"

#include "TaskAndCodeDoc.h"
#include "TaskAndCodeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTaskAndCodeView

IMPLEMENT_DYNCREATE(CTaskAndCodeView, CView)

BEGIN_MESSAGE_MAP(CTaskAndCodeView, CView)
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_MESSAGE(WM_PRINTCLIENT, OnPrintClient)
	ON_REGISTERED_MESSAGE(BCGM_CHANGEVISUALMANAGER, OnChangeVisualManager)
END_MESSAGE_MAP()

// CTaskAndCodeView construction/destruction

CTaskAndCodeView::CTaskAndCodeView()
{
	// TODO: add construction code here

}

CTaskAndCodeView::~CTaskAndCodeView()
{
}

BOOL CTaskAndCodeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTaskAndCodeView drawing

void CTaskAndCodeView::OnDraw(CDC* /*pDC*/)
{
	CTaskAndCodeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}


// CTaskAndCodeView printing

void CTaskAndCodeView::OnFilePrintPreview()
{
	BCGPPrintPreview (this);
}

BOOL CTaskAndCodeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTaskAndCodeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTaskAndCodeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTaskAndCodeView diagnostics

#ifdef _DEBUG
void CTaskAndCodeView::AssertValid() const
{
	CView::AssertValid();
}

void CTaskAndCodeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTaskAndCodeDoc* CTaskAndCodeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTaskAndCodeDoc)));
	return (CTaskAndCodeDoc*)m_pDocument;
}
#endif //_DEBUG


// CTaskAndCodeView message handlers

LRESULT CTaskAndCodeView::OnPrintClient(WPARAM wp, LPARAM lp)
{
	if ((lp & PRF_CLIENT) == PRF_CLIENT)
	{
		CDC* pDC = CDC::FromHandle((HDC) wp);
		ASSERT_VALID(pDC);
		
		OnDraw(pDC);
	}
	
	return 0;
}

LRESULT CTaskAndCodeView::OnChangeVisualManager(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	return 0;
}

void CTaskAndCodeView::OnContextMenu(CWnd*, CPoint point)
{
	if (CBCGPPopupMenu::GetSafeActivePopupMenu() != NULL)
	{
		return;
	}

	theApp.ShowPopupMenu(IDR_CONTEXT_MENU, point, this);
}
