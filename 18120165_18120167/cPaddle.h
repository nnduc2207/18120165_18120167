#pragma once
#include <iostream>
using namespace std;


class cPaddle
{
protected:
	int x, y;
	int originalX, originalY;
public:
	cPaddle();
	cPaddle(int , int);
	void Reset();
	int getX();
	int getY();
	void moveUp();
	void moveDown();
	friend ostream& operator<<(ostream&, cPaddle);
};

