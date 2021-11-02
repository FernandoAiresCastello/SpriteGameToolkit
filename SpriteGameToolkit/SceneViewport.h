#pragma once
#include "Global.h"

namespace SpriteGameToolkit
{
	class Scene;

	class SceneViewport
	{
	public:
		SceneViewport();
		SceneViewport(class Scene* scene, int x, int y, int w, int h, int scx, int scy);
		~SceneViewport();

		void SetScene(class Scene* scene);
		Scene* GetScene();
		int GetX();
		int GetY();
		int GetWidth();
		int GetHeight();
		int GetScrollX();
		int GetScrollY();

	private:
		class Scene* Scene;
		int X;
		int Y;
		int Width;
		int Height;
		int ScrollX;
		int ScrollY;
	};
}
