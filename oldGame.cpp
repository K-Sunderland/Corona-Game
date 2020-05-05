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

bool Poo::drawFinished = false;
Game::Game(MainWindow& wnd)
	:
	poos(10),
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570)
{
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
	if (!isStarted) {
		// spaghetti code for difficulty selection
		if (!difficultySelected) {
			// adds to color index on up keypress 
			if (wnd.kbd.KeyIsPressed(VK_UP)) {
				if (!colorAdd) {
					if (colorIndex < 2) {
						colorIndex++;
					}
					colorAdd = true;
				}
			}
			else {
				colorAdd = false;
			}
			// subtracts from color index on down keypress
			if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
				if (!colorSub) {

					if (colorIndex > 0) {
						colorIndex--;

					}
					colorSub = true;
				}
			}
			else {
				colorSub = false;
			}
			// changes color based on color index
			switch (colorIndex) {

			case 0:
				hardColor = true;
				normalColor = false;
				break;
			case 1:
				hardColor = false;
				normalColor = true;
				easyColor = false;
				break;
			case 2:
				normalColor = false;
				easyColor = true;
			}
			// locks in selection on enterpress
			if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
				if (!enterPressed) {

					enterPressed = true;
					if (easyColor) {
						difficulty = 0;
					}
					else if (normalColor) {
						difficulty = 1;
					}
					else if (hardColor) {
						difficulty = 2;

					}
					difficultySelected = true;
					instructionDrawn = false;

				}


			}
			else {
				enterPressed = false;
			}

			drawEasy(gfx, easyColor);
			drawNormal(gfx, normalColor);
			drawHard(gfx, hardColor);
			drawSelect(gfx);
		}
		// draws instructions at the beginning of game
		if (!instructionDrawn) {
			DrawInstructions(gfx, 225, 209);
			if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
				if (enterPressed) {}
				else {
			
					instructionDrawn = true;
					enterPressed = true;
					isStarted = true;
				}
			}
			else {
				enterPressed = false;
			}
		}
	}
	// sets everything for new game once old one is over
	if (restart)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			enterPressed = true;
			isFinished = false;
			restart = false;
		}

	}
	if (isStarted && initialized)
	{
		// update / clamp dude on screen
		dude.Update(wnd.kbd);
		dude.ClampToScreen();
		// processes dude collision with poo, and stops the game
		for (size_t  i = 0; i < poos.size(); i++) {
			if (poos[i].ProcessCollision(dude)) {
				if (difficulty == 2) {
					level = 1;
				}
			
				isFinished = true;
				for (size_t j = 0; j < poos.size(); j++) {
					poos[j].StopPoo();
				}
			}

			poos[i].Update();
		}
		box.ProcessCollision(dude);
	}
	else {
		// detect enterpress if game isn't started
		if (!gameOver) {
			if (wnd.kbd.KeyIsPressed(VK_RETURN))
			{
				if (enterPressed) {}
				else {
					levAdd = false;
					box.RandPos();
					box.setScore(0);
				}
			}
			else {
				enterPressed = false;
			}
		}
	}
}



