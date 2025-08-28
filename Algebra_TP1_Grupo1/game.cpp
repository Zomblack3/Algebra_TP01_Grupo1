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

	std::vector<Line> line = { basicLine };

	SetTargetFPS(60); 

	while (!WindowShouldClose())
	{
		switch (actualScreen)
		{
		case MAIN_MENU:



			break;
		case PROGRAM:
			
			program(actualScreen, line);
			
			break;
		case EXIT:
			
			
			
			break;
		default:
			break;
		}
	}
}
