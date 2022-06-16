#include "Stage.h"
#include "ETCScene.h"
#include "Item.h"
#include "Gate.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <fstream>

class Scene
{
protected:
    int width, height;

public:
    Scene();
    WINDOW *changeScene(int stage, Snake snake);
    WINDOW *gamingScene(int stage, MapSet &mapset, Snake &snake, Item &growth, Item &poison, Gate &fGate, Gate &sGate);
};
