/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-01
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include "Define_comm.h"

class StatPane;
class InputPane;
class Player;
class Map;

class GameManager
{
    public:
        GameManager();
        ~GameManager();

        void Play();
        void Init();
        void Render();
        void Destroy();

        HitResult HitCheck (Map* m_pMap, const Position& pos);
        bool CheckGameOver(); // false is GameOver
        int Remove(int which, Position attack);
    
    protected:
        Player* m_Attacker;
        Player* m_Defender;

        Map* m_pMap1; //배의 배치가 보임
        Map* m_pMap2; //배의 배치가 보이지 않음
        StatPane* m_pStatPane;
        InputPane* m_pInputPane;
};