#ifndef GRAPHICS_H
#define GRAPHICS_H

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'

#define LINE 1
#define RECTANGLE 2
#define CIRCLE 3
#define TRIANGLE 4

extern char picture[HEIGHT][WIDTH];

#define MAX_SHAPES 100

typedef struct
{
    int type;

    int x1, y1;
    int x2, y2;
    int x3, y3;

    int radius;
} Shape;

extern Shape shapes[MAX_SHAPES];
extern int shapeCount;

void clearPicture();
void displayPicture();
void setPixel(int x, int y);

void drawLine(int x1, int y1, int x2, int y2);
void drawRectangle(int x1, int y1, int x2, int y2);
void drawCircle(int cx, int cy, int radius);
void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3);
void saveLine(int x1,int y1,int x2,int y2);
void saveRectangle(int x1,int y1,int x2,int y2);
void saveCircle(int cx,int cy,int radius);
void saveTriangle(
    int x1,int y1,
    int x2,int y2,
    int x3,int y3);
void listShapes();
void deleteShape(int index);
void redrawShapes();
void clearAllShapes();

#endif