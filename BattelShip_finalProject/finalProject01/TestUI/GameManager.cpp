#include <iostream>
#include "GameManager.h"
#include "Player.h"
#include "Map.h"
#include "AirCraft.h"
#include "BattleShip.h"
#include "Cruiser.h"
#include "Destroyer.h"
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
    Render();
    Position attackPos = m_Attacker->GetAttackPos();
    // while (true)
    // {
    //     if(CheckGameOver())
    //     {
    //         Position attackPos = m_Attacker->GetAttackPos();
    //         HitResult output = HitCheck(attackPos);
    //     }
    //     else break;
    // }
    // 끝내기
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

    m_pMap1 = new Map(1, 4, 2, MAP_SIZE + 7, MAP_SIZE +2);
    m_pMap2 = new Map(2, 4, 15, MAP_SIZE + 7, MAP_SIZE +2);
    m_pStatPane = new StatPane(30, 3, 30 ,6);
    m_pInputPane = new InputPane(30, 15, 30, 4);

    // 배를 배치하기 위해 백터에 각 항목을 넣는다.
    m_Attacker = new Player();
    m_Defender = new Player();

    AirCraft* air = new AirCraft();
    BattleShip* battle = new BattleShip();
    Cruiser* cru = new Cruiser();
    Destroyer* dest1 = new Destroyer();
    Destroyer* dest2 = new Destroyer();
    Ship* arrShip[5] = {air, battle, cru, dest1, dest2 };
    
    m_Defender->SetupShips(*arrShip, m_pMap1);
}

void GameManager::Render()
{
    mvprintw(1,1, "<< Battle Ship Game >>");

    m_pStatPane->Draw();
    m_pInputPane->Draw();
    m_pMap1->Draw(1);
    m_pMap2->Draw(2);

    refresh();
}

void GameManager::Destroy()
{
    getch();
    endwin();
}
