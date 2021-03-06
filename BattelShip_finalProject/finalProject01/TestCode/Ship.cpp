#include <iostream>
#include "Ship.h"
using namespace std;

Ship::Ship(int len)
{
    m_length = len;
    // destroy = len;
    m_pos.resize(len);
    if(len == 5)
        m_Type = AIRCRAFT;
    else if(len == 4)
        m_Type = BATTLESHIP;
    else if(len == 3)
        m_Type = CRUISER;
    else if(len == 2)
        m_Type = DESTROYER;
}
Ship::~Ship()
{

}

void Ship::SetPosition(int index, const Position& pos)
{
    //m_pos는 배의 위치를 넣는 것
    m_pos[index] = pos;
    // m_pos.push_back(pos);
}