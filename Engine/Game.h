/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Poo.h"
#include "Dude.h"
#include <random>
#include <algorithm>
#include "box.h"
#include "Levels.h"
#include <vector>
using namespace std;
class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawInstructions(int x, int y);
	void DrawGameOver(int x, int y);
	void DrawGameOverText(int x, int y);
	void DrawGameContinueText(int x, int y);
	void DrawScoreBar(int x, int y);
	void levelSelect(int level, int indexEnd);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables   */
	bool isFinished = false;
	bool isStarted = false;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	int nPoo = 30;
	vector<Poo> poos;
	int randomVelocityX[6] = { 1 , -1, 2, -2, 3, -3 };
	int randomVelocityY[6] = { 1 , -1, 2, -2, 3, -3 };
	Dude dude; 
	bool restart = false;
	Box box;
	int level = 0;
	bool levAdd = false;
	bool enterPressed = false;
	bool instructionDrawn = true;
	bool gameOver = false;
	int difficulty = 0;
	bool difficultySelected = false;
	bool normalColor = true;
	bool hardColor = false;
	/********************************/
};