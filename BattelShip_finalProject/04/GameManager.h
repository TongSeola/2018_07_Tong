/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-09
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include "Define_comm.h"

class StatPane;
class InputPane;
class Player;
class Map;
class PercentMap;

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

        void Percentage(Map* m_pMap, Position pos, PercentMap* Map, int plus);
        void ResetPercnet(Map *m_pMap, PercentMap* Map);

    protected:
        Player* m_Attacker;
        Player* m_Defender;

        Map* m_pMap1; //배의 배치가 보임
        Map* m_pMap2; //배의 배치가 보이지 않음
        PercentMap* m_Map_percent;

        StatPane* m_pStatPane;
        InputPane* m_pInputPane;

        int averageTurn;
        int countTurn;
};