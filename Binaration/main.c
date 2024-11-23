#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    
    system("cls");

    char line1 = '/';
    char line2 = '/';
    char line3 = '/';

    int i = 0;
    int speed = 10;
    scanf("%d" ,&speed);

    while(1)
    {

        if(i == 3)
        {
            i = 0;
        }

        switch (i)
        {
            case 0:
                line1 = '\\';
                line2 = '/';    
                line3 = '/';
                break;
        
            case 1:
                line1 = '/';
                line2 = '\\';
                line3 = '/';     
                break;

            case 2:
                line1 = '/';
                line2 = '/';
                line3 = '\\';
                break;
        }

        printf("\r%c%c%c" ,line1 ,line2, line3);
        fflush(stdout);
        i++;
        Sleep(speed);
        
    }

    return 0;
}
