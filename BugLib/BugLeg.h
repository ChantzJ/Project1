/**
* \file BugLeg.h
*
* \author Chantz Johnson
*
* Class that represents the Bug legs'
*
*
*/

#pragma once
#include "BugPart.h"
#include "ActualBug.h"

/**
* Class the represents the bug legs
*/
class CBugLeg :
	public CBugPart
{
public:

	/// default constructor
	CBugLeg();

	/// destructor
	virtual ~CBugLeg();

	/**
	* Constructor
	* \param bug
	*
	*/
	CBugLeg(std::shared_ptr<CActualBug> bug);

	/**
	* Overridden draw for elgs
	* \param graphics
	*
	*/
	void Draw(Graphics * graphics);


	/**
	* Grow for legs
	* \param size
	*
	*/
	void Grow(double size) override;

	//void Grow(double size);

private:

	/// angle the legs will grow at
	double mLegAngle = 30;
};

