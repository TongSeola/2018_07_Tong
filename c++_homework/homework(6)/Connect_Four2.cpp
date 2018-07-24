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

        int stage[7][7];
        for(int i=0; i < 7; ++i)
        {
            for(int j=0; j < 7; ++j) stage[i][j] = 0;
        }

        bool diffOneTwo = true;
        int index1 = 0;
        int index2 = 0;
        while (chips_number > 0)
        {
            int where = 0;
            fin >> where;
            where = where-1; // 0 ~ 6
            index1 = 0;
            index2 = 0;
        
            if(diffOneTwo)
            {
                while(stage[index1][where] != 0)
                {
                    index1 ++;
                }
                stage[index1][where] = 1;
                diffOneTwo = !diffOneTwo;
            }
            else
            {
                while(stage[index2][where] != 0)
                {
                    index2 ++;
                }
                stage[index2][where] = 2;
                diffOneTwo = !diffOneTwo;
            } 

            // cout << "게임판상태 : " << endl;
            // for(int j=0; j<7; j++)
            // {
            //     for(int i=0; i < 7; ++i)
            //     {
            //         cout << stage[j][i] << " ";
            //     }
            //     cout << endl;
            // }
            chips_number --;
        }
        // cout << "게임판상태 : " << endl;
        // for(int j=0; j<7; j++)
        // {
        //     for(int i=0; i < 7; ++i)
        //     {
        //         cout << stage[j][i] << " ";
        //     }
        //     cout << endl;
        // }

        bool diffCout = false;
        for(index1 = 0; index1 < 7; index1++)
        {
            if(diffCout) break;
            cout << "index1이 증가해라" << endl;
            for(index2 = 0; index2 < 7 ; index2++)
            {
                if(diffCout) break;
                if(stage[index1][index2]==1)
                {
                    // cout << "1 자리 : " << index1 << " " << index2 << endl;
                    if((index2 <= 3 &&(stage[index1][index2+1]==1 && stage[index1][index2+2]==1 && stage[index1][index2+3]==1)) ||
                       (index1 <= 3 &&(stage[index1+1][index2]==1 && stage[index1+2][index2]==1 && stage[index1+3][index2]==1)) ||
                       ((index1 <= 3 && index2 <= 3) &&(stage[index1+1][index2+1]==1 && stage[index1+2][index2+2]==1 && stage[index1+3][index2+3]==1)) ||
                       ((index1 <= 3 && 3 <= index2) &&(stage[index1+1][index2-1]==1 && stage[index1+2][index2-2]==1 && stage[index1+3][index2-3]==1)))
                       {
                        //    cout << "시작 자리 : " << index1 << " " << index2 << endl;
                           cout << 1 << endl;
                           diffCout = ! diffCout;
                           break;
                       }
                }
                else if(stage[index1][index2]==2)
                {
                    // cout << "2 자리 : " << index1 << " " << index2 << endl;
                    if((index2 <= 3 &&(stage[index1][index2+1]==2 && stage[index1][index2+2]==2 && stage[index1][index2+3]==2)) ||
                       (index1 <= 3 &&(stage[index1+1][index2]==2 && stage[index1+2][index2]==2 && stage[index1+3][index2]==2)) ||
                       ((index1 <= 3 && index2 <= 3) &&(stage[index1+1][index2+1]==2 && stage[index1+2][index2+2]==2 && stage[index1+3][index2+3]==2)) ||
                       ((index1 <= 3 && 3 <= index2) &&(stage[index1+1][index2-1]==2 && stage[index1+2][index2-2]==2 && stage[index1+3][index2-3]==2)))
                       {
                        //    cout << "시작 자리 : " << index1 << " " << index2 << endl;
                           cout << 2 << endl;
                           diffCout = ! diffCout;
                           break;
                       }
                }
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
