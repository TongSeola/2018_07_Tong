/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-09
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
    Position(int a, int b)
    {
        x = a;
        y = b;
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
