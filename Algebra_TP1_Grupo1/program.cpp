#include "program.h"

int actualLineSelected = 0;
int actualAmountOfPolygones = 0;

int timeBetweenLines = 0;
int timerToCreateLine = timeBetweenLines;

Line basicLine = { };
Polygon basicPolygon = { };

void program(Screen& actualScreen, std::vector <Line>& line, std::vector <Polygon>& polygones)
{
	actualLineSelected = line.size();

	updateProgram(actualScreen, line, polygones);

	drawProgram(line, polygones);
}

void updateProgram(Screen& actualScreen, std::vector <Line>& line, std::vector <Polygon>& polygones)
{
	if (actualLineSelected == 1)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			if (!line[actualLineSelected - 1].hasStartingPos)
			{
				line[actualLineSelected - 1].x1 = GetMousePosition().x;
				line[actualLineSelected - 1].y1 = GetMousePosition().y;

				line[actualLineSelected - 1].hasStartingPos = true;
			}
		}
	}
	else
	{
		line[actualLineSelected - 1].x1 = line[actualLineSelected - 2].x2;
		line[actualLineSelected - 1].y1 = line[actualLineSelected - 2].y2;

		line[actualLineSelected - 1].hasStartingPos = true;
	}

	if (timerToCreateLine == 0)
	{
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && line[actualLineSelected - 1].hasStartingPos)
		{
			if (!line[actualLineSelected - 1].hasEndingPos)
			{
				if (line[actualLineSelected - 1].x1 != GetMousePosition().x && line[actualLineSelected - 1].y1 != GetMousePosition().y)
				{
					line[actualLineSelected - 1].x2 = GetMousePosition().x;
					line[actualLineSelected - 1].y2 = GetMousePosition().y;

					line[actualLineSelected - 1].hasEndingPos = true;

					timerToCreateLine = timeBetweenLines;
				}
			}
		}
	}
	else
		timerToCreateLine--;

	if (line[actualLineSelected - 1].hasStartingPos && line[actualLineSelected - 1].hasEndingPos)
	{
		if (actualLineSelected > 1)
			if (checkDistanceBetweenLines(line))
				setPolygone(line, polygones);

		addLine(line);
	}
}

void drawProgram(std::vector <Line> line, std::vector <Polygon> polygones)
{
	BeginDrawing();

	ClearBackground(BLACK);

	for (int i = 0; i < line.size(); i++)
		if (line[i].hasStartingPos && line[i].hasEndingPos)
			DrawLine(line[i].x1, line[i].y1, line[i].x2, line[i].y2, WHITE);

	if (actualAmountOfPolygones > 0)
		for (int i = 0; i < polygones.size(); i++)
			for (int j = 0; j < polygones.at(i).lines.size(); j++)
				DrawLine(polygones.at(i).lines.at(j).x1, polygones.at(i).lines.at(j).y1, polygones.at(i).lines.at(j).x2, polygones.at(i).lines.at(j).y2, WHITE);

	DrawText(TextFormat("%03i", line.size()), 10, 10, 30, WHITE);
	DrawText(TextFormat("%02i", polygones.size()), 10, 40, 30, WHITE);

	EndDrawing();
}

void addLine(std::vector <Line>& line)
{
	line.push_back(basicLine);

	actualLineSelected++;
}

void setPolygone(std::vector <Line>& line, std::vector <Polygon>& polygones)
{
	polygones.push_back(basicPolygon);

	for (int i = 0; i < actualLineSelected; i++)
		polygones.at(actualAmountOfPolygones).lines.push_back(line.at(i));

	actualAmountOfPolygones++;

	line.clear();
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

bool checkDistanceBetweenLines(std::vector <Line> line)
{
	int distanceX = 0;
	int distanceY = 0;

	int lastLinePosX = line.at(actualLineSelected - 1).x2;
	int lastLinePosY = line.at(actualLineSelected - 1).y2;
	int firstLinePosX = line.at(0).x1;
	int firstLinePosY = line.at(0).y1;	

	if (lastLinePosX > firstLinePosX)
		distanceX = lastLinePosX - firstLinePosX;
	else if (lastLinePosX < firstLinePosX)
		distanceX = firstLinePosX - lastLinePosX;

	if (lastLinePosY > firstLinePosY)
		distanceY = lastLinePosY - firstLinePosY;
	else if (lastLinePosY < firstLinePosY)
		distanceY = firstLinePosY - lastLinePosY;
	
	if (distanceX <= 5 && distanceY <= 5)
		return true;

	return false;
}