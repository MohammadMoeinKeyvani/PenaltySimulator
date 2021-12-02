/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	randomNum(rd()),
	vxDist(-300.0f, 300.0f),
	vyDist(400.0f, 500.0f),
	gkSpeedDist(200.0f, 350.0f),
	gkRandomDirection(0, 1),
	ball(Vec2(400.0f, 200.0f), Vec2(vxDist(randomNum), vyDist(randomNum))),
	wall(10.0f, 10.0f, float(gfx.ScreenWidth - 10), float(gfx.ScreenHeight - 10)),
	goalkeeper(Vec2(400.0f, 500.0f), 60.0f, 12.0f, gkSpeedDist(randomNum), gkRandomDirection(randomNum))
{
	int left = (gfx.ScreenWidth - (numberOfBrickColumns * brickWidth)) / 2;
	Vec2 topLeft(float(left), 540.0f);


	int i = 0;

	for (int y = 0; y < numberOfBrickRows; y++)
	{
		const Color c(255, 255, 204);

		for (int x = 0; x < numberOfBrickColumns; x++)
		{
			bricks[i] = Brick(
				Rect(topLeft + Vec2(float(x * brickWidth), float(y * brickHeight)),
					brickWidth,
					brickHeight),
				c);
			i++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float deltaTime = ft.Mark();

	goalkeeper.Update(deltaTime);
	goalkeeper.DoWallCollision(wall);

	if (goalkeeper.DoBallCollision(ball) || ball.IsCollidingWithWall(wall))
	{
		goalkeeper.GameOver();
		ball.GameOver();
	}

	ball.Update(deltaTime);
}

void Game::ComposeFrame()
{
	for (Brick& b : bricks)
	{
		b.Draw(gfx);
	}
	gfx.DrawRect(0, 520, 800, 540, Colors::White);
	ball.Draw(gfx);
	goalkeeper.Draw(gfx);
	
}
