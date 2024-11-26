#include <stdio.h>
#include <Windows.h>
#include <time.h>


#include "main.h"
#include "playerStats.h"


int bjWins;


int getbjWins()
{
    return bjWins;
}

void playBj()
{
    system("cls");
    srand(time(0));

    placeBet();



    
}

void menuBj()
{
    int choice;

    do
    {
        system("cls");
        printf("Blackjack: $%d\n" ,getMoney());
        printf("1 - Play\n");
        printf("9 - Back\n");
        scanf("%d" ,&choice);
        if(choice == 1)
        {
            playBj();
        }

    } while(choice != 9);
}