#include <stdio.h>
#include <string.h>
#include <windows.h>



int main() {
    const int length = 20;
    int position = 0;
    int direction = 1;

    char line[length + 1];
    memset(line, '.', length);
    line[length] = '\0';

    while (1)
    {
        memset(line, '.', length);

        line[position] = '0';

        printf("\r%s", line);
        fflush(stdout);

        position += direction;

        if (position == 0 || position == length - 1) {
            direction = -direction;
        }

        Sleep(100);
    }

    return 0;
}
