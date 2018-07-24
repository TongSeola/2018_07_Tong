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