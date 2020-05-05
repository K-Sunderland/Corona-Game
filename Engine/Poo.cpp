#include "Poo.h"
#include "Graphics.h"
#include <assert.h>

void Poo::Init(int in_x, int in_y, int in_vx, int in_vy, Dude& dude)
{

	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	// ensures that all poos are initialized at least 100 pixels from dude

		const int duderight = dude.getX() + dude.getWidth();
		const int dudebottom = dude.getY() + dude.getHeight();
		const int pooright = x + width;
		const int poobottom = y + height;
		if (
			duderight + 100 >= x &&
			dude.getX() - 100 <= pooright &&
			dudebottom + 100 >= y &&
			dude.getY() - 100 <= poobottom) {
			x = 300;
			y = 150;
			vx = 1;
			vy = 1;
		}
	
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
		duderight -2 >= x +2 &&
		dude.getX() +2 <= pooright - 2 &&
		dudebottom  -2 >= y + 2&&
		dude.getY() +2 <= poobottom - 2 )
		{
		return true;
}
	else {
		return false;
	}

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

 void Poo::Draw(Graphics& gfx)  const {
	 gfx.PutPixel(4 + x, 0 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 0 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 0 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 0 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 0 + y, 255, 0, 0);
	 gfx.PutPixel(3 + x, 1 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 1 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 1 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 1 + y, 255, 0, 0);
	 gfx.PutPixel(13 + x, 1 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 2 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 2 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 2 + y, 255, 0, 0);
	 gfx.PutPixel(1 + x, 3 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 3 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 3 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 3 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 3 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 3 + y, 255, 0, 0);
	 gfx.PutPixel(15 + x, 3 + y, 255, 0, 0);
	 gfx.PutPixel(0 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(1 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 4 + y, 255, 138, 146);
	 gfx.PutPixel(9 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 4 + y, 115, 0, 0);
	 gfx.PutPixel(15 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(16 + x, 4 + y, 255, 0, 0);
	 gfx.PutPixel(2 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 5 + y, 115, 0, 0);
	 gfx.PutPixel(12 + x, 5 + y, 115, 0, 0);
	 gfx.PutPixel(14 + x, 5 + y, 255, 0, 0);
	 gfx.PutPixel(3 + x, 6 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 6 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 6 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 6 + y, 255, 138, 146);
	 gfx.PutPixel(7 + x, 6 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 6 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 6 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 6 + y, 255, 138, 146);
	 gfx.PutPixel(11 + x, 6 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 6 + y, 115, 0, 0);
	 gfx.PutPixel(13 + x, 6 + y, 115, 0, 0);
	 gfx.PutPixel(0 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(3 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 7 + y, 115, 0, 0);
	 gfx.PutPixel(13 + x, 7 + y, 115, 0, 0);
	 gfx.PutPixel(16 + x, 7 + y, 255, 0, 0);
	 gfx.PutPixel(0 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(1 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(2 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(3 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 8 + y, 255, 138, 146);
	 gfx.PutPixel(5 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 8 + y, 255, 138, 146);
	 gfx.PutPixel(9 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 8 + y, 255, 138, 146);
	 gfx.PutPixel(13 + x, 8 + y, 115, 0, 0);
	 gfx.PutPixel(14 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(15 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(16 + x, 8 + y, 255, 0, 0);
	 gfx.PutPixel(0 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(3 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 9 + y, 115, 0, 0);
	 gfx.PutPixel(13 + x, 9 + y, 115, 0, 0);
	 gfx.PutPixel(16 + x, 9 + y, 255, 0, 0);
	 gfx.PutPixel(3 + x, 10 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 10 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 10 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 10 + y, 255, 138, 146);
	 gfx.PutPixel(7 + x, 10 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 10 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 10 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 10 + y, 255, 138, 146);
	 gfx.PutPixel(11 + x, 10 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 10 + y, 115, 0, 0);
	 gfx.PutPixel(13 + x, 10 + y, 115, 0, 0);
	 gfx.PutPixel(2 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 11 + y, 115, 0, 0);
	 gfx.PutPixel(12 + x, 11 + y, 115, 0, 0);
	 gfx.PutPixel(14 + x, 11 + y, 255, 0, 0);
	 gfx.PutPixel(0 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(1 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 12 + y, 255, 138, 146);
	 gfx.PutPixel(9 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 12 + y, 115, 0, 0);
	 gfx.PutPixel(11 + x, 12 + y, 115, 0, 0);
	 gfx.PutPixel(15 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(16 + x, 12 + y, 255, 0, 0);
	 gfx.PutPixel(1 + x, 13 + y, 255, 0, 0);
	 gfx.PutPixel(6 + x, 13 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 13 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 13 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 13 + y, 255, 0, 0);
	 gfx.PutPixel(10 + x, 13 + y, 115, 0, 0);
	 gfx.PutPixel(15 + x, 13 + y, 255, 0, 0);
	 gfx.PutPixel(5 + x, 14 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 14 + y, 255, 0, 0);
	 gfx.PutPixel(11 + x, 14 + y, 255, 0, 0);
	 gfx.PutPixel(3 + x, 15 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 15 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 15 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 15 + y, 255, 0, 0);
	 gfx.PutPixel(13 + x, 15 + y, 255, 0, 0);
	 gfx.PutPixel(4 + x, 16 + y, 255, 0, 0);
	 gfx.PutPixel(7 + x, 16 + y, 255, 0, 0);
	 gfx.PutPixel(8 + x, 16 + y, 255, 0, 0);
	 gfx.PutPixel(9 + x, 16 + y, 255, 0, 0);
	 gfx.PutPixel(12 + x, 16 + y, 255, 0, 0);

 }

bool Poo::IsEaten() const
{
	
	return isEaten;
}
void Poo::setDrawFinished(bool input) 
{
	
	drawFinished = input;
}


