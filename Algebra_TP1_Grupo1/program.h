#pragma once

#include "raylib.h"
#include "game.h"

struct Line
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	bool hasStartingPos = false;
	bool hasEndingPos = false;
};

void program(Screen& actualScreen, Line& line);
void updateProgram(Screen& actualScreen, Line& line);
void drawProgram(Line line);