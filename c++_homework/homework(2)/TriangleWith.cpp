#include<iostream>
#include<fstream>
using namespace std;

double Inclination(const int a1, const int a2, const int b1, const int b2)
{
    // (a1-b1)(y-a2) = (a2-b2)(x-a1)
    return (a2-b2)/(a1-b1);
}

int LocationOfab(const int a1, const int a2, const int b1, const int b2, const int c1, const int c2)
{
    int x = a1-b1;
    int y = a2-b2;
    int inc = Inclination(a1,a2,b1,b2);
    if (x*y > 0 )
    {
        //증가함수
        if (x >0 )
        {
            //b가 밑 a가 위  즉 left
            if(Assignment(inc,a1,a2,c1,c2) > 0){ return 1; }
            else if (Assignment(inc,a1,a2,c1,c2) == 0) {return 0;}
            else {return -1;}
        }
        else
        {
            // b가 위 a가 아래 즉 right
            if(Assignment(inc,a1,a2,c1,c2) > 0){return -1; }
            else if (Assignment(inc,a1,a2,c1,c2) == 0) {return 0;}
            else{ return 1;}
        }
    }
    else
    {
        if( x > 0 )
        {
            //a가 밑 b가 위 즉 right
            if(Assignment(inc,a1,a2,c1,c2) > 0){ return -1;}
            else if (Assignment(inc,a1,a2,c1,c2) == 0) {return 0;}
            else { return 1;}
        }
        else
        {
            //a가 위 b가 밑 즉 left
            if(Assignment(inc,a1,a2,c1,c2) > 0){ return 1;}
            else if (Assignment(inc,a1,a2,c1,c2) == 0) {return 0;}
            else { return -1;}
        }
    }

}

double Assignment(const int inc, const int a1, const int a2, const int c1, const int c2)
{
    return inc*(c1-a1) + a2;
}

int main()
{  // 이거는 삼각형 시계방향인지 아닌지 판별하다가 뻘짓 한것 ㄷ ㄷ ㅜ ㅜ
    fstream fin;
    fin.open("input.txt");
    int testCase = 0;
    
    fin >> testCase;
    while (testCase > 0 )
    {
        int a1, a2, b1, b2, c1, c2;
        fin >> a1 >> a2;
        fin >> b1 >> b2;
        fin >> c1 >> c2;

        int clockDirection ;

        //수직 평행 인지 구하기
        if ((a1-b1 !=0 )&& (a2-b2 !=0))
        {
            clockDirection = LocationOfab(a1,a2,b1,b2,c1,c2);
        }
        else if (a1-b1 ==0)
        {
            if (a2-b2>0)
            {
                if(c1 < a1) {clockDirection = -1;}
                else if (c1 == a1) {clockDirection = 0;}
                else {clockDirection = 1;}
            }
            else
            {
                if(c1 < a1) {clockDirection = 1;}
                else if (c1 == a1) {clockDirection = 0;}
                else {clockDirection = -1;}   
            }
        }
        else
        {
            if (a1-b1>0)
            {
                if(c2 < a2) {clockDirection = -1;}
                else if (c2 == a2) {clockDirection = 0;}
                else {clockDirection = 1;}
            }
            else
            {
                if(c2 < a2) {clockDirection = 1;}
                else if (c2 == a2) {clockDirection = 0;}
                else {clockDirection = -1;}   
            }
        }

        

        testCase--;
    }
    return 0;
}