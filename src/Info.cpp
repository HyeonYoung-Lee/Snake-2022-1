#include "Info.h"

vector<vector<int>> Info::snakeLoc;
vector<vector<int>> Info::allWallLoc;
vector<vector<int>> Info::wallLoc;
vector<vector<int>> Info::planeLoc;
vector<int> Info::growthLoc = {0, 0};
vector<int> Info::poisonLoc = {0, 0};
vector<vector<int>> Info::gateLoc;
bool Info::MakeGate = false;
bool Info::gateExistence = false;

Info::Info(){};

void Info::setSnakeLoc(Snake snake)
{
    snakeLoc = snake.getSnakeInfo();
}

void Info::setAllWallLoc(vector<int> v)
{
    allWallLoc.push_back(v);
}
void Info::setWallLoc(vector<int> v)
{
    wallLoc.push_back(v);
}
void Info::setPlaneLoc(vector<int> v)
{
    planeLoc.push_back(v);
}
void Info::setGrowthLoc(int x, int y)
{
    growthLoc.clear();
    growthLoc.push_back(x);
    growthLoc.push_back(y);
}
void Info::setPoisonLoc(int x, int y)
{
    poisonLoc.clear();
    poisonLoc.push_back(x);
    poisonLoc.push_back(y);
}
void Info::setGateLoc(vector<int> v)
{
    gateLoc.push_back(v);
}
