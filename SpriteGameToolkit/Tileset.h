#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include "Global.h"

namespace SpriteGameToolkit
{
	class Image;

	struct TiledPosition
	{
		int X;
		int Y;
	};

	class Tileset
	{
	public:
		Tileset(Image* image, int tileWidth, int tileHeight);
		Tileset(Image* image, int tileWidth, int tileHeight, int transparencyKey);
		~Tileset();

		Image* GetImage();
		int GetTileWidth();
		int GetTileHeight();
		int GetCols();
		int GetRows();
		int GetTileXFromIndex(int index);
		int GetTileYFromIndex(int index);

	private:
		Image* Img;
		int TileWidth;
		int TileHeight;
		int Cols;
		int Rows;
		std::vector<TiledPosition> TiledPositions;

		void Init(Image* img, int tileWidth, int tileHeight);
		void CalculateTiledPositions();
	};
}
