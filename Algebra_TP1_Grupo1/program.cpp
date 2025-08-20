#include "program.h"

void program(Screen& actualScreen, Line& line)
{
	updateProgram(actualScreen, line);

	drawProgram(line);
}

void updateProgram(Screen& actualScreen, Line& line)
{

	if (IsKeyPressed(KEY_R))
	{
		line.hasStartingPos = false;
		line.hasEndingPos = false;
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (!line.hasStartingPos)
		{
			line.x1 = GetMousePosition().x;
			line.y1 = GetMousePosition().y;

			line.hasStartingPos = true;
		}
		else if (!line.hasEndingPos)
		{
			line.x2 = GetMousePosition().x;
			line.y2 = GetMousePosition().y;

			line.hasEndingPos = true;
		}
	}
}

void drawProgram(Line line)
{
	BeginDrawing();

	ClearBackground(BLACK);

	if (line.hasStartingPos && line.hasEndingPos)
		DrawLine(line.x1, line.y1, line.x2, line.y2, WHITE);

	EndDrawing();
}