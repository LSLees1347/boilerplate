#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main()
{
    system("cls");

    int x = 0;
    int y = 0;
    int ax = 1;
    int ay = 1;

    int xbound = 20;
    int ybound = 10;

    int speed = 125;

    srand(time(0));
    x = rand() % (10 - -10 + 1) + -10;
    y = rand() % (10 - -10 + 1) + -10;

    while(1)
    {
        x += ax;
        if(x >= xbound || x <= xbound*-1)
        {
            ax = ax * -1;
        }

        y += ay;
        if(y >= ybound || y <= ybound*-1)
        {
            ay = ay * -1;
        }

        system("cls");

        for (int row = -ybound; row <= ybound; row++)
        {
            for (int col = -xbound; col <= xbound; col++)
            {
                if (col == x && row == y)
                {
                    printf("O");
                }
                else 
                {
                    printf(".");
                }
            }
            printf("\n");
        }
        Sleep(speed);
    }

    return 0;
}