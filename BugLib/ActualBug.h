/**
* \file ActualBug.h
*
* \author Chantz Johnson
*
* Class that represents the actual bug
*
* 
*/

#pragma once
#include "Bug.h"

class CBugPart;
class CBugRoot;
class CPseudoRandom;
class CActualHead;

/**
* class that represents the actual bug
*/
class CActualBug :
	public CBug
{
public:

	/// default constructor
	CActualBug();

	/// destructor
	virtual ~CActualBug();

	/// Copy constructor/disabled
	CActualBug(const CActualBug &) = delete;

	/// Assignment operator/disabled
	void operator=(const CActualBug &) = delete;


	/**
	* Draw the bug at the currently specified location
	* \param graphics GDI+ Graphics object
	*/
	void DrawBug(Gdiplus::Graphics *graphics) override;

	/**
	* Set the current bug animation frame
	* \param frame Frame number
	*/
	virtual void SetBugFrame(int frame) override;

	/**
	* Set  the bend angle
	* \param bend Bend angle in radians
	*/
	virtual void SetBend(double bend) override;

	/**
	* Set the bug seed
	* \param seed An integer number. Each number makes a different bug
	*/
	virtual void SetSeed(int seed) override;

	/**
	* Get the current bug seed
	* \return Bug seed integer
	*/
	virtual int GetSeed() override;

	/**
	* Harvest the head
	* \return Pointer to a CHead object or null if none to harvest.
	*/
	virtual std::shared_ptr<CHead> Harvest() override;

	///reset the random number gen
	void Reset();

	/**
	* Setter for the Root
	* \param root
	*
	*/
	void SetRoot(std::shared_ptr<CBugRoot> root);

	///**
	//* Adds a part to the bug
	//* \param part
	//*
	//*/
	//void AddPart(std::shared_ptr<CBugPart> part);

	/// show the dialog box
	void ShowDialogBox();

	/**
	* Get the random object
	* \return mRand
	*
	*/
	std::shared_ptr<CPseudoRandom> GetRand() { return mRand; }

	/**
	* Setter for the head
	* \param head
	*
	*/
	void SetHead(std::shared_ptr<CActualHead> head) { mHead = head; }

	/**
	* Getter for the head
	* \return mHead
	*
	*/
	std::shared_ptr<CActualHead> GetHead() { return mHead; }

	/**
	* getter for the root
	* \return mRoot
	*
	*/
	std::shared_ptr<CBugRoot> GetRoot() { return mRoot; }

private:

	/// member frame rate
	int mFrameRate = 30;

	/// member current frame;
	int mCurrentFrame = 100;

	/// member random seed
	int mSeed;


	///////////actual bug is composed of a root and shares many parts

	/// vector of parts for testing purposes
	//std::vector<std::shared_ptr<CBugPart>> mParts;

	/// The root drawable
	std::shared_ptr<CBugRoot> mRoot;

	//////////////////////////////////////////////

	/// PSUEDORANDOM OBJECT
	std::shared_ptr<CPseudoRandom> mRand;

	/// member head object
	std::shared_ptr<CActualHead> mHead;
};

