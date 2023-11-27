#include "SnakeGame.h"
#include "SnakeGame.cpp"
#include <iostream>
using namespace std;

int main()
{   
    int diff = 200;
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(diff); // Adjust game speed by changing sleep duration

        //will add difficulty.cpp later
    }
    return 0;
}