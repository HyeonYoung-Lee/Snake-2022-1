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

    WINDOW *win;
    scene.startScene();

    keypad(stdscr, TRUE);

    // show Intro scene
    win = scene.changeScene(0);

    // turn into Game scene
    getch();
    while (true)
    {
        win = scene.changeScene(1);
    }

    // exit game
    delwin(win);
    endwin();

    return 0;
}
