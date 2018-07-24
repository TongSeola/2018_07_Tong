/*
세로열 1~7(왼~오)
4개로 들어오면 이긴다
개임에 사용된 돌의 갯수
번갈아 가면서 넣은 열의 수
먼저 -1 나중-2 무승부-0
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while (TestCase > 0 )
    {
        int chips_number = 0;
        fin >> chips_number;

        const int order = chips_number/2 + 1; //한사람당 몇번의 횟수를 같는지

        int* first = new int[order];
        int* second = new int[order];

        int stage[ 7 * 7 ] = {0, }; // 넣는곳

        bool diffOneTwo = true;
        int index1 = 0;
        int index2 = 0;
        while (chips_number > 0)
        {
            int where = 0;
            fin >> where;
            where = where-1; // 0 ~ 6
        
            if(diffOneTwo)
            {
                while(stage[where] != 0)
                {
                    where = where + 7;
                }
                stage[where] = 1;
                diffOneTwo = !diffOneTwo;
            }
            else
            {
                while(stage[where] != 0)
                {
                    where = where + 7;
                }
                stage[where] = 2;
                diffOneTwo = !diffOneTwo;
            } 

            cout << "게임판상태 : " << endl;
            for(int j=0; j<7; j++)
            {
                for(int i=0; i < 7; i++) cout << stage[j*7+i] << " " ;
                cout << endl;
            }
            // 가로로 발견이후 +3까지 ( 0~3 / 7~10 / 14~17 / 21~24 / 28~31 / 35~38 / 42~45 )
            // 세로로 발견이후 다음 row까지 +7*3 ( <27)
            // 대각선 (오른쪽 - 왼쪽) +8*3 ( 0~3 / 7~10 / 14~17 / 21~24 / 28~31 )
            // 대각선 (왼쪽 - 오른쪽) +6*3 ( 3~6 / 10~13 / 17~20 / 24~27 / 31~34)
            chips_number --;
        }
        bool diffCout = false;
        for(int index=0; index < 48; index++)
        {
            if(diffCout) break;
            if( ( ( (0 < index && index < 3) || (7 < index && index < 10) || (14 < index && index < 17) || 
                    (21 < index && index < 24) || (28 < index && index < 31) || (35 < index && index < 38) || (42 < index && index < 45) )
                && (stage[index]==1 && stage[index+1]==1 && stage[index+2]==1 && stage[index+3]==1) )       ||
                ( index < 27 && (stage[index]==1 && stage[index+7*1]==1 && stage[index+7*2]==1 && stage[index+7*3]==1)) ||
                ( ( (0 < index && index < 3) || (7 < index && index < 10) || (14 < index && index < 17) || 
                    (21 < index && index < 24) || (28 < index && index < 31) )
                && (stage[index]==1 && stage[index+8*1]==1 && stage[index+8*2]==1 && stage[index+8*3]==1) ) ||
                ( ( ( 3 < index && index < 6) || (10 < index && index < 13) || (17 < index && index < 20) || (24 < index && index < 27) || (31 < index && index < 34) ) 
                && (stage[index]==1 && stage[index+6*1]==1 && stage[index+6*2]==1 && stage[index+6*3]==1)) )
            { 
                cout << 1 << endl;
                diffCout = !diffCout;
                // cout << "여기가 시작이다1111 : " << index << endl;
                break;
            }
            if( ( ( (0 < index && index < 3) || (7 < index && index < 10) || (14 < index && index < 17) || 
                    (21 < index && index < 24) || (28 < index && index < 31) || (35 < index && index < 38) || (42 < index && index < 45) )
                && (stage[index]==2 && stage[index+1]==2 && stage[index+2]==2 && stage[index+3]==2) )       ||
                ( index < 27 && (stage[index]==2 && stage[index+7*1]==2 && stage[index+7*2]==2 && stage[index+7*3]==2)) ||
                ( ( (0 < index && index < 3) || (7 < index && index < 10) || (14 < index && index < 17) || 
                    (21 < index && index < 24) || (28 < index && index < 31) )
                && (stage[index]==2 && stage[index+8*1]==2 && stage[index+8*2]==2 && stage[index+8*3]==2) ) ||
                ( ( ( 3 < index && index < 6) || (10 < index && index < 13) || (17 < index && index < 20) || (24 < index && index < 27) || (31 < index && index < 34) ) 
                && (stage[index]==2 && stage[index+6*1]==2 && stage[index+6*2]==2 && stage[index+6*3]==2)) )
            { 
                cout << 2 << endl;
                // cout << "여기가 시작이다2222 : " << index << endl;
                diffCout = !diffCout;
                break;
            }
        }
        if (diffCout == false)  cout << 0 << endl;

        TestCase --;
    }
    return 0;
}


/*
4
15 4 5 4 5 1 1 2 3 3 2 6 7 4 5 5 
8 1 2 1 3 1 4 7 5 
14 4 5 4 5 1 1 2 3 3 2 6 7 4 5 
39 2 4 3 3 2 1 1 3 6 1 5 6 3 1 5 4 7 4 1 5 5 5 6 5 7 6 2 7 6 7 7 7 3 2 6 1 4 3 4

1
2
0
1
*/

