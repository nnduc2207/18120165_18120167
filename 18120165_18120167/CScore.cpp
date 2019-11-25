#include "CScore.h"

int CScore::GetLeftScore()
{
	return score_left;
}

int CScore::GetRightScore()
{
	return score_right;
}

void CScore::Init()
{
	score_left = 0;
	score_right = 0;
}

void CScore::Goal(int x)
{
	if (x == 0)
	{
		score_left += 1;
		return;
	}
	if (x == 1)
	{
		score_right += 1;
		return;
	}
}

int CScore::IsEndGame()
{
	if (score_left >= condition_endgame)
	{
		return -1;
	}
	if (score_right >= condition_endgame)
	{
		return 1;
	}
	return 0;
}

void CScore::Show()
{
	glColor3f(1.0, 1.0, 1.0); // White
	drawText(width / 4, height - 40, int2str(score_left));
	drawText(width / 4 * 3, height - 40, int2str(score_right));
}

std::string int2str(int x) {
	// converts int to string
	std::stringstream ss;
	ss << x;
	return ss.str();
}

void drawText(float x, float y, std::string text) {
	// draw text on display with address (x,y) on Oxy
	glRasterPos2f(x , y);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)text.c_str());
}