// initializes poos with velocities specified by the level number
void Game::levelSelect(int level, int indexEnd) {
	for (size_t  i = 0; i < poos.size(); i++) {
		std::random_shuffle(&randomVelocityX[0], &randomVelocityX[indexEnd]);
		std::random_shuffle(&randomVelocityY[0], &randomVelocityY[indexEnd]);
		poos[i].Init(xDist(rng), yDist(rng), randomVelocityX[0], randomVelocityY[0], dude);
	}
}
void Game::ComposeFrame() {
	// sets the game as over when level 15 is passed
	if (level == 16 && box.getScore() == 750) {
		gameOver = true;
		isFinished = true;
	}
	// Display level numbers
	if (!initialized)
	{
		// easy difficulty
		if (difficulty == 0) {
			switch (level) {

			case 1:
				poos.resize(2);
				levelSelect(level, 2);
				box.setScoreInc(375);
				break;
			case 2:
				poos.resize(3);
				levelSelect(level, 2);
				box.setScoreInc(375);
				break;
			case 3:
				poos.resize(4);
				levelSelect(level, 2);
				box.setScoreInc(375);
				break;
			case 4:
				poos.resize(5);
				levelSelect(level, 2);
				box.setScoreInc(250);
				break;
			case 5:
				poos.resize(6);
				levelSelect(level, 2);
				box.setScoreInc(250);
				break;
			case 6:
				poos.resize(7);
				levelSelect(level, 2);
				box.setScoreInc(250);
				break;
			case 7:
				poos.resize(8);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 8:
				poos.resize(9);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 9:
				poos.resize(10);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 10:
				poos.resize(11);
				levelSelect(level, 2);
				box.setScoreInc(125);
				break;
			case 11:
				poos.resize(12);
				levelSelect(level, 2);
				box.setScoreInc(125);
				break;
			case 12:
				poos.resize(13);
				levelSelect(level, 2);
				box.setScoreInc(125);
				break;
			case 13:
				poos.resize(14);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 14:
				poos.resize(15);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 15:
				poos.resize(20);
				levelSelect(level, 2);
				box.setScoreInc(75);
				drawFinalRound(gfx);
			}
		}
		// normal difficulty
		else if (difficulty == 1) {
			switch (level) {

			case 1:
				poos.resize(6);
				levelSelect(level, 2);
				box.setScoreInc(375);
				break;
			case 2:
				poos.resize(8);
				levelSelect(level, 2);
				box.setScoreInc(375);
				break;
			case 3:
				poos.resize(10);
				levelSelect(level, 2);
				box.setScoreInc(250);
				break;
			case 4:
				poos.resize(12);
				levelSelect(level, 2);
				box.setScoreInc(250);
				break;
			case 5:
				poos.resize(14);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 6:
				poos.resize(16);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 7:
				poos.resize(18);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 8:
				poos.resize(20);
				levelSelect(level, 2);
				box.setScoreInc(125);
				break;
			case 9:
				poos.resize(22);
				levelSelect(level, 2);
				box.setScoreInc(125);
				break;
			case 10:
				poos.resize(24);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 11:
				poos.resize(26);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 12:
				poos.resize(28);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 13:
				poos.resize(30);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 14:
				poos.resize(32);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 15:
				poos.resize(35);
				levelSelect(level, 2);
				box.setScoreInc(50);
				drawFinalRound(gfx);
			}
		}
		// hard difficulty
		else if (difficulty == 2) {

			switch (level) {

			case 1:
				poos.resize(6);
				levelSelect(level, 2);
				box.setScoreInc(375);
				break;
			case 2:
				poos.resize(8);
				levelSelect(level, 2);
				box.setScoreInc(375);
				break;
			case 3:
				poos.resize(10);
				levelSelect(level, 2);
				box.setScoreInc(250);
				break;
			case 4:
				poos.resize(12);
				levelSelect(level, 2);
				box.setScoreInc(250);
				break;
			case 5:
				poos.resize(14);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 6:
				poos.resize(16);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 7:
				poos.resize(18);
				levelSelect(level, 2);
				box.setScoreInc(150);
				break;
			case 8:
				poos.resize(20);
				levelSelect(level, 2);
				box.setScoreInc(125);
				break;
			case 9:
				poos.resize(22);
				levelSelect(level, 2);
				box.setScoreInc(125);
				break;
			case 10:
				poos.resize(24);
				levelSelect(level, 2);
				box.setScoreInc(75);
				break;
			case 11:
				poos.resize(18);
				levelSelect(level, 4);
				box.setScoreInc(75);
				break;
			case 12:
				poos.resize(20);
				levelSelect(level, 4);
				box.setScoreInc(75);
				break;
			case 13:
				poos.resize(22);
				levelSelect(level, 4);
				box.setScoreInc(75);
				break;
			case 14:
				poos.resize(24);
				levelSelect(level, 4);
				box.setScoreInc(75);
				break;
			case 15:
				poos.resize(26);
				levelSelect(level, 4);
				box.setScoreInc(50);
				drawFinalRound(gfx);

			}
		}
		drawLevel(level, gfx);
		dude.setVals(374, 277);
	}
	// Run game
	else {
		// draws dude and box if game isn't over
		if (!restart) {
			dude.Draw(gfx);
			//	box.Flash();
			box.Draw(gfx, level);
			if (wnd.kbd.KeyIsPressed('D')) {
				level = 15;
				box.setScore(750);
			}
		}
		// draws poos
		for (size_t  i = 0; i < poos.size(); i++) {
			if (!poos[i].IsEaten()) {
				poos[i].Draw(gfx);
			}
		}
		// draws scorebar
		DrawScoreBar(gfx,25, 5);
		box.ScoreBar(gfx, 27);
		// detects if score surpasses 750 and ends game
		if (box.getScore() == 750) {
			Poo::setDrawFinished(true);
			isFinished = true;
		}
	}

	if (isFinished) {

		
		// draws game over (lost) graphic
		if (box.getScore() != 750) {
			DrawGameOver(gfx, 100, 131);
			DrawGameOverText(gfx, 275, 265);

		}
		// draws game over (won) graphic
		else if (box.getScore() == 750 && !gameOver) {
			DrawGameOver(gfx, 100, 131);
			DrawGameContinueText(gfx, 285, 265);
			for (size_t  i = 0; i < poos.size(); i++) {
				poos[i].StopPoo();
				restart = true;
				if (!levAdd) {
					level++;
					levAdd = true;
				}
			}

		}
		// draws game final end
		else if (gameOver) {
			for (size_t  i = 0; i < poos.size(); i++) {
				poos[i].StopPoo();
			}
			restart = false;


			if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
				difficultySelected = false;
				enterPressed = true;
				isFinished = false;
				gameOver = false;
				isStarted = false;
				
			}
			drawYouWin(gfx, 200, 83);
			drawEnding(gfx, 200, 154);
			DrawGameOver(gfx, 308, 336);
			drawEndInstruction(gfx, 200, 464);

		}
		
		dude.Draw(gfx);
	}




}
