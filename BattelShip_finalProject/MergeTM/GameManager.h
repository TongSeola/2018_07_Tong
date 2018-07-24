// #include "Player.h"
#include "StatPane.h"
#include "InputPane.h"
#include "Define_comm.h"

class Player;

class GameManager
{
    public:
        GameManager();
        ~GameManager();

        void Init();
        void Play();
        // HitResult HitCheck (const Position& pos);

        void Render();
        void Destroy();

        HitResult HitCheck (const Position& pos);
        bool CheckGameOver(); // false is GameOver

    protected:
        Player* m_Attacker;
        Player* m_Defender;

        GameManager* m_pMap;
        StatPane* m_pStatPane;
        InputPane* m_pInputPane;
};