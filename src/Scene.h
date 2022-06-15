#include "Stage.h"
#include "ETCScene.h"
#include <iostream>
#include <fstream>
class Scene
{
protected:
    int width, height;

public:
    Scene();
    WINDOW *changeScene(int stage, Snake snake);
    WINDOW *gamingScene(int stage, MapSet &mapset, Snake &snake, Item &growth, Item &poison);
};
