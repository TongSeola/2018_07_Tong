#include<iostream>
#include<fstream>
using namespace std;

int main()
{//주어진 수들을 곱한 후 0이 아닌 마지막 수 + 총 0의 개수 구하기
    fstream fin;
    fin.open("input.txt");
    int testCase = 0;
    
    fin >> testCase;
    while (testCase > 0 )
    {
        int inputNumberCase = 0;
        fin >> inputNumberCase;

        int multi=1;
        int countTwo =0;
        int countFive =0;
        int countZero =0;
        int towFivemiss = 0;

        while (inputNumberCase > 0)
        {
            int inputNumber;
            fin >> inputNumber;

            while(inputNumber%2 ==0)
            {
                inputNumber = inputNumber/2;
                countTwo++;
            }
            while(inputNumber%5 == 0)
            {
                inputNumber = inputNumber/5;
                countFive++;
            }

            multi *= inputNumber;

            inputNumberCase--;
        }

        if(countFive < countTwo) {
            countZero = countFive;
            towFivemiss = countTwo- countFive;

            cout << "10의 갯수 : " << countZero << endl;
            for (int i=0; i < towFivemiss%4; i++){
                multi *= 2;
                multi = multi%10;
                cout << "남은 값들의 곲의 마지막 값 2: " << multi << endl;
            }
        }
        else { 
            countZero = countTwo;
            towFivemiss = countFive - countTwo;

            cout << "10의 갯수 : " << countZero << endl;
            for (int i=0; i < towFivemiss%5; i++){
                multi *= 5;
                multi = multi%10;
                cout << "남은 값들의 곲의 마지막 값 5: " << multi << endl;
            }
        }

        cout << multi%10 << " " << countZero << endl;
        testCase--;
    }

    return 0;
}