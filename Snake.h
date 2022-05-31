#pragma once
#include <vector>

class Snake
{
private:
    // score board 변수
    int currentLength;
    int maxLength;
    int growthItems;
    int poisonItems;
    int gateUses;
    std::vector<std::vector<int>> snakeBody;
    int direction; // snake의 머리 진행 방향
    //    1      //    1 북
    // 4     2   // 4 서  2 동
    //    3      //    3 남
    bool isAlive;

public:
    Snake();
    int score;
    // getter and setter
    int getDirection() { return direction; }
    void setDirection(int direction) { this->direction = direction; }
    bool getIsAlive() { return isAlive; }
    void setIsAlive(bool isAlive) { this->isAlive = isAlive; }
    std::vector<std::vector<int>> getSnakeBody() { return this->snakeBody; }

    void addSnakeBody(int row, int col, int num);
    void clearSnake();
    void understandKey(int key);

    // score
    void addScore();
    int getScore();

    // score board accessor
    void setCurrentLength(int cl);
    int getCurrentLength();
    void setMaxLength(int ml);
    int getMaxLength();
    void setGrowthItems(int gi);
    int getGrowthItems();
    void setPoisonItems(int pi);
    int getPoisonItems();
    void setGateUses(int gu);
    int getGateUses();
};
