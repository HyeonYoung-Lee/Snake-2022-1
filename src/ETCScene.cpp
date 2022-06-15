#include "ETCScene.h"

GameStartScene::GameStartScene()
{
	this->width = 100;
	this->height = 100;
}

WINDOW *GameStartScene::renderGameStartScene() {
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
		mvwprintw(winGameStart, 1, idx, charStr);
		idx++;
    }
	scenefile.close();
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
