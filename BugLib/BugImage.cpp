#include "stdafx.h"
#include "BugImage.h"

using namespace std;
using namespace Gdiplus;


CBugImage::CBugImage()
{
}

CBugImage::CBugImage(std::wstring name)
{
	LoadImage(mImage,name);
}


CBugImage::~CBugImage()
{
}

void CBugImage::LoadImage(std::unique_ptr<Gdiplus::Bitmap>& image, std::wstring name)
{
	wstring filename = name;
	image = unique_ptr<Bitmap>(Bitmap::FromFile(filename.c_str()));
	if (image->GetLastStatus() != Ok)
	{
		wstring msg(L"Failed to open ");
		msg += filename;
		AfxMessageBox(msg.c_str());
	}
}


void CBugImage::Draw(Graphics * graphics, bool mirror)
{
	//graphics->DrawImage(mBug.get(), 0, 0,
	//	mBug->GetWidth(), mBug->GetHeight());

	if (mirror)
	{
		graphics->DrawImage(mImage.get(), 0,
			-(int)mImage->GetHeight() / 2,
			-(int)mImage->GetWidth(), mImage->GetHeight());
	}
	else
	{
		graphics->DrawImage(mImage.get(), 0,
			-(int)mImage->GetHeight() / 2,
			mImage->GetWidth(), mImage->GetHeight());

	}

	
}
