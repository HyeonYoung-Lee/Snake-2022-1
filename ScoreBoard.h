#include "Snake.h"
class ScoreBoard
{
protected:
    int width, height;

public:
    ScoreBoard();
    WINDOW *updateScoreBoard(Snake snake);
};