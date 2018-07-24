#include <iostream>
#include "Map.h"
using namespace std;

Map::Map(int which)
{
    for(int i =0; i < MAP_SIZE; i++)
    {
        for(int j=0; j < MAP_SIZE; ++j)
        {
            m_Data[i][j] = DATA_NONE;
        }
    }
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

ShipType Map::GetData(int x, int y) const
{
    if( x < 0 || x >=MAP_SIZE ||
        y < 0 || y >=MAP_SIZE)
        return DATA_ERROR;

    return m_Data[y][x];
}

void Map::SetData(const Position& pos, ShipType type)
{
    if( pos.x < 0 || pos.x >=MAP_SIZE ||
        pos.y < 0 || pos.y >=MAP_SIZE)
        return ;

    m_Data[pos.y][pos.x] = type;
}
