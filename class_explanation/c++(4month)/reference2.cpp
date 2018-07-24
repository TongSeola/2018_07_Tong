#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

void Swap(int* x, int*y)
{
    if (!x) return ;

    int temp = *x; //nullpoiner 인 경우 조심 // 방어코드 만들자~!
    *x = *y;
    *y = temp;
}

void SwapReference(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a=3, b=5;
    SwapReference(a, b);
    cout <<  a; // 5가 출력 된다. 
    
    int x,y;
    x = y;

    int* p = &x;
    int& z = y; // 참조reference :


    int n=1; // 4 byte
    int* pn = &n; // 4byte
    int m = n; // 12 byte
    int& r = n; // 12 byte // r은 n의 참조(reference-다른이름) // 무조건 할당해야한다.
    ++r;
    cout << n; // 2가 나온다.

    char szTest[6] = {"Hello"}; // 마지막에 0이 들어가 있다. 
    char szTest[] = {"apple"}; // 이것도 가능하다. 
    const char* szTest = {"father"}; // 문자열을 바꾸지 않는 다고 가정했을 때 주로 사용하다. 

    return 0;

}