#include <ncurses.h>
#include <iostream>
#include <string>
#include "ScoreBoard.h"
#include "Snake.h"
using namespace std;

ScoreBoard::ScoreBoard()
{
    width = 15;
    height = 5;
}

WINDOW *ScoreBoard::upDateScoreBoard(Snake snake)
{
    WINDOW *winScore;
    winScore = newwin(height, width, 5, 70);
    wborder(winScore, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(winScore, 1, 1, "Score Board");
    std::string S = std::to_string(snake.getScore());
    auto charScore = S.c_str();
    mvwprintw(winScore, 2, 1, charScore);
    wrefresh(winScore);
}