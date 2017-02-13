/**
 * \file Bug.cpp
 *
 * \author Charles Owen
 *
 * You are not allowed to change this class in any way!
 *
 * This is a simple adapter class that routes all of the 
 * operations to the class CBugStandin, which is a standin
 * for an actual bug in the system.
 */

#include "stdafx.h"
#include "Bug.h"
#include "BugStandin.h"

using namespace Gdiplus;
using namespace std;


CBug::CBug() 
{
    mStandin = make_shared<CBugStandin>();
}

void CBug::DrawBug(Gdiplus::Graphics *graphics)
{
    mStandin->DrawBug(graphics);
}


void CBug::SetBugFrame(int frame) 
{
    mStandin->SetBugFrame(frame);
}


void CBug::SetBend(double bend) 
{
    mStandin->SetBendAngle(bend);
}


void CBug::SetSeed(int seed) 
{
    mStandin->SetSeed(seed);
}

int CBug::GetSeed()
{
    return mStandin->GetSeed();
}

std::shared_ptr<CHead> CBug::Harvest()
{
    return mStandin->Harvest();
}
