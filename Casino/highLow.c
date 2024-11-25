#include <stdio.h>
#include <Windows.h>
#include <time.h>

#include "main.h"
#include "playerStats.h"

int hlWins = 0;

int gethlWins()
{
    return hlWins;
}

void playHl()
{
    int choice;
    srand(time(0));
    int base = rand() % 10 + 1;
    int anwser = rand() % 10 + 1;
    int bet = placeBet();

    system("cls");
    printf("Number 1 is %d. Number 2 is...\n\n" ,base);
    printf("1 - Higher\n");
    printf("2 - Lower\n");
    printf("3 - Equal\n");
    scanf("%d" ,&choice);

    printf("\nNumber 2 is...");
    Sleep(750);
    printf("\rNumber 2 is %d.\n\n" ,anwser);
    
    if(anwser > base && choice == 1)
    {
        int mtp = 11 - base;
        addMoney(bet * mtp + bet);
        hlWins++;
        printf("You Win!\n");
        printf("+ $%d\n" ,bet * mtp);
        
    }
    else if(anwser < base && choice == 2)
    {
        addMoney(bet * base + bet);
        hlWins++;
        printf("You Win!\n");
        printf("+ $%d\n" ,bet * base);
    }
    else if(anwser == base && choice == 3)
    {
        addMoney(bet*10);
        hlWins++;
        printf("You Win!\n");
        printf("+ $%d\n" ,bet*10 - bet);
    }
    else
    {
        printf("You lose, try again.\n");
        printf("- $%d\n" ,bet);
    }
    system("pause");
}

void menuHl()
{
    int choice;

    do
    {
        system("cls");
        printf("High Low: $%d\n" ,getMoney());
        printf("1 - Play\n");
        printf("9 - Back\n");
        scanf("%d" ,&choice);
        if(choice == 1)
        {
            playHl();
        }

    } while(choice != 9);
}