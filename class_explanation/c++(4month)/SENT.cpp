#include<iostream>
using namespace std;

void Squre(const int& x, int& result)
{
    result = x*x; // 복사가 하나도 일어나지 않는다
    // 레퍼런스 값을 바꾸면 값이 바뀌므로 조심해야 한다 그래서 const를 넣어서 바꿀 수 없게 만들어 준다
    //const가 없으면 무조건 return 값으로 취급 된다. 

}

int main()
{
    int x = 5;
    int squre = 0;
    Squre(x , squre); // squre 은 25이다

    const char* A = "Hello";
    const char* B = "Hello";

    string A1 = "Hello";
    string B1 = "Hello";

    if( A == B) // false
    if( A1 == B1) // true



    return 0;
}

//inline은 항상 일어나는 것이 아니라 컴파일러 마음데로임 ㅋㅋㅋ
