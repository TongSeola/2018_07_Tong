#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Map.h" // 전방으로 h에서 만들면 여기다가 include를 불러 온다
#include "Ship.h"
using namespace std;

Player::Player()
{
    countTurn = 0;
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
        //맨처음 시작 위치 찾기
        srand (time(NULL));
        Position pos;
        pos.x = rand() % MAP_SIZE;
        pos.y = rand() % MAP_SIZE;

        while(true)
        {
            ShipType dataTypeStart = m_Map->GetData(pos);
            // 빈 곳이 아니라면 다시 랜덤으로 가져오기
            if(dataTypeStart != DATA_NONE)
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

            bool bsucess = true;
            for(int i=0; i < pShip->GetLength(); ++i)
            {
                pos = pos + dir;
                //배치가능한지 확인
                ShipType dataType = m_Map->GetDate(pos);
                if(dataType != DATA_NONE)
                {
                    bsucess = false;
                    break;
                }

                // 잘못 놨다고 하더라도 i가 초기화 되기 때문에 괜춘
                pShip->SetPosition(i, pos);
                    
            }

            if(bsucess)
            {
                //bsucess = true : 배치완료
                break;
            }
            else
            { 
                ////bsucess = false : 재배치
                continue;
            }
        }
    }
}

void Player::IncreseTurn()
{
    countTurn ++;
}

Position Player::GetAttackPos()
{
    cout << "Enter the Position (A~H and 1~8) : ";
    string Position;
    cin >> Position;
    // 65-A 97-a
    int posX = (int)Position.at(0)-65;
    int posY = (int)Position.at(1);

    Position setPos;
    setPos.x = posX;
    setPos.y = posY;

    return setPos;
}