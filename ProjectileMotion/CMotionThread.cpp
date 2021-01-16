/// CMotionThread.cpp : implementation file
//

#include "pch.h"
#include "ProjectileMotion.h"
#include "CMotionThread.h"
#include "ProjectileMotionView.h"

// CMotionThread

IMPLEMENT_DYNCREATE(CMotionThread, CWinThread)

CMotionThread::CMotionThread()
{
}

CMotionThread::~CMotionThread()
{
}

BOOL CMotionThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CMotionThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMotionThread, CWinThread)
END_MESSAGE_MAP()


// CMotionThread message handlers
UINT CMotionThread::RunThreadFunction(LPVOID param)
{
	CProjectileMotionView* pProjectileMotionView = (CProjectileMotionView*)param;
	while (1)
	{
		pProjectileMotionView->m_iCounter++;
		pProjectileMotionView->Invalidate();
		Sleep(500);
	}
}