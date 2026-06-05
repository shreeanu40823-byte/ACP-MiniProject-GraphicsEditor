#ifndef GRAPHICS_H
#define GRAPHICS_H

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'

extern char picture[HEIGHT][WIDTH];

void clearPicture();
void displayPicture();
void setPixel(int x, int y);

void drawLine(int x1, int y1, int x2, int y2);
void drawRectangle(int x1, int y1, int x2, int y2);
void drawCircle(int cx, int cy, int radius);
void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3);

#endif