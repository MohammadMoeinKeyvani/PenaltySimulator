#include "Brick.h"

Brick::Brick(const Rect& rectInput, Color c)
	:
	rect(rectInput),
	color(c)
{
}

void Brick::Draw(Graphics& gfx)
{
	if (!destroyed)
	{
		gfx.DrawRect(rect.GetExpanded(-1), color);
	}
}

bool Brick::DoBallCollision(Ball& ball)
{
	if (!destroyed && rect.IsCollidingWith(ball.GetRectangle()))
	{
		destroyed = true;
		return true;
	}
	return false;
}