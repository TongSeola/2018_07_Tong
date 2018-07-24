#include <iostream>
#include "GameManager.h"
using namespace std;

int main()
{
    // Position pos;
    // pos.x = 10;
    // pos.y = 20;
    // pos = pos + pos;
    // std::cout << pos; //연산자 오버로딩이 필요하다

    GameManager manager;
    manager.Init();
    manager.Play();

    return 0;
}