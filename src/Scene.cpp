#include "Scene.h"

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

        std::vector<int> snakehead = info.snakeLoc.at(0);
        auto itWall = std::find(info.allWallLoc.begin(), info.allWallLoc.end(), snakehead);
        if (itWall != info.allWallLoc.end())
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
                if ((0 < newHeadRow && newHeadRow < 20) && (newHeadCol == 0)) // left edge -> direction is right
                {
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                    snake.setDirection(2);
                }
                else if ((0 < newHeadRow && newHeadRow < 20) && (newHeadCol == 40)) // right edge -> direction is left
                {
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                    snake.setDirection(4);
                }
                else if ((0 < newHeadCol && newHeadCol < 40) && (newHeadRow == 0)) // top edge -> direction is bottom
                {
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                    snake.setDirection(3);
                }
                else if ((0 < newHeadCol && newHeadCol < 40) && (newHeadRow == 20)) // bottem edge -> direction is top
                {
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                    snake.setDirection(1);
                }
                else // inner edge
                {
                    int tempRow;
                    int tempCol;
                    if (snake.getDirection() == 1) // in direction == top  -> row--
                    {
                        tempRow = newHeadRow - 1;
                        tempCol = newHeadCol;
                        // check can remain direction
                        std::vector<int> temp{tempRow, tempCol};
                        auto it = std::find(info.allWallLoc.begin(), info.allWallLoc.end(), temp);
                        if (it != info.allWallLoc.end())
                            snake.setDirection(2);
                    }
                    else if (snake.getDirection() == 2) // in direction == right  -> col++
                    {
                        tempRow = newHeadRow;
                        tempCol = newHeadCol + 1;
                        std::vector<int> temp{tempRow, tempCol};
                        auto it = std::find(info.allWallLoc.begin(), info.allWallLoc.end(), temp);
                        if (it != info.allWallLoc.end())
                            snake.setDirection(3);
                    }
                    else if (snake.getDirection() == 3) // in direction == bottom  -> row++
                    {
                        tempRow = newHeadRow + 1;
                        tempCol = newHeadCol;
                        std::vector<int> temp{tempRow, tempCol};
                        auto it = std::find(info.allWallLoc.begin(), info.allWallLoc.end(), temp);
                        if (it != info.allWallLoc.end())
                            snake.setDirection(4);
                    }
                    else if (snake.getDirection() == 4) // in direction == left  -> col--
                    {
                        tempRow = newHeadRow;
                        tempCol = newHeadCol - 1;
                        std::vector<int> temp{tempRow, tempCol};
                        auto it = std::find(info.allWallLoc.begin(), info.allWallLoc.end(), temp);
                        if (it != info.allWallLoc.end())
                            snake.setDirection(1);
                    }
                    snake.addSnakeBody(newHeadRow, newHeadCol, 3);
                }
                snake.incGateUses();
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
    // if (stage == 0)
    // {
    // }

    wrefresh(winScene);
    return winScene;
}
