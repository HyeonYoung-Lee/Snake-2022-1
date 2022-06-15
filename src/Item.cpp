#include "Item.h"
#include "Info.h"
#include <random>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

Item::Item(int value)
{
    time = 0;
    resetItem(value);
}

void Item::resetItem(int value)
{
    Info info;
    vector<int> xy;
    while (true)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> disX(1, 19);
        std::uniform_int_distribution<int> disY(1, 39);
        xy.push_back(disX(gen));
        xy.push_back(disY(gen));

        bool isNotWall = false;
        bool isNotSnake = false;

        auto it1 = find(info.allWallLoc.begin(), info.allWallLoc.end(), xy);
        if (it1 == info.allWallLoc.end())
            isNotWall = true;

        auto it2 = find(info.snakeLoc.begin(), info.snakeLoc.end(), xy);
        if (it2 == info.snakeLoc.end())
            isNotSnake = true;

        if (isNotWall && isNotSnake)
            break;
        else
            xy.clear();
    }

    item[0] = xy.at(0);
    item[1] = xy.at(1);
    item[2] = value; // growth == 5, poison==6
    time = 0;

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
int Item::getTime()
{
    return time;
}
void Item::upTime()
{
    time++;
}