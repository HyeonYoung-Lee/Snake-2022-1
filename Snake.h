#pragma once
class Snake
{
protected:
    // score board 변수
    int currentLength;
    int maxLength;
    int growthItems;
    int poisonItems;
    int gateUses;

    int score;

public:
    Snake();
    ~Snake();
    int direction; // Snake의 방향  // 1 북 2 동 3 남 4 서
    int y, x;      // snake의 머리 위치

    bool isDead;          // Snake 생존여부
    void setDir(int dir); // Snake 방향 설정
    void willMove();      // Snake 움직임
    void upDate();
    void setFirst();
    void addScore();
    int getScore();

    // score board accessor
    void setCurrentLength(int cl)
    {
        currentLength = cl;
    }
    int getCurrentLength()
    {
        return currentLength;
    }
    void setMaxLength(int ml)
    {
        maxLength = ml;
    }
    int getMaxLength()
    {
        return maxLength;
    }
    void setGrowthItems(int gi)
    {
        growthItems = gi;
    }
    int getGrowthItems()
    {
        return growthItems;
    }
    void setPoisonItems(int pi)
    {
        poisonItems = pi;
    }
    int getPoisonItems()
    {
        return poisonItems;
    }
    void setGateUses(int gu)
    {
        gateUses = gu;
    }
    int getGateUses()
    {
        return gateUses;
    }
};
