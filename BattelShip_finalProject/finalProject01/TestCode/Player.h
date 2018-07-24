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
        void SetupShips (Ship* ships[], Map* m_pMap);
        void IncreseTurn() { countTurn ++;}
        int GetTurn() {return countTurn;}
        
    // for Attacker
        Position GetAttackPos(); // 어디를 공격한지 할당
        Ship* GetShips(int index){ return m_pShips[index]; }

    protected:
        int countTurn;
        Ship* m_pShips[SET_SHIPS];
};
