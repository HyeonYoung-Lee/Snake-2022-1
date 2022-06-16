#include "ETCScene.h"

GameStartScene::GameStartScene()
{
	this->width = 100;
	this->height = 100;
	this->selected = 0;
}

int	GameStartScene::GameStartStatus() {
	if (this->selectMode == 0 && this->selected == 1) // START ENTER
		return	0;
	else if (this->selectMode == 1 && this->selected == 1) // EXIT ENTER
		return	1;
	else
		return	-1;
}

WINDOW *GameStartScene::renderGameStartScene(int key) {
	WINDOW *winGameStart;
	initscr();

    resize_term(height, width);
    curs_set(0);
    noecho();
	winGameStart = newwin(height, width, 0, 0);
	std::ifstream	scenefile;
	std::string	filess;
	int	idx = 0;
	scenefile.open("./Framework/startscene");
	while (!(scenefile.eof())) {
		getline(scenefile, filess);
		auto charStr = filess.c_str();
		mvwprintw(winGameStart, idx, 1, charStr);
		idx++;
    }
	scenefile.close();
	switch (key) {
		case KEY_DOWN:
			mvwprintw(winGameStart, 24, 28, "  ");
			mvwprintw(winGameStart, 26, 28, "->");
			this->selectMode = 0;
			this->selected = 0;
			break;
		case KEY_UP:
			mvwprintw(winGameStart, 24, 28, "->");
			mvwprintw(winGameStart, 26, 28, "  ");
			this->selectMode = 1;
			this->selected = 0;
			break;
		case 10:
			this->selected = 1;
			break;
	}
	wborder(winGameStart, '|', '|', '-', '-', '*', '*', '*', '*');
	wrefresh(winGameStart);
	return	winGameStart;
}

GameOverScene::GameOverScene()
{
	this->width = 100;
	this->height = 100;
	this->selected = 0;
}

int	GameOverScene::GameOverStatus() {
	if (this->selectMode == 0 && this->selected == 1) // TRYAGAIN ENTER
		return	0;
	else if (this->selectMode == 1 && this->selected == 1) // EXIT ENTER
		return	1;
	else
		return	-1;
}

WINDOW *GameOverScene::renderGameOverScene(int key) {
	WINDOW *winGameOver;
	initscr();

    resize_term(height, width);
    curs_set(0);
    noecho();
	winGameOver = newwin(height, width, 0, 0);
	std::ifstream	scenefile;
	std::string	filess;
	int	idx = 0;
	scenefile.open("./Framework/gameoverscene");
	while (!(scenefile.eof())) {
		getline(scenefile, filess);
		auto charStr = filess.c_str();
		mvwprintw(winGameOver, idx, 1, charStr);
		idx++;
    }
	scenefile.close();
	switch (key) {
		case KEY_DOWN:
			mvwprintw(winGameOver, 24, 28, "  ");
			mvwprintw(winGameOver, 26, 28, "->");
			this->selectMode = 0;
			this->selected = 0;
			break;
		case KEY_UP:
			mvwprintw(winGameOver, 24, 28, "->");
			mvwprintw(winGameOver, 26, 28, "  ");
			this->selectMode = 1;
			this->selected = 0;
			break;
		case 10:
			this->selected = 1;
			break;
	}
	wborder(winGameOver, '|', '|', '-', '-', '*', '*', '*', '*');
	wrefresh(winGameOver);
	return	winGameOver;
}

GameClearScene::GameClearScene()
{
	this->width = 100;
	this->height = 100;
	this->selected = 0;
}

WINDOW *GameClearScene::renderGameClearScene() {
	WINDOW *winGameClear;
	initscr();

    resize_term(height, width);
    curs_set(0);
    noecho();
	winGameClear = newwin(height, width, 0, 0);
	std::ifstream	scenefile;
	std::string	filess;
	int	idx = 0;
	scenefile.open("./Framework/gameclearscene");
	while (!(scenefile.eof())) {
		getline(scenefile, filess);
		auto charStr = filess.c_str();
		mvwprintw(winGameClear, idx, 1, charStr);
		idx++;
    }
	scenefile.close();
	mvwprintw(winGameClear, 23, 28, "->");
	wborder(winGameClear, '|', '|', '-', '-', '*', '*', '*', '*');
	wrefresh(winGameClear);
	return	winGameClear;
}
