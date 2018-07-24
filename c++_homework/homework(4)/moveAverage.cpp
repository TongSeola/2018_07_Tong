#include <iostream>
#include <fstream>
using namespace std;
/* 
몇개 입력 받는지
몇개의 자연수가 들어온다 inputNums
몇개씩 묶어서 평균구할지 howManyTie

몇개의 평균이 나오는지 \n outputNums
몇개의 평균

outputNums = inputNums - howManyTie +1

*/

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while(TestCase > 0)
    {
        int inputNums = 0;
        fin >> inputNums ;

        // 주어진 수를 배열에 순서대로 넣는다
        int* pArray = new int[inputNums];
        int index = 0;
        for(int i=0; i < inputNums; i++)
        {
            int num = 0;
            fin >> num ;
            pArray[index] = num;
            index++;
        }

        int howManyTie = 0;
        fin >> howManyTie ;

        // 몇개의 결과 값이 나오느지 구하고 
        // 이를 저장하는 배열을 만든다
        int outputNums = inputNums - howManyTie +1;
        int* pResult = new int[outputNums];
        int indexP = 0;
        int indexR = 0;

        for(int i=0; i < outputNums; i++)
        {
            indexP = i;
            int numPlus = 0;
            for(int j=0; j < howManyTie; j++)
            {
                numPlus += pArray[indexP];
                indexP++;
            }
            pResult[indexR] = numPlus/howManyTie;
            indexR++;
        }

        cout << outputNums << " ";
        for(int i=0; i < outputNums; i++)
        {
            cout << pResult[i] << " ";
        }
        cout << endl;

        delete[] pArray;
        delete[] pResult;

        TestCase--;
    }
    return 0;
}


/*
7 25 35 45 55 65 75 85
9 1 2 3 4 5 6 7 8 9
1 100 
*/