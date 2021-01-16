 
// ProjectileMotionView.h : interface of the CProjectileMotionView class
//

#pragma once
#include "ProjectileMotionDoc.cpp"


class CProjectileMotionView : public CView
{
protected: // create from serialization only
	CProjectileMotionView() ;
	DECLARE_DYNCREATE(CProjectileMotionView)
	CWinThread* pThread;
// Attributes
public:
	CProjectileMotionDoc* GetDocument() const;

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
	virtual ~CProjectileMotionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnThreadStart();
	afx_msg void OnThreadPause();
	afx_msg void OnThreadResume();

public :
	long m_iCounter;

};


#ifndef _DEBUG  // debug version in ProjectileMotionView.cpp
inline CProjectileMotionDoc* CProjectileMotionView::GetDocument() const
   { return reinterpret_cast<CProjectileMotionDoc*>(m_pDocument); }
#endif

