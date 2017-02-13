/**
 * \file BugSeedDlg.h
 *
 * \author Charles Owen
 *
 * Class that implements a dialog box for bug seeds
 */

#pragma once

#include <memory>

class CBug;

/**
* Exported dialog box class for entering a bug seed
*
* You can't open a Dialog Box from a remote DLL, so
* this class is a wrapper that creates and calls DoModal
* on the dialog box in this class.
*
* You are not allowed to change this class in any way!
*
* AFX_EXT_CLASS is a Microsoft directive that indicates
* that this class can be used outside the DLL. Do not change
* it or add it to any other classes.
*/
class AFX_EXT_CLASS CBugSeedDlg
{
public:
    /**
     * Constructor
     * \param bug Bug we are editing the seed for 
     */
    CBugSeedDlg(std::shared_ptr<CBug> bug);
    INT_PTR DoModal();

private:
    /// Bug we are editing
    std::shared_ptr<CBug> mBug;
};

/**
 * Dialog box class for entering a Bug Seed.
 *
 * This is the actual MFC dialog box class.
 *
 * \cond
 */
class CBugSeedActualDlg : public CDialog
{
	DECLARE_DYNAMIC(CBugSeedActualDlg)

public:
	CBugSeedActualDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBugSeedActualDlg();

    virtual INT_PTR DoModal() override;

    int GetSeed() { return mSeed; }
    void SetSeed(int seed) { mSeed = seed; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonrandom();

private:
    int mSeed = 99;

    CBrush mBrushBack;

public:
    virtual BOOL OnInitDialog();
    afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

/// \endcond
