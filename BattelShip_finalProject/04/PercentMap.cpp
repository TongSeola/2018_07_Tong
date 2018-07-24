#include <iostream>
#include "PercentMap.h"
using namespace std;

PercentMap::PercentMap(int x, int y, int width, int height) 
    :Pane(x, y, width, height)
{
    for(int i =0; i < MAP_SIZE; i++)
    {
        for(int j=0; j < MAP_SIZE; ++j)
        {
            m_Data[i][j] = 0;
        }
    }

    for(int i=0; i < MAP_SIZE; ++i)
    {
        mvprintw(i + 1 + m_y, m_x -1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x+2+i, "%d", 1+i);
    }

    mvwprintw(m_pWindow, 0, 1, "< PERCENT >");
}

PercentMap::~PercentMap()
{
}

void PercentMap::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(5));
    for(int i=0; i<MAP_SIZE; ++i)
    {
        for(int j=0; j<MAP_SIZE; ++j)
        {
            int data;
            data = m_Data[i][j];
            mvwprintw(m_pWindow, i+1, j+2, "%d", data);
        }
    }
    wattroff(m_pWindow, COLOR_PAIR(5));
    wrefresh(m_pWindow);
}

int PercentMap::GetData(const Position& pos) const
{
    if( pos.x < 0 || pos.x >=MAP_SIZE ||
        pos.y < 0 || pos.y >=MAP_SIZE)
        return -2;

    return m_Data[pos.y][pos.x];
}

int PercentMap::GetData(int x, int y) const
{
    if( x < 0 || x >=MAP_SIZE ||
        y < 0 || y >=MAP_SIZE)
        return -2;

    return m_Data[y][x];
}

void PercentMap::SetData(const Position& pos, int plus)
{
    if( pos.x < 0 || pos.x >=MAP_SIZE ||
        pos.y < 0 || pos.y >=MAP_SIZE)
        return ;

    m_Data[pos.y][pos.x] = plus;
}

void PercentMap::SetData(int x, int y, int plus)
{
    if( x < 0 || x >=MAP_SIZE ||
        y < 0 || y >=MAP_SIZE)
        return ;

    m_Data[y][x] = plus;
}

