
// ClientCppSyncView.cpp : implementation of the CClientCppSyncView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ClientCppSync.h"
#endif

#include "ClientCppSyncDoc.h"
#include "ClientCppSyncView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientCppSyncView

IMPLEMENT_DYNCREATE(CClientCppSyncView, CView)

BEGIN_MESSAGE_MAP(CClientCppSyncView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CClientCppSyncView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CClientCppSyncView construction/destruction

CClientCppSyncView::CClientCppSyncView()
{
	// TODO: add construction code here

}

CClientCppSyncView::~CClientCppSyncView()
{
}

BOOL CClientCppSyncView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CClientCppSyncView drawing

void CClientCppSyncView::OnDraw(CDC* /*pDC*/)
{
	CClientCppSyncDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CClientCppSyncView printing


void CClientCppSyncView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CClientCppSyncView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CClientCppSyncView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CClientCppSyncView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CClientCppSyncView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CClientCppSyncView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CClientCppSyncView diagnostics

#ifdef _DEBUG
void CClientCppSyncView::AssertValid() const
{
	CView::AssertValid();
}

void CClientCppSyncView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClientCppSyncDoc* CClientCppSyncView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClientCppSyncDoc)));
	return (CClientCppSyncDoc*)m_pDocument;
}
#endif //_DEBUG


// CClientCppSyncView message handlers
