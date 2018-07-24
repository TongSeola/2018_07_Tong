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
    m_pMap = NULL;
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

    if(m_pMap)
    {
        delete m_pMap;
        m_pMap = NULL;
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
    Init();
    Render();
    Destroy();
    Position setPos = m_Attacker->GetAttackPos();
    HitResult output = HitCheck(setPos);
    while(CheckGameOver)
    {
        Play();
    }
    // 게임이 끝났다.
}

void GameManager::Init()
{
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    inti_pair(3, COLOR_YELLOW, COLOR_BLACK);

    m_pMap = new GameManager();
    m_pStatPane = new StatPane(30, 3, 30 ,6);
    m_pInputPane = new InputPane(30, 15, 30, 4);

    m_Attacker = new Player();
    m_Defender = new Player();

    std::vector<Ship*> vecShip;
    vecShip.push_back(new AirCraft());
    vecShip.push_back(new BattleShip());
    vecShip.push_back(new Cruiser());
    vecShip.push_back(new Destroyer());
    vecShip.push_back(new Destroyer());

    m_Defender->SetupShips(vecShip);
}

void GameManager::Render()
{
    mvprintw(1,1, "<< Battle Ship Game >>");

    m_pMap->Draw();
    m_pStatPane->Draw();
    m_pInputPane->Draw();

    refresh();
}

void GameManager::Destroy()
{
    getch();
    endwin();
    delete m_pMap;
}

HitResult Player::HitCheck(const Position& pos)
{
    Position attack = pos;
    ShipType getAttack = m_Defender->m_Map->m_Data[pos.y][pos.x];
    if(getAttack == AIRCRAFT)
    {
        m_Ships[0]->m_pos = std::remove((m_Ships[0]->m_pos.begin(), m_Ships[0]->m_pos.end(), pos))
        if(m_Ships[0]->m_pos.size() == 0)
            return DESTROY;
        else return HIT;
    } 
    else if(getAttack == BATTLESHIP) 
    {
        m_Ships[1]->m_pos = std::remove((m_Ships[1]->m_pos.begin(), m_Ships[1]->m_pos.end(), pos))
        if(m_Ships[1]->m_pos.size() == 0)
            return DESTROY;
        else return HIT;
    }
    else if(getAttack == CRUISER)
    {
        m_Ships[2]->m_pos = std::remove((m_Ships[2]->m_pos.begin(), m_Ships[3]->m_pos.end(), pos))
        if(m_Ships[2]->m_pos.size() == 0)
            return DESTROY;
        else return HIT;
    }
    else if(getAttack == DESTROYER) 
    {
        m_Ships[3]->m_pos = std::remove((m_Ships[3]->m_pos.begin(), m_Ships[4]->m_pos.end(), pos))
        if(m_Ships[3]->m_pos.size() == 0)
            return DESTROY;
        else return HIT;

        m_Ships[4]->m_pos = std::remove((m_Ships[4]->m_pos.begin(), m_Ships[4]->m_pos.end(), pos))
        if(m_Ships[4]->m_pos.size() == 0)
            return DESTROY;
        else return HIT;
    }
    else return MISS;
}

bool GameManager::CheckGameOver()
{
    if(m_Ships[0]->m_pos.size() == 0 &&
       m_Ships[1]->m_pos.size() == 0 &&
       m_Ships[2]->m_pos.size() == 0 &&
       m_Ships[3]->m_pos.size() == 0 &&
       m_Ships[4]->m_pos.size() == 0)
       return false;
    else 
    {
        m_Defender->IncreseTurn();
        return true;    
    }

}
