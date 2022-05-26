#include <ncurses.h>
#include <iostream>
#include <string>
#include "Scene.h"
#include "Stage.h"

Scene::Scene()
{
    Scene::width = 90;
    Scene::height = 100;
    Scene::score = 0;
}

void Scene::startScene()
{
    initscr();
    resize_term(height, width);
    curs_set(0);
    noecho();
    border('|', '|', '-', '-', '*', '*', '*', '*');
    mvprintw(1, 3, "JEOJJEOL SNAKE");
    refresh();
    return;
}
WINDOW *Scene::changeScene(int stage)
{
    WINDOW *winGame;
    WINDOW *winScore;
    WINDOW *winUser;
    winGame = newwin(25, 60, 3, 3);
    winScore = newwin(5, 15, 5, 70);
    winUser = newwin(5, 15, 13, 70);

    MapSet mapset;
    Snake snake;

    start_color();

    init_pair(0, COLOR_BLUE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    wborder(winGame, '*', '*', '*', '*', '*', '*', '*', '*');
    wborder(winScore, '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(winUser, '|', '|', '-', '-', '+', '+', '+', '+');

    // Game window control
    if (stage == 0)
    {
        wbkgd(winGame, COLOR_PAIR(0));
        wattron(winGame, COLOR_PAIR(0));
        mvwprintw(winGame, 5, 5, "Press Any Key To Start Snake Game!");
    }
    else if (stage == 1)
    {
        wbkgd(winGame, COLOR_PAIR(1));
        wattron(winGame, COLOR_PAIR(1));
        mvwprintw(winGame, 1, 1, "Stage One");
        mapset.LoadMap(0);
        mapset.moveSnake(snake);
        for (int i = 0; i < mapset.getrow(); i++)
            mvwprintw(winGame, i + 2, 2, mapset.getMap(i));
    }

    // else if (stage == 2)
    // {
    //     wbkgd(winGame, COLOR_PAIR(2));
    //     wattron(winGame, COLOR_PAIR(2));
    //     mvwprintw(winGame, 1, 1, "Stage Two");
    //     mapset.LoadMap(1);
    //     for (int i = 0; i < mapset.getrow(); i++)
    //         mvwprintw(winGame, i + 2, 2, mapset.getMap(i));
    //     score++;
    // }
    // else if (stage == 3)
    // {
    //     wbkgd(winGame, COLOR_PAIR(3));
    //     wattron(winGame, COLOR_PAIR(3));
    //     mvwprintw(winGame, 1, 1, "Stage Three");
    //     mapset.LoadMap(2);
    //     for (int i = 0; i < mapset.getrow(); i++)
    //         mvwprintw(winGame, i + 2, 2, mapset.getMap(i));
    //     score++;
    // }
    // else
    // {
    //     wbkgd(winGame, COLOR_PAIR(4));
    //     wattron(winGame, COLOR_PAIR(4));
    //     mvwprintw(winGame, 1, 1, "Stage Four");
    //     mapset.LoadMap(3);
    //     for (int i = 0; i < mapset.getrow(); i++)
    //         mvwprintw(winGame, i + 2, 2, mapset.getMap(i));
    //     score++;
    // }

    // Score control
    mvwprintw(winScore, 1, 1, "Score:");
    std::string S = std::to_string(score);
    auto charScore = S.c_str();
    mvwprintw(winScore, 2, 1, charScore);

    // User name control
    mvwprintw(winUser, 1, 1, "Name:");
    mvwprintw(winUser, 2, 1, "User");

    wrefresh(winGame);
    wrefresh(winScore);
    wrefresh(winUser);
    return winGame;
}
