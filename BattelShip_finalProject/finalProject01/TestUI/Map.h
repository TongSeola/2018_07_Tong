#include "Define_comm.h"
#include"Pane.h"

class Map : public Pane
{
    public:
        Map(int which, int x, int y, int width, int height);
        ~Map();

        ShipType GetData(const Position& pos) const;
        void SetData(const Position& pos, ShipType type);

        void Draw(int which);

    protected:
        ShipType m_Data[MAP_SIZE][MAP_SIZE];
};