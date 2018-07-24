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
        
    protected:
        ShipType m_Type;
        int m_length;
        std::vector<Position> m_pos;
};