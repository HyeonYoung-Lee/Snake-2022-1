#include <ncurses.h>
#include "Scene.h"
#include "Snake.h"
#include "ScoreBoard.h"
#include "Mission.h"
#include "Item.h"
#include "Info.h"
#include "Gate.h"
using namespace std;

int main()
{
    // create default window including game screen, score board, user name
    Info info;
    Scene scene;
    MapSet mapset;
    Snake snake;
    GameStartScene gameStartScene;
    Gate gateset;
    GameOverScene gameOverScene;
    GameClearScene gameClearScene;
    int key;
    int chkstage = 0;
    int itemTime = 0;

    WINDOW *winGaming;
    keypad(stdscr, TRUE);
    key = KEY_UP;
    gameStartScene.renderGameStartScene(key);
    while (gameStartScene.GameStartStatus() == -1)
    {
        key = getch();
        gameStartScene.renderGameStartScene(key);
        if (gameStartScene.GameStartStatus() == 0)
        {
            endwin();
            return 0;
        }
        else if (gameStartScene.GameStartStatus() == 1)
            break;
    }
    scene = Scene();

    int len, grth, pois, gate;
    len = 5, grth = 2, pois = 4, gate = 0;

    for (int i = 1; i < 5; i++)
    {
        ScoreBoard scoreBoard;
        Mission missionBoard(len, grth, pois--, gate);
        len += 2, grth += (len / 2), gate *= 2;

        Item growthItem(5);
        Item poisonItem(6);
        scene.changeScene(i, snake); //없앰
        key = KEY_RIGHT;
        snake.setPastKey(key);

        while (snake.getIsAlive())
        {
            scoreBoard.updateScoreBoard(snake);
            missionBoard.updateMissionBoard(snake);
            growthItem.upTime();
            poisonItem.upTime();

            // reset Gate when snake's length is even num
            if ((!gateset.getGateExistence()) && (snake.getCurrentLength() % 2 == 0))
            {
                gateset.resetGate(1);
                gateset.resetGate(2);
                gateset.setGateExistecne(true);
            }

            // init Gate if snake's length is odd num
            if ((gateset.getGateExistence()) && (snake.getCurrentLength() % 2 != 0))
                gateset.initGate();

            if ((growthItem.getTime() != 0) && (growthItem.getTime() % 40 == 0)) // 10�� �� resetItem
            {
                growthItem.resetItem(5);
            }
            if ((poisonItem.getTime() != 0) && (poisonItem.getTime() % 40 == 0)) // 10�� �� resetItem
            {
                poisonItem.resetItem(6);
            }
            nodelay(stdscr, TRUE);
            key = getch();
            int check = snake.understandKey(key);

            if (check == -3)
                continue;
            if (check == -4 || missionBoard.missionAllCleared())
            {
                chkstage = 1;
                break;
            }
            winGaming = scene.gamingScene(i, mapset, snake, growthItem, poisonItem, gateset);
        }
        nodelay(stdscr, FALSE);
        scene = Scene();
        if (chkstage == 1)
        {
            gameClearScene.renderGameClearScene();
            getch();
            continue;
        }
        else
        {
            key = KEY_UP;
            gameOverScene.renderGameOverScene(key);
            while (gameOverScene.GameOverStatus() == -1)
            {
                key = getch();
                gameOverScene.renderGameOverScene(key);
                if (gameOverScene.GameOverStatus() == 0)
                {
                    endwin();
                    return 0;
                }
                else if (gameOverScene.GameOverStatus() == 1)
                {
                    main();
                    return 0;
                }
            }
        }
        snake.clearSnake();
    }

    delwin(winGaming);
    endwin();

    return 0;
}
