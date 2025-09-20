#include "game.h"

#include "raylib.h"
#include "program.h"

#include <vector>

void game()
{
	const int windowWidth = 650;
	const int windowHeight = 500;

	Screen actualScreen = PROGRAM;

	InitWindow(windowWidth, windowHeight, "Algebra TP1");

	std::vector<Polygon> polygons = { basicPolygon };
	std::vector<Line> lines = { basicLine };

	SetTargetFPS(60); 

	while (!WindowShouldClose())
	{
		switch (actualScreen)
		{
		case MAIN_MENU:



			break;
		case PROGRAM:
			
			program(actualScreen, lines, polygons);
			
			break;
		case EXIT:
			
			
			
			break;
		default:
			break;
		}
	}
}
