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
	void	setPastKey(int key) { this->pastKey = key; }
	int getPastKey() { return	this->pastKey; }
	WINDOW *renderGameStartScene(int key);
};

class GameOverScene
{
protected:
    int width, height;

public:
    GameOverScene();
    WINDOW *updateScoreBoard(Snake snake);
};
