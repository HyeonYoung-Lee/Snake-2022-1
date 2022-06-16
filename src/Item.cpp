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
    item[2] = value;
}

void Item::resetItem()
{
    Info info;

    while (true)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> disX(0, info.planeLoc.size() - 1);
        int randomIdx = disX(gen);

        std::vector<int> temp;
        int tempX = info.planeLoc.at(randomIdx).at(0);
        int tempY = info.planeLoc.at(randomIdx).at(1);
        temp.push_back(tempX);
        temp.push_back(tempY);

        bool isNotSnake = false;
        auto it2 = find(info.snakeLoc.begin(), info.snakeLoc.end(), temp);
        if (it2 == info.snakeLoc.end())
            isNotSnake = true;

        if (isNotSnake)
        {
            item[0] = tempX;
            item[1] = tempY;
            break;
        }
    }
    time = 0;

    if (item[2] == 5)
        info.setGrowthLoc(item[0], item[1]);
    else if (item[2] == 6)
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