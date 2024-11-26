#include <stdio.h>
#include <string.h>


int main()
{
    char name[25];
    int age;

    printf("whats your name?\n");
    //scanf("%s" ,&name);
    fgets(name, 25, stdin);
    name[strlen(name)-1] = '\0';

    printf("how old are you?\n");
    scanf("%d" ,&age);

    printf("\nhello %s, how are you" ,name);
    printf("\nyou are %d years old" ,age);

    return 0;
}