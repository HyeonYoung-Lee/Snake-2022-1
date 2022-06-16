#include "Scene.h"
#include "Info.h"
#include "Item.h"
#include "Gate.h"
Scene::Scene()
{
    Scene::width = 100;
    Scene::height = 100;
    initscr();
    resize_term(height, width);
    curs_set(0);
    noecho();
    border('|', '|', '-', '-', '*', '*', '*', '*');
    refresh();
    return;
}

WINDOW *Scene::gamingScene(int stage, MapSet &mapset, Snake &snake, Item &growth, Item &poison, Gate &gateset)
{
    WINDOW *winGaming;
    winGaming = newwin(23, 58, 4, 4);

    if (stage != 0)
    {
        Info info;
        mapset.LoadMap(stage);

        // Item //
        mapset.printItem(growth);
        mapset.printItem(poison);

        // Gate //
        if (gateset.getGateExistence())
            mapset.printGate(gateset);

        info.setSnakeLoc(snake);

        if (info.snakeLoc[0] == info.growthLoc)
        {
            growth.resetItem(5);
            snake.incGrowthItems();
            snake.snakeGrown();
        }
        if (info.snakeLoc[0] == info.poisonLoc)
        {
            poison.resetItem(6);
            snake.incPoisonItems();
            snake.snakePoisoned();
            if (snake.getCurrentLength() < 3)
            {
                snake.setIsAlive(false);
                return winGaming;
            }
        }
        for (int i = 0; i < info.allWallLoc.size(); i++)
        {
            if (info.snakeLoc[0] == info.allWallLoc[i])
            {
                snake.setIsAlive(false);
                return winGaming;
            }
        }
        for (int i = 1; i < info.snakeLoc.size(); i++)
        {
            if (info.snakeLoc[0] == info.snakeLoc[i])
            {
                snake.setIsAlive(false);
                return winGaming;
            }
        }
        for (int i = 1; i < info.snakeLoc.size(); i++)
        {
            if (info.snakeLoc[0] == info.snakeLoc[i])
            {
                snake.setIsAlive(false);
                return winGaming;
            }
        }
        snake.moveSnakeHead();
        mapset.printSnake(snake);

        std::string stage_string = "Stage " + std::to_string(stage);
        auto charStage = stage_string.c_str();
        mvwprintw(winGaming, 0, 0, charStage);
        for (int i = 0; i < mapset.getRow(); i++)
            mvwprintw(winGaming, i + 2, 0, mapset.printMap(i));
    }
    wrefresh(winGaming);
    usleep(500000 - (5000 * (stage - 1)));
    return winGaming;
}

WINDOW *Scene::changeScene(int stage, Snake snake)
{
    WINDOW *winScene;

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
    {
        // mvwprintw(winScene, 5, 5, "Press Any Key To Start Snake Game!");
    }

    wrefresh(winScene);
    return winScene;
}
