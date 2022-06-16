#ifndef __GATE__
#define __GATE__
#include <vector>
#include "Item.h"
class Gate
{
private:
    // bool makeGate;
    // bool gateIsExist;
    int gate[3];

public:
    Gate();
    void resetGate();
    int getX();
    int getY();
    int getValue();
};
#endif
