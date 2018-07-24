/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-09
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include "Define_comm.h"
#include "Pane.h"

class Map : public Pane
{
    public:
        Map(int which, int x, int y, int width, int height);
        ~Map();

        ShipType GetData(const Position& pos) const;
        ShipType GetData(const int x, const int y) const;
        void SetData(const Position& pos, ShipType type);
        void SetData(const int x, const int y, ShipType type);

        void Draw(int which);

    protected:
        ShipType m_Data[MAP_SIZE][MAP_SIZE];
        
};