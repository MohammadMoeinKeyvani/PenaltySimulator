#pragma once

#include "Vec2.h"

class Rect
{
public:
	Rect() = default;
	Rect(float leftInput, float topInput, float rightInput, float bottomInput);
	Rect(const Vec2 topLeft, const Vec2 bottomRight);
	Rect(const Vec2 topLeft, float width, float height);
	static Rect FromCenter(const Vec2 center, float halfWidth, float halfHeight);
	bool IsCollidingWith(const Rect& rect) const;
	Rect GetExpanded(float offset) const;
public:
	float left;
	float top;
	float right;
	float bottom;
};