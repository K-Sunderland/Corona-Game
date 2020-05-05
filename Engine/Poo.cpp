#include "Poo.h"
#include "Graphics.h"
#include <assert.h>

void Poo::Init(int in_x, int in_y, int in_vx, int in_vy)
{

	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	initialized = true;
}

void Poo::Update()
{
	
	x += vx;
	y += vy;
	const int right = x + width;

	if (x < 0) {
		x = 1;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth) {
		x = (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}
	const int bottom = y + height;
	if (y < 0)
	{
		y = 1;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}
	
}

void Poo::StopPoo()
{
	vx = 0;
	vy = 0;
}

bool Poo::ProcessCollision( Dude& dude)
{
	
	const int duderight = dude.getX() + dude.getWidth();
	const int dudebottom = dude.getY() + dude.getHeight();
	const int pooright = x + width;
	const int poobottom = y + height;
	if (
		duderight >= x &&
		dude.getX() <= pooright &&
		dudebottom >= y &&
		dude.getY() <= poobottom )
		{
		return true;
}
	else {
		return false;
	}

}


void Poo::setIsEaten(bool input) 
{
	
	isEaten = input;

}

int Poo::getX() const
{
	return x;
}

int Poo::getY() const
{
	return y;
}

int Poo::getWidth() const
{
	return width;
}

int Poo::getHeight() const
{
	return height;
}

 bool Poo::readDrawFinished()
{
	
	return drawFinished;
}

	void Poo::Draw(Graphics& gfx)  const
	{
		
		
		gfx.PutPixel(x + 7, y + 2, 40, 38, 38);
		gfx.PutPixel(x + 8, y + 2, 40, 38, 38);
		gfx.PutPixel(x + 9, y + 2, 40, 38, 38);
		gfx.PutPixel(x + 10, y + 2, 40, 38, 38);
		gfx.PutPixel(x + 11, y + 2, 40, 38, 38);
		gfx.PutPixel(x + 12, y + 2, 40, 38, 38);
		gfx.PutPixel(x + 13, y + 2, 40, 38, 38);
		gfx.PutPixel(x + 6, y + 3, 40, 38, 38);
		gfx.PutPixel(x + 7, y + 3, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 3, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 3, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 3, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 3, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 3, 93, 55, 33);
		gfx.PutPixel(x + 13, y + 3, 214, 175, 151);
		gfx.PutPixel(x + 14, y + 3, 40, 38, 38);
		gfx.PutPixel(x + 5, y + 4, 40, 38, 38);
		gfx.PutPixel(x + 6, y + 4, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 4, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 4, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 4, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 4, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 4, 93, 55, 33);
		gfx.PutPixel(x + 12, y + 4, 71, 43, 26);
		gfx.PutPixel(x + 13, y + 4, 93, 55, 33);
		gfx.PutPixel(x + 14, y + 4, 214, 175, 151);
		gfx.PutPixel(x + 15, y + 4, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 5, 40, 38, 38);
		gfx.PutPixel(x + 5, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 5, 93, 55, 33);
		gfx.PutPixel(x + 13, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 5, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 5, 214, 175, 151);
		gfx.PutPixel(x + 16, y + 5, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 6, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 5, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 6, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 6, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 7, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 7, 156, 128, 110);
		gfx.PutPixel(x + 5, y + 7, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 7, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 7, 255, 255, 255);
		gfx.PutPixel(x + 8, y + 7, 0, 0, 0);
		gfx.PutPixel(x + 9, y + 7, 0, 0, 0);
		gfx.PutPixel(x + 10, y + 7, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 7, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 7, 0, 0, 0);
		gfx.PutPixel(x + 13, y + 7, 0, 0, 0);
		gfx.PutPixel(x + 14, y + 7, 255, 255, 255);
		gfx.PutPixel(x + 15, y + 7, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 7, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 7, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 8, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 8, 156, 128, 110);
		gfx.PutPixel(x + 5, y + 8, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 8, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 8, 0, 0, 0);
		gfx.PutPixel(x + 8, y + 8, 0, 0, 0);
		gfx.PutPixel(x + 9, y + 8, 0, 0, 0);
		gfx.PutPixel(x + 10, y + 8, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 8, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 8, 0, 0, 0);
		gfx.PutPixel(x + 13, y + 8, 0, 0, 0);
		gfx.PutPixel(x + 14, y + 8, 0, 0, 0);
		gfx.PutPixel(x + 15, y + 8, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 8, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 8, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 9, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 9, 156, 128, 110);
		gfx.PutPixel(x + 5, y + 9, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 9, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 9, 0, 0, 0);
		gfx.PutPixel(x + 8, y + 9, 0, 0, 0);
		gfx.PutPixel(x + 9, y + 9, 0, 0, 0);
		gfx.PutPixel(x + 10, y + 9, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 9, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 9, 0, 0, 0);
		gfx.PutPixel(x + 13, y + 9, 0, 0, 0);
		gfx.PutPixel(x + 14, y + 9, 0, 0, 0);
		gfx.PutPixel(x + 15, y + 9, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 9, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 9, 93, 76, 66);
		gfx.PutPixel(x + 18, y + 9, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 10, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 5, y + 10, 93, 55, 33);
		gfx.PutPixel(x + 6, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 10, 93, 76, 66);
		gfx.PutPixel(x + 17, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 10, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 10, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 11, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 11, 93, 55, 33);
		gfx.PutPixel(x + 5, y + 11, 71, 43, 26);
		gfx.PutPixel(x + 6, y + 11, 93, 55, 33);
		gfx.PutPixel(x + 7, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 11, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 11, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 12, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 5, y + 12, 93, 55, 33);
		gfx.PutPixel(x + 6, y + 12, 0, 0, 0);
		gfx.PutPixel(x + 7, y + 12, 0, 0, 0);
		gfx.PutPixel(x + 8, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 12, 0, 0, 0);
		gfx.PutPixel(x + 16, y + 12, 0, 0, 0);
		gfx.PutPixel(x + 17, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 12, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 12, 40, 38, 38);
		gfx.PutPixel(x + 3, y + 13, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 5, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 13, 0, 0, 0);
		gfx.PutPixel(x + 9, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 13, 0, 0, 0);
		gfx.PutPixel(x + 15, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 13, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 13, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 14, 40, 38, 38);
		gfx.PutPixel(x + 5, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 14, 0, 0, 0);
		gfx.PutPixel(x + 10, y + 14, 0, 0, 0);
		gfx.PutPixel(x + 11, y + 14, 0, 0, 0);
		gfx.PutPixel(x + 12, y + 14, 0, 0, 0);
		gfx.PutPixel(x + 13, y + 14, 0, 0, 0);
		gfx.PutPixel(x + 14, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 14, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 14, 40, 38, 38);
		gfx.PutPixel(x + 5, y + 15, 40, 38, 38);
		gfx.PutPixel(x + 6, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 15, 246, 11, 106);
		gfx.PutPixel(x + 11, y + 15, 246, 11, 106);
		gfx.PutPixel(x + 12, y + 15, 246, 11, 106);
		gfx.PutPixel(x + 13, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 15, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 15, 93, 76, 66);
		gfx.PutPixel(x + 21, y + 15, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 16, 40, 38, 38);
		gfx.PutPixel(x + 5, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 6, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 16, 246, 11, 106);
		gfx.PutPixel(x + 12, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 16, 93, 55, 33);
		gfx.PutPixel(x + 16, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 16, 93, 76, 66);
		gfx.PutPixel(x + 20, y + 16, 156, 128, 110);
		gfx.PutPixel(x + 21, y + 16, 40, 38, 38);
		gfx.PutPixel(x + 4, y + 17, 40, 38, 38);
		gfx.PutPixel(x + 5, y + 17, 71, 43, 26);
		gfx.PutPixel(x + 6, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 7, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 17, 93, 55, 33);
		gfx.PutPixel(x + 15, y + 17, 71, 43, 26);
		gfx.PutPixel(x + 16, y + 17, 93, 55, 33);
		gfx.PutPixel(x + 17, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 17, 156, 128, 110);
		gfx.PutPixel(x + 21, y + 17, 40, 38, 38);
		gfx.PutPixel(x + 5, y + 18, 40, 38, 38);
		gfx.PutPixel(x + 6, y + 18, 71, 43, 26);
		gfx.PutPixel(x + 7, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 8, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 18, 93, 55, 33);
		gfx.PutPixel(x + 15, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 18, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 18, 40, 38, 38);
		gfx.PutPixel(x + 6, y + 19, 40, 38, 38);
		gfx.PutPixel(x + 7, y + 19, 71, 43, 26);
		gfx.PutPixel(x + 8, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 9, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 19, 156, 128, 110);
		gfx.PutPixel(x + 21, y + 19, 40, 38, 38);
		gfx.PutPixel(x + 7, y + 20, 40, 38, 38);
		gfx.PutPixel(x + 8, y + 20, 71, 43, 26);
		gfx.PutPixel(x + 9, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 10, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 20, 156, 128, 110);
		gfx.PutPixel(x + 21, y + 20, 40, 38, 38);
		gfx.PutPixel(x + 8, y + 21, 40, 38, 38);
		gfx.PutPixel(x + 9, y + 21, 71, 43, 26);
		gfx.PutPixel(x + 10, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 11, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 12, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 13, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 14, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 15, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 16, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 17, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 18, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 19, y + 21, 156, 128, 110);
		gfx.PutPixel(x + 20, y + 21, 40, 38, 38);
		gfx.PutPixel(x + 9, y + 22, 40, 38, 38);
		gfx.PutPixel(x + 10, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 11, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 12, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 13, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 14, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 15, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 16, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 17, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 18, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 19, y + 22, 71, 43, 26);
		gfx.PutPixel(x + 20, y + 22, 40, 38, 38);
		gfx.PutPixel(x + 10, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 11, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 12, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 13, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 14, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 15, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 16, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 17, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 18, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 19, y + 23, 40, 38, 38);
		gfx.PutPixel(x + 20, y + 23, 40, 38, 38);







}

bool Poo::IsEaten() const
{
	
	return isEaten;
}
void Poo::setDrawFinished(bool input) 
{
	
	drawFinished = input;
}


