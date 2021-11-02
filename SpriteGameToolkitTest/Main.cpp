#include <SDL.h>
#include <SpriteGameToolkit.h>
using namespace SpriteGameToolkit;

int main(int argc, char** args)
{
	Window* wnd = new Window(256, 192, 3);
	wnd->SetBackColor(0x0000ff);

	ImagePool imgpool;
	imgpool.SetTransparencyKey(0xff00ff);
	imgpool.Load("sky", "C:\\Fernando\\Temp\\sky.bmp");
	imgpool.Load("smiley", "C:\\Fernando\\Temp\\smiley.bmp");

	Tileset* tiles = new Tileset(imgpool.Get("smiley"), 16, 16);
	Image* sky = imgpool.Get("sky");
	
	TiledSprite* player = new TiledSprite(tiles, 0);
	player->SetPosition(50, 100, 0);
	TiledSprite* enemy = new TiledSprite(tiles, 1);
	enemy->SetPosition(120, 120, 0);
	
	const int moveSpeed = 1;
	bool running = true;

	while (running) {

		wnd->Clear();
		wnd->DrawImage(sky);
		wnd->DrawSprite(enemy);
		wnd->DrawSprite(player);
		wnd->Update();

		if (player->CollidesWith(enemy)) {
			enemy->SetVisible(false);
		}
		else {
			enemy->SetVisible(true);
		}

		SDL_Event e = { 0 };
		SDL_PollEvent(&e);
		const Uint8* keystate = SDL_GetKeyboardState(NULL);
		const bool alt = SDL_GetModState() & KMOD_ALT;
		const bool ctrl = SDL_GetModState() & KMOD_CTRL;

		bool glEvent = wnd->ProcessEvents(e);
		if (wnd->IsClosed()) {
			running = false;
			break;
		}
		if (!glEvent) {
			if (e.type == SDL_KEYDOWN) {
				SDL_Keycode keycode = e.key.keysym.sym;
				if (keycode == SDLK_RETURN) {
					player->SetVisible(!player->IsVisible());
				}
			}

			if (keystate[SDL_SCANCODE_RIGHT]) {
				player->Move(1, 0, moveSpeed);
			}
			if (keystate[SDL_SCANCODE_LEFT]) {
				player->Move(-1, 0, moveSpeed);
			}
			if (keystate[SDL_SCANCODE_DOWN]) {
				player->Move(0, 1, moveSpeed);
			}
			if (keystate[SDL_SCANCODE_UP]) {
				player->Move(0, -1, moveSpeed);
			}
		}
	}

	return 0;
}
