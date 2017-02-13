/**
* \file Segment.h
*
* \author Chantz Johnson
*
* derived class for segments
*/

#pragma once
#include "BugPart.h"

class CBugLeg;

/**
* Class that represents a segment.
*
*/
class CSegment :
	public CBugPart
{
public:

	///  Default constructor 
	CSegment();


	/**
	* Constructor
	*
	* \param bug
	*/
	CSegment(std::shared_ptr<CActualBug> bug);

	///destructor
	virtual ~CSegment();

	/**
	* Segment Draw
	*
	* \param graphics
	*/
	virtual void Draw(Graphics * graphics) override;

	/**
	* Overridden SetPart
	*
	* 
	*/
	virtual void SetPart() override;

	/**
	* Overridden Grow
	*
	* \param size
	*/
	void Grow(double size) override;

private:

	/// member vector of front legs
	std::vector<std::shared_ptr<CBugLeg>> mLegsFront;

	/// member vector of back legs
	std::vector<std::shared_ptr<CBugLeg>> mLegsBack;

	/// boolean for leg status
	bool mHasLegs = false;





};

