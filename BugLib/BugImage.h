/**
* \file BugImage.h
*
* \author Chantz Johnson
*
* Class to draw Images
*/

#pragma once
#include "memory"
#include "string"

using namespace Gdiplus;

/**
* Class that draws images
*/
class CBugImage
{
public:

	/// default constructor
	CBugImage();

	/**
	* Constructor
	* \param name
	*
	*/
	CBugImage(std::wstring name);

	/// destructor
	virtual ~CBugImage();

	/**
	* Function to load images
	* \param image
	* \param name
	*
	*/
	void LoadImage(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name);

	//void LoadImage(std::wstring name);

	/**
	* Function to Draw
	* \param graphics context
	* \param side
	*
	*/
	void Draw(Graphics * graphics, bool side);

	/**
	* Getter for width
	* \return mImage->GetWidth()
	* 
	*
	*/
	double GetWidth() { return mImage->GetWidth(); }

	/**
	* Getter for height
	* \return mImage->GetHeight()
	*
	*
	*/
	double GetHeight() { return mImage->GetHeight(); }

private:

	/// the image we are drawing
	std::unique_ptr<Gdiplus::Bitmap> mImage;

};



