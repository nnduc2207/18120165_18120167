#pragma once
#include "cBall (2).h"
#include "cPaddle.h"
#include <time.h>
#include <conio.h>


class cGameManager
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall* ball;
	cPaddle* player1;
	cPaddle* player2;
public:
	cGameManager(int, int);
	~cGameManager();
	void Draw();
	void Logic();
	void Input();
	void Run();
	int flip();
};

