#include "Item.h"
#include "Info.h"
#include <random>
#include <time.h>

Item::Item(int value)
{
    resetItem(value);
}

void Item::resetItem(int value)
{
    int x, y;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(1, 19);
    std::uniform_int_distribution<int> dixY(1, 39);
    item[0] = disX(gen);
    item[1] = dixY(gen);
    item[2] = value; // growth == 5, poison==6

    Info info;
    if (value == 5)
        info.setGrowthLoc(item[0], item[1]);
    else if (value == 6)
        info.setPoisonLoc(item[0], item[1]);
}
int Item::getX()
{
    return item[0];
}

int Item::getY()
{
    return item[1];
}

int Item::getValue()
{
    return item[2];
}