#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "Map.h"
#include "Ship.h"
// #include "AirCraft.h"
// #include "BattleShip.h"
// #include "Cruiser.h"
// #include "Destroyer.h"
using namespace std;

GameManager::GameManager()
{
    m_Attacker = NULL;
    m_Defender = NULL;
    m_pMap1 = NULL;
    m_pMap2 = NULL;
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
}

void GameManager::Play()
{
    // 배를 배치한다
    Init();
    for(int i=0; i<MAP_SIZE; ++i)
    {
        for(int j=0; j<MAP_SIZE; ++j)
        {

            cout << m_pMap1->GetData(j, i) << " ";
        }
        cout << endl;
    }
    while (true)
    {
        if(CheckGameOver())
        {
            Position attackPos = m_Attacker->GetAttackPos();
            cout << attackPos.x << " " << attackPos.y << endl;
            HitResult output = HitCheck(m_pMap1, attackPos);
            if(output !=0 )
            {
                m_pMap2->SetData(attackPos, CHECK);
            }
            if(output == 0)
                cout << "Miss" << endl;
            else if(output == 1)
                cout << "Hit" << endl;
            else if(output == 2)
                cout << "AirCraft Destroy" << endl;
            else if(output == 3)
                cout << "BattleShip Destroy" << endl;
            else if(output == 4)
                cout << "Cruiser Destroy" << endl;
            else if(output == 5)
                cout << "Destroyer1 Destroy" << endl;
            else if(output == 6)
                cout << "Destroyer2 Destroy" << endl;
        }
        else break;

        for(int i=0; i<MAP_SIZE; ++i)
        {
            for(int j=0; j<MAP_SIZE; ++j)
            {

                cout << m_pMap2->GetData(j, i) << " ";
            }
            cout << endl;
        }
    }
    cout << m_Defender->GetTurn();
}

void GameManager::Init()
{
    m_pMap1 = new Map(1);
    m_pMap2 = new Map(2);

    // 배를 배치하기 위해 백터에 각 항목을 넣는다.
    m_Attacker = new Player();
    m_Defender = new Player();

    Ship* air = new Ship(5);
    Ship* battle = new Ship(4);
    Ship* cru = new Ship(3);
    Ship* dest1 = new Ship(2);
    Ship* dest2 = new Ship(2);
    Ship* arrShip[SET_SHIPS] = {air, battle, cru, dest1, dest2 };
    
    m_Defender->SetupShips(arrShip, m_pMap1);
}

HitResult GameManager::HitCheck(Map* m_pMap, const Position& pos)
{
    Position attack = pos;
    // 입력한 자리에 위치한 ShipType을 할당한다
    ShipType getAttack = m_pMap->GetData(attack);
    if(getAttack == AIRCRAFT)
    {
        // // 해당배의 자리가 있는 벡터를 할당받는다
        // VECPOS& getShip = m_Defender->GetShips(0)->m_pos;
        // for(int i=0; i<getShip.size(); ++i)
        // {
        //     if(getShip[i].x == attack.x && getShip[i].y == attack.y)
        //     {
        //         getShip.erase(getShip.begin() + i);
        //         break;
        //     }
        // }
        // cout << "Vector Size = " << getShip.size() << endl;
        int size = Remove(0);
        if(size == 0) return AIRCRAFT_DESTROY;
        else return HIT;
    } 
    else if(getAttack == BATTLESHIP) 
    {
        // VECPOS& getShip = m_Defender->GetShips(1)->m_pos;
        // for(int i=0; i<getShip.size(); ++i)
        // {
        //     if(getShip[i].x == attack.x && getShip[i].y == attack.y)
        //     {
        //         getShip.erase(getShip.begin() + i);
        //         break;
        //     }
        // }
        // cout << "Vector Size = " << getShip.size() << endl;
        int size = Remove(1);
        if(size == 0) return BATTLESHIP_DESTROY;
        else return HIT;
    }
    else if(getAttack == CRUISER)
    {
        // VECPOS& getShip = m_Defender->GetShips(2)->m_pos;
        // for(int i=0; i<getShip.size(); ++i)
        // {
        //     if(getShip[i].x == attack.x && getShip[i].y == attack.y)
        //     {
        //         getShip.erase(getShip.begin() + i);
        //         cout << "Size = " << getShip.size() << endl;
        //         break;
        //     }
        // }
        // cout << "Vector Size = " << getShip.size() << endl;
        int size = Remove(2);
        if(size == 0) return CRUISER_DESTROY;
        else return HIT;
    }
    else if(getAttack == DESTROYER) 
    {
        // VECPOS& getShip1 = m_Defender->GetShips(3)->m_pos;
        // for(int i=0; i<getShip1.size(); ++i)
        // {
        //     if(getShip1[i].x == attack.x && getShip1[i].y == attack.y)
        //     {
        //         getShip1.erase(getShip1.begin() + i);
        //         break;
        //     }
        // }
        // cout << "Vector Size = " << getShip1.size() << endl;
        int size = Remove(3);
        if(size == 0) return DESTROYER1_DESTROY;
        else return HIT;

        // VECPOS& getShip2 = m_Defender->GetShips(4)->m_pos;
        // for(int i=0; i<getShip2.size(); ++i)
        // {
        //     if(getShip2[i].x == attack.x && getShip2[i].y == attack.y)
        //     {
        //         getShip2.erase(getShip2.begin() + i);
        //         break;
        //     }
        // }
        // cout << "Vector Size = " << getShip2.size() << endl;
        int size = Remove(4);
        // if(getShip2.size() == 0) return DESTROYER2_DESTROY;
        if(size == 0) return DESTROYER2_DESTROY;
        else return HIT;
    }
    else return MISS;
}

int Gamemanager::Remove(int which)
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
    cout << "Vector Size = " << getShip.size() << endl;

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
