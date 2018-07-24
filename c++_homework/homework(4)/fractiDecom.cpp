#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>
using namespace std;
// 소수구하기
// 몇개소수존재 소수 지수 소수 지수 ....

/*
2이후 다음 소수 구하기 
다음 소수가 받은 값의 %가 0인지
된다면 아닐때 까지 나누기 (str에 더하기)
안된다면 그 다음 소수로 구하고 거기에는 되는지 확인 
소수가 (sqrt(숫자))에 도착할때 까지
*/

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;
    cout << "TestCase : " << TestCase << endl;
    while(TestCase > 0)
    {
        int number = 0;
        fin >> number;
        cout << "input number : " << number << endl;
        int Array[100] = {0, };
        int index = 0;
        int primeNum = 2; // 소수 
        int countP = 0; // 사용한 소수가 몇개인지
        int count = 0; // 소수가 몇번 나누어 지는지

        while (primeNum <= number)
        {
            if(number%primeNum == 0)
            {
                countP ++;
                while (number%primeNum == 0)
                {
                    number = number/primeNum;
                    count ++;
                }
                // primeNum 랑 count 저장
                cout << "소수 : " << primeNum << endl;
                Array[index] = primeNum;
                index++;
                Array[index] = count;
                index++;
                count = 0;
            }

            // 다음 소수 구하기
            primeNum++;
            for(int i=2; i < primeNum; i++)
            {
                if(primeNum%i == 0) //소수가 아니다
                {
                    primeNum++;
                }
            }
        }

        // 출력하기 
        cout << countP << " ";
        for(int i=0; i<index; i++)
        {
            cout << Array[i] << " " ;
        }
        cout << endl;
        TestCase--;
    }
    return 0;
}

/*
1 7 1
1 2 4
2 2 2 3 2
6 2 2 3 2 7 1 11 2 13 3 17 1 
*/