#pragma once
#include <vector>
#include "Global.h"
#include "SpriteBase.h"

namespace SpriteGameToolkit
{
	class Image;

	class ImageSprite : public SpriteBase
	{
	public:
		ImageSprite(Image* image);
		~ImageSprite();

		void AddFrame(Image* image);
		Image* GetFrame(int frame);
		int GetFrameCount();

		virtual void StepAnimation();

	private:
		std::vector<Image*> Frames;
	};
}
