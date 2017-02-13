/**
 * \file Basket.h
 *
 * \author Charles Owen
 *
 * Class the represents a basket that can hold fruit.
 *
 * You are not allowed to change this class in any way!
 */

#pragma once

#include <vector>
#include <memory>

class CHead;
class CBasketStandin;

/**
 * Class the represents a basket that can hold fruit.
 *
 * This uses a standin class to provide a way to develop
 * the adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CBasket
{
public:
    /// Constructor
    CBasket();
    
    /// Destructor
    virtual ~CBasket() {}

    /// Copy constructor/disabled
    CBasket(const CBasket &) = delete;

    /// Assignment operator/disabled
    void operator=(const CBasket &) = delete;

    /**
    * Draw the basket at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    virtual void DrawBasket(Gdiplus::Graphics *graphics);

    /**
     * Add head to basket
     * \param head Head object
     */
    virtual void AddToBasket(std::shared_ptr<CHead> head);

    /**
     * Empty all fruit from the basket 
     */
    virtual void EmptyBasket();

private:
    /// Standin basket class
    std::shared_ptr<CBasketStandin> mStandin;
};

