#include <ncurses.h>
#include <iostream>
#include "Scene.h"
#include "Snake.h"

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
    win = scene.changeScene(0);

    // turn into Game scene

    for (int i = 1; i < 5; i++)
    {
        getch();
        win = scene.changeScene(i);

        while (true)
        {
            winGaming = scene.gamingScene(i, snake);
            key = getch();
            if (key == 99)
            {
                delwin(winGaming);
                endwin();
                break;
            }
            switch (key)
            {
            case KEY_LEFT:
                --snake.x;
                break;
            case KEY_RIGHT:
                ++snake.x;
                break;
            case KEY_UP:
                --snake.y;
                break;
            case KEY_DOWN:
                ++snake.y;
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
