#include <iostream>
#include "Ship.h"
using namespace std;

Ship::Ship(int len)
{
    // m_Type = DATA_NONE;
    // length = 0;
    m_length = len;
    // m_hp = len; 

    // 벡터에서 확보공간 만드는 함수 reserve 
    // 그래서 할당으로 말고 push_back을 이용해서 넣어야 한다.
    // resize는 확보+할당까지 만들어진다.
    // resize는 할당이 가능하다
    // m_pos.reserve(len);
    m_pos.resize(len);
}
Ship::~Ship()
{

}

// void Ship::AddPsition(const Positon pos)
// {
//     m_pos.push_back(pos);
// }

void Ship::SetPsition(int index, const Positon pos)
{
    m_pos[index] = pos;
}