#include <vector>
#include "Define_comm.h"
class Map; //전방 선언으로 있다고만 가정한다
class Ship;

using std::vector;
#define SHIPS vector<Ship*>

class Player
{
    public :
        Player();
        ~Player();

    // for Definder
        void SetupShips (Ship* ships, Map* m_pMap); 
        void IncreseTurn() { countTurn ++;}
        // Map* GetMap() { return m_pMap;}
        
    // for Attacker
        Position GetAttackPos(); // 어디를 공격한지 할당
        Ship* GetShips(int index){return m_pShips[index];}

    protected:
        int countTurn;
        // Map* m_pMap;  //전방뭐시기로 포인터로 하면 Map을 include 안해도 된다?!?!
        Ship* m_pShips[SET_SHIPS];
};
