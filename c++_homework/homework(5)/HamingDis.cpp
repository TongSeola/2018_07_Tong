#include <iostream>
#include <fstream>
using namespace std;
/*
두개의 10진수를 받아온다
2진수로 변환 후
해밍 무게(1) 해밍무게(2) 해밍거리
*/

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while(TestCase > 0)
    {
        int num1;
        int num2;
        int weight1 = 0;
        int weight2 = 0;
        int lenght1 = 0;
        int lenght2 = 0;
        int distance = 0;
        fin >> num1 >> num2;

        const int num1_1 = num1;
        const int num2_1 = num2;
        while(num1 > 0)
        {
            if(num1 % 2 == 1) weight1 ++;
            num1 = num1/2;
            lenght1++;
        }

        while(num2 > 0)
        {
            if(num2 % 2 == 1) weight2 ++;
            num2 = num2/2;
            lenght2++;
        }

// 해밍 거리를 구하자
        num1 = num1_1;
        num2 = num2_1;
        if(lenght1 == lenght2)
        { // 두개의 길이가 같은 경우
            while(lenght1 > 0)
            {
                if(num1%2 != num2%2) distance ++;
                num1 = num1/2;
                num2 = num2/2;
                lenght1 --;
            }
        }
        else if (lenght1 > lenght2)
        {// num2가 길이가 더 작은 경우
            int find1 = 0; // 길이가 같은 경우 까지 1이 몇개인지 알아야 됨

            while(lenght2 > 0)
            {
                if(num1 % 2 == 1) find1 ++;
                if(num1%2 != num2%2) distance ++;
                num1 = num1/2;
                num2 = num2/2;
                lenght2 --;
            }
            distance = distance + (weight1 - find1);
        }
        else
        {
            int find1 = 0;
            
            while(lenght1 > 0)
            {
                if(num2 % 2 == 1) find1 ++;
                if(num1%2 != num2%2) distance ++;
                num1 = num1/2;
                num2 = num2/2;
                lenght1 --;
            }
            distance = distance + (weight2 - find1);
        }

        cout << weight1 << " " << weight2 << " " << distance << endl;
        TestCase--;
    }
    return 0;
}


/*
16 17 15 
1 1 2 
1 16 15 
*/