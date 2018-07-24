#include<iostream>
#include<fstream>
using namespace std;

int main()
{// 주어진 3개의 점으로 만들어진 삼각형의 넓이 및 점들의 방향 찾기(시계/ 반시계)
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
        double with;

        with = (a1*b2 + b1*c2 + c1*a2) - (b1*a2 + c1*b2 + a1*c2);
        if (with <0) 
        { 
            clockDirection = -1;
            with = with*(-1.0);
        }
        else if (with ==0 ) {clockDirection = 0;}
        else { clockDirection = 1;}

        cout << with << " " << clockDirection << endl;

        testCase--;
    }
    return 0;
}