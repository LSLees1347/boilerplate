#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "playerStats.h"
#include "main.h"
#include "coinFlip.h"


void viewStats()
{
    printf("Money = %d$)\n\n" ,getMoney());
    printf("Total Earnings = %d$" ,getTotalEarnings());
    printf("Coin Flip Wins = %d" ,getcfWins());
    system("pause");
}

void menuStats()
{
    int choice;

    do
    {
        system("cls");
        printf("Player Stats: \n");
        printf("1 - View Stats\n");
        printf("9 - Exit\n");
        scanf("%d" ,&choice);
        if(choice == 1)
        {
            viewStats();
        }
        
    } while(choice != 9);
}