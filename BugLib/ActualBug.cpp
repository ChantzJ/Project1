#include "stdafx.h"
#include "ActualBug.h"
#include "BugPart.h"
#include "BugRoot.h"
#include "PseudoRandom.h"
#include "Head.h"
#include "ActualHead.h"
#include "BugSeedDlg.h"
#include <algorithm>

using namespace std;
/**
* Constructor
*
*/
CActualBug::CActualBug()
{

	mSeed = 12345;
	mRand = make_shared<CPseudoRandom>(mSeed);
	
}


CActualBug::~CActualBug()
{
}

/**
* Set the current bug frame
* \param graphics graphics context
*/
void CActualBug::DrawBug(Gdiplus::Graphics * graphics)
{
	mRoot->Draw(graphics);
}

/**
* Set the current bug frame
* \param frame Frame number
*/
void CActualBug::SetBugFrame(int frame)
{
	if (frame < mCurrentFrame)
	{
		Reset();
	}

	while (mCurrentFrame < frame) {
		mCurrentFrame++;
		mRoot->Grow(1.0 / static_cast<double>(mFrameRate));
	}
}

/**
* Set the current bug frame
* \param bend bend angle
*/
void CActualBug::SetBend(double bend)
{

	for (auto child : mRoot->GetChildren())
	{
		child->SetAngle(bend);
	}


}

/**
* Set the current bug frame
* \param seed seed number
*/
void CActualBug::SetSeed(int seed)
{
	mRand->Seed(seed);
}

/**
* Set the current bug frame
* \returns seed
*/
int CActualBug::GetSeed()
{
	return mSeed;
}

/**
* Harvests the head
* \returns head
*/
std::shared_ptr<CHead> CActualBug::Harvest()
{
	if (mHead == nullptr)
	{
		return nullptr;
	}

	auto parent = mHead->GetParent();


	parent->DeleteChildren();
	parent->SetChildStatus(false);
	mHead->SetParent(nullptr);


	mHead->SetBasketPosition(200, -100);
	auto temp = mHead->GetSelf();
	mHead = nullptr;

	

	return temp;
}

void CActualBug::Reset()
{
	mCurrentFrame = 1;
	mRoot->SetAge(0);
	mRoot->DeleteChildren();
	mRoot->SetChildStatus(false);
	mRand->Reset();
}

/** Set the root drawable for the actor
* \param root Pointer to root drawable */
void CActualBug::SetRoot(std::shared_ptr<CBugRoot> root)
{
	mRoot = root;
}

/////**
////* Add a drawable to this actor
////* \param part The drawable to add
////*/
//void CActualBug::AddPart(std::shared_ptr<CBugPart> part)
//{
//	mParts.push_back(part);
//}

void CActualBug::ShowDialogBox()
{
	//CBugSeedDlg dlg();

	//dlg.SetSeed(mSeed);

	//if (dlg.DoModal() == IDOK)
	//{
	//	mSeed = dlg.GetSeed();
	//}

}