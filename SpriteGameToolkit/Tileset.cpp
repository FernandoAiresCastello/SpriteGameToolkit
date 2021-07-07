#include "Tileset.h"
#include "Image.h"

namespace SpriteGameToolkit
{
	Tileset::Tileset(Image* image, int tileWidth, int tileHeight)
	{
		Init(image, tileWidth, tileHeight);
	}

	Tileset::Tileset(Image* image, int tileWidth, int tileHeight, int transparencyKey)
	{
		Init(image, tileWidth, tileHeight);
	}

	void Tileset::Init(Image* img, int tileWidth, int tileHeight)
	{
		Img = img;
		TileWidth = tileWidth;
		TileHeight = tileHeight;
		Cols = Img->GetWidth() / TileWidth;
		Rows = Img->GetHeight() / TileHeight;

		CalculateTiledPositions();
	}

	Tileset::~Tileset()
	{
		delete Img;
	}

	Image* Tileset::GetImage()
	{
		return Img;
	}

	int Tileset::GetTileWidth()
	{
		return TileWidth;
	}

	int Tileset::GetTileHeight()
	{
		return TileHeight;
	}

	int Tileset::GetCols()
	{
		return Cols;
	}

	int Tileset::GetRows()
	{
		return Rows;
	}

	int Tileset::GetTileXFromIndex(int index)
	{
		if (index >= 0 && index < TiledPositions.size())
			return TiledPositions[index].X;

		return -1;
	}

	int Tileset::GetTileYFromIndex(int index)
	{
		if (index >= 0 && index < TiledPositions.size())
			return TiledPositions[index].Y;

		return -1;
	}

	void Tileset::CalculateTiledPositions()
	{
		TiledPositions.clear();

		for (int y = 0; y < Rows; y++) {
			for (int x = 0; x < Cols; x++) {
				TiledPosition pos;
				pos.X = x * TileWidth;
				pos.Y = y * TileHeight;
				TiledPositions.push_back(pos);
			}
		}
	}
}
