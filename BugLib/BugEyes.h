/**
* \file BugEyes.h
*
* \author Chantz Johnson
*
* Class that represents the bug Eyes
*
*
*/
#pragma once
#include "BugPart.h"
#include "ActualBug.h"

/**
* Class that represents the bug Eyes
*/
class CBugEyes :
	public CBugPart
{
public:

	/// constructor
	CBugEyes();

	/// destructor
	virtual ~CBugEyes();

	/**
	* Constructor
	* \param bug
	*/
	CBugEyes(std::shared_ptr<CActualBug> bug);

	/**
	* Draw for bug eyes
	* \param graphics
	*/
	void Draw(Graphics * graphics);
};

