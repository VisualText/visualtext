// VisualTextDoc.h : interface of the CVisualTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GUI_VISUALSTUDIO6DOC_H__E35628EB_7747_4FEF_8BC8_6D26AFB83243__INCLUDED_)
#define AFX_GUI_VISUALSTUDIO6DOC_H__E35628EB_7747_4FEF_8BC8_6D26AFB83243__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVisualTextDoc : public CDocument
{
protected: // create from serialization only
	CVisualTextDoc();
	DECLARE_DYNCREATE(CVisualTextDoc)

// Attributes
public:
	CONCEPT *m_concept;
	DOC_TYPE m_DocType;
	BOOL m_bPromptSaveModified; //SRP 2001-02-01

// Operations
public:
	void Update();
	void ChangeType(DOC_TYPE docType);
	void UpdateDocviewContent();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVisualTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVisualTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVisualTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUI_VISUALSTUDIO6DOC_H__E35628EB_7747_4FEF_8BC8_6D26AFB83243__INCLUDED_)
