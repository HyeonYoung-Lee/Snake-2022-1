#include <vector>
#include "Snake.h"
using namespace std;
/*############################
���� ���� �������� ����ϴ� Ŭ����
1. �� ������Ʈ�� �������� -> allWallLoc, wallLoc
    allWallLock: ������ũ�� �Ӹ��� �����̴� �κ� (�Ӹ���ġ�� ���ϴ� �κ�) ���� ��� -> die
                �� ���ο� ���� �ִ� ��� item ������ ��� (�� ��ġ�� ��ġ�ϸ� �ٽ� ���� ����)
    wallLoc: gate ������ �� ���� �߿��� ���

2. ������ũ �����ӽ� �������� -> snakeLoc
    item ������ ��� (������ũ �ٵ� ��ġ�� ��ġ�ϸ� �ٽ� ���� ����)

3. item �����ɶ����� �������� -> growthLoc, poisonLoc
    ������ũ �Ӹ��� �����̴� �κ� (�Ӹ���ġ�� ���ϴ� �κ�) ���� ��� -> score +/-

4. gate ���涧���� �������� -> gateLoc
    ������ũ �Ӹ��� �����̴� �κп��� ��� -> �� gate �� ���� gate ������ ������ũ �̵�
############################*/
class Info
{
public:
    static vector<vector<int>> snakeLoc;   // snake body ��ġ ((x, y), (x, y)...)
    static vector<vector<int>> allWallLoc; // ��� �� ��ġ (immune wall ����)
    static vector<vector<int>> wallLoc;    // �� ��ġ (immune wall ����)
    static vector<vector<int>> planeLoc;
    // static vector<vector<int>> leftSideWall;
    // static vector<vector<int>> rightSideWall;
    // static vector<vector<int>> upSideWall;
    // static vector<vector<int>> downSideWall;
    static vector<int> growthLoc;       // growth ��ġ (x, y)
    static vector<int> poisonLoc;       // poison ��ġ (x, y)
    static vector<vector<int>> gateLoc; // gate ��ġ (1��:(x, y), 2��(x, y))

    Info();
    static void setSnakeLoc(Snake snake);
    void setAllWallLoc(vector<int> v);
    void setWallLoc(vector<int> v);
    void setPlaneLoc(vector<int> v);
    // void setLeftWallLoc(vector<int> v);
    // void setRightWallLoc(vector<int> v);
    // void setUpWallLoc(vector<int> v);
    // void setDownWallLoc(vector<int> v);
    void setGrowthLoc(int x, int y);
    void setPoisonLoc(int x, int y);
    void setGateLoc(vector<int> v);
};
