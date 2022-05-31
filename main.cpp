#include <ncurses.h>
#include <iostream>
#include "Scene.h"

#include <chrono>
#include <thread>

using namespace std;

int main()
{
	// create default window including game screen, score board, user name
	Scene scene;
	MapSet mapset;
	Snake snake;
	int key;

	WINDOW *win;
	WINDOW *winGaming;
	scene.startScene();

	keypad(stdscr, TRUE);

	// show Intro scene
	win = scene.changeScene(0, snake.score);

	// turn into Game scene
	getch();
	//cbreak();

	for (int i = 1; i < 5; i++)
	{
		win = scene.changeScene(i, snake.score);
		while (snake.getIsAlive())
		{
			winGaming = scene.gamingScene(i, mapset, snake);
			//nodelay(stdscr, TRUE);
			// nodelay(winGaming, true);
			// getch();
			key = KEY_RIGHT;
			key = getch();
			if (key == 99)	break ;
			snake.understandKey(key);



			noecho();
			timeout(500);
		}
		snake.clearSnake();
	}

	// exit game
	delwin(win);
	delwin(winGaming);
	endwin();

	return 0;
}
