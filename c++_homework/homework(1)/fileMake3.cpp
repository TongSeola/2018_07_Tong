#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int non(int a, int b, int c)
{
    if(a >= b+c || b >=a+c || c >=a+b)
    {
        return 0;
    }
    else { return 4; }
}

int sam(int a, int b, int c)
{
    if(a==b && b==c)
    {
        return 1;
    }
    else { return 4;}
}

int right(int a, int b, int c)
{
    double A = pow(a,2);
    double B = pow(b,2);
    double C = pow(c,2);

    if(A == B+C || B==A+C || C==A+B)
    {
        return 2;
    }
    else{return 4; }
}

int two(int a, int b, int c)
{
    if ( a == b || b==c || c==a)
    {
        return 3;
    }
    else{ return 4;}
}

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int testCase;
    fin >> testCase;
    
    while(testCase > 0)
    {
        int a = 0;
        int b = 0;
        int c = 0;
        fin >> a;
        fin >> b;
        fin >> c;
        
        int result =5;

        result = non(a,b,c);
        if (result==0) 
        {
            cout << result <<endl;
        }
        else{
            result = sam(a,b,c);
            if (result == 1)
            {
                cout << result << endl;
            }
            else{
                result = right(a,b,c);
                if(result ==2)
                {
                    cout << result << endl;
                }
                else{
                    result = two(a,b,c);
                    if(result == 3)
                    {
                        cout << result << endl;
                    }
                    else{
                        cout << result << endl;
                    }
                }
            }
        }

        testCase--;
    }
    return 0;
}



