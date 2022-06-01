#include "Item.h"
#include <random>
#include <time.h>

Item::Item(int value)
{
    resetItem();
    item[2] = value; // growth == 5, poison==6
}

void Item::resetItem()
{
    int x, y;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disX(1, 19);
    std::uniform_int_distribution<int> dixY(1, 39);
    item[0] = disX(gen);
    item[1] = dixY(gen);
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