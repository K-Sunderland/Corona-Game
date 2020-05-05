#pragma once
#include "dude.h"
#include <random>
#include "Graphics.h"
class Box {
public:
	void Flash();
	void RandPos();
	void ProcessCollision(Dude& dude);
	void Draw(Graphics& gfx);
	void ScoreBar(Graphics& gfx, int x);
	void setScore(int input);
	int getScore();
	void setScoreInc(int input);
private:
	int score = 0;
	int r = 0;
	int g = 255;
	int b = 127;
	int x;
	int y;
	static constexpr int width = 20;
	static constexpr int height = 20;
	bool colorInc;
	int scoreInc;
};