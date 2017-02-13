/**
 * \file BugDemoDlg.h
 * The bug demostration dialog box class
 * \author Charles Owen
 */


#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#include "BugDemoView.h"

/**
 * The bug demonstration dialog box class
 */
class CBugDemoDlg : public CDialogEx
{
public:
	CBugDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_BUGDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;  ///< Icon handle

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnBnClickedButtonnewbug();

private:
    int mFrameNum = 0;      ///< Frame number, assumed 30 frames per second
    double mBendAngle = 0;  ///< Wind speed in mile per hour

    void UpdateUI();
    CSliderCtrl mTimeSlider;    ///< The time/frame slider
    CStatic mFrame;             ///< Current frame
        
    CBugDemoView mBugView;    ///< The bug viewer window
    CSliderCtrl mBendSlider;    ///< The bend slider
   
    CStatic mSeedView;          ///< View were we put the bug seed

public:
    afx_msg void OnBnClickedButtonharvest();
    afx_msg void OnBnClickedButtonempty();
};
