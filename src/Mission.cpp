#include "Mission.h"

Mission::Mission(int mlength, int mgrowth, int mposion, int mgate)
{
	width = 19;
	height = 7;

	misLength = mlength;
	misGrowth = mgrowth;
	misPoison = mposion;
	misGate = mgate;

	length = false;
	growth = false;
	poison = false;
	gate = false;
}

bool	Mission::missionAllCleared() {
	if (this->length == true && this->growth == true && this->poison == true && this->gate == true)
		return	true;
	return	false;
}

WINDOW *Mission::updateMissionBoard(Snake &snake)
{
	WINDOW *winMission;
	winMission = newwin(height, width, 13, 70);
	wborder(winMission, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwprintw(winMission, 1, 1, "Mission");
	// B: Render
	std::string MB = std::string("B: ") + std::to_string(getMisLength());
	if (snake.getCurrentLength() >= misLength)
	{
		MB += " (v)";
		length = true;
	}
	else
	{
		MB += " ( )";
		length = false;
	}
	auto charMB = MB.c_str();
	mvwprintw(winMission, 2, 1, charMB);
	// +: Render
	std::string MGrowth = std::string("+: ") + std::to_string(getMisGrowth());
	if (snake.getGrowthItems() >= misGrowth)
	{
		MGrowth += " (v)";
		growth = true;
	}
	else
	{
		MGrowth += " ( )";
		growth = false;
	}
	auto charMGrowth = MGrowth.c_str();
	mvwprintw(winMission, 3, 1, charMGrowth);
	// -: Render
	std::string MPoison = std::string("-: ") + std::to_string(getMisPoison());
	if (snake.getPoisonItems() < misPoison)
	{
		MPoison += " (v)";
		poison = true;
	}
	else
	{
		MPoison += " ( )";
		poison = false;
		snake.setIsAlive(false);
	}
	auto charMPoison = MPoison.c_str();
	mvwprintw(winMission, 4, 1, charMPoison);
	// G: Render
	std::string MGate = std::string("G: ") + std::to_string(getMisGate());
	if (snake.getGateUses() >= misGate)
	{
		MGate += " (v)";
		gate = true;
	}
	else
	{
		MGate += " ( )";
		gate = false;
	}
	auto charMGate = MGate.c_str();
	mvwprintw(winMission, 5, 1, charMGate);

	wrefresh(winMission);
	return winMission;
}
