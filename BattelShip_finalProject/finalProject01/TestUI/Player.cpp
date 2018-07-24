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
    // m_pMap1 = new Map();
}

Player::~Player()
{
    // delete m_pMap;
    for(Ship* pShip : m_pShips)
    {
        if(pShip)
            delete pShip; // 포인터로 가져오기 때문에 이걸 지워도 된다
    }
    // m_Ships.clear();
}

void Player::SetupShips( Ship* ships, Map* m_pMap)
{
    for(int i=0; i < 5; i++)
    {
        Ship* temp = (ships + i);
        m_pShips[i] = temp;// = ships;
    }

    for(Ship* pShip : m_pShips)
    {
        //맨처음 시작 위치 찾기
        srand (time(NULL));
        Position pos;
        pos.x = rand() % MAP_SIZE;
        pos.y = rand() % MAP_SIZE;

        while(true)
        {
            ShipType dataTypeStart = m_pMap->GetData(pos);
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
                    m_pMap->SetData(pShip->GetPos()[i], pShip->GetType());
                }
                // m_pMap1->Draw();
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
    char* Pos;
    keypad(stdscr, TRUE);
    curs_set(0);
    mvscanw(30, 30, "%s", Pos);
    getch();
    mvprintw(10,10,"%s", Pos);
    // 65-A 97-a
    int posX = Pos[0]-65;
    int posY = Pos[1];

    Position setPos;
    setPos.x = posX;
    setPos.y = posY;
    delete Pos;

    return setPos;
}