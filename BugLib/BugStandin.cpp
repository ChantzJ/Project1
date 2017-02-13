/**
 * \file BugStandin.cpp
 *
 * \author Charles Owen
 *
 * This file may not be changed.
 */

#include "stdafx.h"
#include "BugStandin.h"
#include <sstream>

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 */
CBugStandin::CBugStandin()
{
}


/**
 * Destructor
 */
CBugStandin::~CBugStandin()
{
}


/**
* Draw the bug at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CBugStandin::DrawBug(Gdiplus::Graphics *graphics)
{
    const int LineSize = 48;
    const int LineSpacing = 75;

    Pen pen(Color(139, 69, 19), (REAL)3);
    pen.SetEndCap(LineCapRound);
    graphics->DrawLine(&pen, (REAL)mX, (REAL)mY, (REAL)(mX), (REAL)(mY - 300));

    Pen pen2(Color(139, 69, 19), (REAL)2);
    graphics->DrawLine(&pen, (REAL)(mX), (REAL)(mY - 300), (REAL)(mX + 120), (REAL)(mY - 420));
    graphics->DrawLine(&pen, (REAL)(mX), (REAL)(mY - 300), (REAL)(mX - 150), (REAL)(mY - 420));

    int y = mY - LineSize;
    CenteredString(graphics, L"Make Bugs Great Again!", mX, y, LineSize);
    y -= LineSpacing;

    {
        wstringstream str;
        str << L"Seed: " << mSeed << ends;
        CenteredString(graphics, str.str(), mX, y, LineSize);
        y -= LineSpacing;
    }

    {
        wstringstream str;
        str << L"Frame: " << mFrame << ends;
        CenteredString(graphics, str.str(), mX, y, LineSize);
        y -= LineSpacing;
    }


    {
        wstringstream str;
        str << L"Bend Angle: " << mBendAngle;
        CenteredString(graphics, str.str(), mX, y, LineSize);
        y -= LineSpacing;
    }

    if(mHarvested) 
    {
        CenteredString(graphics, L"Harvested", mX, y, LineSize);
        y -= LineSpacing;
    }

}


/**
 * Draw a centered string
 *
 * Yes, I know this function is repeated in both CBugStandin
 * and CBasketStandin. Normally I would create a base class and
 * move this function into it. I'm not doing that to keep the number
 * of class students see minimal.
 *
 * \param graphics Graphics object
 * \param str String to draw
 * \param x X location of bottom center of string
 * \param y Y location of bottom center of string
 * \param dy String height
 */
void CBugStandin::CenteredString(Gdiplus::Graphics *graphics, const std::wstring &str, int x, int y, int dy)
{
    y -= dy;

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, (REAL)dy);

    SolidBrush black(Color(0, 0, 0));
    RectF rect;
    graphics->MeasureString(str.c_str(), -1, &font, PointF((REAL)x, (REAL)y), &rect);
    graphics->DrawString(str.c_str(),  // String to draw
        -1,         // String length, -1 means it figures it out on its own
        &font,      // The font to use
        PointF((REAL)(x - rect.Width / 2), (REAL)y),   // Where to draw (top left corner)
        &black);    // The brush to draw the text with
}