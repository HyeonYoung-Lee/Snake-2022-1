#include "Snake.h"
class Mission
{
private:
    int width, height;
    int maxLength = 10;
    int maxGrowth = 5;
    int maxPoison = 2;
    int maxGate = 1;
    bool length;
    bool growth;
    bool poison;
    bool gate;

public:
    Mission();
    WINDOW *updateMissionBoard(Snake snake);
};