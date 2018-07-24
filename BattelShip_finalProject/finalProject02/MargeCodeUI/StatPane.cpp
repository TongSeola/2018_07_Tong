#include "StatPane.h"

StatPane::StatPane(int x, int y, int width, int height)
    :Pane(x, y, width, height)
{
    mvwprintw(m_pWindow, 0, 3, "< STATUS >");
}

StatPane::~StatPane()
{

}

void StatPane::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 1, 2, "AIRCRAFT : AAAAA");
    mvwprintw(m_pWindow, 2, 2, "BATTLESHIP : BBBB");
    mvwprintw(m_pWindow, 3, 2, "CRUISER: CCC");
    mvwprintw(m_pWindow, 4, 2, "DESTROYER1 : DD ");  
    mvwprintw(m_pWindow, 5, 2, "DESTROYER2 : DD ");  
    mvwprintw(m_pWindow, 6, 2, "TURN : ");  
    wattroff(m_pWindow, COLOR_PAIR(2));

    wrefresh(m_pWindow);
}
