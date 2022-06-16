#ifndef __GATE__
#define __GATE__
#include <vector>
#include <random>
#include <algorithm>
#include "Item.h"

class Gate
{
private:
    int gate[3];

public:
    Gate();
    void resetGate();
    int getX();
    int getY();
    int getValue();
};
#endif
