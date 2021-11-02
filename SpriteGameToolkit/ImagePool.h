#pragma once
#include <map>
#include <string>
#include "Global.h"

namespace SpriteGameToolkit
{
	class Image;

	class ImagePool
	{
	public:
		ImagePool();
		~ImagePool();

		void Load(std::string id, std::string file);
		Image* Get(std::string id);
		void SetTransparencyKey(int color);

	private:
		std::map<std::string, Image*> Images;
		int TransparencyKey;
	};
}
