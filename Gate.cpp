#include "Gate.h"
#include "Info.h"
#include <random>
#include <algorithm>

using namespace std;

Gate::Gate()
{
    idx = resetGate();
}

int Gate::resetGate()
{
    Info info;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> first(0, info.wallLoc.size());

    int randomIdx = first(gen);
    gate = info.wallLoc.at(randomIdx);
    gate.push_back(7);

    return randomIdx;
}

int Gate::getX()
{
    return gate.at(0);
}

int Gate::getY()
{
    return gate.at(1);
}

int Gate::getValue()
{
    return gate.at(2);
}
