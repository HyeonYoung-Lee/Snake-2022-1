#include <ncurses.h>
#include <iostream>
#include "Scene.h"
#include "Snake.h"

using namespace std;

int main()
{
    // create default window including game screen, score board, user name
    Scene scene;

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
    // win = scene.changeScene(1);

    // // example - if press any key, change game stage and score++
    // // stage two
    // getch();
    // win = scene.changeScene(2);
    // // stage three
    // getch();
    // win = scene.changeScene(3);
    // // stage four
    // getch();
    // win = scene.changeScene(4);

    // exit game
    delwin(win);
    endwin();

    return 0;
}
