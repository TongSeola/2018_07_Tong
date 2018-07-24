#include <iostream>
#include <unistd.h>
#include "GameManager.h"
#include "Player.h"
#include "Map.h"
#include "PercentMap.h"
#include "Ship.h"
#include "StatPane.h"
#include "InputPane.h"

using namespace std;

GameManager::GameManager()
{
    m_Attacker = NULL;
    m_Defender = NULL;
    m_pMap1 = NULL;
    m_pMap2 = NULL;    
    m_Map_percent = NULL;
    m_pStatPane = NULL;
    m_pInputPane = NULL;

    averageTurn = 0;
    countTurn = 0;

}

GameManager::~GameManager()
{
    if(m_Attacker)
    {
        delete m_Attacker;
        m_Attacker = NULL;
    }

    if(m_Defender)
    {
        delete m_Defender;
        m_Defender = NULL;
    }
    
    if(m_pMap1)
    {
        delete m_pMap1;
        m_pMap1 = NULL;
    }

    if(m_pMap2)
    {
        delete m_pMap2;
        m_pMap2 = NULL;
    }

    if(m_Map_percent)
    {
        delete m_Map_percent;
        m_Map_percent = NULL;
    }

    if(m_pStatPane)
    {
        delete m_pStatPane;
        m_pStatPane = NULL;
    }

    if(m_pInputPane)
    {
        delete m_pInputPane;
        m_pInputPane = NULL;
    }
}

void GameManager::Play()
{
    // 배를 배치한다
    Init();
    // 그린다
    m_pStatPane->Draw();
    m_pInputPane->Draw();

    while(true)
    {   
        Render();
        if(CheckGameOver())
        {
            Position attackPos = m_Attacker->GetAttackPos(m_pMap2, m_Map_percent);
            HitResult output = HitCheck(m_pMap1, attackPos);
            if(output == MISS )
            {
                m_pMap2->SetData(attackPos, CHECK);
            }
            else
            {
                m_pMap2->SetData(attackPos, m_pMap1->GetData(attackPos));
            }
            
            if(output == MISS)
            {
                Percentage(m_pMap2, attackPos, m_Map_percent, 0);
                mvprintw(18,40,"Miss   ");
            }
            else if(output == HIT)
            {
                Percentage(m_pMap2, attackPos, m_Map_percent, 1);
                mvprintw(18,40,"Hit    ");
            }
            else
            {   
                ResetPercnet(m_pMap2, m_Map_percent);
                if(output == AIRCRAFT_DESTROY)
                {
                    mvprintw(18,40,"Destroy ");
                    mvprintw(4,32,"AirCraft Destroy   ");
                }
                else if(output == BATTLESHIP_DESTROY)
                {
                    mvprintw(18,40,"Destroy ");
                    mvprintw(5,32,"BattleShip Destroy ");
                }
                else if(output == CRUISER_DESTROY)
                {
                    mvprintw(18,40,"Destroy ");
                    mvprintw(6,32,"Cruiser Destroy     ");
                }
                else if(output == DESTROYER1_DESTROY)
                {
                    mvprintw(18,40,"Destroy ");
                    mvprintw(7,32,"Destroyer1 Destroy ");
                }
                else if(output == DESTROYER2_DESTROY)
                {
                    mvprintw(18,40,"Destroy ");
                    mvprintw(8,32,"Destroyer2 Destroy ");
                }

            }
            mvprintw(9,40,"%d", m_Defender->GetTurn());
            continue;
        }
        else break;
    }
    // 끝낸다
    Destroy();
}

