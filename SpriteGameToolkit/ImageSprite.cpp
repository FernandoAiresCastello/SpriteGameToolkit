#include "ImageSprite.h"
#include "Image.h"

namespace SpriteGameToolkit
{
	ImageSprite::ImageSprite(Image* image)
	{
		AddFrame(image);
		BoundingBoxWidth = image->GetWidth();
		BoundingBoxHeight = image->GetHeight();
	}

	ImageSprite::~ImageSprite()
	{
	}

	void ImageSprite::AddFrame(Image* image)
	{
		Frames.push_back(image);
	}

	Image* ImageSprite::GetFrame(int frame)
	{
		return Frames[frame % Frames.size()];
	}

	int ImageSprite::GetFrameCount()
	{
		return Frames.size();
	}
}
