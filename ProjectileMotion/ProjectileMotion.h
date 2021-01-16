
// ProjectileMotion.h : main header file for the ProjectileMotion application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProjectileMotionApp:
// See ProjectileMotion.cpp for the implementation of this class
//

class CProjectileMotionApp : public CWinAppEx
{
public:
	CProjectileMotionApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProjectileMotionApp theApp;
