/**
 * \file Head.h
 *
 * \author Charles Owen
 *
 * Abstract base class for a head that can be placed in the basket.
 */

#pragma once

/**
 * Abstract base class for a head that can be placed in the basket.
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CHead
{
public:
    /// Constructor
    CHead() {}

    /// Destructor
    virtual ~CHead() {}

    /**
     * Set the position of the head in the basket
     *
     * This position is relative to the basket, so 
     * it will be added to the basket location passed
     * to DrawInBasket when we draw it 
     * \param x X position in pixels
     * \param y Y position in pixels
     */
    virtual void SetBasketPosition(int x, int y) = 0;

    /**
     * Draw the head in the basket
     * \param graphics The graphics object to draw on 
     */
    virtual void DrawInBasket(Gdiplus::Graphics *graphics) = 0;
};

