#pragma once
#include "graphics.h"
#include "dude.h"
class Corona
{
public:
	
	void Init(int in_x, int in_y, int in_vx, int in_vy, Dude& dude);
	void Update();
	void StopCorona();
	bool ProcessCollision(Dude& dude);
	void Draw(Graphics& gfx) const;
	bool IsEaten() const;
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
private:
	int x;
	int y;
	int vx;
	int vy;
	static constexpr int width = 17;
	static constexpr int height = 17;
	bool isEaten = false;
	
};