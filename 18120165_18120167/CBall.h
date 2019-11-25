#pragma once
#include "Function_Library.h"]

class CBall
{
private:
	float pos_x;
	float pos_y;
	float go_x;
	float go_y;
	int size;
	float speed;
public:
	float GetPos_x(); // return pos_x
	float GetPos_y(); // return pos_y
	float GetDir_x(); // return go_x
	float GetDir_y(); // return go_y
	float GetSpeed(); // return speed
	void SetPosition(float, float); // change position of ball
	void SetDirection(float, float); // change direction of ball
	void SetSpeed(float); // change speed
	void Init(); // Create first parameter
	void Move(); // ball move
	void Show(); // draw ball
};
void vector2d_norm(float& x, float& y); // make vector (x,y) has size = 1