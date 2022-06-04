#include <ncurses.h>
#include <iostream>
#include <string>
#include "Snake.h"

class GameOverScene
{
protected:
    int width, height;

public:
    GameOverScene();
    WINDOW *updateScoreBoard(Snake snake);
};
