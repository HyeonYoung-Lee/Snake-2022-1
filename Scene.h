#include "Stage.h"
class Scene
{
protected:
    int width, height;

public:
    Scene();
    void startScene();
    WINDOW *changeScene(int stage, Snake snake);
<<<<<<< HEAD
    WINDOW *gamingScene(int stage, MapSet &mapset, Snake &snake, Item growth, Item poison);
=======
    WINDOW *gamingScene(int stage, MapSet mapset, Snake snake, Item growth, Item poison);
    bool conditionSnake();
>>>>>>> 9b6b4f21c38a459be6531a6741c88c3b7d1e3e57
};
