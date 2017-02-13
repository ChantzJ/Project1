#include "stdafx.h"
#include "BugLeg.h"
#include "BugImage.h"
#include "ActualBug.h"


CBugLeg::CBugLeg()
{
}


CBugLeg::~CBugLeg()
{
}

CBugLeg::CBugLeg(std::shared_ptr<CActualBug> bug) : CBugPart(bug)
{
	auto rand = Random(0.0, 1.0);


	if (rand >= 0.0 && rand <= 0.5)
	{
		SetImage(std::make_shared<CBugImage>(L"images/leg2.png"));

	}

	else if (rand > 0.5 && rand <= 1.0)
	{
		SetImage(std::make_shared<CBugImage>(L"images/leg1.png"));

	}
	//SetChildStatus(true);

}

void CBugLeg::Draw(Graphics * graphics)
{
	CBugPart::Draw(graphics);
}


void CBugLeg::Grow(double size)
{
	auto age = GetCurrentAge();
	SetAge(age + size);
	//mAge += size;

}
