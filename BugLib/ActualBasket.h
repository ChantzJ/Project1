/**
* \file ActualBasket.h
*
* \author Chantz Johnson
*
* Class that represents the actual basket
*
*
*/

#pragma once
#include "Basket.h"
#include <memory>

class CBugImage;
class CActualHead;
class CPseudoRandom;

/**
* Class that handles the function of the basket
*/
class CActualBasket :
	public CBasket
{
public:

	/// Constructor
	CActualBasket();

	/// Destructor
	virtual ~CActualBasket() {}

	/// Copy constructor/disabled
	CActualBasket(const CActualBasket &) = delete;

	/// Assignment operator/disabled
	void operator=(const CActualBasket &) = delete;

	/**
	* Draw the basket at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	virtual void DrawBasket(Gdiplus::Graphics *graphics) override;

	/**
	* Add head to basket
	* \param head Head object
	*/
	virtual void AddToBasket(std::shared_ptr<CHead> head) override;

	/**
	* Empty all fruit from the basket
	*/
	virtual void EmptyBasket();

private:



	/// The image of the basket
	std::shared_ptr<CBugImage> mBasketImage1;

	/// The image of the front of the basket
	std::shared_ptr<CBugImage> mBasketImage2;

	/// vector of harvested heads
	std::vector<std::shared_ptr<CHead>> mHarvestedHeads;

	/// random object
	std::shared_ptr<CPseudoRandom> mRand;

};

