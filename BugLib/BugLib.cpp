/**
 * \file BugLib.cpp
 *
 * \author Charles Owen
 */


#include "stdafx.h"
#include "BugLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


BEGIN_MESSAGE_MAP(CBugLibApp, CWinApp)
END_MESSAGE_MAP()


/**
 * Constructor
 */
CBugLibApp::CBugLibApp()
{
}


/// The one and only CBugLibApp object
CBugLibApp theApp;


/**
 * CBugLibApp initialization
 * \returns 
 */
BOOL CBugLibApp::InitInstance()
{
	CWinApp::InitInstance();
    srand((unsigned int)time(nullptr));
	return TRUE;
}

