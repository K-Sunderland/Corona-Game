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
#include "Corona.h"
#include "Dude.h"
#include <random>
#include <algorithm>
#include "Box.h"
#include "Drawing.h"
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
	void levelSelect(int level, int indexEnd);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables   */
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	vector<Corona> corona;
	int randomVelocityX[4] = { 1 , -1, 2, -2};
	int randomVelocityY[4] = { 1 , -1, 2, -2};
	Dude dude; 
	Box box;
	bool isFinished = false;
	bool isStarted = false;
	bool restart = false;
	int level = 1;
	bool levAdd = false;
	bool enterPressed = false;
	bool instructionDrawn = false;
	bool gameOver = false;
	int difficulty = 0;
	bool difficultySelected = true;
	bool easyColor = false;
	bool normalColor = true;
	bool hardColor = false;
	int colorIndex = 1;
	bool colorAdd = false;
	bool colorSub = false;
	bool initialized = false;
	bool gameRun = false;
	/********************************/
};