#include <stdio.h>
#include "graphics.h"

int main()
{
    int choice;

    clearPicture();

    printf("2D Graphics Editor\n");
    printf("Canvas size: %d x %d\n", WIDTH, HEIGHT);
    printf("Use coordinates x y.\n");
    printf("x range: 0 to %d\n", WIDTH - 1);
    printf("y range: 0 to %d\n", HEIGHT - 1);

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Circle\n");
        printf("4. Draw Triangle\n");
        printf("5. Display Picture\n");
        printf("6. Clear Picture\n");
        printf("7. List Shapes\n");
        printf("8. Delete Shape\n");
        printf("9. Clear All Shapes\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int x1, y1, x2, y2;

            printf("Enter x1 y1 x2 y2: ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            drawLine(x1,y1,x2,y2);
            saveLine(x1,y1,x2,y2);

            printf("Line drawn successfully.\n");
        }
        else if (choice == 2)
        {
            int x1, y1, x2, y2;

            printf("Enter top-left x y and bottom-right x y: ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            drawRectangle(x1,y1,x2,y2);
            saveRectangle(x1,y1,x2,y2);

            printf("Rectangle drawn successfully.\n");
        }
        else if (choice == 3)
        {
            int cx, cy, radius;

            printf("Enter center x y and radius: ");
            scanf("%d %d %d", &cx, &cy, &radius);

            drawCircle(cx,cy,radius);
            saveCircle(cx,cy,radius);

            printf("Circle drawn successfully.\n");
        }
        else if (choice == 4)
        {
            int x1, y1, x2, y2, x3, y3;

            printf("Enter x1 y1 x2 y2 x3 y3: ");
            scanf("%d %d %d %d %d %d",
                  &x1, &y1,
                  &x2, &y2,
                  &x3, &y3);

            drawTriangle(x1,y1,x2,y2,x3,y3);
            saveTriangle(x1,y1,x2,y2,x3,y3);

            printf("Triangle drawn successfully.\n");
        }
        else if (choice == 5)
        {
            printf("\nCurrent Picture:\n\n");
            displayPicture();
        }
        else if (choice == 6)
        {
            clearPicture();
            printf("Canvas cleared.\n");
        }
        else if(choice == 7)
        {
            listShapes();
        }
        else if(choice == 8)
        {
            int id;

            printf("Enter shape ID to delete: ");
            scanf("%d", &id);

            deleteShape(id);
        }
        else if(choice == 9)
        {
            clearAllShapes();
        }
        else if (choice == 0)
        {
            printf("Exiting program.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}