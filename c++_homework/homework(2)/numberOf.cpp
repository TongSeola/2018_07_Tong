#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main()
{// 주어진 수의 약수의 개수를 찾고 진약수를 제외한 모든 약수 더하기
    fstream fin;
    fin.open("input.txt");
    int testCase = 0;
    
    fin >> testCase;
    while (testCase > 0 )
    {
        int num;
        fin >> num;

        int sum = 0;
        int otherSum =0;
        int count = 0;
        int findMid = 0;

        for(int i=1; i < sqrt(num) ; i++)
        {
            if ( num%i ==0 )
            {
                if(findMid*i == num)
                {
                    break;
                }
                findMid = i;
                otherSum += (num/i);
                sum += i;
                count++;
            }
        }
        count = count*2 -1;
        otherSum = otherSum - num;

        cout << count << " " << sum+otherSum << endl;

        testCase--;
    }
    return 0;
}