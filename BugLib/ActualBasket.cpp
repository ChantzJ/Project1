#include "stdafx.h"
#include "ActualBasket.h"
#include "BugImage.h"
#include "PseudoRandom.h"
#include "ActualHead.h"


CActualBasket::CActualBasket()
{

	mBasketImage1 = std::make_shared<CBugImage>(L"images/basket.png");
	mBasketImage2 = std::make_shared<CBugImage>(L"images/basket-front.png");
	
}

void CActualBasket::DrawBasket(Gdiplus::Graphics * graphics)
{
	///set the params for the draw
	mBasketImage1->Draw(graphics, false);

	for (auto head : mHarvestedHeads)
	{
		head->DrawInBasket(graphics);

	}

	mBasketImage2->Draw(graphics, false);

}

void CActualBasket::AddToBasket(std::shared_ptr<CHead> head)
{
	mHarvestedHeads.push_back(head);
}

void CActualBasket::EmptyBasket()
{
	mHarvestedHeads.clear();
}
