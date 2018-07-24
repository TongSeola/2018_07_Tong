#include "Define_comm.h"

class Player;
class Map;

class GameManager
{
    public:
        GameManager();
        ~GameManager();

        void Play();
        void Init();

        HitResult HitCheck (Map* m_pMap, const Position& pos);
        bool CheckGameOver(); // false is GameOver
        int Remove(int which, Position attack);

    protected:
        Player* m_Attacker;
        Player* m_Defender;

        Map* m_pMap1; //배의 배치가 보임
        Map* m_pMap2;

};