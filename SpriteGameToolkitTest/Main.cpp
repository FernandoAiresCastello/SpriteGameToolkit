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
	imgpool.Load("man1", "C:\\Fernando\\Temp\\man1.bmp");
	imgpool.Load("man2", "C:\\Fernando\\Temp\\man2.bmp");

	Tileset* tiles = new Tileset(imgpool.Get("smiley"), 16, 16);
	Image* sky = imgpool.Get("sky");
	
	TiledSprite* player = new TiledSprite(tiles, 0);
	player->SetPosition(50, 100, 0);
	TiledSprite* enemy = new TiledSprite(tiles, 1);
	enemy->SetPosition(120, 120, 0);
	
	/*
	ImageSprite* player = new ImageSprite(imgpool.Get("man1"));
	player->SetPosition(50, 100, 0);
	ImageSprite* enemy = new ImageSprite(imgpool.Get("man2"));
	enemy->SetPosition(120, 120, 0);
	*/
	
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
		const Uint8* key = SDL_GetKeyboardState(NULL);
		const bool alt = SDL_GetModState() & KMOD_ALT;
		const bool ctrl = SDL_GetModState() & KMOD_CTRL;

		if (e.type == SDL_QUIT) {
			running = false;
		}
		else if (e.type == SDL_KEYDOWN) {
			SDL_Keycode key = e.key.keysym.sym;
			if (key == SDLK_ESCAPE) {
				running = false;
			}
			else if (key == SDLK_RETURN && alt) {
				wnd->ToggleFullscreen();
			}
			else if (key == SDLK_RETURN) {
				player->SetVisible(!player->IsVisible());
			}
		}

		if (key[SDL_SCANCODE_RIGHT]) {
			//player->Move(1, 0, moveSpeed);
			player->MoveTiled(1, 0);
		}
		if (key[SDL_SCANCODE_LEFT]) {
			//player->Move(-1, 0, moveSpeed);
			player->MoveTiled(-1, 0);
		}
		if (key[SDL_SCANCODE_DOWN]) {
			//player->Move(0, 1, moveSpeed);
			player->MoveTiled(0, 1);
		}
		if (key[SDL_SCANCODE_UP]) {
			//player->Move(0, -1, moveSpeed);
			player->MoveTiled(0, -1);
		}
	}

	return 0;
}
