#pragma once
#include <vector>
#include "Snake.h"
using namespace std;

class Info
{
public:
    static vector<vector<int>> snakeLoc;   // snake body ��ġ ((x, y), (x, y)...)
    static vector<vector<int>> allWallLoc; // ��� �� ��ġ (immune wall ����)
    static vector<vector<int>> wallLoc;    // �� ��ġ (immune wall ����)
    static vector<vector<int>> planeLoc;
    static vector<int> growthLoc;       // growth ��ġ (x, y)
    static vector<int> poisonLoc;       // poison ��ġ (x, y)
    static vector<vector<int>> gateLoc; // gate ��ġ (1��:(x, y), 2��(x, y))
    static bool MakeGate;
    static bool gateExistence;

    Info();
    static void setSnakeLoc(Snake snake);
    void setAllWallLoc(vector<int> v);
    void setWallLoc(vector<int> v);
    void setPlaneLoc(vector<int> v);
    void setGrowthLoc(int x, int y);
    void setPoisonLoc(int x, int y);
    void setGateLoc(vector<int> v);
};
