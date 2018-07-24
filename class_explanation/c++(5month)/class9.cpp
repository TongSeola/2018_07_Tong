/*
friend fuction - 되도록 사용하지 말아라
-> c와의 호환성을 가져오기 위해 존재 하는 것
-> friend void sub();로 만들어 놓으면(class내에서) 
-> 밖에 sub() 함수를 따로 만들어서 안에 있는 것을 꺼내올 수 있게 만듬

<연산자 중복 / 오버로딩>
기본적으로 있는 것이 아니라 내가 원하는 데로 변경하여 연산자를 정의 할 수 있다.
(상식적으로 만들어 놓는 것이 좋다)

[만드는 방법]
반환형 operator 연산자 (const 변수 & 들의 목록)
{
    연산자 수행
}
ex> Vector  operator+(const  Vector&,  const  Vector&); (이건 함수선언으로 ;가 붙는다)
(+를 오버로딩하면 -를 당연히 같이 구현해 놓아야 함) - 세트로 만들어라 

내가 만든 클래스이면 안에서 오버로딩
다른데서 가져온 경우 밖에서 getter 로 가저와서 오버로딩 한다
*/

#include <iostream>
using namespace std;

class Vector
{
    private:
        double x, y;
    public:
        Vector(double x, double y)
        {
            this->x = x;
            this->y = y;
        }
        Vector operator+(const Vector& v2)
        {
            Vector v(0.0, 0.0);
            v.x = this->x + v2.x;
            v.y = this->y + v2.y;
            return v;
        }
        Vector operator-(const Vector& v2)
        {
            Vector v(0.0, 0.0);
            v.x = this->x - v2.x;
            v.y = this->y - v2.y;
            return v;
        }

        // 포인터를 생각해 보았을 때 = 연산자를 오버로딩 하는 것이 필요하다
        // 즉 배열을 복사하면 주소를 복사해 오기 때문에 복.사.라는 것이 불가
        // 그래서 복사를 하려면 for문을 이용해서 만들어 줘야 함.. 
        // for문을 =연산자 오버로딩에 구현해야 한다
        Vector operator=(const Vector& v2)
        {
            this->x = v2.x;
            this->y = v2.y;
            /*
            for (int i=0 ; i < len; i++)
            {
                this->array[i] = v2.array[i];
            }

            // string으로 저장한 경우 그냥 할당해도 된다 (#include <string>)
            // string안에 =이 이미 오버로딩 되어져 있기 때문에
            */
            return *this;
        }

        //형변환 연산자
        operator int() const
        {
            return (int) (x + y);
        }

        //위의 형 변환 보다는 함수를 이용해서 만드는 것이 좋다
        int GetSum() const
        {
            return (int) (x + y);
        }
}

/*
int* p = NULL;

void CreateMem(int*& p)
{
    p = new int[10];
}
CreateMem(&p);

void CreateMen(int** p)
{
    *p = new int[10];
}
CreateMem(&p);

이렇게 해야 안에 값이 새로 배열로 생기면서 주소 값을 가져온다

*/