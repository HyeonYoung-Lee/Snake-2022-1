#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Snake.h"

class GameStartScene
{
protected:
    int width, height;

public:
    GameStartScene();
    WINDOW *renderGameStartScene();
};

class GameOverScene
{
protected:
    int width, height;

public:
    GameOverScene();
    WINDOW *updateScoreBoard(Snake snake);
};
