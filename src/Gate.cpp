#include "Gate.h"
#include "Info.h"
#include <random>
#include <algorithm>

using namespace std;

Gate::Gate()
{
    initGate();
}

int Gate::resetGate(int num)
{
    Info info;
    info.gateLoc.clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disIdx(0, info.wallLoc.size() - 1);

    int randomIdx = disIdx(gen);

    if (num == 1)
    {
        firstGate = info.wallLoc.at(randomIdx);
        firstGate.push_back(7);
        info.setGateLoc(firstGate);
    }
    if (num == 2)
    {
        while (true)
        {
            if (randomIdx != firstGateIdx)
                break;
            randomIdx = disIdx(gen);
        }
        secondGate = info.wallLoc.at(randomIdx);
        secondGate.push_back(7);
        info.setGateLoc(secondGate);
    }
    return randomIdx;
}
bool Gate::getGateExistence()
{
    return gateIsExist;
}
void Gate::setGateExistecne(bool value)
{
    this->gateIsExist = value;
}

bool Gate::getMakeGate()
{
    return makeGate;
}
void Gate::setMakeGate()
{
    this->makeGate = true;
}

void Gate::initGate()
{
    Info info;
    info.gateLoc.clear();

    makeGate = false;
    gateIsExist = false;
    // firstGateIdx = 100000;
    // secondGateIdx = 100000;
    vector<int> temp{0, 0};
    firstGate = temp;
    secondGate = temp;
}

std::vector<int> Gate::getFirst()
{
    return firstGate;
}

std::vector<int> Gate::getSecond()
{
    return secondGate;
}
