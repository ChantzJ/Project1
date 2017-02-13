#include "stdafx.h"
#include "BugPart.h"
#include "BugImage.h"
#include "Segment.h"
#include "ActualBug.h"
#include "PseudoRandom.h"
#include "BugStinger.h"
#include "ActualHead.h"
#include "Head.h"



#include <memory>

using namespace std;

const double MinSize = 0.1;

const double MaxSize = 1;

/**
* Default Constructor
*
* 
*/
CBugPart::CBugPart()
{
}

/**
* overloaded constructor
*
* \param bug
*/
CBugPart::CBugPart(std::shared_ptr<CActualBug> bug) : mBug(bug)
{
}



CBugPart::~CBugPart()
{
	

}

void CBugPart::Draw(Gdiplus::Graphics *graphics)
{

	double scale;

	if (mAge < mAgeGrown)
	{
		scale = MinSize + mAge / mAgeGrown * (MaxSize - MinSize);
	}
	else
	{
		scale = MaxSize;
	}

	double useScale = scale;  // I'll let you figure this one out

	auto save = graphics->Save();
	graphics->TranslateTransform(static_cast<float>(mPosition.X), static_cast<float>(mPosition.Y)); //conversion error here
	graphics->ScaleTransform(useScale, useScale);
	graphics->RotateTransform(static_cast<float>(mAngle));	//conversion error here

	mImage->Draw(graphics, mLeft);

	for (auto child : mChildren) 
	{
		child->Draw(graphics);
	}

	graphics->Restore(save);


}

/**
* Method to add children to the tree
*
* \param part
*/
void CBugPart::AddChild(std::shared_ptr<CBugPart> part)
{
	mChildren.push_back(part);
	part->SetParent(this);
}

/**
* Method to spawn a head
*
* \param childX
*/
void CBugPart::SpawnHead(float childX)
{
	// Grow a stinger
	auto part = make_shared<CActualHead>(GetBug());
	part->SetPosition(PointF(childX, 0));
	part->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
	part->SetLeft(IsLeft());
	part->SetAge(0);
	part->SetChildStatus(true);
	AddChild(part);
	mBug->SetHead(part); 


	/////////////////////////////////////////
	part->SetSelf(part);
	//we now have a pointer to head
	//set head here something
}

/**
* Method to delete children
*
* 
*/
void CBugPart::DeleteChildren()
{
	for (auto child : mChildren)
	{
		child->DeleteChildren();

	}

	mChildren.erase(mChildren.begin(), mChildren.end());
}

/**
* Method to grow the bug parts
*
* \param delta change in frame
*/
void CBugPart::Grow(double delta)
{

	auto test1 = mParent;
	auto test2 = mChildren.size();
	auto testleg = GetChildStatus();

	RootSpawn();

	mAge += delta;


	for (auto child : mChildren)
	{
		child->Grow(delta);
		//child->SetChildStatus(true);

	}

	SetPart();


	
}

/***
* Method to spawn bug parts on the left and right sides
*
*
*/
void CBugPart::SetPart()
{
	/*
	* Spawning child segments, heads, or stingers
	*/

	//if this part already has a child then skip
	if (!mHasChild && mAge > mSpawnTime)
	{
		float childX = (float)(IsLeft() ?
			-GetWidth() * 0.9f : GetWidth() * 0.9f);

		if (Random(0.0, 1.1) < 0.4)
		{
			if (IsLeft())
			{
				SpawnHead(childX);
			}
			else
			{
				// Grow a stinger
				auto part = make_shared<CBugStinger>(GetBug());
				part->SetPosition(PointF(childX, 0));
				part->SetAngle(Random(-30, 30));
				//part->SetLeft(IsLeft());
				part->SetChildStatus(true);

				AddChild(part);
			}

		}
		else
		{
			auto part = make_shared<CSegment>(GetBug());
			part->SetPosition(PointF(childX, 0));
			part->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
			part->SetLeft(IsLeft());
			part->SetAge(0);
			AddChild(part);

		}

		//if we added a segment then we set this's child to true
		mHasChild = true;
	}
}

/***
* Method to set the angle
*
* \param angle
*/
void CBugPart::SetAngle(double angle)
{


	if (IsLeft())
	{
		mAngle = -angle;


	}
	else
	{
		mAngle = angle;
	}


	//mAngle = angle;
	for (auto child : this->GetChildren())
	{

			child->SetAngle(angle);

	}


}

/***
* Method to use random
*
* \param to
* \param fr
*/
double CBugPart::Random(double to, double fr)
{
	return mBug->GetRand()->Random(to, fr);
}

/***
* Method to get width of the image
*
* \returns double width
*/
double CBugPart::GetWidth()
{
	return mImage->GetWidth();
}

void CBugPart::RootSpawn()
{
	//check for the root
	if (mParent == nullptr && mChildren.size() == 0 && mAge >= mSpawnTime && true )

		//auto test = !(mBug->GetHead()->GetHarvest());
	{
		float childX = (float)(GetWidth() * 0.9f);

		float childLX = (float)(-GetWidth() * 0.9f);

		if (Random(0.0, 1.1) < 0.4)
		{
			if (IsLeft())
			{
				SpawnHead(childX);

				auto part = make_shared<CSegment>(GetBug());
				part->SetPosition(PointF(childX, 0));
				part->SetLeft(false);
				//part->SetBug(mBug);
				part->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
				part->SetAge(0);
				AddChild(part);

			}
			else
			{

				// Grow a stinger
				auto part = make_shared<CBugStinger>(GetBug());
				part->SetPosition(PointF(childX, 0));
				part->SetAngle(Random(-30, 30));
				//part->SetLeft(IsLeft());
				AddChild(part);
				part->SetChildStatus(true);

				auto partL = make_shared<CSegment>(GetBug());
				partL->SetPosition(PointF(0, 0));
				//part->SetBug(mBug);
				partL->SetLeft(true);
				partL->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
				partL->SetAge(0);
				AddChild(partL);

			}


		}
		else
		{

			auto part = make_shared<CSegment>(GetBug());
			part->SetPosition(PointF(childX, 0));
			part->SetLeft(false);
			//part->SetBug(mBug);
			part->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
			part->SetAge(0);

			AddChild(part);

			auto partL = make_shared<CSegment>(GetBug());
			partL->SetPosition(PointF(0, 0));
			//part->SetBug(mBug);
			partL->SetLeft(true);
			partL->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
			partL->SetAge(0);
			AddChild(partL);
		}
		SetChildStatus(true);
		mHasChild = true;
	}
}

/***
* Method to get width of the image
*
* \returns double width
*/
double CBugPart::GetHeight()
{
	return mImage->GetHeight();
}