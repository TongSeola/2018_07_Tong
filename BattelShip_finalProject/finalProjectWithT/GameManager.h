// #include "Player.h"
#include "Define_comm.h"
class Player;

class GameManager
{
    public:
        GameManager()
        ~GameManager();

        void Init();
        void Play();
        // HitResult HitCheck (const Position& pos);

    protected:
        Player* m_Attacker;
        Player* m_Defender;
};