#pragma once
#include "graphics.h"
#include "keyboard.h"
class Dude
{
public:
	void ClampToScreen();
	void Draw(Graphics& gfx) const;
	bool Update( const Keyboard& kbd);
	int getX()const;
	int getY() const;
	int getHeight() const;
	int getWidth() const;
	void resetVals();
private:
	int x = 400;
	int y = 300;
	static constexpr int width = 24;
	static constexpr int height = 26;
	int velocity = 2;
	
};