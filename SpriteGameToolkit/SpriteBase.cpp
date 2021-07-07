#include "SpriteBase.h"

namespace SpriteGameToolkit
{
	SpriteBase::SpriteBase()
	{
		X = 0;
		Y = 0;
		Z = 0;
		Visible = true;
		BoundingBoxWidth = 0;
		BoundingBoxHeight = 0;
	}

	SpriteBase::~SpriteBase()
	{
	}

	void SpriteBase::SetX(int x)
	{
		X = x;
	}

	void SpriteBase::SetY(int y)
	{
		Y = y;
	}

	void SpriteBase::SetZ(int z)
	{
		Z = z;
	}

	void SpriteBase::SetPosition(int x, int y)
	{
		X = x;
		Y = y;
	}

	void SpriteBase::SetPosition(int x, int y, int z)
	{
		X = x;
		Y = y;
		Z = z;
	}

	int SpriteBase::GetX()
	{
		return X;
	}

	int SpriteBase::GetY()
	{
		return Y;
	}

	int SpriteBase::GetZ()
	{
		return Z;
	}

	void SpriteBase::SetVisible(bool visible)
	{
		Visible = visible;
	}

	bool SpriteBase::IsVisible()
	{
		return Visible;
	}

	void SpriteBase::SetAnimated(bool animated)
	{
		Animated = animated;
	}

	bool SpriteBase::IsAnimated()
	{
		return Animated;
	}

	void SpriteBase::Move(int dx, int dy)
	{
		X += dx;
		Y += dy;
	}

	void SpriteBase::Move(int dx, int dy, int speed)
	{
		X += dx * speed;
		Y += dy * speed;
	}

	int SpriteBase::GetBoundingBoxWidth()
	{
		return BoundingBoxWidth;
	}

	int SpriteBase::GetBoundingBoxHeight()
	{
		return BoundingBoxHeight;
	}

	bool SpriteBase::CollidesWith(SpriteBase* other)
	{
		return
			X > other->GetX() - BoundingBoxWidth &&
			Y > other->GetY() - BoundingBoxHeight &&
			X < other->GetX() + other->GetBoundingBoxWidth() &&
			Y < other->GetY() + other->GetBoundingBoxHeight();
	}
}
