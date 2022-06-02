#include "Info.h"

vector<vector<int>> Info::snakeLoc;
vector<vector<int>> Info::allWallLoc;
vector<vector<int>> Info::wallLoc;
vector<int> Info::growthLoc = {0, 0};
vector<int> Info::poisonLoc = {0, 0};
vector<vector<int>> Info::gateLoc;
Info::Info(){
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
};

void Info::setSnakeLoc(Snake snake) {
	snakeLoc = snake.getSnakeInfo();
}

void Info::setAllWallLoc(vector<int> v)
{
}
void Info::setWallLoc(vector<int> v)
{
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
void Info::setGateLoc()
{
}
