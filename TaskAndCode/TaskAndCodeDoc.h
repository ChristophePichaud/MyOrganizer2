// TaskAndCodeDoc.h : interface of the CTaskAndCodeDoc class
//


#pragma once


class CTaskAndCodeDoc : public CDocument
{
protected: // create from serialization only
	CTaskAndCodeDoc();
	DECLARE_DYNCREATE(CTaskAndCodeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CTaskAndCodeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


