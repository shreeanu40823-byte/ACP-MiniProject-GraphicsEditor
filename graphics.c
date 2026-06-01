#include <stdio.h>
#include "graphics.h"

char canvas[ROWS][COLS];

void initCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int row, int col, int height, int width)
{
    for(int i=row;i<row+height;i++)
    {
        for(int j=col;j<col+width;j++)
        {
            if(i==row || i==row+height-1 ||
               j==col || j==col+width-1)
            {
                canvas[i][j]='*';
            }
        }
    }
}