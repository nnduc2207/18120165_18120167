
#define _CRT_SECURE_NO_WARNINGS

#include "CBall.h"
#include "CRacket.h"
#include "CScore.h"
#include "cGameManager.h"

int choose;

CScore score;
CBall ball;
CRacket racketleft, racketright;

void Init() { // Create first parameter of game
	score.Init();
	ball.Init();
	racketleft.InitLeft();
	racketright.InitRight();
}

void draw() { // Draw game
	// clear (has to be done at the beginning)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// ToDo: draw our scene

	// draw line
	for (int i = 0; i < height; i++)
	{
		glColor3f(1.0, 1.0, 1.0);
		drawText(width / 2, i, "|");
	}
	// draw rackets
	racketleft.Show();
	racketright.Show();

	// draw ball
	ball.Show();

	// draw score
	score.Show();

	// check end game
	if (score.IsEndGame() != 0)
	{
		int x, y = height / 4 * 3;
		std::string text = "WINNER";
		if (score.IsEndGame() == -1)
		{
			x = 0;
		}
		else
		{
			x = width / 2;
		}
		glPushMatrix();
		glTranslatef(x + 10 , y - 100, 0);
		for (int i = 0; i < text.length(); i++)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
		}
		glPopMatrix();
		ball.SetSpeed(0.0f);

	}


	// swap buffers (has to be done at the end)
	glutSwapBuffers();
}

void keyboard(int k) { // Control game with number of players

	// left racket
	if (k == 1)
	{
		if (racketleft.GetPos_y() + racket_height / 2 + 20 < ball.GetPos_y()) racketleft.Move(0);
		if (racketleft.GetPos_y() + racket_height / 2 - 20 > ball.GetPos_y()) racketleft.Move(1);

	}
	else
	{
		if (GetAsyncKeyState(VK_W)) racketleft.Move(0);
		if (GetAsyncKeyState(VK_S)) racketleft.Move(1);
	}

	// right racket
	if (GetAsyncKeyState(VK_UP)) racketright.Move(0);
	if (GetAsyncKeyState(VK_DOWN)) racketright.Move(1);
}

void updateBall() {	// Events of ball
	// fly a bit
	ball.Move();

	// hit by left racket?
	if (ball.GetPos_x() < racketleft.GetPos_x() + racket_width &&
		ball.GetPos_y() < racketleft.GetPos_y() + racket_height &&
		ball.GetPos_y() > racketleft.GetPos_y()) {
		// set fly direction depending on where it hit the racket
		// (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
		racketleft.RandomColor();
		ball.SetPosition(racketleft.GetPos_x() + racket_width, ball.GetPos_y());
		ball.SetSpeed(ball.GetSpeed() * 1.1);
		float t = ((ball.GetPos_y() - racketleft.GetPos_y()) / racket_height) - 0.5f;
		ball.SetDirection(fabs(ball_dir_x), t);
	}

	// hit by right racket?
	if (ball.GetPos_x() > racketright.GetPos_x() &&
		ball.GetPos_y() < racketright.GetPos_y() + racket_height &&
		ball.GetPos_y() > racketright.GetPos_y()) {
		// set fly direction depending on where it hit the racket
		// (t is 0.5 if hit at top, 0 at center, -0.5 at bottom)
		racketright.RandomColor();
		ball.SetPosition(racketright.GetPos_x(), ball.GetPos_y());
		ball.SetSpeed(ball.GetSpeed() * 1.1);
		float t = ((ball.GetPos_y() - racketright.GetPos_y()) / racket_height) - 0.5f;
		ball.SetDirection(-fabs(ball.GetDir_x()), t);
	}

	// hit left wall?
	if (ball.GetPos_x() < 0) {
		score.Goal(1);
		ball.Init();
		ball.SetDirection(fabs(ball.GetDir_x()), 0);
	}

	// hit right wall?
	if (ball.GetPos_x() > width) {
		score.Goal(0);
		ball.Init();
		ball.SetDirection(-fabs(ball.GetDir_x()), 0);
	}

	// hit top wall?
	if (ball.GetPos_y() > height - 10) {
		ball.SetDirection(ball.GetDir_x(), -fabs(ball.GetDir_y()));
	}

	// hit bottom wall?
	if (ball.GetPos_y() < 10) {
		ball.SetDirection(ball.GetDir_x(), fabs(ball.GetDir_y()));
	}
}

void update(int value) {	// update new status

	// input handling
	keyboard(choose);

	// update ball
	updateBall();

	// Call update() again in 'interval' milliseconds
	glutTimerFunc(interval, update, 0);

	// Redisplay frame
	glutPostRedisplay();
}

void enable2D(int width, int height) {	// 2D settings of OpenGL
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int _tmain(int argc, char** argv) {

	printf("So nguoi choi (1 hoac 2): ");
	scanf("%d", &choose);
	while (choose != 1 && choose != 2)
	{
		printf("Nhap sai, nhap lai: ");
		scanf("%d", &choose);
	}
	Init();
	// initialize opengl (via glut)
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Pong Game");

	// Register callback functions   
	glutDisplayFunc(draw);
	glutTimerFunc(interval, update, 0);


	// setup scene to 2d mode and set draw color to white
	enable2D(width, height);
	glColor3f(1.0f, 1.0f, 1.0f);

	// start the whole thing

	glutMainLoop();
	return 0;
}
