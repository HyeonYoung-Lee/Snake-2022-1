#pragma once
class Snake
{
public:
    Snake();
    ~Snake();
    int direction; //Snake의 방향  // 1 북 2 동 3 남 4 서
    int y, x; //snake의 머리 위치
    bool isDead; //Snake 생존여부
    void setDir(int dir);   //Snake 방향 설정
    void willMove();  //Snake 움직임
    void upDate();

};
