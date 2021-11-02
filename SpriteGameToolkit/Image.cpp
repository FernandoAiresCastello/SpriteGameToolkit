#include "Image.h"
#include "CppUtils.h"
using namespace CppUtils;

namespace SpriteGameToolkit
{
	Image::Image(std::string file)
	{
		Init(file, false, NULL);
	}

	Image::Image(std::string file, int transparencyKey)
	{
		Init(file, true, transparencyKey);
	}

	Image::Image(int width, int height)
	{
		Sfc = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
		Tex = NULL;
		Width = Sfc->w;
		Height = Sfc->h;
		Transparent = false;
		TransparencyKey = NULL;
	}

	void Image::Init(std::string file, bool transparent, int transparencyKey)
	{
		if (!File::Exists(file)) {
			MsgBox::Error("File not found", String::Format("Image file \"%s\" not found", file.c_str()));
			return;
		}

		Sfc = SDL_LoadBMP(file.c_str());
		Tex = NULL;
		Width = Sfc->w;
		Height = Sfc->h;
		Transparent = transparent;
		TransparencyKey = transparencyKey;
		
		if (transparent)
			SDL_SetColorKey(Sfc, SDL_TRUE, transparencyKey);
	}

	Image::~Image()
	{
		SDL_FreeSurface(Sfc);
		Sfc = NULL;
		Tex = NULL;
	}

	SDL_Surface* Image::GetSurface()
	{
		return Sfc;
	}

	SDL_Texture* Image::GetTexture(SDL_Renderer* rend)
	{
		if (Tex == NULL)
			Tex = SDL_CreateTextureFromSurface(rend, Sfc);
		
		return Tex;
	}

	int Image::GetWidth()
	{
		return Width;
	}

	int Image::GetHeight()
	{
		return Height;
	}

	bool Image::IsTransparent()
	{
		return Transparent;
	}

	void Image::FillWithColor(int color)
	{
		SDL_FillRect(Sfc, NULL, color);
	}
}
