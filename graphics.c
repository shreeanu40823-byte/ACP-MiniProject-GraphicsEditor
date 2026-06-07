#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "graphics.h"

char picture[HEIGHT][WIDTH];
Shape shapes[MAX_SHAPES];
int shapeCount = 0;

void clearPicture()
{
    for(int y=0;y<HEIGHT;y++)
    {
        for(int x=0;x<WIDTH;x++)
        {
            picture[y][x] = EMPTY;
        }
    }
}

void displayPicture()
{
    for(int y=0;y<HEIGHT;y++)
    {
        for(int x=0;x<WIDTH;x++)
        {
            printf("%c", picture[y][x]);
        }
        printf("\n");
    }
}

void setPixel(int x, int y)
{
    if(x >= 0 && x < WIDTH &&
       y >= 0 && y < HEIGHT)
    {
        picture[y][x] = PIXEL;
    }
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while(1)
    {
        setPixel(x1, y1);

        if(x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if(e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if(e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRectangle(int x1, int y1, int x2, int y2)
{
    drawLine(x1, y1, x2, y1);
    drawLine(x2, y1, x2, y2);
    drawLine(x2, y2, x1, y2);
    drawLine(x1, y2, x1, y1);
}

void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}

void drawCircle(int cx, int cy, int radius)
{
    int x = radius;
    int y = 0;

    int decision = 1 - radius;

    while(x >= y)
    {
        setPixel(cx + x, cy + y);
        setPixel(cx + y, cy + x);
        setPixel(cx - y, cy + x);
        setPixel(cx - x, cy + y);

        setPixel(cx - x, cy - y);
        setPixel(cx - y, cy - x);
        setPixel(cx + y, cy - x);
        setPixel(cx + x, cy - y);

        y++;

        if(decision <= 0)
        {
            decision += 2*y + 1;
        }
        else
        {
            x--;
            decision += 2*(y - x) + 1;
        }
    }
}
void saveLine(int x1, int y1, int x2, int y2)
{
    if(shapeCount >= MAX_SHAPES)
        return;

    shapes[shapeCount].type = LINE;

    shapes[shapeCount].x1 = x1;
    shapes[shapeCount].y1 = y1;

    shapes[shapeCount].x2 = x2;
    shapes[shapeCount].y2 = y2;

    shapeCount++;
}
void saveRectangle(int x1, int y1, int x2, int y2)
{
    if(shapeCount >= MAX_SHAPES)
        return;

    shapes[shapeCount].type = RECTANGLE;

    shapes[shapeCount].x1 = x1;
    shapes[shapeCount].y1 = y1;

    shapes[shapeCount].x2 = x2;
    shapes[shapeCount].y2 = y2;

    shapeCount++;
}
void saveCircle(int cx, int cy, int radius)
{
    if(shapeCount >= MAX_SHAPES)
        return;

    shapes[shapeCount].type = CIRCLE;

    shapes[shapeCount].x1 = cx;
    shapes[shapeCount].y1 = cy;

    shapes[shapeCount].radius = radius;

    shapeCount++;
}
void saveTriangle(
    int x1,int y1,
    int x2,int y2,
    int x3,int y3)
{
    if(shapeCount >= MAX_SHAPES)
        return;

    shapes[shapeCount].type = TRIANGLE;

    shapes[shapeCount].x1 = x1;
    shapes[shapeCount].y1 = y1;

    shapes[shapeCount].x2 = x2;
    shapes[shapeCount].y2 = y2;

    shapes[shapeCount].x3 = x3;
    shapes[shapeCount].y3 = y3;

    shapeCount++;
}
void listShapes()
{
    if(shapeCount == 0)
    {
        printf("\nNo shapes stored.\n");
        return;
    }

    printf("\nStored Shapes:\n");

    for(int i = 0; i < shapeCount; i++)
    {
        printf("%d. ", i);

        switch(shapes[i].type)
        {
            case LINE:
                printf("Line\n");
                break;

            case RECTANGLE:
                printf("Rectangle\n");
                break;

            case CIRCLE:
                printf("Circle\n");
                break;

            case TRIANGLE:
                printf("Triangle\n");
                break;
        }
    }

    printf("Total Shapes = %d\n", shapeCount);
}
void redrawShapes()
{
    clearPicture();

    for(int i = 0; i < shapeCount; i++)
    {
        switch(shapes[i].type)
        {
            case LINE:
                drawLine(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].x2,
                    shapes[i].y2
                );
                break;

            case RECTANGLE:
                drawRectangle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].x2,
                    shapes[i].y2
                );
                break;

            case CIRCLE:
                drawCircle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].radius
                );
                break;

            case TRIANGLE:
                drawTriangle(
                    shapes[i].x1,
                    shapes[i].y1,
                    shapes[i].x2,
                    shapes[i].y2,
                    shapes[i].x3,
                    shapes[i].y3
                );
                break;
        }
    }
}
void deleteShape(int index)
{
    if(index < 0 || index >= shapeCount)
    {
        printf("Invalid shape ID.\n");
        return;
    }

    for(int i = index; i < shapeCount - 1; i++)
    {
        shapes[i] = shapes[i + 1];
    }

    shapeCount--;

    redrawShapes();

    printf("Shape deleted successfully.\n");
}
void clearAllShapes()
{
    shapeCount = 0;
    clearPicture();

    printf("All shapes cleared successfully.\n");
}
void saveShapesToFile()
{
    FILE *fp = fopen("shapes.txt", "w");

    if(fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    fprintf(fp, "%d\n", shapeCount);

    for(int i = 0; i < shapeCount; i++)
    {
        fprintf(fp,
                "%d %d %d %d %d %d %d %d\n",
                shapes[i].type,
                shapes[i].x1,
                shapes[i].y1,
                shapes[i].x2,
                shapes[i].y2,
                shapes[i].x3,
                shapes[i].y3,
                shapes[i].radius);
    }

    fclose(fp);

    printf("Shapes saved successfully.\n");
}
void loadShapesFromFile()
{
    FILE *fp = fopen("shapes.txt", "r");

    if(fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    fscanf(fp, "%d", &shapeCount);

    for(int i = 0; i < shapeCount; i++)
    {
        fscanf(fp,
               "%d %d %d %d %d %d %d %d",
               &shapes[i].type,
               &shapes[i].x1,
               &shapes[i].y1,
               &shapes[i].x2,
               &shapes[i].y2,
               &shapes[i].x3,
               &shapes[i].y3,
               &shapes[i].radius);
    }

    fclose(fp);

    redrawShapes();

    printf("Shapes loaded successfully.\n");
}