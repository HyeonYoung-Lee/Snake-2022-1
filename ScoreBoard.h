#include "Snake.h"
class ScoreBoard
{
protected:
    int width, height;

public:
    ScoreBoard();
    WINDOW *upDateScoreBoard(Snake snake);
    // WINDOW *updateScore(Snake snake);
};