#include <ncurses.h>
#include <iostream>
#include <string>
#include "Scene.h"
#include <thread>
using std::this_thread::sleep_for;
// ignore
Scene::Scene()
{
    Scene::width = 90;
    Scene::height = 100;
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

WINDOW *Scene::gamingScene(int stage, MapSet mapset, Snake snake)
{
    WINDOW *winGaming;
    winGaming = newwin(23, 58, 4, 4);
    // snake = snake.clearSnake();
    if (stage != 0)
    {
        mapset.LoadMap(stage);
        mapset.printSnake(snake);
        std::string stage_string = "Stage " + std::to_string(stage);
        auto charStage = stage_string.c_str();
        mvwprintw(winGaming, 0, 0, charStage);
        for (int i = 0; i < mapset.getRow(); i++)
            mvwprintw(winGaming, i + 2, 0, mapset.printMap(i));
    }
    wrefresh(winGaming);
    return winGaming;
}

WINDOW *Scene::changeScene(int stage, Snake snake)
{
    WINDOW *winScene;
    WINDOW *trash;
    winScene = newwin(25, 60, 3, 3);

    start_color();

    init_pair(0, COLOR_BLUE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);

    wborder(winScene, '*', '*', '*', '*', '*', '*', '*', '*');

    // Scene window control
    if (stage == 0)
    {
        wbkgd(winScene, COLOR_PAIR(0));
        wattron(winScene, COLOR_PAIR(0));
        mvwprintw(winScene, 5, 5, "Press Any Key To Start Snake Game!");
    }
    else if (stage == 1)
    {
        wbkgd(winScene, COLOR_PAIR(1));
        wattron(winScene, COLOR_PAIR(1));
        mvwprintw(winScene, 1, 1, "Stage One");
    }
    else if (stage == 2)
    {
        wbkgd(winScene, COLOR_PAIR(2));
        wattron(winScene, COLOR_PAIR(2));
        mvwprintw(winScene, 1, 1, "Stage Two");
    }
    else if (stage == 3)
    {
        wbkgd(winScene, COLOR_PAIR(3));
        wattron(winScene, COLOR_PAIR(3));
        mvwprintw(winScene, 1, 1, "Stage Three");
    }
    else
    {
        wbkgd(winScene, COLOR_PAIR(4));
        wattron(winScene, COLOR_PAIR(4));
        mvwprintw(winScene, 1, 1, "Stage Four");
    }

    wrefresh(winScene);
    return winScene;
}
