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
    // create default window including game screen, Score board, Mission
    Scene scene;
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

    nodelay(stdscr, true);
    timeout(500);
    // halfdelay(10);
    // nocbreak();
    cbreak();
    for (int i = 1; i < 5; i++)
    {
        snake.setFirst();
        win = scene.changeScene(i, snake);
        while (true)
        {
            winGaming = scene.gamingScene(i, snake);
            winScoreBoard = scoreBoard.updateScoreBoard(snake);
            winMission = missionBoard.updateMissionBoard(snake);
            // nodelay(winGaming, true);
            // getch();
            key = KEY_RIGHT;
            key = getch();
            if (key == ERR)
            {
                if (snake.direction == 1)
                    key = KEY_UP;
                else if (snake.direction == 2)
                    key = KEY_RIGHT;
                else if (snake.direction == 3)
                    key = KEY_DOWN;
                else if (snake.direction == 4)
                    key = KEY_LEFT;
            }

            if (key == 99)
            {
                break;
            }
            // this_thread::sleep_for(chrono::milliseconds(500));
            switch (key)
            {
            case KEY_UP:
                --snake.y;
                snake.direction = 1;
                break;
            case KEY_RIGHT:
                ++snake.x;
                snake.direction = 2;
                break;
            case KEY_DOWN:
                ++snake.y;
                snake.direction = 3;
                break;
            case KEY_LEFT:
                --snake.x;
                snake.direction = 4;
                break;
            }
        }
    }

    // exit game
    delwin(win);
    delwin(winGaming);
    endwin();

    return 0;
}
