#pragma once

#include "Rect.h"
#include "Graphics.h"
#include "SpriteCodex.h"

class Ball
{
public:
	Ball(Vec2 inputPosition, Vec2 inputVelocity);
	void Draw(Graphics& gfx);
	void Update(float deltaTime);
	bool IsCollidingWithWall(const Rect& wall);
	void GameOver();
	Rect GetRectangle();
	Vec2 GetVelocity();
private:
	Vec2 position;
	Vec2 velocity;
	static constexpr float radius = 7.0f;
};