/**
 * \file BugSeedDlg.cpp
 *
 * \author Charles Owen
 *
 * You are not allowed to change these classes in any way!
 *
*/

#include "stdafx.h"
#include "BugLib.h"
#include "BugSeedDlg.h"
#include "afxdialogex.h"
#include "Bug.h"


/**
 * Open the dialog box as a modal dialog box
 * \returns Dialog box return value
 */
INT_PTR CBugSeedDlg::DoModal()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());
    CBugSeedActualDlg dlg;
    dlg.SetSeed(mBug->GetSeed());
    INT_PTR ret = dlg.DoModal();
    if (ret == IDOK)
    {
        int seed = dlg.GetSeed();
        mBug->SetSeed(seed);
    }
    return ret;
}



/** \cond */
IMPLEMENT_DYNAMIC(CBugSeedActualDlg, CDialog)

CBugSeedActualDlg::CBugSeedActualDlg(CWnd* pParent /*=NULL*/)
    : CDialog(IDD_BUGDLG, pParent), mBrushBack(RGB(255, 255, 255))
{

}

INT_PTR CBugSeedActualDlg::DoModal()
{
   // 
    return CDialog::DoModal();
}

CBugSeedActualDlg::~CBugSeedActualDlg()
{
}

void CBugSeedActualDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDITSEED, mSeed);
}


BEGIN_MESSAGE_MAP(CBugSeedActualDlg, CDialog)
    ON_BN_CLICKED(IDC_BUTTONRANDOM, &CBugSeedActualDlg::OnBnClickedButtonrandom)
    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

/**
 * Constructor
 */
CBugSeedDlg::CBugSeedDlg(std::shared_ptr<CBug> bug) : mBug(bug)
{

}


void CBugSeedActualDlg::OnBnClickedButtonrandom()
{
    mSeed = rand();
    UpdateData(false);
}




BOOL CBugSeedActualDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}


HBRUSH CBugSeedActualDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hBrush = NULL;
    switch (nCtlColor)
    {
    case CTLCOLOR_DLG:
        // just return a not NULL brush handle
        hBrush = (HBRUSH)mBrushBack;
        break;

    default:
        // do the default processing
        hBrush = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
        break;
    }
    return hBrush;
}

/** \endcond */
