#include "ScoreBoard.h"
using namespace std;

ScoreBoard::ScoreBoard()
{
    width = 19;
    height = 7;
}

WINDOW *ScoreBoard::updateScoreBoard(Snake snake)
{
    WINDOW *winScore;
    winScore = newwin(height, width, 5, 70);
    wborder(winScore, '|', '|', '-', '-', '+', '+', '+', '+');

    mvwprintw(winScore, 1, 1, "Score Board");
	// B: Render
	std::string Length = std::string("B: ") + std::to_string(snake.getCurrentLength());
	Length += std::string(" / ");
	Length += std::to_string(snake.getMaxLength());
    auto charLength = Length.c_str();
    mvwprintw(winScore, 2, 1, charLength);
	// +: Render
	std::string Growth = std::string("+: ") + std::to_string(snake.getGrowthItems());
    auto charGrowth = Growth.c_str();
    mvwprintw(winScore, 3, 1, charGrowth);
	// -: Render
	std::string Poison = std::string("-: ") + std::to_string(snake.getPoisonItems());
    auto charPoison = Poison.c_str();
    mvwprintw(winScore, 4, 1, charPoison);
    wrefresh(winScore);
	// G: Render
	std::string Gate = std::string("G: ") + std::to_string(snake.getGateUses());
    auto charGate = Gate.c_str();
    mvwprintw(winScore, 5, 1, charGate);
    wrefresh(winScore);

    return winScore;
}
