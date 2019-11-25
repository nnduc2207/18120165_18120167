#pragma once
#include "Function_Library.h"
#include "cPaddle.h"

class CRacket : public cPaddle
{
private:
	float x;
	float y;
	int red;
	int green;
	int blue;
public:
	float GetPos_x(); // return x
	float GetPos_y(); // return y
	void InitLeft(); // create first position for left racket
	void InitRight(); // create first position for right racket
	void RandomColor(); // Set color of racket random
	void Show(); // draw racket
	void Move(int); // 0 is go up and 1 is go down
};

