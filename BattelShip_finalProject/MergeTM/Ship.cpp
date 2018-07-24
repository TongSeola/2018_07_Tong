#include <iostream>
#include "Ship.h"
using namespace std;

Ship::Ship(int len)
{
    m_length = len;
    m_pos.resize(len);
}
Ship::~Ship()
{

}

void Ship::SetPsition(int index, const Positon pos)
{
    //m_pos는 배의 위치를 넣는 것
    m_pos[index] = pos;
}