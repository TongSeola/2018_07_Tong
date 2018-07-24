/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-09
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include "Define_comm.h"
#include "Pane.h"

class PercentMap : public Pane
{
    public:
        PercentMap(int x, int y, int width, int height);
        ~PercentMap();

        int GetData(const Position& pos) const;
        int GetData(int x, int y) const;
        void SetData(const Position& pos, int plus);
        void SetData(int x, int y, int plus);

        void Draw();

    protected:
        int m_Data[MAP_SIZE][MAP_SIZE];
        
};