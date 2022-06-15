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
