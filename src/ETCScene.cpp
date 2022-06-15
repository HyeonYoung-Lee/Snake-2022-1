#include "ETCScene.h"

GameStartScene::GameStartScene()
{
	this->width = 100;
	this->height = 100;
	this->selected = 0;
}

int	GameStartScene::GameStartStatus(int num, int chk) {
	if (num == 0 && chk == 1)
		return	0;
	else if (num == 1 && chk == 1)
		return	1;
	else
		return	2;
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
		mvwprintw(winGameStart, idx, 1, charStr);
		idx++;
    }
	scenefile.close();
	// int	key = KEY_UP;
	// while (true) {
	// 	key = getch();
	// 	if (key == KEY_DOWN)
	// 	{
	// 		mvwprintw(winGameStart, 24, 28, "  ");
	// 		mvwprintw(winGameStart, 25, 28, "->");
	// 		selectMode = 0;
	// 	}
	// 	else if (key == KEY_UP)
	// 	{
	// 		mvwprintw(winGameStart, 24, 28, "->");
	// 		mvwprintw(winGameStart, 25, 28, "  ");
	// 		selectMode = 1;
	// 	}
	// 	else if (key == 13)
	// 	{
	// 		selected = 1;
	// 		break;
	// 	}
	// }
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
