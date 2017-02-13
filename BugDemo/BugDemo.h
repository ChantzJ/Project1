/**
 * \file BugDemo.h
 * Header file for the BugDemo application class
 * \cond
 */
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

/**
 * BugDemo application class
 */
class CBugDemoApp : public CWinApp
{
public:
	CBugDemoApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()

private:
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
};

extern CBugDemoApp theApp;

/** \endcond */