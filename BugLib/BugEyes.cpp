#include "stdafx.h"
#include "BugEyes.h"
#include "BugImage.h"
#include "BugPart.h"

CBugEyes::CBugEyes()
{
}


CBugEyes::~CBugEyes()
{
}

CBugEyes::CBugEyes(std::shared_ptr<CActualBug> bug) : CBugPart(bug)
{
	auto rand = Random(0.0, 1.0);


	if (rand >= 0.0 && rand <= 0.5)
	{
		SetImage(std::make_shared<CBugImage>(L"images/eye1.png"));

	}

	else if (rand > 0.5 && rand <= 10)
	{
		SetImage(std::make_shared<CBugImage>(L"images/eye2.png"));

	}

	SetAge(GetMaxAge());
	//SetPosition(PointF(150, 150));
		///set position in here as created
}

void CBugEyes::Draw(Graphics * graphics)
{
	CBugPart::Draw(graphics);
}
