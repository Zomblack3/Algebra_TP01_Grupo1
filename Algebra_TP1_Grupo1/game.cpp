#include "game.h"

#include "raylib.h"
#include "program.h"

void game()
{
	const int windowWidth = 650;
	const int windowHeight = 500;

	Screen actualScreen = PROGRAM;

	InitWindow(windowWidth, windowHeight, "Algebra TP1");

	Line line = { };

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
