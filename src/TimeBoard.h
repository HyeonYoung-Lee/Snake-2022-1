#include <ncurses.h>
#include <string>

class TimeBoard
{
protected:
    int width, height;
    double time;
    double stagetime;

public:
    TimeBoard();
    void setTime();
    WINDOW *updateTimeBoard();
};
