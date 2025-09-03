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

bool checkIfLineIsCrossed(std::vector <Line> line)
{
	int px1 = 0;
	int px2 = 0;
	int py1 = 0;
	int py2 = 0;
	int px = 0;
	int py = 0;
	int t = 0;
	int u = 0;

	if (actualLineSelected > 0)
	{
		for (int i = 0; i < line.size(); i++)
		{
			//t = (line[i].x1 - line[i + 1].x2)
			for (int j = 0; j < line.size(); j++)
			{
				if (i != j)
				{
					t = (((line[i].x1 - line[i].x2) * (line[i].y1 - line[j].y1)) - ((line[i].y1 - line[j].y1) * (line[i].x1 - line[i].x2)) / ((line[i].x1 - line[i].x2) * (line[j].y1 - line[j].y2)) - ((line[i].y1 - line[i].y2) * (line[j].x1 - line[j].x2)));
					u = (((line[i].x1 - line[i].x2) * (line[i].y1 - line[j].y1)) - ((line[i].y1 - line[i].y2) * (line[i].x1 - line[j].x1)) / ((line[i].x1 - line[i].x2) * (line[j].y1 - line[j].y2)) - ((line[i].y1 - line[i].y2) * (line[j].x1 - line[j].x2)));

				}

			}
		}
	}
	else
		return false;


}