void GameManager::Init()
{
    initscr();
    resize_term(100, 100);
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);

    m_pMap1 = new Map(1, 4, 2, MAP_SIZE + 5, MAP_SIZE +2);
    m_pMap2 = new Map(4, 4, 13, MAP_SIZE + 5, MAP_SIZE +2);
    m_Map_percent = new PercentMap(4, 24, MAP_SIZE + 4, MAP_SIZE +2);

    m_pStatPane = new StatPane(30, 3, 30 ,8);
    m_pInputPane = new InputPane(30, 15, 30, 5);

    // 배를 배치하기 위해 백터에 각 항목을 넣는다.
    m_Attacker = new Player();
    m_Defender = new Player();

    Ship* air = new Ship(5, 0);
    Ship* battle = new Ship(4, 0);
    Ship* cru = new Ship(3, 0);
    Ship* dest1 = new Ship(2, 0);
    Ship* dest2 = new Ship(2, 1);
    Ship* arrShip[SET_SHIPS] = {air, battle, cru, dest1, dest2 };
    
    m_Defender->SetupShips(arrShip, m_pMap1);
}

void GameManager::Render()
{
    mvprintw(1,12, "<< Battle Ship Game >>");
    m_pMap1->Draw(1);
    m_pMap2->Draw(4);
    m_Map_percent->Draw();
    refresh();
}

void GameManager::Destroy()
{
    countTurn ++;
    averageTurn = averageTurn + m_Defender->GetTurn();
    if(countTurn == 10)
    {
        averageTurn = averageTurn/countTurn;
        mvprintw(11,30, "Average Turn : ");
        mvprintw(11,45, "%d", averageTurn);
        mvprintw(9,40, "OVER");

        char Pos;
        keypad(stdscr, TRUE);
        mvprintw(17, 40, "FINAL_STAT      ");
        curs_set(0);
        mvscanw(17, 40, "%s", Pos);
        endwin();
        // endwin();
    }
    else
    {
        Play();
    } 
}

HitResult GameManager::HitCheck(Map* m_pMap, const Position& pos)
{
    Position attack = pos;
    // 입력한 자리에 위치한 ShipType을 할당한다
    ShipType getAttack = m_pMap->GetData(attack);
    if(getAttack == AIRCRAFT)
    {
        int size = Remove(0, attack);
        if(size == 0) return AIRCRAFT_DESTROY;
        else return HIT;
    } 
    else if(getAttack == BATTLESHIP) 
    {
        int size = Remove(1, attack);
        if(size == 0) return BATTLESHIP_DESTROY;
        else return HIT;
    }
    else if(getAttack == CRUISER)
    {
        int size = Remove(2, attack);
        if(size == 0) return CRUISER_DESTROY;
        else return HIT;
    }
    else if(getAttack == DESTROYER1) 
    {
        int size = Remove(3, attack);
        if(size == 0) return DESTROYER1_DESTROY;
        else return HIT;
    }
    else if(getAttack == DESTROYER2)
    {
        int size = Remove(4, attack);
        if(size == 0) return DESTROYER2_DESTROY;
        else return HIT;
    }
    else return MISS;
}

int GameManager::Remove(int which, Position attack)
{
    // 해당배의 자리가 있는 벡터를 할당받는다
    VECPOS& getShip = m_Defender->GetShips(which)->m_pos;
    for(int i=0; i<getShip.size(); ++i)
    {
        if(getShip[i].x == attack.x && getShip[i].y == attack.y)
        {
            getShip.erase(getShip.begin() + i);
            break;
        }
    }
    // cout << "Vector Size = " << getShip.size() << endl;
    return getShip.size();
}

bool GameManager::CheckGameOver()
{
    if( m_Defender->GetShips(0)->m_pos.size() == 0 &&
        m_Defender->GetShips(1)->m_pos.size() == 0 &&
        m_Defender->GetShips(2)->m_pos.size() == 0 &&
        m_Defender->GetShips(3)->m_pos.size() == 0 &&
        m_Defender->GetShips(4)->m_pos.size() == 0)
       return false;
    else 
    {
        m_Defender->IncreseTurn();
        return true;    
    }

}

