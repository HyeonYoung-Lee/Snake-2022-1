#include "TimeBoard.h"

TimeBoard::TimeBoard()
{
    width = 19;
    height = 5;
	time = 0;
	stagetime = 0;
}

void	TimeBoard::setTime() {
	this->stagetime = 0;
}

WINDOW *TimeBoard::updateTimeBoard()
{
    WINDOW *winScore;
    winScore = newwin(height, width, 21, 70);
    wborder(winScore, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(winScore, 1, 1, "Total Game Time");
	// Time Render
	time += 0.5;
	std::string Time = std::string("Time: ") + std::to_string(int(this->time));
    auto charTime = Time.c_str();
	mvwprintw(winScore, 2, 1, charTime);
	// Stage Time Render
	stagetime += 0.5;
	std::string stageTime = std::string("Stage Time: ") + std::to_string(int(this->stagetime));
    auto charstageTime = stageTime.c_str();
    mvwprintw(winScore, 3, 1, charstageTime);
    wrefresh(winScore);

    return winScore;
}
