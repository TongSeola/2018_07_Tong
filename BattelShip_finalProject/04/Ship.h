/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-09
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include "Define_comm.h"
#include <vector>
#pragma once
#define VECPOS std::vector<Position>

class Ship
{
    public:
        Ship(int len, int which);
        ~Ship(); // 상속받으면 소멸자에 virtual붙이기!!!11(다형성)

        ShipType GetType() const {return m_Type;}
        int GetLength() const {return m_length;}
        void SetPosition(int index, const Position& pos);

        VECPOS m_pos;

    protected:
        ShipType m_Type;
        int m_length;    
};