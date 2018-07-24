#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

void Swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void SwapByPointer(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Add( int* x, int addVal)
{
    int add = *x + addVal;
    x = &add;
    // 뭐가 틀린지 생각해 보자 ㅜㅜ 
}
 
void Memtest(int x, int y)
{
    int val = x;
}

void Add(MemTest test)
{
    // 여기서 불러오는 Memtest test는 복사해온 값이 므로 밖에서는 영향을 주지 않는다.
    // 그래서 pointer로 접근해야 함
    // pointer는 . 이 아닌 ->를 사용해서 안에 것을 가지고 올 수 있다.
}

void Add(Memtest* test)
{
    cout << test->val;
}

int main()
{
    int x = 3;
    int y = 4;
    Swap( x, y);
    cout << x; // 3이 나옴 call by Value

    SwapByPointer(&x, &y);
    cout << x; // 4가 나옴 call by Reference


    int n;
    int* pn = &n;

    int* pm;
    if (true)
    {
        int m;
        pm = &m;  //유효하지 않은 포인터 if문 밖으로 나가면 m이 없어지니까 
                  //주소 안에 무엇이 있을지 알 수 없다.
    }

    
}
