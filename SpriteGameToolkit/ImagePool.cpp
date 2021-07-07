#include "ImagePool.h"
#include "Image.h"

namespace SpriteGameToolkit
{
	ImagePool::ImagePool()
	{
		TransparencyKey = NULL;
	}

	ImagePool::~ImagePool()
	{
		for (auto it = Images.begin(); it != Images.end(); ++it) {
			Image* image = it->second;
			delete image;
			image = NULL;
		}

		Images.clear();
	}

	void ImagePool::Load(std::string id, std::string file)
	{
		Image* image = TransparencyKey != NULL ? 
			new Image(file, TransparencyKey) : new Image(file);

		Images[id] = image;
	}

	Image* ImagePool::Get(std::string id)
	{
		return Images[id];
	}

	void ImagePool::SetTransparencyKey(int color)
	{
		TransparencyKey = color;
	}
}
