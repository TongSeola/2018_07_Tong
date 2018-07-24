#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    return 0;
}

bool Divide (int x, int y, int& z)
{
    // int& z는 참조 값으로 이 함수 밖으로 나가도 할당된 값을 가지고 나간다(return 값)
    if(y == 0)
        return false;

    z = x/y;
    return true;
}

#defind ERROR_POINTER 21;
// 이런식으로 정의 해 놓으면 ERROR_POINTER를 return 값으로 해도 int값으로 취급함

// 일반화 = 추상화 (태권브이 -> 로보트)
// 구체화 (로보트(=개념적 존재) -> 태권브이(=현실속의 존재))
// 기능이 같다고 상속(is a)받으면 안된다 ㅎㅎ 

// 포함관계(has a)
// 캐릭터 has a 인밴토리 has a 아이템
// component class 를 만들어서 포함관계를 사용하여 새로운 오브젝트를 만들 수 있다(?)

//이거는 .h로 만든것에 존재해야한다.
class Character
{
public : 
    Game();
    ~Game();

    void Play();
    void SetHP(int hp);
    int GetHP() const {return my_hp;} // 이거는 hp를 반환만 하기 때문에 const를 사용하였다. 
    int GetHP() {return my_hp;} // 위에 것이랑 다르다
    // void Die(); //여기다가 만드는 것이 맞나??
protected:
// 원래 선언은 숫자가 안돼지만 비주얼 스튜디어 에서는 가능 11이상인 경우
    Character
    int my_hp = 0;
    static int my_Count; //static은 class가 만들어 지기 전에 만들어 지기때문에 새로 정의 해야함 
                            // 그래서 멤버함수 및 변수에 접근할 수 없다.
                            // static 변수를 건드려도는 된다
}

#pragma once
#include "Character.h"

int Game:: my_Count=0;
// 다른곳에서 부를때 레퍼런스를 만들지 않아도 사용가능하다
//ex> Game::my_Count = 0;

// 이부분은 선언 : uid(5)
Game::Game() 
{
    my_pGame = NULL:
    my_Count++;
}

Game::~Game()
{
    //존재여부 확인 이후 지우기
    if(my_pGame)
    {
        my_pGame->Die();
        delete my_pGame;
    }
}

void Game::Play()
{
    // 이 함수가 여러번 호출 될 수 있으므로 데이터를 없애주는 것 만들기
    // 이미 존재하는 경우 만들지 않고
    // 존재하지 않은경우 만든다
    if( !my_pGame)
        my_pGame = new Character();

    Game gg;
    gg.GetHP();

    const Game gg2;
    gg2.GetHP();

}

void Game::SetHP(int hp)
{
    // 함수 뒤에 const를 붙여서 만드는 경우 멤버 변수를 바꿀 수 있다.
    // 지금은 const를 붙이지 않아서 바꿀 수 있다.
    this -> my_hp = hp;
}