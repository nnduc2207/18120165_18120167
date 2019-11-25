#include "CRacket.h"

float CRacket::GetPos_x()
{
	return x;
}

float CRacket::GetPos_y()
{
	return y;
}

void CRacket::InitLeft()
{
	x = 10.0f;
	y = (height - racket_height) / 2;
	red = 0;
	green = 0;
	blue = 0;
}

void CRacket::InitRight()
{
	x = width - racket_width - 10;
	y = (height - racket_height) / 2;
	red = 0;
	green = 0;
	blue = 0;
}

void CRacket::RandomColor()
{
	do
	{
		red = rand();
		green = rand();
		blue = rand();
	} while (cos(red) < 0.1 && cos(green) < 0.1 && cos(blue) < 0.1);
}

void CRacket::Show()
{
	glColor3f(cos(red), cos(green), cos(blue));
	glBegin(GL_QUADS); // draw a box
	glVertex2f(x, y);
	glVertex2f(x + racket_width, y);
	glVertex2f(x + racket_width, y + racket_height);
	glVertex2f(x, y + racket_height);
	glEnd();
}

void CRacket::Move(int k)
{
	if (k == 0 && (y + racket_height < height))
	{
		if (y + racket_height + racket_speed >= height)
		{
			y = height - racket_height;
		}
		else
		{
			y += racket_speed;
		}
		return;
	}
	if (k == 1 && y > 0)
	{
		if (y < racket_speed)
			y = 0.0f;
		else
		{
			y -= racket_speed;
		}
		return;
	}
}
