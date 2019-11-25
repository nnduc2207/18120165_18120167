#pragma once
#include "Function_Library.h"
class CScore
{
private:
	int score_left;
	int score_right;
public:
	int GetLeftScore(); // return left score
	int GetRightScore(); // return right score
	void Init(); // Create first point of 2 players (0:0)
	void Goal(int); // increase 1 point for left player with 0 and for right player with 1
	int IsEndGame(); // return (0 / -1 / 1) if (none won / player left won / player right won)
	void Show(); // draw score
};


std::string int2str(int x); // convert int into string
void drawText(float x, float y, std::string text); // Show the text on the game at location (x,y) of Oxy