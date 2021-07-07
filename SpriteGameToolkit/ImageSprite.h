#pragma once
#include <vector>
#include "Global.h"
#include "SpriteBase.h"

namespace SpriteGameToolkit
{
	class Image;

	class PUBLIC_API ImageSprite : public SpriteBase
	{
	public:
		ImageSprite(Image* image);
		~ImageSprite();

		void AddFrame(Image* image);
		Image* GetFrame(int frame);
		int GetFrameCount();

	private:
		std::vector<Image*> Frames;
	};
}
