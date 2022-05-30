#include "Snake.h"
class Scene
{
protected:
    int width, height;

public:
    Scene();
    void startScene();
    WINDOW *changeScene(int stage, Snake snake);
    WINDOW *gamingScene(int stage, Snake snake);
};
