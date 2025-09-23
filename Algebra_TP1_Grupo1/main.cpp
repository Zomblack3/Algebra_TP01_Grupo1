#include "raylib.h"

const int maxPolygons = 20;
const int maxPoints = 50;

struct Polygon
{
    Vector2 point[maxPoints];
    int pointAmount = 0;
    bool isColliding = false;
};

bool isLineColliding(Vector2 A, Vector2 B, Vector2 C, Vector2 D)
{
    float denom = (A.x - B.x) * (C.y - D.y) - (A.y - B.y) * (C.x - D.x);
    if (denom == 0)
    {
        return false;
    }

    float t = ((A.x - C.x) * (C.y - D.y) - (A.y - C.y) * (C.x - D.x)) / denom;
    float u = ((A.x - C.x) * (A.y - B.y) - (A.y - C.y) * (A.x - B.x)) / denom;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) 
    {
        return true;
    }
    return false;
}

int main()
{
    InitWindow(800, 600, "Poligonos movibles");
    SetTargetFPS(60);

    Polygon polys[maxPolygons];
    int polygonQuantity = 0;
    int moving = -1;
    int collisionAmounts = 0;

    while (!WindowShouldClose())
    {

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && moving == -1)
        {
            polys[polygonQuantity].point[polys[polygonQuantity].pointAmount] = GetMousePosition();
            polys[polygonQuantity].pointAmount++;
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON) && moving == -1 && polys[polygonQuantity].pointAmount >= 2)
        {
            polys[polygonQuantity].point[polys[polygonQuantity].pointAmount] = polys[polygonQuantity].point[0];
            polys[polygonQuantity].pointAmount++;
            polygonQuantity++;
        }

        if (IsKeyPressed(KEY_UP))
        {
            if (moving == -1)
            {
                moving++;
            }
        }
        if (IsKeyPressed(KEY_RIGHT))
        {
            if (moving < polygonQuantity-1)
            {
                moving++;
            }
        }
        if (IsKeyPressed(KEY_LEFT))
        {
            if (moving > -1)
            {
                moving--;
            }
        }
        if (IsKeyPressed(KEY_DOWN))
        {
            moving = -1;
        }

        if (moving >= 0)
        {
            if(IsKeyDown(KEY_W))
            {
                for (int i = 0; i < polys[moving].pointAmount; i++)
                {
                    polys[moving].point[i].y -= 5;
                }
            }
            if (IsKeyDown(KEY_S))
            {
                for (int i = 0; i < polys[moving].pointAmount; i++)
                {
                    polys[moving].point[i].y += 5;
                }
            }
            if (IsKeyDown(KEY_A))
            {
                for (int i = 0; i < polys[moving].pointAmount; i++)
                {
                    polys[moving].point[i].x -= 5;
                }
            }
            if (IsKeyDown(KEY_D))
            {
                for (int i = 0; i < polys[moving].pointAmount; i++)
                {
                    polys[moving].point[i].x += 5;
                }
            }
        }

        for (int i = 0; i < polygonQuantity; i++)
        {
            polys[i].isColliding = false;
        }

        for (int i = 0; i < polygonQuantity; i++)
        {
            for (int c = 0; c < polygonQuantity; c++) 
            {
                if (c != i) 
                {
                    for (int j = 0; j < polys[i].pointAmount; j++)
                    {
                        collisionAmounts = 0;
                        Vector2 start = polys[i].point[j];
                        Vector2 end = { 1600, start.y };

                        for (int d = 0; d < polys[c].pointAmount; d++)
                        {
                            Vector2 p1 = polys[c].point[d];
                            Vector2 p2;
                            if (d != 0)
                            {
                                p2 = polys[c].point[d - 1];
                            }
                            else
                            {
                                p2 = polys[c].point[polys[c].pointAmount-1];
                            }
                            if (isLineColliding(start, end, p1, p2))
                            {
                                collisionAmounts++;
                            }
                        }
                        if (collisionAmounts % 2 == 1)
                        {
                            polys[i].isColliding = true;
                            polys[c].isColliding = true;
                            break;
                        }
                    }

                
                }
            }
        }

        BeginDrawing();

        ClearBackground(BLACK);

        DrawText("Press Up to move polygons, left and right to choose which one to move and press down to be able to draw ", 0, 0, 15, GRAY);

        if (moving >= 0)
        {
            DrawText(TextFormat("Now moving polygon N: %d", moving),0,20,20,GRAY);
        }

        for (int i = 0; i <= polygonQuantity; i++)
        {
            if (polys[i].pointAmount > 1 && !polys[i].isColliding)
            {
                if (moving != i)
                {
                    for (int j = 1; j < polys[i].pointAmount; j++)
                    {
                        DrawLineV(polys[i].point[j - 1], polys[i].point[j], WHITE);
                    }
                }
                else
                {
                    for (int j = 1; j < polys[i].pointAmount; j++)
                    {
                        DrawLineV(polys[i].point[j - 1], polys[i].point[j], GRAY);
                    }
                }
            }
            else
            {
                if (moving != i)
                {
                    for (int j = 1; j < polys[i].pointAmount; j++)
                    {
                        DrawLineV(polys[i].point[j - 1], polys[i].point[j], RED);
                    }
                }
                else
                {
                    for (int j = 1; j < polys[i].pointAmount; j++)
                    {
                        DrawLineV(polys[i].point[j - 1], polys[i].point[j], MAROON);
                    }
                }
            }
        }

        EndDrawing();
    }
}