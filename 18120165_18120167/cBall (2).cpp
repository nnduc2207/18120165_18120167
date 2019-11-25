#include "cBall (2).h"


cBall::cBall(int posX, int posY) {
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
	direction = STOP;
}

void cBall::Reset() {
	x = originalX;
	y = originalY;
	direction = STOP;
}

void cBall::changeDirection(eDir d) {
	direction = d;
}

void cBall::randomDirection() 
{
direction = (eDir)((rand() % 6) + 1);
}

int cBall::getX() {
	return x;
}

int cBall::getY() {
	return y;
}

eDir cBall::getDirection() {
	return direction;
}

void cBall::Move() {
	switch (direction) {
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UPLEFT:
		x--; y--;
		break;
	case DOWNLEFT:
		x--; y++;
		break;
	case UPRIGHT:
		x++; y--;
		break;
	case DOWNRIGHT:
		x++; y++;
		break;
	default:
		break;
	}
}

ostream& operator<<(ostream& o, cBall c) {
	o << "Ball [" << c.x << ","<< c.y << "][" << c.direction << "]";
	return o;
}
