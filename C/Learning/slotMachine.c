#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int choice;

    srand(time(0));

    printf("Welcome to the slot machine: \n");
    printf("1. Play\n2. End\n");
    scanf("%d" ,&choice);

    while(choice == 1)
    {
        SpinSlot();
        printf("1. Play Again\n2. End\n");
        scanf("%d" ,&choice);
    }

    return 0;
}

void SpinSlot()
{
    int reel1, reel2, reel3;

    reel1 = rand() % 9 + 1;
    reel2 = rand() % 9 + 1;
    reel3 = rand() % 9 + 1;

    printf("\n%d %d %d\n\n" ,reel1 ,reel2 ,reel3);

    if(reel1 == reel2 && reel2 == reel3)
    {
        printf("JACKPOT!");
    }
}