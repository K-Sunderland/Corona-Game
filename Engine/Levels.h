#pragma once
#include "Graphics.h"
#include "Poo.h"
void drawLevel(int level, Graphics& gfx);
void drawText(int level, Graphics& gfx);
void drawFinalRound(Graphics& gfx);
void drawYouWin(Graphics& gfx, int x, int y);
void drawEnding(Graphics& gfx, int x, int y);
void drawEndInstruction(Graphics& gfx, int x, int y);
void drawNormal(Graphics& gfx, bool color);
void drawHard(Graphics& gfx, bool color);