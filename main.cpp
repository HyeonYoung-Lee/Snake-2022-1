#include <ncurses.h>
#include <iostream>
#include "Scene.h"
#include "Snake.h"
#include "ScoreBoard.h"
#include "Mission.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    // create default window including game screen, score board, user name
    Scene scene;
    MapSet mapset;
    Snake snake;
    ScoreBoard scoreBoard;
    Mission missionBoard;
    int key;

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
        win = scene.changeScene(i, snake);
        while (snake.getIsAlive())
        {
            winGaming = scene.gamingScene(i, mapset, snake);
            winScoreBoard = scoreBoard.updateScoreBoard(snake);
            winMission = missionBoard.updateMissionBoard(snake);
            nodelay(stdscr, TRUE);
            timeout(500);
            cbreak();
            
            key = KEY_RIGHT;
            key = getch();
            noecho();
            snake.understandKey(key);
            if (key == 99)
                break;

            
            
        }
        snake.clearSnake();
    }

    // exit game
    delwin(win);
    delwin(winGaming);
    endwin();

    return 0;
}
