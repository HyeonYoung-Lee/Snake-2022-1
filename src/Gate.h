#ifndef __GATE__
#define __GATE__
#include <vector>
#include "Item.h"
class Gate
{
private:
    bool gateIsExist;
    int firstGateIdx; // save gotten index of info.wallLoc to use for avoiding gate overlap
    int secondGateIdx;
    std::vector<int> firstGate; // selected value of info.wallLoc[idx] (vector)
    std::vector<int> secondGate;

public:
    Gate();
    int resetGate(int num);
    void initGate();
    bool getGateExistence();
    void setGateExistecne(bool value);
    std::vector<int> getFirst();
    std::vector<int> getSecond();
};
#endif
