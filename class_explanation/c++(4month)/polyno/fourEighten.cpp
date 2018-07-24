// 다형성에 대해 알아보자 (polyno)
/*
상속관계 (is a)
A is B : A는 B다 = A는 B역할을 할 수 있다
다형성 : 하나의 객체가 여러 역할을 할 수 있다, (나 = 딸 친구 학생 ...)
자식은 부모의 역할을 할 수 있다. (즉, 내가 엄마 알바를 대신 갈 수 있음)
배열은 동적으로 사용할 수 없다
그래서 vector는 동적 배열로 크기를 늘릴 수 있다 (.push_back() = 넣기)
*/
//#include "stdafx.h"
#include <CCharacter.h>
#include<iostream>
#include<vector>
#include<Elf.h>
#include<DarkElf.h>

int main()
{
    std::vector<CCharacter> characters;
    characters.reserve(); // capacity를 () 안에 대충 예상해야 한다 ex 10
    Elf newElf;
    DarkElf newDarkElf;

//다형성은 레퍼런스 포인터로 해야 한다
// 즉 포인터로 안하면 vlaue로 들어가서 같은걸로 이식되지 않는다 ㅋㅋ

    characters.push_back(newElf); //push_back 은 주소를 연결하는 것이 아니라 복사되어서 들어간다
    characters.push_back(newDarkElf);// 생성자함수(기본)를 호출하지 않고 객체를 만든다 그대신 복사생성자를 호출한다

    for(auto charac : characters)
    {
        // i <character.size()
        // Character character = characters[i]...
        charac.SayMyName();
    }
    return 0;
}

//  오버라이딩 할때 vertuer 넣어야 한다
