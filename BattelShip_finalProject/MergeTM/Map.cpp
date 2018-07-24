#include <iostream>
#include "Map.h"
using namespace std;

Map::Map() :Pane(4, 4, MAP_SIZE + 3, MAP_AIXE + 2)
{
    for(int i =0; i < MAP_SIZE; i++)
    {
        for(int j=0; j < MAP_SIZE; ++j)
        {
            m_Data[i][j] = '0';
        }
    }

    for(int i=0; i < MAP_SIZE; ++i)
    {
        mvprintw(i + 1 + m_y, m_x -1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x+2+i, "%d", 1+i);
    }

    mvprintw(m_pWindwo, 0, 3, "< MAP >");

}

Map::~Map()
{
}

ShipType Map::GetData(const Position& pos) const
{
    if( pos.x < 0 || pos.x >=MAP_SIZE ||
        pos.y < 0 || pos.y >=MAP_SIZE)
        return DATA_ERROR;

    return m_Data[pos.y][pos.x];
}

void Map::SetData(const Position& pos, ShipType type)
{
    if( pos.x < 0 || pos.x >=MAP_SIZE ||
        pos.y < 0 || pos.y >=MAP_SIZE)
        return ;

    m_Data[pos,y][pos.x] = type
}

void Map::Draw()
{
    wattron(m_mWindow, COLOR_PAIR(1));
    for(int i=0; i<MAP_SIZE; ++i)
    {
        for(int j=0; j<MAP_SIZE;, ++j)
        {
            mvwprintw(m_pWindow, i+1, j+2, "%c", m_Data[i][j]);
        }
    }
    wattroff(m_pWindow, COLOR_PAIR(1));

    wrefresh(m_pWindow);
}
