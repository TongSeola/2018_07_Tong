/*
모든 타입을 다 오버로딩 하면서 만들기 귀찮아서 만들어진 것 -> 템플릿 메타 프로그램
template<typename T> // 원래는 해더파일에서만 정의 할 수 있다. cpp는 불가하다.
타입이 다른것이 들어오면 그만큼 함수의 갯수/필요한/가 늘어난다. (즉, 컴파일시 함수가 만들어진다)

이터레이터 = 반복자

*/
#include <iostream>
using namespace std;

// header File
template<typename T> // <class T>
class CTemplate : 
{
    public :
        CTemplate(int size) {m_arr = new T[size];}
        ~CTemplate() { delete[] m_arry; }
        T* GerArr() {return m_arr;}

        void Test();
        int Print(int x);
        // int Sum(int x, int y) return x+y;
        // int Sum(float x, float y) return x+y;
        template<typename T> // 원래는 해더파일에서만 정의 할 수 있다. cpp는 불가하다
        T Sum(T x, T y) {return x + y ;}

        // char* Alloc(int size);
        // int* Alloc(int size);
        template<typename T>
        T* Alloc(int size)
        {
            T* p = new T[size];
            return p;
        }
        void Test2()
        {
            char* pNewChar = Alloc<char>(10); // 리턴값으로는 구별할 수 없기 때문에 직접 타입을 넣어주어야 한다.
        }

        template<typename T1, typename T2>
        T2 SumTest(T1 x, T2 y) { return x + y; } // return값이 어떤 타입으로 적어야 하는지는 ...... 그건... ㅜㅜ
    
    protected :
        // char* m_arr;
        T* m_arr;
};

// cpp File
// 이거는 템플릿이기 때문에 여기다 선언 불가
// CTemplate::CTemplate(int size)
// {
//     m_arr = new T[size];
// }
// CTemplate::~CTemplate()
// {

// }

void CTemplate::Test()
{
    int a = Sum(1, 2);
    float b = Sum(1.8f, 1.2f);
    Print(4);
    Print(1.2f);
}

int CTemplate::Print(int x)
{
    cout << x << endl;
}

char* CTemplate::Alloc(int size)
{
    char* p = new char[size];
    return p;
}

int main()
{
    CTemplate<char> temp(10);
    CTemplate<int> temp(10) ; // 이렇게 하면 함수가 두개가 만들어 진것이다.
    return 0;
}


//header
#define INT_LIST std::list<int>
#define INT_LIST_IT std::list<int>::iterator
class CSTL():
{
    public :
        CSTL();
        ~CSTL();

        void Test();
    protected:
        // std::list<int> arrList;
        INT_LIST arrList;
};

//cpp
#include <vector>
#include <list>
CSTL::CSTL()
{

}
CSTL::~CSTL()
{

}
void CSTL::Test()
{
    // std::list<int>::iterator itMid;
    // for(std::list<int>::iterator it = arrList.begin(); it!=arrList.end(); ++it)
    // {
    //     if( *it == 3)
    //     {
    //         itMid = it;
    //     }
    // }

    INT_LIST_IT itMid;
    INT_LIST_IT it = arrList.begin();
    INT_LIST_IT end = arrList.end(); // 한번마 호출해서 사용하는 것이 훨씬 빠르다.
    for(it ; it != end; ++it)
    {
        if( *it == 3)
        {
            itMid = it;
        }
    }

    std::vector<int> vecInt;
    // vecInt[0] = 3 이렇게 넣을 수 없다. 아직 존재하지 않는 장소에 3을 넣는다고 말하고 있기 때문에 
    vecInt.push_back(1); //pop_back()은 뒤에서 1개 빼고 지우기
    vecInt.push_back(2);
    vecInt.push_back(3);
    for(int i=0; i< vecInt.size(); ++i)
    {
        cout << vecInt[i] << " ";
    }

    std::vector<std::string> vecString; 

    vector<int> vecInt2;
    vecInt2 = vecInt;
    vecInt2[0] = 4 ; // vecInt의 0번째가 4로 바뀌지 않는다.

    vector<int>& vecInt3 = vecInt; // 이 것은 별명이니까 바뀌면 서로서로가 바뀐다... ㅎ

    list<int> listInt;
    listInt.push_back(1);
    listInt.push_back(2);
    listInt.push_back(3);
    for(list<int>::iterator it = listInt.begin(); it != listInt.end(); ++it)
    {
        // cout << *it << " "; // 커서가 가리키고 있는 내용을 가져와야 한다
        if(*it == 2)
        {
            // it = listInt.insert(it, 10); // 2앞에 10이 들어간다
            it = listInt.erase(it);
        }
    }

}

// 배열 : 램덤엑세스를 할 수 있기 때문에 빠르게 
// 리스트 : 추가삭제가 자유로움