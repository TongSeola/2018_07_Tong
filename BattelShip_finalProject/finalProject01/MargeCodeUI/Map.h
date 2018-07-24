/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-01
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include "Define_comm.h"
#include"Pane.h"

class Map : public Pane
{
    public:
        Map(int which, int x, int y, int width, int height);
        ~Map();

        ShipType GetData(const Position& pos) const;
        void SetData(const Position& pos, ShipType type);

        void Draw(int which);

    protected:
        ShipType m_Data[MAP_SIZE][MAP_SIZE];
};