void GameManager::Percentage(Map* m_pMap, Position pos, PercentMap* Map, int plus)
{
    // 맞힌경우
    if(plus)
    {
        //배가 존재하는 곳은 -5
        Map->SetData(pos.x, pos.y, -5);

        //배가 놓을때 주면 십자가 모양으로 +2
        if(pos.x-1 > -1)
            Map->SetData(pos.x-1, pos.y, Map->GetData(pos.x-1, pos.y) + 2);
        if(pos.x+1 < MAP_SIZE)
            Map->SetData(pos.x+1, pos.y, Map->GetData(pos.x+1, pos.y) + 2);
        if(pos.y-1 > -1)
            Map->SetData(pos.x, pos.y-1, Map->GetData(pos.x, pos.y-1) + 2);
        if(pos.y+1 < MAP_SIZE)
            Map->SetData(pos.x, pos.y+1, Map->GetData(pos.x, pos.y+1) + 2);

        Position subX(pos.x-1, pos.y);
        Position addX(pos.x+1, pos.y);
        Position subY(pos.x, pos.y-1);
        Position addY(pos.x, pos.y+1);

        //이미 배가 놓은 방향족으로는 +4
        if((m_pMap->GetData(subX) != DATA_NONE && m_pMap->GetData(subX) != CHECK) && (pos.x+1 < MAP_SIZE && pos.x-2 > -1))
        {
            Map->SetData(pos.x+1, pos.y, Map->GetData(pos.x+1, pos.y) + 4);
            Map->SetData(pos.x-2, pos.y, Map->GetData(pos.x-2, pos.y) + 4);
        }
        if((m_pMap->GetData(addX) != DATA_NONE && m_pMap->GetData(addX) != CHECK) && (pos.x+2 < MAP_SIZE && pos.x-1 > -1))
        {
            Map->SetData(pos.x+2, pos.y, Map->GetData(pos.x+2, pos.y) + 4);
            Map->SetData(pos.x-1, pos.y, Map->GetData(pos.x-1, pos.y) + 4);
        }
        if((m_pMap->GetData(subY) != DATA_NONE && m_pMap->GetData(subY) != CHECK) && (pos.y+1 < MAP_SIZE && pos.y-2 > -1))
        {
            Map->SetData(pos.x, pos.y+1, Map->GetData(pos.x, pos.y+1) + 4);
            Map->SetData(pos.x, pos.y-2, Map->GetData(pos.x, pos.y-2) + 4);
        }
        if((m_pMap->GetData(addY) != DATA_NONE && m_pMap->GetData(addY) != CHECK) && (pos.y+2 < MAP_SIZE && pos.y-1 > -1))
        {
            Map->SetData(pos.x, pos.y+2, Map->GetData(pos.x, pos.y+2) + 4);
            Map->SetData(pos.x, pos.y-1, Map->GetData(pos.x, pos.y-1) + 4);
        }

        //값이 올라간 곳이 만약 배가 이미 놓은 곳이나 맞힐 수 없는 구간으로 표시 된 곳이라면 원래 상태로 돌려 놓는다
        for(int i=0; i<MAP_SIZE; ++i)
        {
            for(int j=0; j<MAP_SIZE; ++j)
            {
                Position pos(j,i);
                if(m_pMap->GetData(pos) != DATA_NONE)
                {  
                    if(m_pMap->GetData(pos) == CHECK)
                        //배를 놓을 수 없는 곳이면 -15
                        Map->SetData(j,i,-15);
                    else
                        //배가 놓여서 놓을 수 없는 곳이면 -5
                        Map->SetData(j,i,-5);
                }
            }
        }
    }
    else
    { //miss인 경우
        //배가 놓을 수 없는 곳은 -15
        Map->SetData(pos.x, pos.y, -15);

        //맵의 가운데 부분에서 위아래양옆이 배가 놓일 수 없다고 판명되면 가운데도 배가 놓일 수 없다
        //하지만 MISS가 난곳만 계산 배가 놓여서 검사한곳은 제외하고 검사한다(-15)
        for(int i=1; i<MAP_SIZE-1; ++i)
        {
            for(int j=1; j<MAP_SIZE-1; ++j)
            {
                Position upos(j, i-1);
                Position dpos(j, i+1);
                Position lpos(j-1, i);
                Position rpos(j+1, i);
                if(Map->GetData(upos) < -10 &&
                   Map->GetData(dpos) < -10 &&
                   Map->GetData(lpos) < -10 &&
                   Map->GetData(rpos) < -10 )
                {  
                    Map->SetData(j,i,-15);
                    if(m_pMap->GetData(j, i) == DATA_NONE)
                        m_pMap->SetData(j, i, CHECK);
                }
            }
        }
        //맵의 벽부분 검사
        for(int i=1; i<MAP_SIZE-1; ++i)
        {
            if(Map->GetData(i-1,0) < -10 &&
               Map->GetData(i,1) < -10 &&
               Map->GetData(i+1,0) < -10 )
               {
                    Map->SetData(i,0,-15);
                    if(m_pMap->GetData(i, 0) == DATA_NONE)
                        m_pMap->SetData(i, 0, CHECK);
               }

            if(Map->GetData(i-1,MAP_SIZE-1) < -10 &&
               Map->GetData(i,MAP_SIZE-2) < -10 &&
               Map->GetData(i+1,MAP_SIZE-1) < -10 )
               {
                    Map->SetData(i,MAP_SIZE-1,-15);
                    if(m_pMap->GetData(i,MAP_SIZE-1) == DATA_NONE)
                        m_pMap->SetData(i,MAP_SIZE-1, CHECK);
               }

            if(Map->GetData(0,i-1) < -10 &&
               Map->GetData(1,i) < -10 &&
               Map->GetData(0,i+1) < -10 )
               {
                    Map->SetData(0, i,-15);
                    if(m_pMap->GetData(0, i) == DATA_NONE)
                        m_pMap->SetData(0, i, CHECK);
               }
            if(Map->GetData(MAP_SIZE-1,i-1) < -10 &&
               Map->GetData(MAP_SIZE-2,i) < -10 &&
               Map->GetData(MAP_SIZE-1,i+1) < -10 )
               {
                    Map->SetData(MAP_SIZE-1,i,-15);
                    if(m_pMap->GetData(MAP_SIZE-1,i) == DATA_NONE)
                        m_pMap->SetData(MAP_SIZE-1,i, CHECK);
               }
        }

        //맵의 모서리 부분 검사
        //00
        if(Map->GetData(1,0) < -10 &&
           Map->GetData(0,1) < -10 )
        {
            Map->SetData(0,0,-15);
            if(m_pMap->GetData(0,0) == DATA_NONE)
                m_pMap->SetData(0,0, CHECK);
        }

        //70
        if(Map->GetData(6,0) < -10 &&
           Map->GetData(7,1) < -10 )
        {
            Map->SetData(0,7,-15);
            if(m_pMap->GetData(0,7) == DATA_NONE)
                m_pMap->SetData(0,7, CHECK);
        }

        //07
        if(Map->GetData(0,6) < -10 &&
           Map->GetData(1,7) < -10 )
        {
            Map->SetData(0,7,-15);
            if(m_pMap->GetData(0,7) == DATA_NONE)
                m_pMap->SetData(0,7, CHECK);
        }

        //77
        if(Map->GetData(7,6) < -10 &&
           Map->GetData(6,7) < -10 )
        {
            Map->SetData(7,7,-15);
            if(m_pMap->GetData(7,7) == DATA_NONE)
                m_pMap->SetData(7,7, CHECK);
        }
    }
}

void GameManager::ResetPercnet(Map* m_pMap, PercentMap* Map)
{
    //배가 1개가 몽당 파괴 된경우 배가 놓일 확률이 6이 된경우를 제외하고 전부 0으로 초기화한다
    for(int i=0; i<MAP_SIZE; ++i)
    {
        for(int j=0; j<MAP_SIZE; ++j)
        {
            Position pos(j,i);
            if(m_pMap->GetData(pos) == DATA_NONE && Map->GetData(j,i) != 6)
            {
                Map->SetData(j,i,0);
            }
            else if(m_pMap->GetData(pos) == DATA_NONE && Map->GetData(j,i) == 6)
            {
                Map->SetData(j,i,5);
            }
            else if(m_pMap->GetData(pos) == CHECK)
            {
                Map->SetData(j,i,-15);            
            }
            else Map->SetData(j,i,-5);            
        }
    }
}