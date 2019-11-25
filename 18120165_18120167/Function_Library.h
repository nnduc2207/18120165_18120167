#pragma once


#include "stdafx.h"

#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
#include <random>
#pragma comment(lib, "OpenGL32.lib")

//using namespace std;

const int condition_endgame = 3;

// window size and update rate (60 fps)
const int width = 1000;
const int height = 600;
const int interval = 1000 / 60;


// ball
const float ball_pos_x = width / 2 + 4;
const float ball_pos_y = height / 2;
const float ball_dir_x = -1.0f;
const float ball_dir_y = 0.0f;
const int ball_size = 10;
const float ball_speed = 5.0f;

// racket

	// keycodes
	#define VK_W 0x57
	#define VK_S 0x53

	// rackets in general
const int racket_width = 20;
const int racket_height = 150;
const int racket_speed = 6;

