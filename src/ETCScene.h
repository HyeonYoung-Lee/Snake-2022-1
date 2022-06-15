#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Snake.h"

class GameStartScene
{
protected:
    int width, height;
	int	selectMode;
	int	selected;

public:
    GameStartScene();
	int	GameStartStatus(int num, int chk);
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
