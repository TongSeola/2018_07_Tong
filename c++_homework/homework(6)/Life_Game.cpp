/*
격자 - 살아있거나 /죽어있거나
8개와 이웃한다

1. 1개 이하의 이웃만 있다면 다음에 죽는다
2. 2개/3개 이웃이 있다면 현재가 살아있으면 다음에 살아있음
3. 3개의 이웃만이 있다면 살아난다
4. 4개 이상 이웃이 있다면 다음 시간에 죽는다

임의로 주어진 상태 = 0번째 세대

가로 * 세로
몇세대 까지
O - live X - die

두 개의 정수 m n ( 3 ≤ m, n ≤ 100)  m : 가로 줄의 개수 n : 세로 줄의 개수 
g ( 1 ≤ g ≤ 100) g 번째 세대까지를 계산
0번째 세대 왼쪽 셀부터 오른쪽 셀
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;
    while (TestCase > 0)
    {
        int berow, becol;
        int totalLiveCount = 0;
        fin >> berow >> becol ;
        const int row = berow;
        const int col = becol;
        char stage2[102][102];// = new char[col+2][row+2]; // 현재 상태를 나타낸다
        int stage1[102][102]; // = new int[col+2][row+2]; // 다음에 어떻게 처리할지 명령내리기
        int generation = 0 ;
        fin >> generation;
        // cout << "row col : " << row << " " << col << endl;
        // cout << "generation : " << generation << endl;

        // 넣기
        for(int i=0; i < (row); i++)
        {
            string rowSten = "";
            fin >> rowSten;
            for(int j=0; j < (col+2); j++) 
            {
                if(i==0 || j==0 || j==col+1)
                {
                    stage2[i][j] = 'X';
                    stage1[i][j] = -1;
                }
                if(i < row && j < col)
                {
                    stage2[i+1][j+1] = rowSten[j];
                    if(rowSten[j] == 'O') stage1[i+1][j+1] = 1;
                    else stage1[i+1][j+1] = 0;
                }
            }
        }
        for(int i=row; i < row+2; ++i)
        {
            for(int j=0; j < (col+2); j++) 
            {
                if(i==row && (j==0 || j==col+1))
                {
                    stage2[i][j] = 'X';
                    stage1[i][j] = -1;
                }
                else if(i==row+1)
                {
                    stage2[i][j] = 'X';
                    stage1[i][j] = -1;
                }
            }
        }
        // 잘집어 넣어 졌는지 확인
        // cout << "First ranke : " <<endl;
        // for(int i=1; i < row+1; i++)
        // {
        //     for(int j=1; j < col+1; j++) 
        //     {
        //         cout << stage2[i][j];
        //     }
        //     cout << endl;
        // }
        // for(int i=0; i < row+2; i++)
        // {
        //     for(int j=0; j < col+2; j++) 
        //     {
        //         cout << stage2[i][j];
        //     }
        //     cout << endl;
        // }  
        while (generation > 0)
        {
            for(int indexRow = 1; indexRow < row+1; ++indexRow)
            {
                for(int indexCol = 1; indexCol < col+1; ++indexCol)
                {
                    int liveCount = 0;
                    // stage2[indexRow][indexCol] == 'O'
                    if( stage2[indexRow-1][indexCol-1] == 'O' ) liveCount++;
                    if( stage2[indexRow-1][indexCol] == 'O') liveCount++;
                    if( stage2[indexRow-1][indexCol+1] == 'O') liveCount++;
                    if( stage2[indexRow][indexCol-1] == 'O') liveCount++;
                    if( stage2[indexRow][indexCol+1] == 'O') liveCount++;
                    if( stage2[indexRow+1][indexCol-1] == 'O') liveCount++;
                    if( stage2[indexRow+1][indexCol] == 'O') liveCount++;
                    if( stage2[indexRow+1][indexCol+1] == 'O') liveCount++;
                    // if(liveCount > 0 ) cout << "stage2["<< indexRow <<"]["<< indexCol <<"] : " << liveCount << endl; 

                    if ( liveCount <= 1 || 4 <= liveCount) // 죽는다 -> 0
                    {
                        stage1[indexRow][indexCol] = 0;
                    }
                    else if ( liveCount == 3) // 산다  -> 1
                    {
                        stage1[indexRow][indexCol] = 1;
                    }
                }
            }
            totalLiveCount = 0;
            for(int i=1; i < row+1; i++)
            {
                for(int j=1; j < col+1; j++) 
                {
                    if(stage1[i][j] == 1) stage2[i][j] = 'O';
                    else if(stage1[i][j] == 0) stage2[i][j] = 'X';
                    if(stage2[i][j] == 'O') totalLiveCount++;
                }
            }
            // 다음세대 잘 만들어 졌는지 확인
            // cout << "Next Generation : " << generation << endl;
            // for(int i=1; i < row+1; i++)
            // {
            //     for(int j=1; j < col+1; j++) 
            //     {
            //         cout << stage2[i][j];
            //     }
            //     cout << endl;
            // }    
            generation --;
        }

        // cout << "final result : " << endl;
        cout << totalLiveCount << endl;
        for(int i=1; i < row+1; i++)
        {
            for(int j=1; j < col+1; j++) 
            {
                cout << stage2[i][j];
            }
            cout << endl;
        }     
        TestCase --;
    }
    return 0 ;
}

/*
2 
8 8  
6 
XXXXXOXO 
XXXXXOOX 
XXXXXXOX 
XXXXXXXX 
XXXXXXXX 
XXXXXXXX 
OOOXXXXX 
XXXXXXXX 
11 25 
39 
XXXXXXXXXXXXXXXXXXXXXXXXX 
XXXXXXXXXXXXXXXXXXXXXXXXX 
XXXXXXXXXXXXXXOOXXXXXXXXX 
XXXXXXXXXXXXXOXXXOXXXXXXX 
XXXXXXXXXXXXOXXXXXOXXXXXX 
XXXXXXXXXXXXOXXXOXOOXXXXX 
XXXXXXXXXXXXOXXXXXOXXXXXX 
XXXXXXXXXXXXXOXXXOXXXXXXX 
XXXXXXXXXXXXXXOOXXXXXXXXX 
XXXXXXXXXXXXXXXXXXXXXXXXX 
XXXXXXXXXXXXXXXXXXXXXXXXX 

8 
XXXXXXXX 
XXXXXOXX 
XXXOOXXX 
XXXXOOXX 
XXXXXXXX 
XXXXXXXX 
OOOXXXXX 
XXXXXXXX 
27 
XXXXXXXXXXXXXXXXXXXXXXXXX 
XXXXXXXXXXXXXXXXXXXXXXXXX 
XXXXXXXXXXXXXXOOOXXXXXXXX 
XXXXXXXXXXXXXXOOOXXXXXXXX 
XXXXXXOOXXXXXXOOOXXXXXXXX 
XXXXXOXXOXXXXXXXXXXXXXOOO 
XXXXXXOOXXXXXXOOOXXXXXXXX 
XXXXXXXXXXXXXXOOOXXXXXXXX 
XXXXXXXXXXXXXXOOOXXXXXXXX 
XXXXXXXXXXXXXXXXXXXXXXXXX 
XXXXXXXXXXXXXXXXXXXXXXXXX
*/

