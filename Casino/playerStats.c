#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


void menuStats()
{
    int choice;
    
    do
    {
        system("cls");
        printf("Player Stats: \n");
        printf("1 - Play\n");
        printf("9 - Exit\n");
        scanf("%d" ,&choice);
        if(choice == 1)
        {
            playCf();
        }
        
    } while(choice != 9);
}