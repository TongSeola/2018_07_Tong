/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-01
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include "Pane.h"

class StatPane : public Pane
{
    public:
        StatPane(int x, int y, int width, int height);
        ~StatPane();

        void Draw();
};
