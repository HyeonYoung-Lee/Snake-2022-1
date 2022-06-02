#include <ncurses.h>
#include <iostream>
#include <string>
#include "Scene.h"
#include <thread>
#include "Info.h"
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

WINDOW *Scene::gamingScene(int stage, MapSet mapset, Snake snake, Item growth, Item poison)
{
    WINDOW *winGaming;
    winGaming = newwin(23, 58, 4, 4);
    // snake = snake.clearSnake();

    if (stage != 0)
    {
        mapset.LoadMap(stage);
        mapset.printSnake(snake);

        // Item //
        mapset.printItem(growth);
        mapset.printItem(poison);

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
    wbkgd(winScene, COLOR_PAIR(stage));
    wattron(winScene, COLOR_PAIR(stage));
    if (stage == 0)
        mvwprintw(winScene, 5, 5, "Press Any Key To Start Snake Game!");

    wrefresh(winScene);
    return winScene;
}
bool Scene::conditionSnake()
{
    Info info;
    int snakeX = info.snakeLoc[0][0];
    int snakeY = info.snakeLoc[0][1];
    for(int i=0;i<info.allWallLoc.size();i++){
        if(snakeX == info.allWallLoc[i][0] && snakeY == info.allWallLoc[i][1]){
            return false;
        }
    }
    return true;
    
}
