class Scene
{
protected:
    int width, height;
    int score;

public:
    Scene();
    void startScene();
    WINDOW *changeScene(int stage);
};
