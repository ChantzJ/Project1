#include "stdafx.h"
#include "BasketStandin.h"

using namespace Gdiplus;
using namespace std;



/**
* Draw the basket at the currently specified location
* \param graphics GDI+ Graphics object
*/
void CBasketStandin::DrawBasket(Gdiplus::Graphics *graphics)
{
    const int LineSize = 48;
    const int LineSpacing = 75;

    int y = -LineSize;
    CenteredString(graphics, L"Make Bugs Great Again!", 0, y, LineSize);
    y -= LineSpacing;

    if (mAdded) 
    {
        CenteredString(graphics, L"Heads added.", 0, y, LineSize);
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
void CBasketStandin::CenteredString(Gdiplus::Graphics *graphics, const std::wstring &str, int x, int y, int dy)
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