class Scene
{
protected:
    int width, height;
    int score;

public:
    Scene();
    void startScene();
    WINDOW *changeScene(int stage);
    WINDOW *gamingScene(int stage);
    // WINDOW *movingSnake(int stage);
};
