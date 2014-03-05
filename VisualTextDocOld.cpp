// VisualTextDoc.cpp : implementation of the CVisualTextDoc class
//

#include "stdafx.h"
#include "kb.h"
#include "Utils.h"
#include "VisualText.h"
#include "VisualTextView.h"
#include "VisualTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVisualTextDoc

IMPLEMENT_DYNCREATE(CVisualTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CVisualTextDoc, CDocument)
	//{{AFX_MSG_MAP(CVisualTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVisualTextDoc construction/destruction

CVisualTextDoc::CVisualTextDoc()
{
	// TODO: add one-time construction code here

}

CVisualTextDoc::~CVisualTextDoc()
{
}

BOOL CVisualTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVisualTextDoc serialization

void CVisualTextDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CVisualTextDoc diagnostics

#ifdef _DEBUG
void CVisualTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVisualTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CVisualTextDoc commands

void CVisualTextDoc::UpdateDocviewContent()
{
	CVisualTextView *docView = (CVisualTextView *)GetFirstView(this);
	long scrollPos = docView->GetRichEditCtrl().GetFirstVisibleLine();

	CString textStr = NLPReadFile(GetPathName());
	docView->SetWindowText(textStr);
	docView->UpdateWindow();

	docView->Scroll(scrollPos);
	if (m_DocType == DOC_RULE)
		docView->FormatAll();

	docView->GetRichEditCtrl().SetModify(false);
}

void CVisualTextDoc::ChangeType(DOC_TYPE docType) 
{
	m_DocType = docType;
	CString titleStr = StripPath(GetPathName(),0);
	ClipRight(titleStr,4);  // TRIM OFF .TXT
	SetTitle(titleStr);
	CVisualTextView *docView = (CVisualTextView *)GetFirstView(this);

	//PD 02/22/2001
	// crash protection
	if (!docView)
		return;

	docView->SetIconType();
}

void CVisualTextDoc::Update() 
{
	CVisualTextView *docView = (CVisualTextView *)GetFirstView(this);

	//PD 02/22/2001
	// crash protection
	if (!docView)
		return;

	int scrollPos = docView->GetRichEditCtrl().GetFirstVisibleLine();
	//CString textStr = NLPReadFile(GetPathName(),true);
	const CString pathNameStr = GetPathName();
	CString textStr = NLPReadFile(pathNameStr);
	docView->SetWindowText(textStr);
	docView->UpdateWindow();
	docView->Scroll(scrollPos);
	if (m_DocType == DOC_RULE)
		docView->FormatAll();
	docView->GetRichEditCtrl().SetModify(false);
}