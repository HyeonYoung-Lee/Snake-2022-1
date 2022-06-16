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
    GameOverScene gameOverScene;
    GameClearScene gameClearScene;

    Gate fGate;
    Gate sGate;

    int key;
    int chkstage = 0;

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
        scene = Scene();
        snake.clearSnake();
        ScoreBoard scoreBoard;
        Mission missionBoard(len, grth, pois--, gate);
        len += 2, grth += (len / 2), gate *= 2;
        chkstage = 0;
        Item growthItem(5);
        Item poisonItem(6);
        scene.changeScene(i, snake); //없앰
        key = KEY_RIGHT;
        snake.setPastKey(key);

        info.MakeGate = false;
        while (snake.getIsAlive())
        {
            scoreBoard.updateScoreBoard(snake);
            missionBoard.updateMissionBoard(snake);

            // reset Gate when snake's length is evenNum
            if ((!info.gateExistence) && (snake.getCurrentLength() % 2 == 0))
            {
                info.gateLoc.clear();
                fGate.resetGate();
                sGate.resetGate();
            }

            if (snake.getCurrentLength() % 2 != 0)
            {
                info.gateExistence = false;
                info.gateExistence = false;
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
            winGaming = scene.gamingScene(i, mapset, snake, growthItem, poisonItem, fGate, sGate);
            growthItem.upTime();
            poisonItem.upTime();
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
