#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "playerStats.h"
#include "coinFlip.h"
#include "highLow.h"
#include "blackJack.h"


int money = 100;
int totalEarnings = 0;

void addMoney(int tooAdd)
{
    money += tooAdd;
    if(tooAdd > 0)
    {
        totalEarnings += tooAdd;
    }
}

int getMoney()
{
    return money;
}

int getTotalEarnings()
{
    return totalEarnings;
}

int placeBet()
{
    int bet;
    printf("\nMoney: $%d\n" ,getMoney());
    printf("Place your bet: $");
    scanf("%d" ,&bet);

    money -= bet;
    return bet;
}

int main()
{
    int choice = 0;

    do
    {
        system("cls");
        printf("Welcome to the casino!  $%d\n\n" ,money);
        printf("0 - Player Stats\n\n");
        printf("1 - Coin Flip\n");
        printf("2 - High Low\n");
        printf("3 - Blackjack\n");
        printf("\n");
        printf("9 - Exit\n");
        scanf("%d" ,&choice);

        switch (choice)
        {
        case 0:
            menuStats();
            break;
        case 1:
            menuCf();
            break;
        case 2:
            menuHl();
            break;
        case 3:
            menuBj();
            break;
        }

    } while(choice != 9);

    return 0;
}