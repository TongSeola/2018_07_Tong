#include <iostream>
#include <stdlib.h>
using namespace std;

#define Add
#define SubR
#define Sub

int main()
{
    int z = Add(1,2); // 3
    z = Add(1) // 11

    // 레퍼런스(참조)는 원본을 바로 할당해주어야 하기 때문에 null을 확인할 필요가 없다
    // 반대로 포인터는 null이 가능하다.

    const int MAS_COUNT =100; // #difine이라 같다 즉, 상수는 선언이 무조건 있어야 한다 
    // class에서는 바로 하지 않아도 되긴 한다????

    int age_1 = 1;
    int age_2 = 2;
    int _age;

    int* p = &age_1;
    p = &age_2; // age_1 에서 age_2로 pointer를 바꾼다
    *p = 10; //age_2의 값을 바꾼다

    int* const pconst = &age_1; //이렇게 하면 주소를 못바꾸는 것일 뿐 값은 바뀔 수 있다.
    *pconst = 100; // 이것만 가능

    const int* constp = &age_1; //이렇게 하면 역추적해서 값을 바꿀 수 없다.
    constp = age_2; // 이것만 가능 그래도 age_2 또는 age_1의 값을 바꿀 수 있다.

    int a = 100, b = 50;
    Sub(a,b);  // 100
    SubR(a,b); // 50  상수는 참조할 수 없기 때문에 함수함들때 무턱대로 &를 하면... ㅋ
    SubR(a, 50); // 상수 > 비상수 그래서 함수에 const를 붙여서 int를 참조하면 둘다 가능    
    // 그래서 const int& = input, int& = output으로 일반적으로 생각한다


    const int arrSize = 100;
    int arr[arrSize];
    for(int a : arr) // 같은 범위{}내에 있기 때문에 길이를 알 수 있음 즉, 다른 함수로 가면 길이를 모른다 ㅎㅎ
    {
        a = rand();
    }
    PrintArray(arr, arrSize);

    int movelen = 50;
    int* move = new int[movelen]; //동적 배열
    for(int i=0; i< movelen; ++i)
    {
        move[i] = rand();
    }
    delete move;

    sizeof(arr); // 400
    int arrCount = sizeof(arr) / sizeof(arr[0]); // 같은 {}안에서 길이를 아는 방법
    int* parr = arr;
    PrintArrayp(parr, arrSize); // PrintArrayp(arr, arrSize) 두개는 같은 것 ㅋㅋㅋ
    // arr == &arr[0]

    const char* text = "Hello world";
    char* newWord = ChangeWordToSmall(text, strlen(text));
    char szNew[128] = {0, };
    ChangeWordToSmallplus(text, strlen(text), szNew);
    delete[] newWord;

    return 0;
}

int Add()(int x, int y = 10 /*디폴트값은 y가 10으로 설정됨*/)
{
    // 디폴트 파라미터는 뒤에서 부터만 가능하다
    return x+y;
}

void Sub(int x, int y)
{
    x -= y;
}

void SubR(/*INOUT*/int& x,/*IN*/ const int y)
{
    // 그래서 const int& = input, int& = output으로 일반적으로 생각한다
    x -= y;
}

void PrintArray(int arr[], int len )
{
    for(int i=0; i<len; ++i)
    {
        std::cout << arr[i];
    }
}

void PrintArrayP(int* arr, int len )
{
    //call by reference
    for(int i=0; i<len; ++i)
    {
        std::cout << arr[i];
    }
}

char* ChangeWordToSmall(const char* szText, int len) // 대문자 받아서 소문자로 반환
{
    char* szNew = new char[len+1];

    // szText가 대문자인것을 가정
    for (int i=0; i < len; ++i)
    {
        if( 'A' <= szText[i] && szText[i] <= 'Z')
        {
            szText[i] += 'a' - 'A';// 소문자가 대문자 보다 위에 있다. 
            szNew[i] = szText[i];
        }
    }

    szNew[len] = '!';

    return szNew;
}

char* ChangeWordToSmallplus(const char* szText, int len, char* szNew) // 대문자 받아서 소문자로 반환
{
    char* szNew = new char[len+1];

    // szText가 대문자인것을 가정
    for (int i=0; i < len; ++i)
    {
        if( 'A' <= szText[i] && szText[i] <= 'Z')
        {
            szText[i] += 'a' - 'A';// 소문자가 대문자 보다 위에 있다. 
            szNew[i] = szText[i];
        }
    }

    szNew[len] = '!';

    return szNew;
}

// 헤더파일 
// class Exam{
//public:
// Exam(int number =10) {m_number = number;} // 기본생성자 유지하면서 할당 받을 수도 있음
// ~ Exam();
// void SetNumber(const int& number){ m_number = number;}
// int GetNumber() const {return m_number;} // output은 변경이없기 때문에 const를 넣는다

//protected : 
// int m_number;
//};