#pragma once

#include "raylib.h"
#include "game.h"

#include <vector>

struct Line
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	bool hasStartingPos = false;
	bool hasEndingPos = false;
};

extern Line basicLine;

void program(Screen& actualScreen, std::vector <Line>& line);
void updateProgram(Screen& actualScreen, std::vector <Line>& line);
void drawProgram(std::vector <Line> line);