#include <vector>
using namespace std;
class Info
{
    vector<vector<int>> snakeLoc;   // snake body ��ġ ((x, y), (x, y)...)
    vector<vector<int>> allWallLoc; // ��� �� ��ġ (immune wall ����)
    vector<vector<int>> wallLoc;    // �� ��ġ (immune wall ����)
    vector<int> growthLoc;          // growth ��ġ (x, y)
    vector<int> poisonLoc;          // poison ��ġ (x, y)
    vector<vector<int>> gateLoc;    // gate ��ġ (1��:(x, y), 2��(x, y))

    Info();
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