// TaskAndCodeDoc.cpp : implementation of the CTaskAndCodeDoc class
//

#include "stdafx.h"
#include "TaskAndCode.h"

#include "TaskAndCodeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTaskAndCodeDoc

IMPLEMENT_DYNCREATE(CTaskAndCodeDoc, CDocument)

BEGIN_MESSAGE_MAP(CTaskAndCodeDoc, CDocument)
END_MESSAGE_MAP()


// CTaskAndCodeDoc construction/destruction

CTaskAndCodeDoc::CTaskAndCodeDoc()
{
	// TODO: add one-time construction code here

}

CTaskAndCodeDoc::~CTaskAndCodeDoc()
{
}

BOOL CTaskAndCodeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CTaskAndCodeDoc serialization

void CTaskAndCodeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CTaskAndCodeDoc diagnostics

#ifdef _DEBUG
void CTaskAndCodeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTaskAndCodeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTaskAndCodeDoc commands
