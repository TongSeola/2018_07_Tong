#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/*
스트링 값으로 들어 온다
1의 자리를 제외하고 계산을 시작한다
왼쪽에서 부터 짝수는 2배 (10이 넘어가는 경우 -9)
홀수는 1배
두개를 모두 더한다 
이후 1의 자릿수를 더한다
== 10의 배수가 되어야 한다
3 - 15,14
6 - 16
5 - 16
4 - 13,16
*/

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while (TestCase > 0 )
    {
        //스트링으로 입력받는다
        int plusAll = 0;
        string cardNumber = "";
        fin >> cardNumber;

        // 최대 20길이의 숫자를 받아오기 때문에
        // 0로 초기화 한다
        int array[20] = {0,};

        // 배열에 앞에서 부터 넣는다
        int len = cardNumber.length();

        for(int i=0; i < len; i++)
        {
            char num = cardNumber[i];
            array[i] = num - 48;
        }
/*3 - 15,14
6 - 16
5 - 16
4 - 13,16*/
//신용카드 회사가 맞는지 확인
        if ((array[0] == 3 && len == 15) ||
            (array[0] == 3 && len == 14) ||
            (array[0] == 6 && len == 16) ||
            (array[0] == 5 && len == 16) ||
            (array[0] == 4 && len == 13) ||
            (array[0] == 4 && len == 16)  )
        {
    // 마지막것은 빼고 더해야 하므로 len-1
            bool findTwo = true;
            for(int i=len-2; i >= 0 ; i--)
            {
                if (findTwo)
                {
                    array[i] = array[i]*2;
                    if(array[i] >= 10)
                    {
                        array[i] = array[i]-9;
                    }
                }
                findTwo = !findTwo;
                // cout << array[i] << " ";
            }
            // cout << endl;

    // 10의 배수로 나누어 떨어지는 검사
            for(int i=0; i < len-1; i++)
            {
                plusAll += array[i];
            }
            // cout << plusAll << endl;
            int findKey = 10 - (plusAll%10);
            if( array[len-1] == findKey)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else
        {
            cout << 0 << endl;
        }
        

        TestCase --;
    }
    return 0;
}

/*
4 
345678901234564 
345678901234568 
34567890123454 
745638901234564 

1
0
0
0
*/