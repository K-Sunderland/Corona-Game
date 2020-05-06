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
		if (!instructionDrawn) {
			drawInstructions(gfx, 200, 151);
			//drawDescription(gfx, 210, 100);
			drawTitle(gfx, 202,40);
			drawTip(gfx, 231, 343);
			drawPressEnter(gfx, 316, 465);
			if (wnd.kbd.KeyIsPressed(VK_RETURN)) { 
				if (!enterPressed) {
					instructionDrawn = true;
					difficultySelected = false;
					enterPressed = true;
					box.RandPos();
				}
			}
			else {
				enterPressed = false;
			}
		}
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
			// locks in selection 
			if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
				if (!enterPressed) {
					enterPressed = true;
					difficultySelected = true;
					if (easyColor) {
						difficulty = 0;
					}
					else if (normalColor) {
						difficulty = 1;
					}
					else if (hardColor) {
						difficulty = 2;
					}
					instructionDrawn = false;
					isStarted = true;
				}
			}
			else {
				enterPressed = false;
			}
			drawEasy(gfx, easyColor);
			drawNormal(gfx, normalColor);
			drawHard(gfx, hardColor);
			drawSelect(gfx);
            drawPressEnter(gfx, 316, 530);
		}
    }

	else {
		if (!initialized) {
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
			levAdd = false;
			drawLevel(level, gfx);
			if (level != 15) {
				drawPressEnter(gfx, 316, 350);
			}
			else {
				drawPressEnter(gfx, 316, 470);

			}
			dude.resetVals();
			if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
				if (!enterPressed) {
					initialized = true;
					gameRun = true;
				}
   		    }
			else {
				enterPressed = false;
			}
        }
    }
	if (gameRun) {
		for (size_t i = 0; i < poos.size(); i++) {
			if (poos[i].ProcessCollision(dude)) {
				isFinished = true;
			}
		}
		if (box.getScore() == 750) {
			isFinished = true;
		}
		if (box.getScore() == 750 && level == 15) {
			isFinished = true;
			gameOver = true;
		}
	}
	if (isFinished) {
		if (box.getScore() == 750 && level != 15) {
			drawGameOver(gfx, 250, 216);
			drawGameContinueText(gfx, 285, 265);
			if (!levAdd) {
				level++;
				levAdd = true;
			}
		}
		else if (box.getScore() != 750) {
			drawGameOver(gfx, 250, 216);
			drawGameOverText(gfx, 275, 265);
		}
		else if (gameOver) {

			drawToiletPaperWall(gfx, 100, 100);
			
		}

		for (size_t i = 0; i < poos.size(); i++) {
			poos[i].StopPoo();
		}
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			if (gameOver) {
				isStarted = false;
				instructionDrawn = true;
				level = 1;
				gameOver = false;
				difficultySelected = false;
			
			}
			isFinished = false;
			initialized = false;
			gameRun = false;
			box.resetScore();
			enterPressed = true;
		}
	}
	
}

void Game::ComposeFrame() {
	

	if (gameRun) {
		if (!gameOver) {
			for (size_t i = 0; i < poos.size(); i++) {
				poos[i].Draw(gfx);
				poos[i].Update();
			}
			dude.Draw(gfx);
			dude.Update(wnd.kbd);
			dude.ClampToScreen();
			box.ScoreBar(gfx, 27);
			drawScoreBar(gfx, 25, 5);
		}
		if (!isFinished) {
	    box.Draw(gfx, level);
		box.ProcessCollision(dude);
		}
	}
}
// initializes poos with velocities specified by the level number
void Game::levelSelect(int level, int indexEnd) {
	for (size_t i = 0; i < poos.size(); i++) {
		std::random_shuffle(&randomVelocityX[0], &randomVelocityX[indexEnd]);
		std::random_shuffle(&randomVelocityY[0], &randomVelocityY[indexEnd]);
		poos[i].Init(xDist(rng), yDist(rng), randomVelocityX[0], randomVelocityY[0], dude);
	}
}