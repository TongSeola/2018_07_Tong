#include <iostream>
#include <fstream>
using namespace std;
/* 
먼저 받은 두개의 수를 따로 따로 저장한다(row,col)
두개의 수를 곲한 값을 길이로 같은 일차 배열을 만든다
각 값을 넣는다


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
        int row1 = 0;
        int col1 = 0;
        int row2 = 0;
        int col2 = 0;
        fin >> row1 >> col1 >> col2;
        row2 = col1;

        const int len1 = row1*col1;
        const int len2 = row2*col2;
        const int len3 = row1*col2;

        int* pArray1 = new int[len1];
        int* pArray2 = new int[len2];
        int* pArray3 = new int[len3]; // 결과

        for(int i=0 ; i < len1 ; i++)
        {
            int num;
            fin >> num;
            pArray1[i] = num;
        }
        
//         index = 0;
//         for(int j=0; j < row1; j++)
//         {
//             for(int i=0; i<col1; i++)
//             {
//                 cout << pArray1[index] << " ";
//                 index++;
//             }
//             cout << endl;
//         }
// cout << "=============================" << endl;
        for(int i=0 ; i < len2 ; i++)
        {
            int num = 0;
            fin >> num;
            pArray2[i] = num;
        }

//         index = 0;
//         for(int j=0; j < row2; j++)
//         {
//             for(int i=0; i<col2; i++)
//             {
//                 cout << pArray2[index] << " ";
//                 index++;
//             }
//             cout << endl;
//         }
// cout << "=============================" << endl;
        for(int i=0 ; i < len3 ; i++)
        {
            pArray3[i] = 0;
        }

        int index = 0;
        // for(int j=0; j < col2; j++)
        for(int t=0; t < row1; t++)
        {
            // for(int t=0; t < row1; t++)
            for(int j=0; j < col2; j++)
            {
                int index1 = t*col1;
                int index2 = j;
                for(int i=0 ; i < row2 ; i++)
                {
                    cout << "곱할값" << pArray1[index1] << " " << pArray2[index2] << endl;
                    pArray3[index] += pArray1[index1] * pArray2[index2];
                    index1++;
                    index2 += col2;
                }
                index++;
            }
        }

        index = 0;
        for(int j=0; j < row1; j++)
        {
            for(int i=0; i<col2; i++)
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
20 -1
58 20
41 22

1 2 3
4 5 6
7 8 9 
*/