/* 
<연산자오버로딩>
캐릭터형의 포인터는 문자열로 인식하기 때문에 함수로 char*로 받는 경우 
주소를 출력하고 싶으면 (void*)변수명 로 해야 함(출력할 때)

< #definde TREE 3> - 메크로
TREE를 사용한 경우 3으로 그냥 change 된다 

<함수의 내용이 짧고 많이 사용된다면>
그냥 함수가 아닌 inLine으로 선언해야 한다 (함수 대신에 그냥 내용이 복사 되어서 들어가기 때문에 = 치환)
함수 호출 시간이 오래 걸리기 때문에 빨리 실해을 시키기 위해서 
ex>  #definde MAX(x,y) (x > y ? x : y )    <- inLine과 같은 용도 이다

<메크로 함수를 여러줄 쓰고 싶을 때 모든 줄에 \(역슬래스)를 넣는다>
#define SWICH(x) \
    switch(x)\
    {\
        case 0:\
            break;\
        case 1:\
            break;\
    }\

#pragma once 
-> 1번만(여러번 include시) include 되고 나머지는 무시해라 / 리눅스에서 안됨 ㅋㅋㅋㅋㅋㅋㅋㅋㅋ

<내가 안드로이드로 코드가 돌아 갈때 pc로 코드가 돌아갈때 어떤것을 선택할 건지 할때 사용>
#define CHARACTER_H
#ifdef CHARACTER_H  컴파일 될대까지 실행 여부를 알 수 없음

<중복 include 방지 하기>
#ifndef CHARACTER_H 정의가 아직 하나도 겹치지 않으면 
#define CHARACTER_H 컴파일 된다

마지막에
#endif

std::vector<Character*> char;
<downCasting>
Elfd의 부모가 char이다 
char은 캐릭터형태로 upCasting이 자동으로 된다 
따라서 Elf안에 만든 Fly()함수를 사용하려면 downCasting이 필요하다
Elf* pElf = (Elf*)char[0];
pElf->Fly()

소멸자는 앞에 virtual을 넣어서 선언하자!!!!
-> 메모릭을 만들지 않기 위해서 
-> vtable 자식이 오버라이딩 되어 있다면 자식을 호출한ㄷ.. 
즉 없으면 부모의 것이 나온다
(부모의 것에 virtual을 붙여야 한다)
생성 : 부모->자식
소멸 : 자식->부모
이기 때문에 부모 소멸자에 virtual이 없다면 부모를 먼저 소멸하기 때문에 자식을 없애지 못한다
(@@@@가상소멸자 vtable공부하기@@@@)

new로 만들면 delete 만들기 꼭!!!!!!!!!!!

*/
