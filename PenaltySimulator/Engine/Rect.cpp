#include "Rect.h"

Rect::Rect(float leftInput, float topInput, float rightInput, float bottomInput)
	:
	left(leftInput),
	top(topInput),
	right(rightInput),
	bottom(bottomInput)
{
}

Rect::Rect(const Vec2 topLeft, const Vec2 bottomRight)
	:
	Rect(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y)
{
}

Rect::Rect(const Vec2 topLeft, float width, float height)
	:
	Rect(topLeft, topLeft + Vec2(width, height))
{
}

Rect Rect::FromCenter(const Vec2 center, float halfWidth, float halfHeight)
{
	Vec2 half(halfWidth, halfHeight);
	return Rect(center - half, center + half);
}

bool Rect::IsCollidingWith(const Rect& rect) const
{
	return left < rect.right &&
		right > rect.left &&
		top < rect.bottom &&
		bottom > rect.top;
}

Rect Rect::GetExpanded(float offset) const
{
	return Rect(left - offset, top - offset, right + offset, bottom + offset);
}
