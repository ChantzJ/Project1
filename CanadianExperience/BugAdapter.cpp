#include "stdafx.h"
#include "BugAdapter.h"
#include "BugFactory.h"
#include "Basket.h"
#include "Bug.h"
#include "Drawable.h"
#include "Timeline.h"
#include "Head.h"
#include "BugSeedDlg.h"


/** \brief Constructor for a polygon object
* \param name The drawable name */
CBugAdapter::CBugAdapter(const std::wstring &name) : CDrawable(name)
{
	CBugFactory factory;
	mBug = factory.CreateBug();

//	mBasket = factory.CreateBasket();


	//std::shared_ptr<CBug> bug = factory.CreateBug();
}


/**
* \brief Destructor
*/
CBugAdapter::~CBugAdapter()
{
}

void CBugAdapter::Draw(Gdiplus::Graphics * graphics)
{
	auto channel = GetAngleChannel();
	auto frame = channel->GetTimeline()->GetCurrentFrame();

	if (frame >= mStartFrame)
	{

		frame = frame - mStartFrame;
		mBug->SetBugFrame(frame);

		float scale = 0.3f;
		//mPlacedPosition.X = 600;
		//mPlacedPosition.Y = 100;

		//begin graphics block
		auto save = graphics->Save();

		graphics->TranslateTransform((float)mPlacedPosition.X,
			(float)mPlacedPosition.Y);
		graphics->ScaleTransform(scale, scale);
		mBug->DrawBug(graphics);
		graphics->Restore(save);

		//end graphics block

		//mPlacedPosition.X = 550;
		//mPlacedPosition.Y = 420;


		//harvesting
		if (frame >= mHarvestFrame && !mHarvested)
		{
			mHarvested = true;

			auto harvest = mBug->Harvest();
			if (harvest != nullptr)
			{
				mBasket->AddToBasket(harvest);
			}
		}
	}
}

/**
* \brief Test to see if we clicked on this drawable
* \param pos Position we clicked
* \returns True if we clicked on it
*/
bool CBugAdapter::HitTest(Gdiplus::Point pos)
{
	return false;
}

void CBugAdapter::ShowDlgBox()
{
		CBugSeedDlg dlg(mBug);

		if (dlg.DoModal() == IDOK) {
			
			// A new seed has been set
		}
	
}
