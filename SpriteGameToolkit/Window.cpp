#include "Window.h"
#include "Color.h"
#include "Image.h"
#include "Tileset.h"
#include "TiledSprite.h"
#include "ImageSprite.h"

namespace SpriteGameToolkit
{
	Window::Window(int width, int height)
		: Window(width, height, width, height)
	{
	}

	Window::Window(int width, int height, int zoom)
		: Window(width, height, zoom * width, zoom* height)
	{
	}

	Window::Window(int screenWidth, int screenHeight, int windowWidth, int windowHeight)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_SetHint(SDL_HINT_RENDER_DRIVER, "direct3d");
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");

		Wnd = SDL_CreateWindow("",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			windowWidth, windowHeight, 0);

		Renderer = SDL_CreateRenderer(Wnd, -1,
			SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

		SDL_RenderSetLogicalSize(Renderer, screenWidth, screenHeight);

		ScreenTex = SDL_CreateTexture(Renderer,
			SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, screenWidth, screenHeight);

		SDL_SetWindowPosition(Wnd, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
		SDL_RaiseWindow(Wnd);

		BackColor = 0x000000;
		Clear();
		Update();
	}

	Window::~Window()
	{
		SDL_DestroyTexture(ScreenTex);
		SDL_DestroyRenderer(Renderer);
		SDL_DestroyWindow(Wnd);
		SDL_Quit();
	}

	void Window::Update()
	{
		SDL_RenderPresent(Renderer);
	}

	void Window::Clear()
	{
		Color color = Color::FromInteger(BackColor);
		SDL_SetRenderDrawColor(Renderer, color.R, color.G, color.B, 255);
		SDL_RenderClear(Renderer);
	}

	void Window::SetBackColor(int color)
	{
		BackColor = color;
	}

	int Window::GetBackColor()
	{
		return BackColor;
	}

	void Window::SetFullscreen(bool full)
	{
		Uint32 fullscreenFlag = SDL_WINDOW_FULLSCREEN_DESKTOP;
		Uint32 isFullscreen = SDL_GetWindowFlags(Wnd) & fullscreenFlag;

		if ((full && isFullscreen) || (!full && !isFullscreen))
			return;

		SDL_SetWindowFullscreen(Wnd, full ? fullscreenFlag : 0);
		SDL_ShowCursor(isFullscreen);
	}

	void Window::ToggleFullscreen()
	{
		Uint32 fullscreenFlag = SDL_WINDOW_FULLSCREEN_DESKTOP;
		Uint32 isFullscreen = SDL_GetWindowFlags(Wnd) & fullscreenFlag;
		SDL_SetWindowFullscreen(Wnd, isFullscreen ? 0 : fullscreenFlag);
		SDL_ShowCursor(isFullscreen);
	}

	void Window::DrawImage(Image* img)
	{
		SDL_Texture* tex = img->GetTexture(Renderer);
		SDL_RenderCopy(Renderer, tex, NULL, NULL);
	}

	void Window::DrawImage(Image* img, int x, int y)
	{
		DrawImage(img, x, y, img->GetWidth(), img->GetHeight());
	}

	void Window::DrawImage(Image* img, int x, int y, int zoom)
	{
		DrawImage(img, x, y, img->GetWidth() * zoom, img->GetHeight() * zoom);
	}

	void Window::DrawImage(Image* img, int x, int y, int w, int h)
	{
		SDL_Texture* tex = img->GetTexture(Renderer);
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		dest.w = w;
		dest.h = h;

		SDL_RenderCopy(Renderer, tex, NULL, &dest);
	}

	void Window::DrawTile(Tileset* tiles, int index, int x, int y)
	{
		SDL_Rect src;
		src.x = tiles->GetTileXFromIndex(index);
		src.y = tiles->GetTileYFromIndex(index);
		src.w = tiles->GetTileWidth();
		src.h = tiles->GetTileHeight();

		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		dest.w = tiles->GetTileWidth();
		dest.h = tiles->GetTileHeight();

		SDL_RenderCopy(Renderer, tiles->GetImage()->GetTexture(Renderer), &src, &dest);
	}

	void Window::DrawSprite(TiledSprite* sprite)
	{
		if (!sprite->IsVisible() || sprite->GetFrameCount() == 0)
			return;

		DrawTile(sprite->GetTileset(), sprite->GetFrame(0), sprite->GetX(), sprite->GetY());
	}

	void Window::DrawSprite(ImageSprite* sprite)
	{
		if (!sprite->IsVisible() || sprite->GetFrameCount() == 0)
			return;

		DrawImage(sprite->GetFrame(0), sprite->GetX(), sprite->GetY());
	}
}
