#include <iostream>
#include <unistd.h>
#include "GameManager.h"
#include "Player.h"
#include "Map.h"
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
            Position attackPos = m_Attacker->GetAttackPos(m_pMap2);
            HitResult output = HitCheck(m_pMap1, attackPos);
            if(output == 0 )
            {
                m_pMap2->SetData(attackPos, CHECK);
            }
            else
            {
                m_pMap2->SetData(attackPos, m_pMap1->GetData(attackPos));
            }
            
            if(output == 0)
                mvprintw(18,40,"Miss   ");
            else if(output == 1)
                mvprintw(18,40,"Hit    ");
            else if(output == 2)
            {
                mvprintw(18,40,"Destroy ");
                mvprintw(4,32,"AirCraft Destroy   ");
            }
            else if(output == 3)
            {
                mvprintw(18,40,"Destroy ");
                mvprintw(5,32,"BattleShip Destroy ");
            }
            else if(output == 4)
            {
                mvprintw(18,40,"Destroy ");
                mvprintw(6,32,"Cruiser Destroy     ");
            }
            else if(output == 5)
            {
                mvprintw(18,40,"Destroy ");
                mvprintw(7,32,"Destroyer1 Destroy ");
            }
            else if(output == 6)
            {
                mvprintw(18,40,"Destroy ");
                mvprintw(8,32,"Destroyer2 Destroy ");
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

    m_pMap1 = new Map(1, 4, 2, MAP_SIZE + 5, MAP_SIZE +2);
    m_pMap2 = new Map(4, 4, 15, MAP_SIZE + 5, MAP_SIZE +2);
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
    }
    else
    {
        // sleep(1);
        Play();
    } 
    // endwin();
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