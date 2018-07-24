#include <vector>
#include <iostream>

enum ShipType
{ // 4바이트로 int와 같은.... 맨 앞은 초기화 할 수 있는 값을 넣는다.
    DATA_ERROR = -1,
    DATA_NONE,
    AIRCRAFT,
    BATTLESHIP,
    CRUISER,
    DESTROYER
};

#define MAP_SIZE 8 

struct Position
{
    Position() : x(0), y(0) {}
    int x;
    int y;

    // 할당한 이후에 사라지는 것이기 때문에 &로 해도 된다. 
    Position operator + (const Position& pos) const
    {
        Position repos;
        repos.x = x + pos.x;
        repos.y = x + pos.y;
        return repos;
    }

    Position operator - (const Position& pos) const
    {
        Position repos;
        repos.x = x - pos.x;
        repos.y = x - pos.y;
        return repos;
    }

    Position operator * (const float t)
    {
        Position repos;
        repos.x = x * t;
        repos.y = x * t;
        return repos;
    }

// // 특정의 안에 넣지 않고 외부함수이다(원래는) - source traget
// // friend를 적음으로써 외부함수로 인식하게 만든다
//     friend::ostream& operator << (std::ostream& os, Position pos) const
//     {
//         os << "x = " <<  pos.x << " y = " << pos.y;
//         return os;
//     }
};

std::ostream& operator << (std::ostream& os, Position pos)
{
    os << "x = " <<  pos.x << " y = " << pos.y;
    return os;
}

enum HitResult
{
    MISS,
    HIT,
    DESTROY
};
