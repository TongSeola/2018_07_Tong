#include "AirCraft.h"

//자식에서 부모생성자를 호출하는 방법
//자식이 다른형태의 부모 생성자를 호출하고 싶을 때
//부모으 기초 생성자가 없을때만 컴파일 에러가 난다 
// 있다면 기초 생성자가 돌아 온다
AirCraft::AirCraft() : Ship(5)
{
    // 부모클래스의 것은 : 이걸로 할당이 불가하다
    m_Type = AIRCRAFT;
    // m_length = 5;
}

AirCraft::~AirCraft()
{

}

HitResult AirCraft::HitCheck(const Position& pos)
{
    HitResult result = Ship::HitCheck(pos);
    if(result == DESTROY)
    {
        return AirCraft_DESTROY;
    }
    else result;
}
