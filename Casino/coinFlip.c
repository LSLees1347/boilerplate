#include <stdio.h>
#include <Windows.h>
#include <time.h>

#include "coinFlip.h"
#include "main.h"

int cfWins = 0;

int getcfWins()
{
    return cfWins;
}

void playCf()
{
    int choice;
    srand(time(0));
    int anwser = rand() % 2 ? 1 : 2;

    int bet = placeBet();

    system("cls");
    printf("Heads or Tails?\n");
    printf("1 - Heads\n");
    printf("2 - Tails\n");
    scanf("%d" ,&choice);
    
    if(choice == anwser)
    {
        printf("\nYou Win!\n");
        printf("+ $%d\n" ,bet*2);
        addMoney(bet*2);
        cfWins++;
    }
    else
    {
        printf("\nYou Lose, try again.\n\n");
        printf("- $%d\n" ,bet);
    }
    system("pause"); 
}

void menuCf()
{
    int choice;

    do
    {
        system("cls");
        printf("Coin Flip: $%d\n" ,getMoney());
        printf("1 - Play\n");
        printf("9 - Back\n");
        scanf("%d" ,&choice);
        if(choice == 1)
        {
            playCf();
        }

    } while(choice != 9);
}