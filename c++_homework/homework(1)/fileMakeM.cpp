#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int testCase;
    fin >> testCase;
    
    while(testCase >0)
    {
        // *+* -*- *+*
        // 짝수 번째는 * 홀수 번째는 + 나머지 구간 -
        int rowcol =0;
        fin >> rowcol;

        // + *의 출력을 컨트롤 하는 변수
        int plusStar = rowcol;
        // -의 출력을 컨트롤 하는 변수로 처음은 0개 출력이므로
        int miss =0;
        // - 가 출력을 늘려야 할 시점을 나타내 준다
        int block = (rowcol-1)/2;

        // 한줄출력
        for(int i=0; i < block; i++)
        {
            for(int j=0; j < miss; j++)
            {
                cout << "-";
            }
            for(int j=0; j < plusStar; j++)
            {
                if (j%2 == 0)
                {
                    cout << "*";
                }            
                else
                {
                    cout << "+";
                }
            }
            for(int j=0; j < miss; j++)
            {
                cout << "-";
            }
            // 다음줄로 옮긴다
            cout << endl;
            miss++;
            plusStar = plusStar-2;
        }

        // 가운데 한줄
        for(int i=0; i < rowcol; i++)
        {
            if(i==block)
            {
                cout << "*";
            }
            else
            {
                cout << "-";
            }
        }
        cout << endl;
        miss --;
        plusStar = plusStar+2;

        // 아래 한줄
        for(int i=0; i < block; i++)
        {
            for(int j=0; j < miss; j++)
            {
                cout << "-";
            }
            for(int j=0; j < plusStar; j++)
            {
                if (j%2 == 0)
                {
                    cout << "*";
                }            
                else
                {
                    cout << "+";
                }
            }
            for(int j=0; j < miss; j++)
            {
                cout << "-";
            }
            // 다음줄로 옮긴다
            cout << endl;
            miss--;
            plusStar = plusStar+2;
        }
        testCase--;
    }
    return 0;
}