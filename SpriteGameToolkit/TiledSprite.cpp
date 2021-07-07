#include "TiledSprite.h"
#include "Tileset.h"

namespace SpriteGameToolkit
{
	TiledSprite::TiledSprite(class Tileset* tileset)
	{
		Tileset = tileset;
		BoundingBoxWidth = tileset->GetTileWidth();
		BoundingBoxHeight = tileset->GetTileHeight();
	}

	TiledSprite::TiledSprite(class Tileset* tileset, int tileIndex)
		: TiledSprite(tileset)
	{
		AddFrame(tileIndex);
	}

	TiledSprite::~TiledSprite()
	{
	}

	Tileset* TiledSprite::GetTileset()
	{
		return Tileset;
	}

	void TiledSprite::AddFrame(int tileIndex)
	{
		Frames.push_back(tileIndex);
	}

	int TiledSprite::GetFrame(int frame)
	{
		return Frames[frame % Frames.size()];
	}

	int TiledSprite::GetFrameCount()
	{
		return Frames.size();
	}

	void TiledSprite::MoveTiled(int dx, int dy)
	{
		Move(dx * BoundingBoxWidth, dy * BoundingBoxHeight);
	}
}
