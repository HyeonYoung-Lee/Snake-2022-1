#include "Stage.h"
class Scene
{
protected:
    int width, height;

public:
    Scene();
    WINDOW *changeScene(int stage, Snake snake);
    WINDOW *gamingScene(int stage, MapSet &mapset, Snake &snake, Item &growth, Item &poison);
};
