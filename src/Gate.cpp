#include "Gate.h"
#include "Info.h"
#include <random>
#include <algorithm>

using namespace std;

Gate::Gate()
{
    gate[2] = 7;
}

void Gate::resetGate()
{
    Info info;
    info.MakeGate = true;
    info.gateExistence = true;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disIdx(0, info.wallLoc.size() - 1);

    int randomIdx = disIdx(gen);
    std::vector<int> temp = info.wallLoc.at(randomIdx);

    if (info.gateLoc.size() > 0) // if second gate - avoiding overlap
    {
        while (true)
        {
            if (temp != info.gateLoc.at(0))
                break;
            randomIdx = disIdx(gen);
        }
    }

    gate[0] = temp.at(0);
    gate[1] = temp.at(1);
    info.setGateLoc(temp);
}

int Gate::getX()
{
    return gate[0];
}

int Gate::getY()
{
    return gate[1];
}

int Gate::getValue()
{
    return gate[2];
}
