#include "Ball.h"

Ball::Ball(Vec2 inputPosition, Vec2 inputVelocity)
	:
	position(inputPosition),
	velocity(inputVelocity)
{
}

void Ball::Draw(Graphics& gfx)
{
	SpriteCodex::DrawBall(position, gfx);
}

void Ball::Update(float deltaTime)
{
	position += velocity * deltaTime;
}

bool Ball::IsCollidingWithWall(const Rect& wall)
{
	const Rect ballRectangle = GetRectangle();
	bool collide = false;
	if (ballRectangle.left < wall.left)
	{
		collide = true;
		position.x += wall.left - ballRectangle.left;
	}
	if (ballRectangle.right > wall.right)
	{
		collide = true;
		position.x += wall.right - ballRectangle.right;
	}
	if (ballRectangle.top < wall.top)
	{
		collide = true;
		position.y += wall.top - ballRectangle.top;
	}
	if (ballRectangle.bottom > wall.bottom)
	{
		collide = true;
		position.y += wall.bottom - ballRectangle.bottom;
	}

	return collide;
}

void Ball::GameOver()
{
	velocity.x = 0;
	velocity.y = 0;
}

Rect Ball::GetRectangle()
{
	Rect rectBall;
	return rectBall.FromCenter(position, radius, radius);
}

Vec2 Ball::GetVelocity()
{
	return velocity;
}
