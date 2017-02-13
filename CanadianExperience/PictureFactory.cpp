/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "stdafx.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "BugFactory.h"
#include "BugAdapter.h"
#include "BasketAdapter.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/*! \brief Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
	auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
	picture->AddActor(background);



	auto basket = make_shared<CActor>(L"Bug");
	basket->SetPosition(Point(550, 420));
	basket->SetClickable(false);
	auto basketItem = make_shared<CBasketAdapter>(L"Basket");
	//basketItem->SetPosition(Point(550, 420));
	basket->AddDrawable(basketItem);
	basket->SetRoot(basketItem);
	picture->AddActor(basket);


	auto bug = make_shared<CActor>(L"Bug");
	bug->SetPosition(Point(300, 120));
	bug->SetClickable(false);
	auto bugItem = make_shared<CBugAdapter>(L"Bug");
	bugItem->SetPosition(Point(300, 120));
	bugItem->SetHarvest(750);
	bugItem->SetStart(1);
	bugItem->SetSeed(2345);
	bugItem->SetBasket(basketItem->GetBasket());
	bug->AddDrawable(bugItem);
	bug->SetRoot(bugItem);
	picture->AddActor(bug);

	auto bug2 = make_shared<CActor>(L"Bug2");
	bug->SetPosition(Point(300, 120));
	bug->SetClickable(false);
	auto bugItem2 = make_shared<CBugAdapter>(L"BugItem2");
	bugItem2->SetPosition(Point(300, 120));
	bugItem2->SetHarvest(450);
	bugItem2->SetStart(1);
	bugItem2->SetSeed(1245);
	bugItem2->SetBasket(basketItem->GetBasket());
	bug2->AddDrawable(bugItem2);
	bug2->SetRoot(bugItem2);
	picture->AddActor(bug2);


    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(200, 500));
    picture->AddActor(sparty);



    return picture;
}
