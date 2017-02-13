#include "stdafx.h"
#include "BugStinger.h"
#include "BugImage.h"


CBugStinger::CBugStinger()
{
}

CBugStinger::CBugStinger(std::shared_ptr<CActualBug> bug) : CBugPart(bug)
{
	auto rand = Random(0.0, 1.0);


	if (rand >= 0.0 && rand <= 0.5)
	{
		SetImage(std::make_shared<CBugImage>(L"images/stinger1.png"));

	}

	else if (rand > 0.5 && rand <= 1.0)
	{
		SetImage(std::make_shared<CBugImage>(L"images/stinger2.png"));

	}

}


CBugStinger::~CBugStinger()
{
}


void CBugStinger::Draw(Graphics * graphics)
{
	CBugPart::Draw(graphics);
}