#include "cPaddle.h"

cPaddle::cPaddle() {
	x = y = 0;
}

cPaddle::cPaddle(int posX, int posY) : cPaddle() {
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
}

void cPaddle::Reset() {
	x = originalX;
	y = originalY;
};
int cPaddle::getX() { return x; }
int cPaddle::getY() { return y; }
void cPaddle::moveUp() { y--; }
void cPaddle::moveDown() { y++; }

ostream& operator<<(ostream& o, cPaddle c) {
	o << "Paddle [" << c.x<< "," << c.y << "]";
	return o;
}

