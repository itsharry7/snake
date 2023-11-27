#include "SnakeGame.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
eDirection dir;

void Setup()
{
    // Implementation
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;   
    score = 0;
}

void Draw()
{
    // Displaying current frame
    system("cls");

    //printing roof
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                //printing left wall
                cout << "#";
            if (i == y && j == x)
                //snake head
                cout << "^";
            else if (i == fruitY && j == fruitX)
                //snake's food
                cout << "*";
            else
            {
                bool printTail = false;
                //logic for snake's tail
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {   
                        //snake's tail
                        cout << "+";
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

void Input()
{
    // Manipulating user input
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    // Updating the game state as per previous position
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    //checking snake hits the wall

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;


    //checking snake eats itself
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    //checking if snake eats food
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}