#include "stdafx.h"
#include "Segment.h"
#include "BugImage.h"
#include "ActualBug.h"
#include "PseudoRandom.h"
#include "BugLeg.h"

using namespace std;

CSegment::CSegment()
{

}

CSegment::CSegment(std::shared_ptr<CActualBug> bug) : CBugPart(bug)
{

	auto rand = GetBug()->GetRand()->Random(0.0, 1.0);
	//auto rand = Random(0.0, 1.0);

	if (rand >= 0.0 && rand < 0.2)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment1.png"));

	}

	else if (rand >= 0.2 && rand < 0.4)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment2.png"));

	}

	else if (rand >= 0.4 && rand < 0.6)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment3.png"));

	}

	else if (rand >= 0.6 && rand < 0.8)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment3.png"));

	}

	else if (rand >= 0.8 && rand <= 1.0)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment4.png"));

	}


}


CSegment::~CSegment()
{
}

void CSegment::Draw(Graphics * graphics)
{

	for (auto legs : mLegsBack)
	{
		legs->Draw(graphics);
	}

	CBugPart::Draw(graphics);

	for (auto legs : mLegsFront)
	{
		legs->Draw(graphics);
	}



}

void CSegment::SetPart()
{
	int legs = floor(static_cast<int>(Random(0.0, 3.9)));




	if (GetCurrentAge() > GetMaxAge() && !mHasLegs)
	{

			for (auto i = 1; i < legs; i++)
			{
				auto offsetX = GetPosition().X + GetImage()->GetWidth()/2;

				auto testOffsetX = GetImage()->GetWidth() / legs;

				auto frontLeg = make_shared<CBugLeg>(GetBug());
				frontLeg->SetPosition(PointF(GetPosition().X + testOffsetX, 0));
				frontLeg->SetAngle(-240);
				frontLeg->SetAge(0);
				frontLeg->SetChildStatus(true);

				mLegsFront.push_back(frontLeg);



				auto backLeg = make_shared<CBugLeg>(GetBug());
				backLeg->SetImage(frontLeg->GetImage());
				backLeg->SetPosition(PointF(GetPosition().X + testOffsetX, 0));
				backLeg->SetAngle(-270);
				backLeg->SetAge(0);
				mLegsBack.push_back(backLeg);

				backLeg->SetChildStatus(true);




			}


		mHasLegs = true;

	}

	CBugPart::SetPart();
}

void CSegment::Grow(double size)
{
	for (auto leg : mLegsFront)
	{
		//leg->SetChildStatus(true);
		leg->Grow(size);
	}
	
	for (auto leg : mLegsBack)
	{
		//leg->SetChildStatus(true);
		leg->Grow(size);
	}

	CBugPart::Grow(size);
}