#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Snake.h"

class GameStartScene
{
protected:
    int width, height;
	int	selectMode; // Select Using Arrow Keys 0: START 1: EXIT
	int	selected; // Pressed Enter?
	int	pastKey;

public:
    GameStartScene();
	int	GameStartStatus();
	int	getSelectMode() { return	this->selectMode; }
	int getSelected() { return	this->selected; }
	WINDOW *renderGameStartScene(int key);
};

class GameOverScene
{
protected:
    int width, height;
	int	selectMode; // Select Using Arrow Keys 0: MAINMENU 1: EXIT
	int	selected; // Pressed Enter?
	int	pastKey;

public:
    GameOverScene();
	int	GameOverStatus();
	int	getSelectMode() { return	this->selectMode; }
	int getSelected() { return	this->selected; }
	WINDOW *renderGameOverScene(int key);
};

class GameClearScene
{
protected:
    int width, height;
	int	selected; // Pressed Enter?

public:
    GameClearScene();
	int getSelected() { return	this->selected; }
	WINDOW *renderGameClearScene();
};
