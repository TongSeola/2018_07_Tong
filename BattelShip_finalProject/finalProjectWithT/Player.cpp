#include <iostream>
#include "Player.h"
#include "Map.h" // 전방으로 h에서 만들면 여기다가 include를 불러 온다
#include "Ship.h"
using namespace std;

Player::Player()
{
    // m_Map 0으로 초기화 시키기
    // for(int i=0; i<MAP_SIZE; ++i)
    // {
    //     for(int j=0; j<MAP_SIZE; ++j)
    //         m_Map->m_Data[i][j] = DATA_NONE;
    // }
}

Player::~Player()
{
    delete m_Map;
    for(auto pShip : m_Ships)
    {
        if(pShip)
            delete pShip; // 포인터로 가져오기 때문에 이걸 지워도 된다
    }
    m_Ships.clear();
}

void Player::SetupShips(const SHIPS& ships)
{
    m_Ships = ships;

    for(auto pShip : m_Ships)
    {
        Position pos;
        pos.x = rand() % MAP_SIZE;
        pos.y = rand() % MAP_SIZE;

        while(true)
        {
            ShipType dataType = m_Map->GetData(pos);
            // 빈 곳이 아니라면 다시 랜덤으로 가져오기
            if(dataType != DATA_NONE)
                continue;

            Position dir;

            if( rand() % 2 )
            { //  xy중에 고르기
                if(rand()%2) dir.x = 1;
                else dir.x = -1;
            }
            else 
            {
                if(rand()%2) dir.y = 1;
                else dir.y = -1;
            }
            // pos = pos + dir;

            bool bsucess = true;
            for(int i=0; i < pShip->GetLength(); ++i)
            {
                pos = pos + dir;
                ShipType dataType = m_Map->GetDate(pos);
                if(dataType != DATA_NONE)
                {
                    bsucess = false;
                    break;
                }

                pShip->SetPosition(i, pos);
                    
            }

            if(bsucess)
            {
                //배치완료
                for(int i=0; i < pShip->GetLength(); ++i)
                {
                    Position* pos = pShip->GetPosition(i);
                    m_Map -> SetData(*pos, pShip->GetType());
                }
                break;
            }
            else
            { //재배치
                continue;
            }
        }
    }
}

HitResult Player::HitCheck(const Position& pos)
{
    // for(Position m_pos: m_Pos)
    for(int i=0; i < m_Pos.size(); ++i)
    {
        if(m_Pos[i] == pos)
        {
            -- m_hp;
            m_Pos[i].x = -1;
            m_Pos[i].y = -1; // unused 처리 (한번 친곳은 miss처리 할 수 있게)

            if(m_hp <= 0)
            {
                return AirCraft_DESTROY;
            }
            else    return HIT;
        }
    }
    return MISS;
}

Position Player::GetAttackPos()
{
    Position pos;
    do{
        pos.x = rand() % MAP_SIZE;
        pos.y = rand() % MAP_SIZE;
    } while(m_Map->GetData(pos) != DATA_NONE);
    // 내가 공격한 곳은 공격하지 않는다ㅏ.
    return pos;
}