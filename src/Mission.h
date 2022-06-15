#include "Snake.h"
class Mission
{
private:
    int width, height;

    int misLength;
    int misGrowth;
    int misPoison;
    int misGate;

    bool length;
    bool growth;
    bool poison;
    bool gate;

public:
    Mission(int length, int growth, int posion, int gate);
    WINDOW *updateMissionBoard(Snake snake);
    int getMisLength() { return misLength; }
    int getMisGrowth() { return misGrowth; }
    int getMisPoison() { return misPoison; }
    int getMisGate() { return misGate; }
};
