#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int Non(double a, double b, double c)
{
    if(a >= b+c || b >=a+c || c >=a+b)
    {
        return 0;
    }
    else { return 4; }
}

int Right(int a, int b, int c)
{
    if (a == b+c || b == c+a || c == b+a)
    {
        return 1;
    }
    else { return 4;}
}

int Big (int a, int b, int c)
{
    if(a > b+c || b >a+c || c >a+b)
    {
        return 2;
    }
    else { return 4; }
}

int Small (int a, int b, int c)
{
    if(a < b+c || b <a+c || c <a+b)
    {
        return 3;
    }
    else { return 4; }    
}

int main()
{//주어진 3개의 점으로 삼각형의 종류판별 및 삼각형 가능여부 판별
    fstream fin;
    fin.open("input.txt");
    int testCount = 0;
    
    fin >> testCount;
    while (testCount > 0 )
    {
        int a1, a2, b1, b2, c1, c2;
        fin >> a1 >> a2;
        fin >> b1 >> b2;
        fin >> c1 >> c2;

        int A, B, C;
        A = pow((a1-b1),2) + pow((a2-b2),2);
        B = pow((b1-c1),2) + pow((b2-c2),2);
        C = pow((c1-a1),2) + pow((c2-a2),2);
        double a, b, c;
        a = sqrt(A);
        b = sqrt(B);
        c = sqrt(C);

        cout << "A B C : "<<A<< " " << B<< " " << C << endl;
        cout << "a b c : " << a << " "<<b << " "<< c << endl;

        int result;
        // result = non(sqrt(A), sqrt(B), sqrt(C));
        int right = Right(A,B,C);
        int big = Big(A,B,C);
        int small = Small(A,B,C);
        int non = Non(a,b,c) ;

        if (right == 1) {result = right;}
        else if (big == 2) { result = big;}
        else if (small == 3) { result = small;}
        if ( non == 0) {result = non; }

        cout << result << endl;

        testCount--;
    }

    return 0;
}
