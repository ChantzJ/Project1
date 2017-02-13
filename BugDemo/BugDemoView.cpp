/**
 * \file BugDemoView.cpp
 *
 * \author Charles Owen
 */

#include "stdafx.h"
#include "BugDemo.h"
#include "BugDemoView.h"
#include "DoubleBufferDC.h"
#include "BugFactory.h"

using namespace Gdiplus;

// Window class name for this view
#define VIEWER_CLASSNAME    _T("CBugDemoView")  // Window class name

/// Offset of the bottom of view from bottom of parent view in pixels
const int BugBottomOffset = 10;

/// Scale to draw the bug and basket
const float Scale = 0.3f;

IMPLEMENT_DYNAMIC(CBugDemoView, CWnd)

/**
 * Constructor
 */
CBugDemoView::CBugDemoView()
{
    RegisterWindowClass();

    //
    // Use a factory to create the bug and basket objects
    //
    CBugFactory factory;
    mBug = factory.CreateBug();
    mBasket = factory.CreateBasket();
}

/**
 * Destructor
 */
CBugDemoView::~CBugDemoView()
{
}

/**
 * Register this view as  a window
 * \return TRUE if successful
 */
BOOL CBugDemoView::RegisterWindowClass()
{
    WNDCLASS wndcls;
    HINSTANCE hInst = AfxGetInstanceHandle();

    if (!(::GetClassInfo(hInst, VIEWER_CLASSNAME, &wndcls)))
    {
        // otherwise we need to register a new class
        wndcls.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
        wndcls.lpfnWndProc = ::DefWindowProc;
        wndcls.cbClsExtra = wndcls.cbWndExtra = 0;
        wndcls.hInstance = hInst;
        wndcls.hIcon = NULL;
        wndcls.hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
        wndcls.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
        wndcls.lpszMenuName = NULL;
        wndcls.lpszClassName = VIEWER_CLASSNAME;

        if (!AfxRegisterClass(&wndcls))
        {
            AfxThrowResourceException();
            return FALSE;
        }
    }

    return TRUE;
}


/**
 * Create the view
 * \param pParentWnd Optional parent window
 * \param rect View rectanlge
 * \param nID ID for the view
 * \param dwStyle Window style
 * \returns true if successful
 */
BOOL CBugDemoView::Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle /*=WS_VISIBLE*/)
{
    return CWnd::Create(VIEWER_CLASSNAME, _T(""), dwStyle, rect, pParentWnd, nID);
}

/** \cond */
BEGIN_MESSAGE_MAP(CBugDemoView, CWnd)
    ON_WM_PAINT()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()
/** \endcond */


/**
 * Paint the view
 */
void CBugDemoView::OnPaint()
{
    CPaintDC paintDC(this);     // device context for painting
    CDoubleBufferDC dc(&paintDC); // device context for painting

    Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context

    CRect rect;
    GetClientRect(&rect);

    auto save = graphics.Save();
    graphics.TranslateTransform((REAL)rect.right * 3.0f / 5.0f, (REAL)rect.bottom - 200.0f);
    graphics.ScaleTransform(Scale, Scale);
    mBug->DrawBug(&graphics);
    graphics.Restore(save);

    save = graphics.Save();
    graphics.TranslateTransform((REAL)rect.right / 6.0f, (REAL)rect.bottom - 200.0f);
    graphics.ScaleTransform(Scale, Scale);
    mBasket->DrawBasket(&graphics);
    graphics.Restore(save);

}


/**
 * Handle an erase background message. Since we use CDoubleBufferDC, we ignore it
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CBugDemoView::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}


/**
 * Set the current view frame
 * \param frame Frame number
 */
void CBugDemoView::SetFrame(int frame) 
{
    mBug->SetBugFrame(frame);
    Invalidate();
}


/**
 * Set the bend angle
 * \param bend Bend angle in radians
 */
void CBugDemoView::SetBendAngle(double bend)
{
    mBug->SetBend(bend);
    Invalidate();
}


/**
 * Set the bug seed
 * \param seed Seed integer value
 */
void CBugDemoView::SetSeed(int seed)
{
    mBug->SetSeed(seed);
}

/**
* Handle the Harvest button press
*/
void CBugDemoView::Harvest()
{
    auto harvest = mBug->Harvest();
    if (harvest != nullptr)
    {
        mBasket->AddToBasket(harvest);
    }

    Invalidate();
}

/**
* Handle the Empty Basket button press
*/
void CBugDemoView::EmptyBasket()
{
    mBasket->EmptyBasket();
    Invalidate();
}