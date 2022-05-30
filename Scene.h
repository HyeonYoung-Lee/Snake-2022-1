#include "Snake.h"
class Scene
{
protected:
    int width, height;
    int score;

public:
    Scene();
    void startScene();
    WINDOW *changeScene(int stage);
    WINDOW *gamingScene(int stage, Snake *snake, int *key);
    // WINDOW *movingSnake(int stage);
};
