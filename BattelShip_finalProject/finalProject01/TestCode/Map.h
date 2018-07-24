#include "Define_comm.h"

class Map
{
    public:
        Map(int which);
        ~Map();

        ShipType GetData(const Position& pos) const;
        ShipType GetData(int x, int y) const;
        void SetData(const Position& pos, ShipType type);

    protected:
        ShipType m_Data[MAP_SIZE][MAP_SIZE];
};