#include <ncurses.h>
#include <iostream>
#include "Scene.h"
#include "Snake.h"

#include <chrono>
#include <thread>




using namespace std;

int main()
{
    // create default window including game screen, score board, user name
    Scene scene;
    Snake snake;
    int key;

    WINDOW *win;
    WINDOW *winGaming;
    scene.startScene();

    keypad(stdscr, TRUE);

    // show Intro scene
    win = scene.changeScene(0);

    // turn into Game scene
    
    getch();
    for(int i=1;i<5;i++){
        snake.setFirst();
        win = scene.changeScene(i);
        while(true){
            winGaming = scene.gamingScene(i, snake);
            // getch();
            key = KEY_RIGHT;
            if(key == 99 ){
                break;
            }
            this_thread::sleep_for(chrono::milliseconds(500));
            switch(key)
            {
                case KEY_LEFT:
                    --snake.x;
                    break;
                case KEY_RIGHT:
                    ++snake.x;
                    break;
                case KEY_UP:
                    --snake.y;
                    break;
                case KEY_DOWN:
                    ++snake.y;
                    break;
            }
        }
        
        
    }
    getch();
    // win = scene.changeScene(1);

    // // example - if press any key, change game stage and score++
    // // stage two
    // getch();
    // win = scene.changeScene(2);
    // // stage three
    // getch();
    // win = scene.changeScene(3);
    // // stage four
    // getch();
    // win = scene.changeScene(4);

    // exit game
    delwin(win);
    delwin(winGaming);
    endwin();

    return 0;
}
