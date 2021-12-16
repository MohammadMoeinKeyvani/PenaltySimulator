#include "Goalkeeper.h"

Goalkeeper::Goalkeeper(Vec2 inputPos, float inputHalfWidt, float inputHalfHeight, float inputSpeed, int inputDirection)
	:
	position(inputPos),
	halfWidth(inputHalfWidt),
	halfHeight(inputHalfHeight),
	speed(inputSpeed),
	direction(inputDirection)
{
}

bool Goalkeeper::DoBallCollision(Ball& ball) const
{
	if (GetRectangle().IsCollidingWith(ball.GetRectangle()))
	{
		return true;
	}
	return false;
}

void Goalkeeper::DoWallCollision(const Rect wall)
{
	Rect r = GetRectangle();
	if (r.left < wall.left)
	{
		position.x += wall.left - r.left;
	}
	if (r.right > wall.right)
	{
		position.x += wall.right - r.right;
	}
}

void Goalkeeper::Update(float deltaTime)
{
	if (direction)
	{
		position.x -= speed * deltaTime;
	}
	else
	{
		position.x += speed * deltaTime;
	}
	
}

void Goalkeeper::Draw(Graphics& gfx)
{
	

	gfx.DrawRect(GetRectangle(), marginColor);
	Rect r = GetRectangle();
	
	r.left += margin;
	r.right -= margin;
	gfx.DrawRect(r, color);

	Rect head = GetRectangle();
	head.right -= 2 * margin;
	head.left += 2 * margin;
	head.top += 2.0f;
	head.bottom -= 2.0f;
	gfx.DrawRect(head, Colors::Black);

	
}

void Goalkeeper::GameOver()
{
	speed = 0;
}

Rect Goalkeeper::GetRectangle() const
{
	return Rect::FromCenter(position, halfWidth, halfHeight);
}
