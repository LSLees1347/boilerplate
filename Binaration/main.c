#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    char l1 = '/';
    char l2 = '-';
    char l3 = '\\';

    int i = 0;
    int speed = 10;

    printf("Speed: ");
    scanf("%d" ,&speed);

    system("cls");
    printf("\n\n\n");

    while(1)
    {

        if(i == 4)
        {
            i = 0;
        }

        switch (i)
        {
            case 0:
                l1 = '|';
                l2 = '/';
                l3 = '-';
                break;
        
            case 1:
                l1 = '/';
                l2 = '-';
                l3 = '\\';
                break;

            case 2:
                l1 = '-';
                l2 = '\\';
                l3 = '|';
                break;

            case 3:
                l1 = '\\';
                l2 = '|';
                l3 = '/';
                break;
        }

        printf("\r                %c%c%c%c%c%c    %c            " ,l1 ,l2 ,l3 ,l1 ,l2 ,l3 ,l1);
        fflush(stdout);
        i++;
        Sleep(speed);
        
    }

    return 0;
}
