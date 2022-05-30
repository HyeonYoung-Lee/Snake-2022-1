#include "Snake.h"
class Scene
{
protected:
    int width, height;

public:
    Scene();
    void startScene();
    WINDOW *changeScene(int stage, int score);
    WINDOW *gamingScene(int stage, Snake snake);
};
