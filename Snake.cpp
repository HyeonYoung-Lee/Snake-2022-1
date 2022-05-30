#include <iostream>
#include "Snake.h"
#include <ncurses.h>

Snake::Snake()
{
    this->direction = 2;
    this->isDead = false;
    this->x = 6;
    this->y = 6;
    this->score = 0;
}
Snake::~Snake() {}

void Snake::setDir(int direction)
{
    this->direction = direction;
}

void Snake::willMove()
{
    if (direction == 1)
    {
        y--;
    }
    else if (direction == 2)
    {
        x++;
    }
    else if (direction == 3)
    {
        y++;
    }
    else if (direction == 4)
    {
        x--;
    }
}

void Snake::upDate()
{
    int KeyPressed;

    KeyPressed = getch();
    switch (KeyPressed)
    {
    case KEY_LEFT:
        if (direction != 4)
            direction = 4;
        else
            break;
        break;

    default:
        break;
    }
}

void Snake::setFirst()
{
    this->x = 6;
    this->y = 6;
    return;
}

void Snake::addScore()
{
    score++;
}

int Snake::getScore()
{
    return score;
}

// score board accessor
void Snake::setCurrentLength(int cl)
{
    currentLength = cl;
}
int Snake::getCurrentLength()
{
    return currentLength;
}
void Snake::setMaxLength(int ml)
{
    maxLength = ml;
}
int Snake::getMaxLength()
{
    return maxLength;
}
void Snake::setGrowthItems(int gi)
{
    growthItems = gi;
}
int Snake::getGrowthItems()
{
    return growthItems;
}
void Snake::setPoisonItems(int pi)
{
    poisonItems = pi;
}
int Snake::getPoisonItems()
{
    return poisonItems;
}
void Snake::setGateUses(int gu)
{
    gateUses = gu;
}
int Snake::getGateUses()
{
    return gateUses;
}