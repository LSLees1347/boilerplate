#include <stdio.h>
#include "coinFlip.h"
#include <Windows.h>
#include <time.h>


void playCf()
{
    int choice;
    srand(time(0));
    int anwser = rand() % 2 ? 1 : 2;

    system("cls");
    printf("Heads or Tails?\n");
    printf("1 - Heads\n");
    printf("2 - Tails\n");
    scanf("%d" ,&choice);
    if(choice == anwser)
    {
        printf("\nYou Win!\n");
    }
    else
    {
        printf("\nYou Lose, try again.\n");
    }
    system("pause"); 
}

void menuCf()
{
    int choice;

    do
    {
        system("cls");
        printf("Coin Flip: \n");
        printf("1 - Play\n");
        printf("9 - Exit\n");
        scanf("%d" ,&choice);
        if(choice == 1)
        {
            playCf();
        }

    } while(choice != 9);
}