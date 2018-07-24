/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-01
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include <ncurses.h>
#pragma once
class Pane
{
    public:
        Pane(int x, int y, int width, int height);
        virtual ~Pane();

        virtual void Draw();
    
    protected:
        int m_width, m_height;
        int m_x, m_y;
        WINDOW* m_pWindow;
        

};