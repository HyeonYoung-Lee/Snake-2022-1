#include "Info.h"
using namespace std;

Info::Info(){
    /*############################
    전역 변수 느낌으로 사용하는 클래스
    1. 맵 업데이트시 정보갱신 -> allWallLoc, wallLoc
        allWallLock: 스네이크의 머리가 움직이는 부분 (머리위치가 변하는 부분) 에서 사용 -> die
                    맵 내부에 벽이 있는 경우 item 리젠시 사용 (맵 위치와 일치하면 다시 난수 생성)
        wallLoc: gate 생성시 이 값들 중에서 사용

    2. 스네이크 움직임시 정보갱신 -> snakeLoc
        item 리젠시 사용 (스네이크 바디 위치와 일치하면 다시 난수 생성)

    3. item 리젠될때마다 정보갱신 -> growthLoc, poisonLoc
        스네이크 머리가 움직이는 부분 (머리위치가 변하는 부분) 에서 사용 -> score +/-

    4. gate 생길때마다 정보갱신 -> gateLoc
        스네이크 머리가 움직이는 부분에서 사용 -> 두 gate 중 남은 gate 값으로 스네이크 이동
    ############################*/
};