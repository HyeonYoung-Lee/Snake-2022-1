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
    GameStartScene gameStartScene;
    int key;

    int itemTime = 0;

    WINDOW *winGaming;
    keypad(stdscr, TRUE);

    // win = scene.changeScene(0, snake);

    // turn into Game scene
    // show Intro scene
    // while (true) {
    gameStartScene.renderGameStartScene();
    // 	if (gameStartScene.GameStartStatus(gameStartScene.))
    // }
    getch();
    new Scene();
    for (int i = 1; i < 5; i++)
    {
        ScoreBoard scoreBoard;
        Mission missionBoard;
        Snake snake;

        Item growthItem(5);
        Item poisonItem(6);
        scene.changeScene(i, snake); //없앰
        key = KEY_RIGHT;
        snake.setPastKey(key);

        while (snake.getIsAlive())
        {
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
            if (check == -4)
                break;
            winGaming = scene.gamingScene(i, mapset, snake, growthItem, poisonItem);

            scoreBoard.updateScoreBoard(snake);
            missionBoard.updateMissionBoard(snake);
            growthItem.upTime();
            poisonItem.upTime();
        }
        snake.clearSnake();
    }

    // exit game
    // delwin(win);
    delwin(winGaming);
    endwin();

    return 0;
}
