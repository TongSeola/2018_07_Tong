#include "Define_comm.h"

class Map : public Pane
{
    public:
        Map();
        ~Map();

        ShipType GetData(const Position& pos) const;
        void SetData(const Position& pos, ShipType type);

        void Draw();

    protected:
        ShipType m_Data[MAP_SIZE][MAP_SIZE];
};