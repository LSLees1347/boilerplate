#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stats.h"


int main()
{
    int choice;

    srand(time(0));

    printf("Welcome to the slot machine: \n");
    printf("1. Play\n2. Quit\n");
    scanf("%d" ,&choice);

    while(choice == 1)
    {
        SpinSlot();
        printf("\n\nMoney: %d$" ,getMoney());
        printf("\n1. Play Again\n2. Quit");
        scanf("\n%d" ,&choice);
    }

    return 0;
}

void SpinSlot()
{
    int reel1, reel2, reel3;

    reel1 = rand() % 9 + 1;
    reel2 = rand() % 9 + 1;
    reel3 = rand() % 9 + 1;

    printf("\n%d %d %d" ,reel1 ,reel2 ,reel3);

    if(reel1 == reel2 && reel2 == reel3)
    {
        printf("\nJACKPOT!");
        incrementJackpots();
        printf("\n+ 100$" ,getMoney());
        addMoney(100);
    }

    else if(reel1 == reel2 || reel1 == reel3 || reel2 == reel3)
    {
        printf("\nSmall Win");
        printf("\n+ 25$" ,getMoney());
        addMoney(25);
    }

    else
    {
        printf("\nNo Win");
    }
}