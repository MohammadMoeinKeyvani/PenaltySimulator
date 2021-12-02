#pragma once

#include "Vec2.h"
#include "Ball.h"
#include "Colors.h"
#include "Keyboard.h"

class Goalkeeper
{
public:
	Goalkeeper(Vec2 inputPos, 
		float inputHalfWidt, 
		float inputHalfHeight, 
		float inputSpeed, 
		int inputDirection);
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const Rect wall);
	void Update(float deltaTime);
	void Draw(Graphics& gfx);
	void GameOver();
	Rect GetRectangle() const;
private:
	Vec2 position;
	Color color = Colors::Green;
	float halfWidth;
	float halfHeight;
	float speed;
	float margin = halfWidth / 2.5f;
	int direction;
	Color marginColor = Colors::Red;
};