#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "graphics.h"

char picture[HEIGHT][WIDTH];

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