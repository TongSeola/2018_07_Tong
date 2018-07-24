/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-01
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/

#include <vector>
#include <iostream>
#include <ncurses.h>
#pragma once

enum ShipType
{ // 4바이트로 int와 같은.... 맨 앞은 초기화 할 수 있는 값을 넣는다.
    DATA_ERROR = -1,
    DATA_NONE,
    AIRCRAFT,
    BATTLESHIP,
    CRUISER,
    DESTROYER1,
    DESTROYER2,
    CHECK
};

#define MAP_SIZE 8 
#define SET_SHIPS 5

struct Position
{
    Position() : x(0), y(0) {}
    int x;
    int y;

// // 특정의 안에 넣지 않고 외부함수이다(원래는) - source traget
// // friend를 적음으로써 외부함수로 인식하게 만든다
    friend std::ostream& operator << (std::ostream& os, Position pos)
    {
        os << "x = " <<  pos.x << " y = " << pos.y;
        return os;
    }
};

enum HitResult
{
    MISS,
    HIT,
    AIRCRAFT_DESTROY,
    BATTLESHIP_DESTROY,
    CRUISER_DESTROY,
    DESTROYER1_DESTROY,
    DESTROYER2_DESTROY
};
