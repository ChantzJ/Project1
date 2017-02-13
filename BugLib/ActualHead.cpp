#include "stdafx.h"
#include "ActualHead.h"
#include "BugImage.h"
#include "BugEyes.h"
#include "BugPart.h"


using namespace std;

CActualHead::~CActualHead()
{
}

CActualHead::CActualHead(std::shared_ptr<CActualBug> bug) : CBugPart(bug)
{


	auto rand = Random(0.0, 1.0);


	if (rand >= 0.0 && rand <= 0.5)
	{
		SetImage(std::make_shared<CBugImage>(L"images/head3m.png"));

	}

	else if (rand > 0.5 && rand <= 10)
	{
		SetImage(std::make_shared<CBugImage>(L"images/head2m.png"));

	}


//	mEyes = std::make_shared<CBugEyes>(bug);
}

void CActualHead::Draw(Graphics * graphics)
{


	CBugPart::Draw(graphics);

	for (auto eyes : mEyes)
	{
		//GetImage()->
		eyes->Draw(graphics);
	}

}

void CActualHead::SetBasketPosition(int x, int y)
{
	auto headHeight = GetImage()->GetHeight();

	auto headWidth = GetImage()->GetWidth();

	auto offsetX = Random(-headWidth / 2 , headWidth / 2);

	auto offsetY = Random(-headHeight / 3, headHeight / 3);

	SetPosition(PointF(x + offsetX, y + offsetY));

	for (auto eye : mEyes)
	{
		auto offsetX = Random(-headWidth / 3, headWidth / 3);

		auto offsetY = Random(-headHeight / 4, headHeight / 4);

		eye->SetPosition(PointF(GetPosition().X - GetImage()->GetWidth() / 2 + offsetX, GetPosition().Y + offsetY));
		//eye->SetPosition(PointF(GetPosition().X, GetPosition().Y));


		//eye->Draw(graphics);
	}
}

void CActualHead::DrawInBasket(Gdiplus::Graphics * graphics)
{
	auto headHeight = GetImage()->GetHeight();

	auto headWidth = GetImage()->GetWidth();

	//auto offsetX = Random(-headWidth / 5, headWidth / 5);

	//auto offsetY = Random(-headHeight / 4, headHeight / 3);

	//part->SetPosition(PointF(GetPosition().X - GetImage()->GetWidth() / 2 + offsetX, GetPosition().Y + offsetY));


	CBugPart::Draw(graphics);

	for (auto eye : mEyes)
	{

		eye->Draw(graphics);
	}
}

void CActualHead::Grow(double size)
{

	auto eyes = floor(Random(0.0, 5.9));


	//if the current age of the head is the max age a.k.a fully grown
	if (GetCurrentAge() >= GetMaxAge() && mEyes.size() < eyes)
	{
		auto spawnChance = Random(0.0, 1.0);
		////for (auto i = 0; i < eyes; i++)
		////{
		if(spawnChance > 0.9 )
		{ 
			auto part = make_shared<CBugEyes>(GetBug());

			//part->SetLeft(IsLeft());

			auto headHeight = GetImage()->GetHeight();

			auto headWidth = GetImage()->GetWidth();

			auto offsetX = Random(-headWidth/5, headWidth/5);

			auto offsetY = Random(-headHeight/4, headHeight/3);

			part->SetPosition(PointF(GetPosition().X - GetImage()->GetWidth() / 2 + offsetX, GetPosition().Y + offsetY));

			//AddChild(part);
			//GetPosition().Y  + offsetY

			//GetPosition().X - GetImage()->GetWidth()/2 + offsetX, GetPosition().Y+ offsetY

			mEyes.push_back(part);
		}

		//call heads grow
		//mEyes->Draw(graphics);
	}

	CBugPart::Grow(size);
}
