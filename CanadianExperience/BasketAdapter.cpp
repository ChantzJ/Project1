#include "stdafx.h"
#include "BasketAdapter.h"
#include "BugAdapter.h"
#include "BugFactory.h"
#include "Basket.h"
#include "Bug.h"
#include "Drawable.h"
#include "Timeline.h"
#include "Basket.h"


CBasketAdapter::CBasketAdapter(const std::wstring & name) : CDrawable(name)
{
		CBugFactory factory;
		//mBug = factory.CreateBug();

		mBasket = factory.CreateBasket();
}

CBasketAdapter::~CBasketAdapter()
{
}

void CBasketAdapter::Draw(Gdiplus::Graphics * graphics)
{

	auto channel = GetAngleChannel();
	auto frame = channel->GetTimeline()->GetCurrentFrame();


	float scale = 0.3f;

	mPlacedPosition.X = 550;
	mPlacedPosition.Y = 420;

	auto save = graphics->Save();


	graphics->TranslateTransform((float)mPlacedPosition.X,
		(float)mPlacedPosition.Y);
	graphics->ScaleTransform(scale, scale);
	mBasket->DrawBasket(graphics);

	//CBug::DrawBug(graphics);
	graphics->Restore(save);
}
