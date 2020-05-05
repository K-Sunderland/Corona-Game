#pragma once
#include "graphics.h"
#include "keyboard.h"
class Dude
{
public:
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	bool Update( const Keyboard& kbd);
	int getX();
	int getY();
	int getHeight();
	int getWidth();
	void setVals(int x, int y );
private:
	int x = 400;
	int y = 300;
	static constexpr int width = 26;
	static constexpr int height = 23;
	int velocity = 2;
	
};