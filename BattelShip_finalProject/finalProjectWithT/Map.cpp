#include <iostream>
#include "Map.h"
using namespace std;

Map::Map()
{
    // // 초기화 
    // // memset(m_Data, DATA_NONE, sizeof(m_Data)); //메모리는 1차원이기 때문에 가능하다
    // for(int i=0; i < MAP_SIZE ; ++i)
    // {
    //     for(int j=0; j < MAP_SIZE ; ++j)
    //     {
    //         m_Data[i][j] = DATA_NONE;
    //     }
    // }

}

Map::~Map()
{
    // for(int i=0; i < MAP_SIZE ; ++i)
    // {
    //     for(int j=0; j < MAP_SIZE ; ++j)
    //     {
    //         delete m_Data[i][j];
    //     }
    // }
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
