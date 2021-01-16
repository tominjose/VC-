
// ProjectileMotionView.cpp : implementation of the CProjectileMotionView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ProjectileMotion.h"
#endif

#include "ProjectileMotionDoc.h"
#include "ProjectileMotionView.h"
#include "Motion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CMotionThread.cpp"


// CProjectileMotionView

IMPLEMENT_DYNCREATE(CProjectileMotionView, CView)

BEGIN_MESSAGE_MAP(CProjectileMotionView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CProjectileMotionView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_THREAD_START, &CProjectileMotionView::OnThreadStart)
	ON_COMMAND(ID_THREAD_PAUSE, &CProjectileMotionView::OnThreadPause)
	ON_COMMAND(ID_THREAD_RESUME, &CProjectileMotionView::OnThreadResume)
END_MESSAGE_MAP()

// CProjectileMotionView construction/destruction

CProjectileMotionView:: CProjectileMotionView()
{
	 m_iCounter = 0;

}



BOOL CProjectileMotionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CProjectileMotionView drawing

void CProjectileMotionView::OnDraw(CDC* pDC)
{
	CProjectileMotionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_iCounter++;
	CString strCounter;
	strCounter.Format(L"The Counter i %d", m_iCounter);
	pDC->TextOut(100, 100, strCounter);
	pDC->MoveTo(100, 250);
	pDC->LineTo(450, 250);
	pDC->MoveTo(100, 250);
	pDC->LineTo(100, 10);
}


// CProjectileMotionView printing


void CProjectileMotionView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CProjectileMotionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CProjectileMotionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CProjectileMotionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CProjectileMotionView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CProjectileMotionView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CProjectileMotionView diagnostics

#ifdef _DEBUG
void CProjectileMotionView::AssertValid() const
{
	CView::AssertValid();
}

void CProjectileMotionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProjectileMotionDoc* CProjectileMotionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProjectileMotionDoc)));
	return (CProjectileMotionDoc*)m_pDocument;
}
#endif //_DEBUG


// CProjectileMotionView message handlers


void CProjectileMotionView::OnThreadStart()
{
	pThread = AfxBeginThread(CMotionThread::RunThreadFunction, this);
}


void CProjectileMotionView::OnThreadPause()
{
	pThread->SuspendThread();
}


void CProjectileMotionView::OnThreadResume()
{
	pThread->ResumeThread();
}
