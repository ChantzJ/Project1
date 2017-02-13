/**
 * \file BugFactory.cpp
 *
 * \author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "stdafx.h"
#include "BugFactory.h"
#include "Bug.h"
#include "Basket.h"
#include "ActualBug.h"
#include "BugPart.h"
#include "BugRoot.h"
#include "ActualBasket.h"

using namespace std;

/**
 * Constructor
 */
CBugFactory::CBugFactory()
{
}


/**
 * Destructor
 */
CBugFactory::~CBugFactory()
{
}


/**
 * Create a bug object
 * \returns Object of type CBug
 */
std::shared_ptr<CBug> CBugFactory::CreateBug()
{
	shared_ptr<CActualBug> bug = make_shared<CActualBug>();

	auto part = make_shared<CBugRoot>(bug);
	part->SetPosition(PointF(0,-114));
	//part->SetChildStatus(true);
	bug->SetRoot(part);
//	bug->AddPart(part);


	return bug;
}


/**
 * Create a Basket object
 * \returns Object of type CBasket
 */
std::shared_ptr<CBasket> CBugFactory::CreateBasket()
{
	shared_ptr<CActualBasket> basket = make_shared<CActualBasket>();
	


    return basket;
}

