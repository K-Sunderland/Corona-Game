#pragma once
#include "dude.h"
#include <random>
#include "Graphics.h"
class Box {
public:
	 // void Flash();
	void RandPos();
	void ProcessCollision(Dude& dude);
	void Draw(Graphics& gfx, int level);
	void ScoreBar(Graphics& gfx, int x);
	void resetScore();
	int getScore();
	void setScoreInc(int input);
private:
	int score = 0;
	/* 
	int r = 0;
	int g = 255;
	int b = 127;
	*/
	int x;
	int y;
	int width = 10;
	int height = 10;
	bool colorInc;
	int scoreInc;
};