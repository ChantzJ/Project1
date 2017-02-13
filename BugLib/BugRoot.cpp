#include "stdafx.h"
#include "BugRoot.h"
#include "BugImage.h"
#include "Segment.h"

using namespace std;


CBugRoot::CBugRoot()
{
}

CBugRoot::CBugRoot(std::shared_ptr<CActualBug> bug) : CSegment(bug)
{
	auto rand = Random(0.0, 1.5);


	if (rand >= 0.0 && rand <= 0.2)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment1.png"));

	}

	else if (rand > 0.2 && rand <= 0.4)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment2.png"));

	}

	else if (rand > 0.4 && rand <= 0.6)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment3.png"));

	}

	else if (rand > 0.8 && rand <= 1.0)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment4.png"));

	}
	else if (rand > 1.0 && rand <= 1.2)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment5.png"));

	}
	else if (rand > 1.2 && rand <= 1.5)
	{
		SetImage(std::make_shared<CBugImage>(L"images/segment3.png"));

	}

}


CBugRoot::~CBugRoot()
{
}


void CBugRoot::Draw(Graphics * graphics)
{
	//if ()
	//{
	//	float childX = (float)(GetWidth() * 0.9f);

	//	float childLX = (float)(-GetWidth() * 0.9f);

	//	auto part = make_shared<CSegment>(GetBug());
	//	part->SetPosition(PointF(childX, 0));
	//	part->SetLeft(IsLeft());
	//	//part->SetBug(mBug);
	//	part->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
	//	//part->SetLeft(IsLeft());
	//	part->SetAge(0);
	//	AddChild(part);

	//	auto partL = make_shared<CSegment>(GetBug());
	//	partL->SetPosition(PointF(childLX, 0));
	//	//part->SetBug(mBug);
	//	partL->SetAngle(IsLeft() ? Random(-10, 30) : -Random(-10, 30));
	//	//part->SetLeft(IsLeft());
	//	partL->SetAge(0);
	//	AddChild(partL);
	//}

	CBugPart::Draw(graphics);
}
