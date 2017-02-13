#pragma once
#include "Head.h"
#include "BugPart.h"
#include "ActualBug.h"

class CBugEyes;

/**
* Class that represents a bug head.
*
*/
class CActualHead :
	public CBugPart, public CHead
{
public:

	/// default constructor
	CActualHead() {};

	/// destructor
	virtual ~CActualHead();

	/**
	* Constructor
	* \param bug
	*
	*/
	CActualHead(std::shared_ptr<CActualBug> bug);

	/**
	* Draw for Head
	* \param graphics
	*
	*/
	void Draw(Graphics * graphics);


	/**
	* Set the position of the head in the basket
	*
	* This position is relative to the basket, so
	* it will be added to the basket location passed
	* to DrawInBasket when we draw it
	* \param x X position in pixels
	* \param y Y position in pixels
	*/
	virtual void SetBasketPosition(int x, int y);

	/**
	* Draw the head in the basket
	* \param graphics The graphics object to draw on
	*/
	virtual void DrawInBasket(Gdiplus::Graphics *graphics);

	/**
	* Grow for Head
	* \param size
	*
	*/
	virtual void Grow(double size);

	/**
	* Get the harvest status for head
	* \return mHarvested
	*
	*/
	bool GetHarvest() { return mHarvested; }

	/**
	* Set the harvest status for head
	* \param status
	*
	*/
	void SetHarvested(bool status) { mHarvested = status; }


private:

	/// member vector of eyes on head
	std::vector<std::shared_ptr<CBugEyes>> mEyes;


	/// harvest status
	bool mHarvested = false;

public:

	/**
	* Set a pointer to self
	* \param self
	*
	*/
	void SetSelf(std::shared_ptr<CHead> self) { mSelf = self; }

	/**
	* Getter for self
	* \return mSelf.lock()
	*
	*/
	std::shared_ptr<CHead> GetSelf() { return mSelf.lock(); }

private:

	/// weak pointer to self
	std::weak_ptr<CHead> mSelf;
};

