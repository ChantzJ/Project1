/**
* \file BugStinger.h
*
* \author Chantz Johnson
*
* Class that represents the stinger
*
*
*/
#pragma once
#include "BugPart.h"

/**
* Class that represents the stinger
*/
class CBugStinger : 
	public CBugPart
{
public:

	/// constructor
	CBugStinger();

	/**
	* Constructor
	* \param bug
	*/
	CBugStinger(std::shared_ptr<CActualBug> bug);

	/// destructor
	virtual ~CBugStinger();

	/**
	* Draw for stinger
	* \param graphics
	*/
	void Draw(Graphics * graphics);
};

