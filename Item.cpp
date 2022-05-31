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
    std::srand(time(NULL));
    x = rand() % 19 + 1;
    y = rand() % 39 + 1;
    item[0] = x;
    item[1] = y;
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