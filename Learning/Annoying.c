#include <Windows.h>
#include <stdbool.h>

#define MOVE_RIGHT -1
#define MOVE_LEFT 1

void shakeWindow(int moveDirection, HWND hWindow)
{
    RECT windowRect;
    GetWindowRect(hWindow, &windowRect);

    int moveAmount = moveDirection * 10;
    SetWindowPos(hWindow, NULL, 
                 windowRect.left + moveAmount, 
                 windowRect.top, 
                 0, 0, 
                 SWP_NOSIZE);
}

int main(int argc, char** argv)
{
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    int currentMoveDirection = MOVE_LEFT;

    while(true)
    {
        Sleep(35);
        shakeWindow(currentMoveDirection, GetForegroundWindow());

        // Toggle between left and right
        currentMoveDirection = (currentMoveDirection == MOVE_LEFT) ? MOVE_RIGHT : MOVE_LEFT;
    }
}