/**
 * \file Bug.h
 *
 * \author Charles Owen
 *
 * Class that represents a bug.
 *
 * You are not allowed to change this class in any way!
 */

#pragma once

#include <vector>
#include <memory>

class CHead;
class CBugStandin;

/**
 * Class that represents a bug.
 *
 * This uses a standin class to provide a way to develop
 * the adapter class first if you so choose.
 *
 * You are not allowed to change this class in any way!
 *
 * AFX_EXT_CLASS is a Microsoft directive that indicates
 * that this class can be used outside the DLL. Do not change
 * it or add it to any other classes.
 */
class AFX_EXT_CLASS CBug
{
public:
    /// Constructor
    CBug();

    /// Destructor
    virtual ~CBug() {}

    /// Copy constructor/disabled
    CBug(const CBug &) = delete;

    /// Assignment operator/disabled
    void operator=(const CBug &) = delete;

    /**
    * Draw the bug at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    virtual void DrawBug(Gdiplus::Graphics *graphics);

    /**
    * Set the current bug animation frame
    * \param frame Frame number
    */
    virtual void SetBugFrame(int frame);

    /**
    * Set  the bend angle
    * \param bend Bend angle in radians
    */
    virtual void SetBend(double bend);

    /**
    * Set the bug seed
    * \param seed An integer number. Each number makes a different bug
    */
    virtual void SetSeed(int seed);

    /**
     * Get the current bug seed
     * \return Bug seed integer
     */
    virtual int GetSeed();

    /**
     * Harvest the head
     * \return Pointer to a CHead object or null if none to harvest.
     */
    virtual std::shared_ptr<CHead> Harvest();


private:
    /**
     * A stand-in bug class. 
     *
     * This draws simple stand-in graphics
     * so you can see where the bug will be and what its state
     * is. This makes it easy to develop code that uses the
     * bug before you have the bug working.
     *
     * And no, you may not change this to point to your
     * bug implementation!
     */
    std::shared_ptr<CBugStandin> mStandin;
};

