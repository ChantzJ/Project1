/**
 * \file BugDemoView.h
 *
 * \author Charles Owen
 *
 * A view window that displays a single bug object
 */

#pragma once

#include <memory>
#include "Bug.h"
#include "Basket.h"

/**
 * A view window that displays a single bug object
 */
class CBugDemoView : public CWnd
{
	DECLARE_DYNAMIC(CBugDemoView)

public:
	CBugDemoView();
	virtual ~CBugDemoView();

    void SetFrame(int frame);
    void SetBendAngle(double speed);
    void SetSeed(int seed);

    void Harvest();
    void EmptyBasket();

    /**
     * Get the bug object
     * 
     * You are not allowed to do this in your adapter class!
     * \return CBug object
     */
    std::shared_ptr<CBug> GetBug() { return mBug; }

protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    BOOL Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle);

private:
    BOOL RegisterWindowClass();

    std::shared_ptr<CBug> mBug;       ///< Bug we are displaying
    std::shared_ptr<CBasket> mBasket;   ///< Basket
};


