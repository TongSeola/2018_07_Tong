#include <iostream>
#include <fstream>
using namespace std;
/* 
먼저 받은 두개의 수를 따로 따로 저장한다(row,col)
두개의 수를 곲한 값을 길이로 같은 일차 배열을 만든다
각 값을 넣는다
두 배열을 합한 것을 배열에 넣는다
col의 배수만큼(-1)이 될때마다 endl로 출력다음줄로 실행
*/

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while(TestCase > 0)
    {
        int row = 0;
        int col = 0;
        fin >> row >> col;

        int index = 0;
        const int len = row*col;
        int* pArray1 = new int[len];
        int* pArray2 = new int[len];
        int* pArray3 = new int[len];

        for(int i=0 ; i < len ; i++)
        {
            int num;
            fin >> num;
            pArray1[i] = num;
        }
        
        index = 0;
        for(int j=0; j < row; j++)
        {
            for(int i=0; i<col; i++)
            {
                cout << pArray1[index] << " ";
                index++;
            }
            cout << endl;
        }
cout << "=============================" << endl;
        for(int i=0 ; i < len ; i++)
        {
            int num = 0;
            fin >> num;
            pArray2[i] = num;
        }

        index = 0;
        for(int j=0; j < row; j++)
        {
            for(int i=0; i<col; i++)
            {
                cout << pArray2[index] << " ";
                index++;
            }
            cout << endl;
        }
cout << "=============================" << endl;
        for(int i=0 ; i < len ; i++)
        {
            int sumNum = pArray1[i]+pArray2[i];
            pArray3[i] = sumNum;
        }

        index = 0;
        for(int j=0; j < row; j++)
        {
            for(int i=0; i<col; i++)
            {
                cout << pArray3[index] << " ";
                index++;
            }
            cout << endl;
        }
cout << "==============NEXT===============" << endl;
        delete[] pArray1;
        delete[] pArray2;
        delete[] pArray3;
        TestCase--;
    }
    return 0;
}


/*
-1 5 8 6 1
9 8 18 4 3
1 5 9 7 4
1 2 3 4
5 6 7 8 
*/