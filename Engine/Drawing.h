#pragma once
#include "Graphics.h"
#include "Poo.h"
void drawLevel(int level, Graphics& gfx);
void drawLevelText(int x, int y, Graphics& gfx);
void drawFinalRound(Graphics& gfx);
void drawYouWin(Graphics& gfx, int x, int y);
void drawEnding(Graphics& gfx, int x, int y);
void drawEndInstruction(Graphics& gfx, int x, int y);
void drawNormal(Graphics& gfx, bool color);
void drawHard(Graphics& gfx, bool color);
void drawGameOverText(Graphics& gfx, int x, int y);
void drawGameContinueText(Graphics& gfx, int x, int y);
void drawInstructions(Graphics& gfx, int x, int y);
void drawTip(Graphics& gfx, int x, int y);
void drawTitle(Graphics& gfx, int x, int y);
void drawDescription(Graphics& gfx, int x, int y);
void drawGameOver(Graphics& gfx, int x, int y);
void drawScoreBar(Graphics& gfx, int x, int y);
void drawEasy(Graphics& gfx, bool color);
void drawSelect(Graphics& gfx);
void drawPressEnter(Graphics& gfx, int x, int y);
void drawEnding(Graphics& gfx, int x, int y);
void drawToiletPaperWall(Graphics& gfx, int x, int y);