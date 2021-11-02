#include "SceneViewport.h"
#include "Scene.h"

namespace SpriteGameToolkit
{
	SceneViewport::SceneViewport()
		: SceneViewport(NULL, 0, 0, 0, 0, 0, 0)
	{
	}

	SceneViewport::SceneViewport(class Scene* scene, int x, int y, int w, int h, int scx, int scy)
	{
		Scene = scene;
		X = x;
		Y = y;
		Width = w;
		Height = h;
		ScrollX = scx;
		ScrollY = scy;
	}

	SceneViewport::~SceneViewport()
	{
	}

	void SceneViewport::SetScene(class Scene* scene)
	{
		Scene = scene;
	}

	class Scene* SceneViewport::GetScene()
	{
		return Scene;
	}

	int SceneViewport::GetX()
	{
		return X;
	}

	int SceneViewport::GetY()
	{
		return Y;
	}

	int SceneViewport::GetWidth()
	{
		return Width;
	}

	int SceneViewport::GetHeight()
	{
		return Height;
	}

	int SceneViewport::GetScrollX()
	{
		return ScrollX;
	}

	int SceneViewport::GetScrollY()
	{
		return ScrollY;
	}
}
