#include "CBall.h"

void CBall::Init()
{
	pos_x = ball_pos_x;
	pos_y = ball_pos_y;
	go_x = ball_dir_x;
	go_y = ball_dir_y;
	size = ball_size;
	speed = ball_speed;
}

void CBall::Move()
{
	pos_x += go_x * speed;
	pos_y += go_y * speed;
}

void CBall::Show()
{
	glColor3f(1.0, 1.0, 1.0); // White
	glBegin(GL_QUADS); // draw a box
	glVertex2f(pos_x - size / 2, pos_y - size / 2);
	glVertex2f(pos_x + size / 2, pos_y - size / 2);
	glVertex2f(pos_x + size / 2, pos_y + size / 2);
	glVertex2f(pos_x - size / 2, pos_y + size / 2);
	glEnd();
}


float CBall::GetPos_x()
{
	return pos_x;
}

float CBall::GetPos_y()
{
	return pos_y;
}

float CBall::GetDir_x()
{
	return go_x;
}

float CBall::GetDir_y()
{
	return go_y;
}

float CBall::GetSpeed()
{
	return speed;
}

void CBall::SetPosition(float x, float y)
{
	pos_x = x;
	pos_y = y;
}

void CBall::SetDirection(float x, float y)
{
	float a = x,
		b = y;
	vector2d_norm(a, b);
	go_x = a;
	go_y = b;
}

void CBall::SetSpeed(float k)
{
	speed = k;
}


void vector2d_norm(float& x, float& y) {
	// sets a vectors length to 1 (which means that x + y == 1)
	float length = sqrt((x * x) + (y * y));
	if (length != 0.0f) {
		length = 1.0f / length;
		x *= length;
		y *= length;
	}
}