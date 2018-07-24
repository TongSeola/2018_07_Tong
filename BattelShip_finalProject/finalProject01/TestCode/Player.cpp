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
    for(Ship* pShip : m_pShips)
    {
        if(pShip)
            delete pShip; // 포인터로 가져오기 때문에 이걸 지워도 된다
    }
    // m_Ships.clear();
}

void Player::SetupShips( Ship* ships[], Map* m_pMap)
{
    for(int i=0; i <SET_SHIPS; ++i)
    {
        m_pShips[i] = ships[i];
    }
    // srand((unsigned int)time(NULL)); //랜덤함수 겹치지 않게 돌아가게 만들기
    for(Ship* pShip : m_pShips)
    {
        cout << "배를 가져오자 !" << endl;
        while(true)
        {
            //맨처음 시작 위치 찾기
            Position pos;
            pos.x = rand() % MAP_SIZE; 
            pos.y = rand() % MAP_SIZE;

            ShipType dataTypeStart = m_pMap->GetData(pos);

            // 빈 곳이 아니라면 다시 랜덤으로 가져오기
            if(dataTypeStart != DATA_NONE) continue;

            // 처음 위치는 0번째로 저장한다
            pShip->SetPosition(0, pos);
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
            for(int i=1; i < pShip->GetLength(); ++i)
            {
                pos.x = pos.x + dir.x;
                pos.y = pos.y + dir.y;

                //배치가능한지 확인
                ShipType dataType = m_pMap->GetData(pos);
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
                for(int i=0; i < pShip->GetLength(); ++i)
                {
                    // 위치, 타입
                    m_pMap->SetData(pShip->m_pos[i], pShip->GetType());
                }
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

Position Player::GetAttackPos()
{
    Position setPos;
    char Pos;
    int posX;
    int posY;
    cout << "공격하고 싶은 위치(A~H)(1~8) : ";
    cin >> Pos;
    posX = Pos-65;
    cin >> posY;

    setPos.x = posY-1;
    setPos.y = posX;

    return setPos;
}