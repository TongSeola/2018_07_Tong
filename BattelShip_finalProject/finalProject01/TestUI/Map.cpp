#include <iostream>
#include "Map.h"
using namespace std;

Map::Map(int which, int x, int y, int width, int height) 
    :Pane(x, y, width, height)
{
    for(int i =0; i < MAP_SIZE; i++)
    {
        for(int j=0; j < MAP_SIZE; ++j)
        {
            m_Data[i][j] = DATA_NONE;
        }
    }

    for(int i=0; i < MAP_SIZE; ++i)
    {
        mvprintw(i + 1 + m_y, m_x -1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x+2+i, "%d", 1+i);
    }

    if (which == 1)
        mvwprintw(m_pWindow, 0, 1, "< DEFENDER >");
    else if (which == 2)
        mvwprintw(m_pWindow, 0, 1, "< ATTACKER >");

}

Map::~Map()
{
}

void Map::Draw(int which)
{
    if(which == 1)
    {
        wattron(m_pWindow, COLOR_PAIR(1));
        for(int i=0; i<MAP_SIZE; ++i)
        {
            for(int j=0; j<MAP_SIZE; ++j)
            {
                char data;
                if(m_Data[i][j]==DATA_NONE)
                    data = '0';
                else if(m_Data[i][j]==AIRCRAFT)
                    data = 'A';
                else if(m_Data[i][j]==BATTLESHIP)
                    data ='B';
                else if(m_Data[i][j]==CRUISER)
                    data ='D';
                mvwprintw(m_pWindow, i+1, j+2, "%c", data);
            }
        }
        wattroff(m_pWindow, COLOR_PAIR(1));
    }
    else if(which == 2)
    {
        wattron(m_pWindow, COLOR_PAIR(4));
        for(int i=0; i<MAP_SIZE; ++i)
        {
            for(int j=0; j<MAP_SIZE; ++j)
            {
                char data;
                if(m_Data[i][j]==DATA_NONE)
                    data = '0';
                else if(m_Data[i][j]==AIRCRAFT)
                    data = 'A';
                else if(m_Data[i][j]==BATTLESHIP)
                    data ='B';
                else if(m_Data[i][j]==CRUISER)
                    data ='D';
                mvwprintw(m_pWindow, i+1, j+2, "%c", data);
            }
        }
        wattroff(m_pWindow, COLOR_PAIR(4));
    }

    wrefresh(m_pWindow);
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

    m_Data[pos.y][pos.x] = type;
}
