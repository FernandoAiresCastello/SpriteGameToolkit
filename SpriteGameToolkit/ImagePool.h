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

		void SetBasePath(std::string path);
		void Load(std::string id, std::string file);
		Image* Get(std::string id);
		void SetTransparencyKey(int color);

	private:
		std::string BasePath;
		std::map<std::string, Image*> Images;
		int TransparencyKey;
	};
}
