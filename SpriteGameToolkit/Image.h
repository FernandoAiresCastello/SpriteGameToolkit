#pragma once
#include <SDL.h>
#include <string>
#include "Global.h"

namespace SpriteGameToolkit
{
	class Image
	{
	public:
		Image(std::string file);
		Image(std::string file, int transparencyKey);
		Image(int width, int height);
		~Image();

		SDL_Surface* GetSurface();
		SDL_Texture* GetTexture(SDL_Renderer* rend);
		int GetWidth();
		int GetHeight();
		bool IsTransparent();
		void FillWithColor(int color);

	private:
		SDL_Surface* Sfc;
		SDL_Texture* Tex;
		bool Transparent;
		int TransparencyKey;
		int Width;
		int Height;

		void Init(std::string file, bool transparent, int transparencyKey);
	};
}
