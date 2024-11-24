#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "playerStats.h"
#include "coinFlip.h"



int main()
{
    int choice = 0;

    do
    {
        system("cls");
        printf("Welcome to the casino!\n\n");
        printf("0 - Player Stats\n");
        printf("1 - Coin Flip\n");
        printf("9 - Exit\n");
        scanf("%d" ,&choice);

        switch (choice)
        {
        case 1:
            menuCf();
            break;
        case 2:
            menuStats();
            break;
        default:
            system("cls");
            printf("Invalid Choice.");
            system("pause");
            break;
        }

    } while(choice != 9);

    return 0;
}