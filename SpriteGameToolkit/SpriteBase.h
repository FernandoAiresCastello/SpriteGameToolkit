#pragma once
#include "Global.h"

namespace SpriteGameToolkit
{
	class PUBLIC_API SpriteBase
	{
	public:
		SpriteBase();
		~SpriteBase();

		void SetX(int x);
		void SetY(int y);
		void SetZ(int z);
		void SetPosition(int x, int y);
		void SetPosition(int x, int y, int z);
		int GetX();
		int GetY();
		int GetZ();
		void SetVisible(bool visible);
		bool IsVisible();
		void SetAnimated(bool animated);
		bool IsAnimated();
		void Move(int dx, int dy);
		void Move(int dx, int dy, int speed);
		int GetBoundingBoxWidth();
		int GetBoundingBoxHeight();
		bool CollidesWith(SpriteBase* other);

	protected:
		int X;
		int Y;
		int Z;
		bool Visible;
		bool Animated;
		int BoundingBoxWidth;
		int BoundingBoxHeight;
	};
}
