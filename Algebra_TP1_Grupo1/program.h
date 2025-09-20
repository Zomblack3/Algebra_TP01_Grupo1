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

struct Polygon
{
	std::vector<Line> lines = { basicLine };
};

extern Polygon basicPolygon;

void program(Screen& actualScreen, std::vector <Line>& line, std::vector <Polygon>& polygones);
void updateProgram(Screen& actualScreen, std::vector <Line>& line, std::vector <Polygon>& polygones);
void drawProgram(std::vector <Line> line, std::vector <Polygon> polygones);
void addLine(std::vector <Line>& line);
void setPolygone(std::vector <Line>& line, std::vector <Polygon>& polygones);

bool checkDistanceBetweenLines(std::vector <Line> line);