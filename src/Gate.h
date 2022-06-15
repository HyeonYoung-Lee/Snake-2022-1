#ifndef __GATE__
#define __GATE__
#include <vector>
#include "Item.h"
class Gate
{
private:
    int idx;
    std::vector<int> gate;

public:
    Gate();
    int resetGate();
    int getX();
    int getY();
    int getValue();
};
#endif
