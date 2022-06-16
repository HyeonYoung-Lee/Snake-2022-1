#include "Scene.h"
#include "Info.h"
#include "Item.h"
#include "Gate.h"
#include <vector>
#include <algorithm>
#include <fstream>
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

WINDOW *Scene::gamingScene(int stage, MapSet &mapset, Snake &snake, Item &growth, Item &poison, Gate &fGate, Gate &sGate)
{
    WINDOW *winGaming;
    winGaming = newwin(23, 58, 4, 4);

    if (stage != 0)
    {
        Info info;
        mapset.LoadMap(stage);

        // Item //
        if ((growth.getTime() % 50 == 0)) // 10?? ?? resetItem
        {
            growth.resetItem();
        }
        if ((poison.getTime() % 50 == 0)) // 10?? ?? resetItem
        {
            poison.resetItem();
        }

        mapset.printItem(growth);
        mapset.printItem(poison);

        // Gate
        if (info.MakeGate == true)
        {
            mapset.printGate(fGate);
            mapset.printGate(sGate);
        }

        info.setSnakeLoc(snake);

        for (int i = 0; i < info.allWallLoc.size(); i++)
        {
            if (info.snakeLoc[0] == info.allWallLoc[i])
            {
                if (info.MakeGate == true)
                {
                    if (info.snakeLoc[0] != info.gateLoc[0] && info.snakeLoc[0] != info.gateLoc[1])
                    {
                        snake.setIsAlive(false);
                        return winGaming;
                    }
                }
                else
                {
                    snake.setIsAlive(false);
                    return winGaming;
                }
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

        if (info.MakeGate)
        {
            if (info.snakeLoc.at(0) == info.gateLoc.at(0) || info.snakeLoc.at(0) == info.gateLoc.at(1))
            {
                std::ofstream gateLog;
                gateLog.open("./log/gateLog", std::ios::app);
                std::vector<int> inGate = (info.snakeLoc.at(0) == info.gateLoc.at(0)) ? info.gateLoc.at(0) : info.gateLoc.at(1);
                std::vector<int> outGate = (info.snakeLoc.at(0) == info.gateLoc.at(0)) ? info.gateLoc.at(1) : info.gateLoc.at(0);
                int newHeadRow = outGate.at(0);
                int newHeadCol = outGate.at(1);
                gateLog << "in gate : " << inGate.at(0) << " " << inGate.at(1) << " ";
                gateLog << "out gate : " << newHeadRow << " " << newHeadCol << std::endl;

                // edge gate
                if (0 < newHeadRow && newHeadRow < 20)
                {
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                    if (newHeadCol == 0) // left edge -> direction is right
                        snake.setDirection(2);
                    else if (newHeadCol == 40) // right edge -> direction is left
                        snake.setDirection(4);
                }
                else if (0 < newHeadCol && newHeadCol < 40)
                {
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                    if (newHeadRow == 0) // top edge -> direction is bottom
                        snake.setDirection(3);
                    else if (newHeadRow == 20) // bottem edge -> direction is top
                        snake.setDirection(1);
                }
                else // inner edge
                {
                    if (snake.getDirection() == 3)
                        snake.setDirection(4);
                    else if (snake.getDirection() == 4)
                        snake.setDirection(1);
                    else if (snake.getDirection() == 1)
                        snake.setDirection(2);
                    else if (snake.getDirection() == 2)
                        snake.setDirection(3);
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                }
                gateLog.close();
            }
        }

        if (info.snakeLoc[0] == info.growthLoc)
        {
            growth.resetItem();
            snake.incGrowthItems();
            snake.snakeGrown();
        }
        if (info.snakeLoc[0] == info.poisonLoc)
        {
            poison.resetItem();
            snake.incPoisonItems();
            snake.snakePoisoned();
            if (snake.getCurrentLength() < 3)
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
    usleep(500000);
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
