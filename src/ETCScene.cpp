#include "ETCScene.h"

GameOverScene::GameOverScene()
{
    width = 100;
    height = 100;
}

WINDOW *GameOverScene::updateScoreBoard(Snake snake)
{
    WINDOW *winGameover;
    winGameover = newwin(height, width, 5, 70);
    wborder(winGameover, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(winGameover, 1, 1, "Game Over");

    return winGameover;
}
