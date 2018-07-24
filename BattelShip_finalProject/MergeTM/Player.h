#include <vector>
#include "Define_comm.h"

class Map; //전방 선언으로 있다고만 가정한다
class Ship;
#define SHIPS std::vector<Ship*>

class Player
{
    public :
        Player();
        ~Player();

    // for Definder
        void SetupShips (const SHIPS& ships); // 포인터 참조 const
        void IncreseTurn();
        
    // for Attacker
        Position GetAttackPos();

    protected:
        int countTurn;
        Map* m_Map :  //전방뭐시기로 포인터로 하면 Map을 include 안해도 된다?!?!
        SHIPS m_Ships;
};
