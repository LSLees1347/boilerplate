#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "playerStats.h"
#include "coinFlip.h"

int money = 100;
int totalEarnings = 0;

void addMoney(int tooAdd)
{
    money += tooAdd;
    totalEarnings += tooAdd;
}

int getMoney()
{
    return money;
}

int getTotalEarnings()
{
    return totalEarnings;
}

int main()
{
    int choice = 0;

    do
    {
        system("cls");
        printf("Welcome to the casino!  $%d\n\n" ,money);
        printf("0 - Player Stats\n");
        printf("1 - Coin Flip\n");
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
        }

    } while(choice != 9);

    return 0;
}