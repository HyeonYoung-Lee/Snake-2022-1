#include <ncurses.h>
#include "Scene.h"
#include "Snake.h"
#include "ScoreBoard.h"
#include "Mission.h"
#include "Item.h"
#include "Info.h"
#include "Gate.h"
using namespace std;

int main()
{
    // create default window including game screen, score board, user name
    Info info;
    Scene scene;
    MapSet mapset;
    Snake snake;
    ScoreBoard scoreBoard;
    Mission missionBoard;
    int key;

    int itemTime = 0;

    WINDOW *win;
    WINDOW *winGaming;
    WINDOW *winScoreBoard;
    WINDOW *winMission;
    keypad(stdscr, TRUE);

    // show Intro scene
    win = scene.changeScene(0, snake);

    // turn into Game scene
    getch();
    for (int i = 1; i < 5; i++)
    {
        Item growthItem(5);
        Item poisonItem(6);
        win = scene.changeScene(i, snake);
		key = KEY_RIGHT;
        snake.setPastKey(key);

        while (snake.getIsAlive())
        {
            if ((growthItem.getTime() != 0) && (growthItem.getTime() % 40 == 0)) // 10�� �� resetItem
            {
                growthItem.resetItem(5);
            }
            if ((poisonItem.getTime() != 0) && (poisonItem.getTime() % 40 == 0)) // 10�� �� resetItem
            {
                poisonItem.resetItem(6);
            }
			nodelay(stdscr, TRUE);
			key = getch();
			int check = snake.understandKey(key);

			if (check == -3)
				continue;
			if (check == -4)
				break;
            winGaming = scene.gamingScene(i, mapset, snake, growthItem, poisonItem);

            scoreBoard.updateScoreBoard(snake);
            missionBoard.updateMissionBoard(snake);
            growthItem.upTime();
            poisonItem.upTime();
        }
        snake.clearSnake();
    }

    // exit game
    delwin(win);
    delwin(winGaming);
    endwin();

    return 0;
}
