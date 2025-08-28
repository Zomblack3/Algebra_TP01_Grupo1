#include "program.h"

int actualLineSelected = 0;

Line basicLine = { };

void program(Screen& actualScreen, std::vector <Line>& line)
{
	updateProgram(actualScreen, line);

	drawProgram(line);
}

void updateProgram(Screen& actualScreen, std::vector <Line>& line)
{
	if (line[actualLineSelected].hasStartingPos && line[actualLineSelected].hasEndingPos)
	{
		++actualLineSelected;

		line.push_back(basicLine);
	}

	if (IsKeyPressed(KEY_R))
	{
		line[actualLineSelected].hasStartingPos = false;
		line[actualLineSelected].hasEndingPos = false;
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (!line[actualLineSelected].hasStartingPos)
		{
			line[actualLineSelected].x1 = GetMousePosition().x;
			line[actualLineSelected].y1 = GetMousePosition().y;

			line[actualLineSelected].hasStartingPos = true;
		}
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		if (!line[actualLineSelected].hasEndingPos)
		{
			if (line[actualLineSelected].x1 != line[actualLineSelected].x2 && line[actualLineSelected].y1 != line[actualLineSelected].y2)
			{
				line[actualLineSelected].x2 = GetMousePosition().x;
				line[actualLineSelected].y2 = GetMousePosition().y;

				line[actualLineSelected].hasEndingPos = true;
			}
		}
	}
}

void drawProgram(std::vector <Line> line)
{
	BeginDrawing();

	ClearBackground(BLACK);

	for (int i = 0; i < line.size(); i++)
	{
		if (line[i].hasStartingPos && line[i].hasEndingPos)
			DrawLine(line[i].x1, line[i].y1, line[i].x2, line[i].y2, WHITE);
	}

	EndDrawing();
}