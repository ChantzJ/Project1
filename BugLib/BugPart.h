/**
* \file BugPart.h
*
* \author Chantz Johnson
*
* Base Parts class for all parts
*/

#pragma once
#include <memory>
#include <vector>

using namespace Gdiplus;

class CActualBug;
class CBugImage;
class CSegment;

/**
* Class that represents a bug part.
*
*/
class CBugPart
{
public:
	///  Default constructor
	CBugPart();

	/**
	* Constructor
	*
	* \param bug this bug
	*/
	CBugPart(std::shared_ptr<CActualBug> bug);

	/**
	* Destructor
	*/
	virtual ~CBugPart();

	/**
	* Bug parts Draw
	*
	* \param graphics
	*/
	virtual void Draw(Graphics * graphics);


	/**
	* Add child to this part
	*
	* \param part part to add
	*/
	void AddChild(std::shared_ptr<CBugPart> part);

	/**
	* Method to spawn a head
	*
	* \param childX
	*/
	void SpawnHead(float childX);

	/**
	* delete all the children
	*
	*/
	void DeleteChildren();

	/**
	* grow the current part
	* \param delta current size
	*/
	virtual void Grow(double delta);

	/**
	* Random function for upcall to bugs random
	*
	* \param to first num
	* \param fr second num
	* \return random in range
	*/
	double Random(double to, double fr);

	////////SETTERS/////////////////////

	/**
	* Set a valid part for spawning
	*
	*
	*/
	virtual void SetPart();

	/**
	* Set the position for the part
	* \param point gdi Point
	*
	*/
	void SetPosition(PointF point) { mPosition.X = point.X; mPosition.Y = point.Y; }

	/**
	* Set the desired angle of the part
	* \param angle
	*
	*/
	void SetAngle(double angle);

	/**
	* Set the left status of the part
	* \param left bool
	*
	*/
	void SetLeft(bool left) { mLeft = left; }

	/**
	* Set the member age of the part
	* \param age
	*
	*/
	void SetAge(double age) { mAge = age; }

	/**
	* Set the parent bug of the part
	* \param bug
	*
	*/
	void SetBug(std::shared_ptr<CActualBug> bug) { mBug = bug; }

	/**
	* Set the parent part of the part
	* \param part
	*
	*/
	void SetParent(CBugPart *part) { mParent = part; }

	/**
	* Set the child status of the part i.e. haschild
	* \param status
	*
	*/
	void SetChildStatus(bool status) 
	{ 
		mHasChild = status; 
	}

	/**
	* Set the image of the part
	* \param image part image
	*
	*/
	void SetImage(std::shared_ptr<CBugImage> image) { mImage = image; }


	///////GETTERS/////////////////////

	/**
	* Get the width of the image
	*\return double image width
	*
	*/
	double GetWidth();

	/**
	* Handle the first double spawning of the root
	*
	*
	*/
	void RootSpawn();

	/**
	* get the height of the image
	* \return double height
	*
	*/
	double GetHeight();

	/**
	* Get the left status of the part
	* \return mLeft status
	*
	*/
	bool IsLeft() { return mLeft; }

	/**
	* Get the bug for our part
	* \return mBug
	*
	*/
	std::shared_ptr<CActualBug> GetBug() { return mBug; }

	/**
	* Get the children of the part
	* \return mchildren
	*
	*/
	std::vector<std::shared_ptr<CBugPart>> GetChildren() { return mChildren; }

	/**
	* Get the current age of the part
	* \return mAge
	*
	*/
	double GetCurrentAge() { return mAge; }

	/**
	* Get the max Age
	* \return mAgeGrown
	*
	*/
	double GetMaxAge() { return mAgeGrown; }

	/**
	* Get the image of the part
	* \return mImage
	*
	*/
	std::shared_ptr<CBugImage> GetImage() { return mImage; }

	/**
	* Get the Position of the part
	* \return mPosition
	*
	*/
	PointF GetPosition() { return mPosition; }

	/**
	* Get the Child Status
	* \return mHasChild
	*
	*/
	bool GetChildStatus() { return mHasChild; }

	/**
	* Get the Spawn Time
	* \return mSpawnTime
	*
	*/
	double GetSpawnTime() { return mSpawnTime; }

	/**
	* Get a pointer to the parent
	* \return mParent
	*
	*/
	CBugPart * GetParent() { return mParent; }



private:

	/// angle of the part
	double mAngle = 0;

	///bool for the status of child
	bool mHasChild = false;

	/// point position
	PointF mPosition = PointF(0, 0);

	/// age of the part
	double mAge = 1;

	/// max age
	double mAgeGrown = 3;

	/// time when a new node will spawn
	double mSpawnTime = 1.1;

	/// bool for left part
	bool mLeft = false;


private:

	/// The child of the parent
	std::vector<std::shared_ptr<CBugPart>> mChildren;

	/// The parent of the current part
	CBugPart *mParent = nullptr;

	/// shared pointer to the bug we are a part of
	std::shared_ptr<CActualBug> mBug;

	/// The image of the basket
	std::shared_ptr<CBugImage> mImage;


};

