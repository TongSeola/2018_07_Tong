#include "Define_comm.h"
#include <vector>

class Ship
{
    public:
        Ship(int len);
        virtual ~Ship(); // 상속받으면 소멸자에 virtual붙이기!!!11(다형성)

        ShipType GetType() const {return m_Type};
        int GetLength() const {return m_length};
        // void AddPosition(const Position& pos);
        void SetPosition(int index, const Position& pos);

        Position* GetPosition(int index)
        {
            if(index >= m_Pos.size())
            {
                return NULL;
            }
            else 
                return &m_Pos[index];
        } 

        virtual HitResult HitCheck(const Position& pos);

        virtual void AAA() = 0;  //순수가상함수 상속 받은 곳에서만 구현을 해야한다
        // 순수함수를 하나라도 가지고 있으며 객채화가 불가한다.(추상클래스와 비슷하다)

        // 인터페이스 - 모든 함수가 순수가상함수로 이루어져 있는 것
        
    protected:
        ShipType m_Type;
        int m_length;
        // int m_hp;
        std::vector<Position> m_pos;
        // std::vector<Position*> m_pos;
        // Position m_Pos;
        // 벡터캐파시티 확보길이 사이즈는 안에 들어있는 양

};