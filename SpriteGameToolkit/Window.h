#pragma once
#include <SDL.h>
#include "Global.h"

namespace SpriteGameToolkit
{
	class Image;
	class Tileset;
	class TiledSprite;
	class ImageSprite;

	class PUBLIC_API Window
	{
	public:
		Window(int width, int height);
		Window(int width, int height, int zoom);
		Window(int screenWidth, int screenHeight, int windowWidth, int windowHeight);
		~Window();

		void Update();
		void Clear();
		void SetBackColor(int color);
		int GetBackColor();
		void SetFullscreen(bool full);
		void ToggleFullscreen();
		void DrawImage(Image* img);
		void DrawImage(Image* img, int x, int y);
		void DrawImage(Image* img, int x, int y, int zoom);
		void DrawImage(Image* img, int x, int y, int w, int h);
		void DrawTile(Tileset* tiles, int index, int x, int y);
		void DrawSprite(TiledSprite* sprite);
		void DrawSprite(ImageSprite* sprite);

	private:
		SDL_Window* Wnd;
		SDL_Renderer* Renderer;
		SDL_Texture* ScreenTex;

		int BackColor;
	};
}
