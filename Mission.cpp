#include <ncurses.h>
#include <iostream>
#include <string>
#include "Mission.h"
#include "Snake.h"
using namespace std;

Mission::Mission()
{
    width = 19;
    height = 7;
    bool length = false;
    bool growth = false;
    bool poison = false;
    bool gate = false;
}

WINDOW *Mission::updateMissionBoard(Snake snake)
{
    WINDOW *winMission;
    winMission = newwin(height, width, 13, 70);
    wborder(winMission, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwprintw(winMission, 1, 1, "Mission");
	// Mission B: Render
	//std::string MB = std::string("B: ") + std::to_string(snake.getGrowthItems());
    //auto charGrowth = Growth.c_str();
    //mvwprintw(winScore, 3, 1, charGrowth);

    wrefresh(winMission);
    return winMission;
}
