#include <stdio.h>
#include "graphics.h"

int main()
{
    int choice;
    int row,col,height,width;

    initCanvas();

    printf("1. Draw Rectangle\n");
    printf("2. Display Canvas\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("Enter row col height width: ");
        scanf("%d%d%d%d",&row,&col,&height,&width);

        drawRectangle(row,col,height,width);
        displayCanvas();
    }
    else if(choice==2)
    {
        displayCanvas();
    }

    return 0;
}