/**
* \file BasketAdapter.h
*
* \author Chantz Johnson
*
* Class that adapts as basket to Drawable
*
*
*/

#pragma once
#include "Drawable.h"
#include "Bug.h"
#include <memory>
#include <string>
#include <vector>
#include "Basket.h"

/**
* Interface for Drawable and CBasket
*/
class CBasketAdapter :
	public CDrawable
{
public:
	/** \brief Default constructor disabled */
	CBasketAdapter() = delete;
	/** \brief Copy constructor disabled */
	CBasketAdapter(const CBasketAdapter &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBasketAdapter &) = delete;

	/**
	* constructor
	* \param name
	*
	*/
	CBasketAdapter(const std::wstring & name);

	/// desctructor
	virtual ~CBasketAdapter();

	/**
	* Getter for Basket
	* \return mBasket
	*
	*/
	std::shared_ptr<CBasket> GetBasket() { return mBasket; }

	/**
	* Draw for basket
	* \param graphics
	*
	*/
	void Draw(Gdiplus::Graphics *graphics) override;

	/**
	* blank hit test
	* \param pos
	* \return false
	*/
	bool HitTest(Gdiplus::Point pos) { return false; };


private:

	/// member basket
	std::shared_ptr<CBasket> mBasket;

};

