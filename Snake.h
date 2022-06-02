#pragma once
#include <vector>
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <iostream>

class Snake
{
private:
    // score board 변수
    int maxLength = 10;
    int growthItems = 0;
    int poisonItems = 0;
    int gateUses = 0;
    std::vector<std::vector<int>> snakeBody;
    int direction; // snake의 머리 진행 방향
    //    1      //    1 북
    // 4     2   // 4 서  2 동
    //    3      //    3 남
    bool isAlive;
    int pastKey;

public:
    Snake();
    int score;
    // getter and setter
    int getDirection() { return direction; }
    void setDirection(int direction) { this->direction = direction; }
    bool getIsAlive() { return isAlive; }
    void setIsAlive(bool isAlive) { this->isAlive = isAlive; }
    std::vector<std::vector<int>> getSnakeBody() { return this->snakeBody; }
	std::vector<std::vector<int>> getSnakeInfo();

    void addSnakeBody(int row, int col, int num);
	void onlyaddSnakeBody(int row, int col, int num);
	void snakePoisoned();
    void clearSnake();
    int understandKey(int key);
    void setPastKey(int key);
    int getPastKey();

    // score
    void addScore();
    int getScore();

    // score board accessor
    int getCurrentLength() { return snakeBody.size(); }
    void setMaxLength(int ml) { maxLength = ml; }
    int getMaxLength() { return maxLength; }
    void incGrowthItems() { growthItems++; }
    int getGrowthItems() { return growthItems; }
    void incPoisonItems() { poisonItems++; }
    int getPoisonItems() { return poisonItems; }
    void incGateUses() { gateUses++; }
    int getGateUses() { return	gateUses; }
};
