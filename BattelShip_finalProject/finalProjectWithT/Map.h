#include "Define_comm.h"
// static const int MAP_SIZE = 8 ;

class Map()
{
    public:
        Map();
        ~Map();

        ShipType GetData(const Position& pos) const;
        void SetData(const Position& pos, ShipType type);

    protected:
        // 상수를 적어서 만들지 말자
        // MapData m_Data[MAP_SIZE][MAP_SIZE];
        ShipType m_Data[MAP_SIZE][MAP_SIZE];
};