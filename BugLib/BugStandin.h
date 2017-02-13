/**
 * \file BugStandin.h
 *
 * \author Charles Owen
 *
 * This class is a stand-in class that will allow you to
 * develop the bug adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 */

#pragma once

#include <vector>
#include <memory>

class CHead;


/**
 * This class is a stand-in class that will allow you to
 * develop the bug adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 */
class CBugStandin
{
public:
    CBugStandin();
    virtual ~CBugStandin();

    void DrawBug(Gdiplus::Graphics *graphics);

    /**
    * Set the current bug animation frame
    * \param frame Frame number
    */
    void SetBugFrame(int frame) { mFrame = frame; mHarvested = false; }

    /**
    * Set  the bend angle
    * \param bend Bend angle in radians
    */
    void SetBendAngle(double bend) { mBendAngle = bend; }

    /**
    * Set the bug seed
    * \param seed An integer number. Each number makes a different bug
    */
    void SetSeed(int seed) { mSeed = seed; }

    /**
    * Get the current bug seed
    * \return Bug seed integer
    */
    virtual int GetSeed() { return mSeed; }

    /**
    * Harvest all of the heads
    * \return Vector of objects of type CHead
    */
    std::shared_ptr<CHead> Harvest()
    {
        mHarvested = true;
        return nullptr;
    }

private:
    void CenteredString(Gdiplus::Graphics *graphics, const std::wstring &str, int x, int y, int dy);

    int mX = 0;     ///< Bug X location
    int mY = 0;     ///< Bug Y location
    int mFrame = 0; ///< Current frame
    double mBendAngle = 0;  ///< Bend angle
    int mSeed = 0;  ///< Bug seed
    bool mHarvested = false;    ///< Has it been harvested?
};

