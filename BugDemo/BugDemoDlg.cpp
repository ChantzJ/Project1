/**
 * \file BugDemoDlg.cpp
 *
 * \author Charles Owen
 */

#include "stdafx.h"
#include <string>
#include <sstream>

#include "BugDemo.h"
#include "BugDemoDlg.h"
#include "BugSeedDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

/// The bottom border below the bug window in pixels
const int BottomBorder = 100;

/// Maximum bend angle in radians
const double MaxBendAngle = 20;

/**
 * Constructor
 * \param pParent Parent window (optional)
 */
CBugDemoDlg::CBugDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBugDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

    srand((unsigned int)time(NULL));
}

/**
 * Exchange data between the dialog box and variables
 * \param pDX Data exchange object
 */
void CBugDemoDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_TIMESLIDER, mTimeSlider);
    DDX_Control(pDX, IDC_FRAME, mFrame);
    DDX_Control(pDX, IDC_BENDSLIDER, mBendSlider);
    DDX_Control(pDX, IDC_BUGSEED, mSeedView);
}

/** \cond */
BEGIN_MESSAGE_MAP(CBugDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_WM_HSCROLL()
    ON_WM_SIZE()
    ON_BN_CLICKED(IDC_BUTTONNEWBUG, &CBugDemoDlg::OnBnClickedButtonnewbug)
    ON_BN_CLICKED(IDC_BUTTONHARVEST, &CBugDemoDlg::OnBnClickedButtonharvest)
    ON_BN_CLICKED(IDC_BUTTONEMPTY, &CBugDemoDlg::OnBnClickedButtonempty)
END_MESSAGE_MAP()
/** \endcond */


/**
 * Initialize the dialog box
 * \returns TRUE on success
 */
BOOL CBugDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

    mTimeSlider.SetRange(0, 300, TRUE);
    mTimeSlider.SetPageSize(30);
    mTimeSlider.SetTicFreq(30);

    mBendSlider.SetRange(0, 100, TRUE);
    mBendSlider.SetPageSize(10);
    mBendSlider.SetTicFreq(10);

   // mBugView.SetSeed(2);

    CRect rect;
    GetClientRect(&rect);

    mBugView.Create(this, CRect(0, 0, rect.Width(), rect.Height() - BottomBorder), 1, WS_VISIBLE);

    UpdateUI();

	return TRUE;  // return TRUE  unless you set the focus to a control
}



/**
 * Paint the dialog box
 */
void CBugDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

/**
 * The system calls this function to obtain the cursor to display while the user drags
 * the minimized window. 
 * \return Cursor handle
 */
HCURSOR CBugDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





/**
 * Handle a horizontal scroll message
 * \param nSBCode Message code
 * \param nPos Position of the scroll
 * \param pScrollBar Source scroll bar object
 */
void CBugDemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
    mFrameNum = mTimeSlider.GetPos();
    mBendAngle = mBendSlider.GetPos() * MaxBendAngle / mBendSlider.GetRangeMax();
    UpdateUI();

    CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

/**
 * Update the user interface to match the current object state 
 */
void CBugDemoDlg::UpdateUI() 
{
    wstringstream str;
    str << "Frame: " << mFrameNum << endl;
    mFrame.SetWindowTextW(str.str().c_str());


    mBugView.SetFrame(mFrameNum);
    mBugView.SetBendAngle(mBendAngle);

    wstringstream str2;
    str2 << "Seed: " << mBugView.GetBug()->GetSeed() << endl;
    mSeedView.SetWindowTextW(str2.str().c_str());

}


/**
 * Handle a size message
 * \param nType Type of size request
 * \param cx New width
 * \param cy New height
 */
void CBugDemoDlg::OnSize(UINT nType, int cx, int cy)
{
    CDialogEx::OnSize(nType, cx, cy);

    CRect rect;
    GetClientRect(&rect);

    if (IsWindow(mBugView.m_hWnd)) {
        mBugView.MoveWindow(0, 0, rect.Width(), rect.Height() - BottomBorder);
    }
}
    


/**
 * Handle the New Bug button press
 */
void CBugDemoDlg::OnBnClickedButtonnewbug()
{
    CBugSeedDlg dlg(mBugView.GetBug());
    if (dlg.DoModal() == IDOK) {
        UpdateUI();
        mBugView.SetFrame(0);
        mBugView.SetFrame(mFrameNum);
    }
}

/**
 * Handle the Harvest button press 
 */
void CBugDemoDlg::OnBnClickedButtonharvest()
{
    mBugView.Harvest();
}

/**
 * Handle the Empty Basket button press
 */
void CBugDemoDlg::OnBnClickedButtonempty()
{
    mBugView.EmptyBasket();
}
