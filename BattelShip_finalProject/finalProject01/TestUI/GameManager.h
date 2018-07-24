// #include "Player.h"
// #include "StatPane.h"
// #include "InputPane.h"
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

    protected:
        Player* m_Attacker;
        Player* m_Defender;

        Map* m_pMap1; //배의 배치가 보임
        Map* m_pMap2; //배의 배치가 보이지 않음
        StatPane* m_pStatPane;
        InputPane* m_pInputPane;
};