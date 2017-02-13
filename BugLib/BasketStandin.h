/**
 * \file BasketStandin.h
 *
 * \author Charles Owen
 *
 * This class is a stand-in class that will allow you to
 * develop the basket adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 */

#pragma once

#include <vector>
#include <memory>

class CHead;

/**
 * This class is a stand-in class that will allow you to
 * develop the basket adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 */
class CBasketStandin
{
public:
    CBasketStandin() {}
    virtual ~CBasketStandin() {}

    void DrawBasket(Gdiplus::Graphics *graphics);

    /**
    * Add a head to the basket
    * \param head CHead object to add
    */
    void AddToBasket(std::shared_ptr<CHead> head) { mAdded = true; }

    /**
    * Empty all heads from the basket
    */
    void EmptyBasket() { mAdded = false; }

private:
    void CenteredString(Gdiplus::Graphics *graphics, const std::wstring &str, int x, int y, int dy);

    bool mAdded = false;    ///< Add has been called?
};

