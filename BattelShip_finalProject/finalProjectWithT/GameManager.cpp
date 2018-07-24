#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "AirCraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
// using namespace std;

GameManager::GameManager()
{
    m_Attacker = NULL;
    m_Defender = NULL;
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
}

void GameManager::Init()
{
    m_Attacker = new Player();
    m_Defender = new Player();

    std::vector<Ship*> vecShip;
    vecShip.push_back(new AirCraft());
    vecShip.push_back(new BattleShip());
    vecShip.push_back(new Cruiser());
    vecShip.push_back(new Destroyer());
    vecShip.push_back(new Destroyer());

//하나씩 돌면서 delete하고 마지막에 clear를 해야한다
// vecShip[0] 의 타입은 ship이다. 그래서 타입변환이 필요히디 - 형변환은 강제적으로 진행해서 조심해야 한다
    // AirCraft* pAirCraft = (AirCraft*)vecShip[0];
    // BattleShip* pBattleShip = (BattleShip*)vecShip[1];

    // for(auto pShip : vecShip)
    // {
    //     if(pShip->GetType() == AIRCRAFT)
    //     {
    //         AirCraft* pAirCraft = (AirCraft*)pShip;
    //     }
    // }

    m_Defender->SetupShips(vecShip);
}

void GameManager::Play()
{
    
}

// HitResult Player::HitCheck(const Position& pos)
// {
//     Position attack = pos;
//     ShipType getAttack = m_Defender->m_Map->m_Data[pos.y][pos.x];
//     if(getAttack == AIRCRAFT)
//     {
//         AirCraft.findLen++;
//         if(AirCraft.findLen == AirCraft.length)
//             return DESTROY;
//         else return HIT;
//     } 
//     else if(getAttack == BATTLESHIP) 
//     {
//         BattleShip.findLen++;
//         if(BattleShip.findLen == BattleShip.length)
//             return DESTROY;
//         else return HIT;
//     }
//     else if(getAttack == CRUISER)
//     {
//         Cruiser.findLen++;
//         if(Cruiser.findLen == Cruiser.length)
//             return DESTROY;
//         else return HIT;
//     }
//     else if(getAttack == DESTROYER) 
//     {
//         Destroyer.findLen++;
//         if(Destroyer.findLen == Destroyer.length)
//             return DESTROY;
//         else return HIT;
//     }
//     else return MISS;
// }
