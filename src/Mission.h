#include "Snake.h"
class Mission
{
private:
    int width, height;
    int misLength = 8;
    int misGrowth = 5;
    int misPoison = 3;
    int misGate = 1;
    bool length;
    bool growth;
    bool poison;
    bool gate;

public:
    Mission();
    WINDOW *updateMissionBoard(Snake snake);
	int getMisLength() {return	misLength; }
	int getMisGrowth() {return	misGrowth; }
	int getMisPoison() {return	misPoison; }
	int	getMisGate() { return	misGate; }
};
