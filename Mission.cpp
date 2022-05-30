#include <ncurses.h>
#include <iostream>
#include <string>
#include "Mission.h"
#include "Snake.h"
using namespace std;

Mission::Mission()
{
    width = 15;
    height = 5;
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
    mvwprintw(winMission, 1, 1, "Name:");
    mvwprintw(winMission, 2, 1, "User");
    wrefresh(winMission);
    return winMission;
}
