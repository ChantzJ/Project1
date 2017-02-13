/**
* \file BugAdapter.h
*
* \author Chantz Johnson
*
* Adapter for the bug class
*/


#pragma once
#include "Drawable.h"
#include "Bug.h"
#include <memory>
#include <string>
#include <vector>
#include "Basket.h"

/**
* Class that acts as the interface for Drawable and CBug
*/
class CBugAdapter :
	public CDrawable
{
public:
	/** \brief Default constructor disabled */
	CBugAdapter() = delete;
	/** \brief Copy constructor disabled */
	CBugAdapter(const CBugAdapter &) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CBugAdapter &) = delete;

	/**
	* Constructor
	* \param name
	*
	*/
	CBugAdapter(const std::wstring & name);

	/// destructor
	virtual ~CBugAdapter();

	/**
	* Draw function
	* \param graphics
	*
	*/
	void Draw(Gdiplus::Graphics *graphics) override;

	/**
	* Blank hitest
	* \param pos
	*
	*/
	bool HitTest(Gdiplus::Point pos);

	/**
	* Setter for Harvest frame
	* \param frame
	*
	*/
	void SetHarvest(int frame) { mHarvestFrame = frame; }

	/**
	* Setter for start Frame
	* \param frame
	*
	*/
	void SetStart(int frame) { mStartFrame = frame; }

	/**
	* Setter for the seed
	* \param seed
	*
	*/
	void SetSeed(int seed) { mBug->SetSeed(seed); }

	/**
	* Setter for this bugs basket
	* \param basket
	*
	*/
	void SetBasket(std::shared_ptr<CBasket> basket) { mBasket = basket; }

	void ShowDlgBox();


private:

	/// member bug
	std::shared_ptr<CBug> mBug;

	/// member basket
	std::shared_ptr<CBasket> mBasket;

	/// starting frame for growing
	int mStartFrame = 0;

	/// frame for harvesting
	int mHarvestFrame = 200;

	/// harvested status
	bool mHarvested = false;
};

