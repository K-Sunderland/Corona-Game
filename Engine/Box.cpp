#include "Box.h"

void Box::Flash()
{
    if (colorInc) {
        if (b >= 253) {
            colorInc = false;
        }
        else {
            r += 4;
            b += 2;
        }
    }
    else {
        if (b <= 127) {
            colorInc = true;
        }
        else {
            r -= 4;
            b -= 2;
        }
    }
}

void Box::RandPos()
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(0, 770);
    std::uniform_int_distribution<int> yDist(19 , 570);
    x = xDist(rng);
    y = yDist(rng);
  
}

void Box::ProcessCollision(Dude& dude) {
    const int duderight = dude.getX() + dude.getWidth();
    const int dudebottom = dude.getY() + dude.getHeight();
    const int boxright = x + width;
    const int boxbottom = y + height;
    if (
        duderight >= x &&
        dude.getX() <= boxright &&
        dudebottom >= y &&
        dude.getY() <= boxbottom)
    {
        score += scoreInc;
        RandPos();
       
    }
  

}

void Box::Draw(Graphics& gfx) {
   gfx.DrawRectDimensions(x, y, width, height, r, g, b);
}

void Box::ScoreBar(Graphics& gfx, int x)
{ 
    int  y = 6;
    for (int i = x; i < x + score; i += 10) {
        gfx.PutPixel(0 + i, 0 + y, 0, 47, 255);
        gfx.PutPixel(1 + i, 0 + y, 0, 255, 234);
        gfx.PutPixel(2 + i, 0 + y, 0, 255, 234);
        gfx.PutPixel(3 + i, 0 + y, 0, 47, 255);
        gfx.PutPixel(4 + i, 0 + y, 0, 47, 255);
        gfx.PutPixel(5 + i, 0 + y, 0, 47, 255);
        gfx.PutPixel(6 + i, 0 + y, 0, 255, 234);
        gfx.PutPixel(7 + i, 0 + y, 0, 255, 234);
        gfx.PutPixel(8 + i, 0 + y, 0, 47, 255);
        gfx.PutPixel(9 + i, 0 + y, 0, 47, 255);
        gfx.PutPixel(0 + i, 1 + y, 0, 255, 234);
        gfx.PutPixel(1 + i, 1 + y, 0, 255, 234);
        gfx.PutPixel(2 + i, 1 + y, 0, 47, 255);
        gfx.PutPixel(3 + i, 1 + y, 0, 47, 255);
        gfx.PutPixel(4 + i, 1 + y, 0, 47, 255);
        gfx.PutPixel(5 + i, 1 + y, 0, 255, 234);
        gfx.PutPixel(6 + i, 1 + y, 0, 255, 234);
        gfx.PutPixel(7 + i, 1 + y, 0, 47, 255);
        gfx.PutPixel(8 + i, 1 + y, 0, 47, 255);
        gfx.PutPixel(9 + i, 1 + y, 0, 47, 255);
        gfx.PutPixel(0 + i, 2 + y, 0, 255, 234);
        gfx.PutPixel(1 + i, 2 + y, 0, 47, 255);
        gfx.PutPixel(2 + i, 2 + y, 0, 47, 255);
        gfx.PutPixel(3 + i, 2 + y, 0, 47, 255);
        gfx.PutPixel(4 + i, 2 + y, 0, 255, 234);
        gfx.PutPixel(5 + i, 2 + y, 0, 255, 234);
        gfx.PutPixel(6 + i, 2 + y, 0, 47, 255);
        gfx.PutPixel(7 + i, 2 + y, 0, 47, 255);
        gfx.PutPixel(8 + i, 2 + y, 0, 47, 255);
        gfx.PutPixel(9 + i, 2 + y, 0, 255, 234);
        gfx.PutPixel(0 + i, 3 + y, 0, 47, 255);
        gfx.PutPixel(1 + i, 3 + y, 0, 47, 255);
        gfx.PutPixel(2 + i, 3 + y, 0, 47, 255);
        gfx.PutPixel(3 + i, 3 + y, 0, 255, 234);
        gfx.PutPixel(4 + i, 3 + y, 0, 255, 234);
        gfx.PutPixel(5 + i, 3 + y, 0, 47, 255);
        gfx.PutPixel(6 + i, 3 + y, 0, 47, 255);
        gfx.PutPixel(7 + i, 3 + y, 0, 47, 255);
        gfx.PutPixel(8 + i, 3 + y, 0, 255, 234);
        gfx.PutPixel(9 + i, 3 + y, 0, 255, 234);
        gfx.PutPixel(0 + i, 4 + y, 0, 47, 255);
        gfx.PutPixel(1 + i, 4 + y, 0, 47, 255);
        gfx.PutPixel(2 + i, 4 + y, 0, 255, 234);
        gfx.PutPixel(3 + i, 4 + y, 0, 255, 234);
        gfx.PutPixel(4 + i, 4 + y, 0, 47, 255);
        gfx.PutPixel(5 + i, 4 + y, 0, 47, 255);
        gfx.PutPixel(6 + i, 4 + y, 0, 47, 255);
        gfx.PutPixel(7 + i, 4 + y, 0, 255, 234);
        gfx.PutPixel(8 + i, 4 + y, 0, 255, 234);
        gfx.PutPixel(9 + i, 4 + y, 0, 47, 255);
        gfx.PutPixel(0 + i, 5 + y, 0, 47, 255);
        gfx.PutPixel(1 + i, 5 + y, 0, 255, 234);
        gfx.PutPixel(2 + i, 5 + y, 0, 255, 234);
        gfx.PutPixel(3 + i, 5 + y, 0, 47, 255);
        gfx.PutPixel(4 + i, 5 + y, 0, 47, 255);
        gfx.PutPixel(5 + i, 5 + y, 0, 47, 255);
        gfx.PutPixel(6 + i, 5 + y, 0, 255, 234);
        gfx.PutPixel(7 + i, 5 + y, 0, 255, 234);
        gfx.PutPixel(8 + i, 5 + y, 0, 47, 255);
        gfx.PutPixel(9 + i, 5 + y, 0, 47, 255);
        gfx.PutPixel(0 + i, 6 + y, 0, 255, 234);
        gfx.PutPixel(1 + i, 6 + y, 0, 255, 234);
        gfx.PutPixel(2 + i, 6 + y, 0, 47, 255);
        gfx.PutPixel(3 + i, 6 + y, 0, 47, 255);
        gfx.PutPixel(4 + i, 6 + y, 0, 47, 255);
        gfx.PutPixel(5 + i, 6 + y, 0, 255, 234);
        gfx.PutPixel(6 + i, 6 + y, 0, 255, 234);
        gfx.PutPixel(7 + i, 6 + y, 0, 47, 255);
        gfx.PutPixel(8 + i, 6 + y, 0, 47, 255);
        gfx.PutPixel(9 + i, 6 + y, 0, 47, 255);
        gfx.PutPixel(0 + i, 7 + y, 0, 255, 234);
        gfx.PutPixel(1 + i, 7 + y, 0, 47, 255);
        gfx.PutPixel(2 + i, 7 + y, 0, 47, 255);
        gfx.PutPixel(3 + i, 7 + y, 0, 47, 255);
        gfx.PutPixel(4 + i, 7 + y, 0, 255, 234);
        gfx.PutPixel(5 + i, 7 + y, 0, 255, 234);
        gfx.PutPixel(6 + i, 7 + y, 0, 47, 255);
        gfx.PutPixel(7 + i, 7 + y, 0, 47, 255);
        gfx.PutPixel(8 + i, 7 + y, 0, 47, 255);
        gfx.PutPixel(9 + i, 7 + y, 0, 255, 234);
        gfx.PutPixel(0 + i, 8 + y, 0, 47, 255);
        gfx.PutPixel(1 + i, 8 + y, 0, 47, 255);
        gfx.PutPixel(2 + i, 8 + y, 0, 47, 255);
        gfx.PutPixel(3 + i, 8 + y, 0, 255, 234);
        gfx.PutPixel(4 + i, 8 + y, 0, 255, 234);
        gfx.PutPixel(5 + i, 8 + y, 0, 47, 255);
        gfx.PutPixel(6 + i, 8 + y, 0, 47, 255);
        gfx.PutPixel(7 + i, 8 + y, 0, 47, 255);
        gfx.PutPixel(8 + i, 8 + y, 0, 255, 234);
        gfx.PutPixel(9 + i, 8 + y, 0, 255, 234);
        gfx.PutPixel(0 + i, 9 + y, 0, 47, 255);
        gfx.PutPixel(1 + i, 9 + y, 0, 47, 255);
        gfx.PutPixel(2 + i, 9 + y, 0, 255, 234);
        gfx.PutPixel(3 + i, 9 + y, 0, 255, 234);
        gfx.PutPixel(4 + i, 9 + y, 0, 47, 255);
        gfx.PutPixel(5 + i, 9 + y, 0, 47, 255);
        gfx.PutPixel(6 + i, 9 + y, 0, 47, 255);
        gfx.PutPixel(7 + i, 9 + y, 0, 255, 234);
        gfx.PutPixel(8 + i, 9 + y, 0, 255, 234);
        gfx.PutPixel(9 + i, 9 + y, 0, 47, 255);
        gfx.PutPixel(0 + i, 10 + y, 0, 47, 255);
        gfx.PutPixel(1 + i, 10 + y, 0, 255, 234);
        gfx.PutPixel(2 + i, 10 + y, 0, 255, 234);
        gfx.PutPixel(3 + i, 10 + y, 0, 47, 255);
        gfx.PutPixel(4 + i, 10 + y, 0, 47, 255);
        gfx.PutPixel(5 + i, 10 + y, 0, 47, 255);
        gfx.PutPixel(6 + i, 10 + y, 0, 255, 234);
        gfx.PutPixel(7 + i, 10 + y, 0, 255, 234);
        gfx.PutPixel(8 + i, 10 + y, 0, 47, 255);
        gfx.PutPixel(9 + i, 10 + y, 0, 47, 255);

    }
    if (score == 750) {
        gfx.PutPixel(x + 750, y + 1, 0, 255, 234);
        gfx.PutPixel(x + 750, y + 2, 0, 255, 234);
        gfx.PutPixel(x + 750, y + 3, 0, 47, 255);
        gfx.PutPixel(x + 750, y + 4, 0, 47, 255);
        gfx.PutPixel(x + 750, y + 5, 0, 47, 255);
        gfx.PutPixel(x + 750, y + 6, 0, 255, 234);
        gfx.PutPixel(x + 750, y + 7, 0, 255, 234);
        gfx.PutPixel(x + 750, y + 8, 0, 47, 255);
        gfx.PutPixel(x + 750, y + 9, 0, 47, 255);

    }

}

void Box::setScore(int input)
{
    score = input;
}

int Box::getScore()
{
    return score;
}

void Box::setScoreInc(int input)
{
    scoreInc = input;
}
