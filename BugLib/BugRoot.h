/**
* \file BugRoot.h
*
* \author Chantz Johnson
*
* derived class for the bug root
*/

#pragma once
#include "Segment.h"

/**
* Class that represents a bug root.
*
*/
class CBugRoot :
	public CSegment
{
public:
	///  Default constructor (disabled)
	//CBugRoot() = delete;

	///  Copy constructor (disabled)
	//CBugRoot(const CBugRoot &) = delete;

	/// Default constructor
	CBugRoot();

	/// Constructor that takes a bug
	/// \param bug that this belongs to
	CBugRoot(std::shared_ptr<CActualBug> bug);
	
	/// Destructor
	virtual ~CBugRoot();

	/// Draw for bug root
	/// \param graphics
	virtual void Draw(Graphics * graphics);

};

