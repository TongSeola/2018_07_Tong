#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main()
{//주어진 수가 소수인지 아닌지 구하기
    fstream fin;
    fin.open("input.txt");
    int testCase = 0;
    
    fin >> testCase;
    while (testCase > 0 )
    {
        int number;
        fin >> number;

        if (number==2)
        {
            cout << 1 << endl;
        }
        else
        {

            int half = sqrt(number)+2;
            int result ;

            for (int i=2; i < half ; i++)
            {
                if (number%i ==0)
                {
                    result = 0;
                    break;
                }
                else
                {
                    result = 1;
                }
            }

            cout << result << endl;
        }
        testCase--;
    }
    return 0;
}