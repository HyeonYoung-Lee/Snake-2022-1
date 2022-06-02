#include <ncurses.h>
#include <iostream>
#include "Scene.h"
#include "Snake.h"
#include "ScoreBoard.h"
#include "Mission.h"
#include <chrono>
#include <thread>
#include "Item.h"
#include "Info.h"
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
    scene.startScene();

    keypad(stdscr, TRUE);

    // show Intro scene
    win = scene.changeScene(0, snake);

    // turn into Game scene
    getch();
    // cbreak();
    for (int i = 1; i < 5; i++)
    {
        Item growthItem(5);
        Item poisonItem(6);
        win = scene.changeScene(i, snake);
        key = KEY_RIGHT;
        snake.setPastKey(key);
        while (snake.getIsAlive())
        {
            if ((itemTime != 0) && (itemTime % 20 == 0)) // 10ÃÊ ÈÄ resetItem
            {
                growthItem.resetItem();
                poisonItem.resetItem();
            }

            winGaming = scene.gamingScene(i, mapset, snake, growthItem, poisonItem);
            winScoreBoard = scoreBoard.updateScoreBoard(snake);
            winMission = missionBoard.updateMissionBoard(snake);
            nodelay(stdscr, TRUE);
            timeout(1000);
            cbreak();

            key = getch();
            noecho();
            bool check = snake.understandKey(key);

            if (!check)
            {
                if (key == 99)
                    break;
            }
            itemTime += 1;
        }
        snake.clearSnake();
    }

    // exit game
    delwin(win);
    delwin(winGaming);
    endwin();

    return 0;
}
