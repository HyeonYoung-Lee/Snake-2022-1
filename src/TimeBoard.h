#include <ncurses.h>
#include <string>
#include <cmath>

class TimeBoard
{
protected:
    int width, height;
	double	time;
	double	stagetime;

public:
    TimeBoard();
	void setTime();
    WINDOW *updateTimeBoard();
};
