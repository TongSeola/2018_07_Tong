/*
C++ BattleShip 프로젝트
작성일자 : 2018-06-09
학번 : 20171618
이름 : 동설아(Tong-Seol-a) 
*/
#include <vector>
#include "Define_comm.h"
class Map; //전방 선언으로 있다고만 가정한다
class Ship;
class PercentMap;

class Player
{
    public :
        Player();
        ~Player();

    // for Definder
        void SetupShips (Ship* ships[], Map* m_pMap);
        void IncreseTurn() { countTurn ++;}
        int GetTurn() {return countTurn;}
        
    // for Attacker
        Position GetAttackPos(Map* m_pMap, PercentMap* Map); // 어디를 공격한지 할당
        Ship* GetShips(int index){return m_pShips[index];}

    protected:
        int countTurn;
        Ship* m_pShips[SET_SHIPS];
};
