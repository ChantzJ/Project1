/**
 * \file BugFactory.h
 *
 * \author Charles Owen
 *
 * Bug factory class. Creates Bug and Basket objects
 */

#pragma once

#include <memory>

class CBug;
class CBasket;
class CActualBug;


/**
 * Bug factory class. Creates Bug and Basket objects
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CBugFactory
{
public:
    CBugFactory();
    ~CBugFactory();

    std::shared_ptr<CBug> CreateBug();
    std::shared_ptr<CBasket> CreateBasket();
};

