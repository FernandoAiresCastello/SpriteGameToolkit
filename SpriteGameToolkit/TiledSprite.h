#pragma once
#include <vector>
#include "Global.h"
#include "SpriteBase.h"

namespace SpriteGameToolkit
{
	class Tileset;

	class TiledSprite : public SpriteBase
	{
	public:
		TiledSprite(class Tileset* tileset);
		TiledSprite(class Tileset* tileset, int tileIndex);
		~TiledSprite();

		class Tileset* GetTileset();
		void AddFrame(int tileIndex);
		int GetFrame(int frame);
		int GetFrameCount();
		void MoveTiled(int dx, int dy);
	
	private:
		class Tileset* Tileset;
		std::vector<int> Frames;
	};
}
