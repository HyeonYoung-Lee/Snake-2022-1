#include "Scene.h"
#include "Info.h"
#include "Item.h"
#include "Gate.h"
#include <vector>

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

        // Gate
        //  if ( snake.getCurrentLength() % 2 == 0  && (info.snakeLoc[0] == info.gateLoc[0] || info.snakeLoc[0] == info.gateLoc[1])){
        //      int loc;
        //      if (info.snakeLoc[0] == info.gateLoc[0]){
        //          snake.addSnakeBody(info.gateLoc[1][0]-1, info.gateLoc[1][1], 3);
        //          snake.setDirection(1);
        //      }
        //      if (info.snakeLoc[0] == info.gateLoc[1]){
        //          snake.addSnakeBody(info.gateLoc[0][0]-1, info.gateLoc[0][1], 3);
        //          snake.setDirection(1);
        //      }
        //  }

        if (info.gateExistence)
        {
            if (info.snakeLoc[0] == info.gateLoc.at(0) || info.snakeLoc[0] == info.gateLoc.at(0))
            {
                std::ofstream gateLog;
                gateLog.open("./log/gateLog", ios::app);
                std::vector<int> inGate = (info.snakeLoc[0] == info.gateLoc[0]) ? info.gateLoc[0] : info.gateLoc[1];
                std::vector<int> outGate = (info.snakeLoc[0] == info.gateLoc[0]) ? info.gateLoc[1] : info.gateLoc[0];
                int newHeadRow = outGate.at(0);
                int newHeadCol = outGate.at(1);
                gateLog << "in gate : " << inGate.at(0) << " " << inGate.at(1) << std::endl;
                gateLog << "out gate : " << newHeadRow << " " << newHeadCol << " ";

                // edge gate
                if (0 < newHeadRow && newHeadRow < 20)
                {
                    if (newHeadCol == 0)
                    { // left edge -> direction is right
                        snake.addSnakeBody(newHeadRow, newHeadCol + 1, 3);
                    }
                    else if (newHeadCol == 40)
                    { // right edge -> direction is left
                        snake.addSnakeBody(newHeadRow, newHeadCol - 1, 3);
                    }
                }
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

        for (int i = 0; i < info.allWallLoc.size(); i++)
        {
            if (info.snakeLoc[0] == info.allWallLoc[i] && (info.snakeLoc[0] != info.gateLoc[0] && info.snakeLoc[0] != info.gateLoc[1]))
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
    usleep(500000 - (50000 * (stage - 1)));
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
