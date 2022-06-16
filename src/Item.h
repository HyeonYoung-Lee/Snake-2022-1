#ifndef __ITEM__
#define __ITEM__
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>
#include "Info.h"

class Item
{
private:
    int item[3];
    int time;

public:
    Item(int value);
    void resetItem();
    int getX();
    int getY();
    int getValue();
    int getTime();
    void upTime();
};
#endif
