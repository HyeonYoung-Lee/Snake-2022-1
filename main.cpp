#include <ncurses.h>
#include <iostream>
#include "Scene.h"
#include "Snake.h"

#include <chrono>
#include <thread>
#include "kbhit.h"

using namespace std;

int main()
{
    // create default window including game screen, score board, user name
    Scene scene;
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

    nodelay(stdscr, true);
    timeout(500);
    // halfdelay(10);
    // nocbreak();
    cbreak();
    for (int i = 1; i < 5; i++)
    {
        snake.setFirst();
        win = scene.changeScene(i, snake.score);
        key = KEY_RIGHT;
        while (true)
        {
            winGaming = scene.gamingScene(i, snake);
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
                key = getch();
                if (key == 99)
                    break;
            }
            // this_thread::sleep_for(chrono::milliseconds(500));
            switch (key)
            {
            case KEY_LEFT:
                --snake.x;
                snake.direction = 4;
                break;
            case KEY_RIGHT:
                ++snake.x;
                snake.direction = 2;
                break;
            case KEY_UP:
                --snake.y;
                snake.direction = 1;
                break;
            case KEY_DOWN:
                ++snake.y;
                snake.direction = 3;
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
