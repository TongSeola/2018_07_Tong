/*
4~50

4의 배수 마방진 1_n^2 n^2~1까지 넣기
(n/4)^2으로 x나누기 
대각선에 대당하는 곳 바꾸기

4의 배수 아닌 짝수 마방진
1번째 가운데 1 올라가고 오른쪽 
자리 없으면 올라가지 말고 밑으로 

L - 4 1
    2 3
x - 1 4
    3 2
u - 1 4
    2 3

k+1 까지 L
다음 U
나머지 X
l과 u사이 가운데 것 바꾸기
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

    while (TestCase > 0)
    {
        int row_col = 0;
        fin >> row_col ;

        if(row_col%4 !=0)
        {
            int array_row_col = row_col/2; // 2X2배열?의 큰 갯수
            int findCase = array_row_col*array_row_col;
            int array_index_max = array_row_col-1; // 인덱스의 max
            int array_start_middle = array_index_max/2; // 중간점(시작점)

            int first_L = array_index_max/2; //L이 끝나는 곳
            int second_U = first_L+1; // U가 있는 곳
            int third_X = second_U+1; // X가 시작하는 곳

            // L=-1 U=-2 X=-3 초기화=0
            int Array[25][25][5] = {0,};
            for(int i=0; i<array_row_col; ++i)
            {
                for(int j=0; j<array_row_col; ++j)
                {
                    if(i >=0 && i<= first_L)
                    {
                        if( i==second_U-1 && j== array_start_middle) Array[i][j][0] = -2;
                        else Array[i][j][0] = -1;
                    }
                    else if(i==second_U)
                    {
                        if(j==array_start_middle) Array[i][j][0] = -1;
                        else Array[i][j][0] = -2;
                    }
                    else
                    {
                        Array[i][j][0] = -3;
                    } 
                }
            }
            //=====LUX를 구별해서 넣음
            int index1 = 0;
            int subIndex1 = 0;
            int index2 = array_start_middle;
            int subIndex2 = array_start_middle;
            int inputNum = 1;
            while(findCase > 0)
            {
                // cout << "Index : " << index1 << " " << index2 << endl;
                if(Array[index1][index2][0] == -1)
                { // L 4 1 2 3
                    Array[index1][index2][2] = inputNum;
                    inputNum ++;
                    Array[index1][index2][3] = inputNum;
                    inputNum ++;
                    Array[index1][index2][4] = inputNum;
                    inputNum ++;
                    Array[index1][index2][1] = inputNum;
                    inputNum ++;
                }
                else if(Array[index1][index2][0] == -2)
                { // U 1 4 2 3
                    Array[index1][index2][1] = inputNum;
                    inputNum ++;
                    Array[index1][index2][3] = inputNum;
                    inputNum ++;
                    Array[index1][index2][4] = inputNum;
                    inputNum ++;
                    Array[index1][index2][2] = inputNum;
                    inputNum ++;

                }
                else if(Array[index1][index2][0] == -3)
                { // X 1 4 3 2
                    Array[index1][index2][1] = inputNum;
                    inputNum ++;
                    Array[index1][index2][4] = inputNum;
                    inputNum ++;
                    Array[index1][index2][3] = inputNum;
                    inputNum ++;
                    Array[index1][index2][2] = inputNum;
                    inputNum ++;
                }

                subIndex1 = index1;
                subIndex2 = index2;
                index1 = index1-1;
                index2 = index2+1;
                if(index1 < 0) index1 = array_index_max;
                if(index2 > array_index_max) index2 = 0; 

                if(Array[index1][index2][1]==0) {}
                else 
                {
                    index1 = subIndex1+1;
                    if(index1 > array_index_max) index1 = 0;
                    index2 = subIndex2;
                }

                findCase --;
            }

            for(index1=0; index1 < array_row_col; ++index1)
            {
                for(int t=0; t<2; t++)
                {
                    for(index2=0; index2 < array_row_col; index2++)
                    {
                        if(t==0)
                        cout << Array[index1][index2][1] << " " << Array[index1][index2][2] << " ";   
                        else
                        cout << Array[index1][index2][3] << " " << Array[index1][index2][4] << " ";
                    }
                    cout << endl;                 
                }
            }
        }

        else if(row_col%4 == 0)
        {
            int array1[25][25] = {0, };
            int array2[25][25] = {0, };
            int maxNum = row_col * row_col+1;
            int subtract = 1;
            int index = 0;
            for(int i=0; i<row_col; ++i)
            {  
                for(int j=0; j<row_col; ++j)
                {
                    array1[i][j] = subtract;
                    if(i%4 == index || i%4 == 3-index)
                    {
                        array1[i][j] = row_col*row_col+1-subtract;
                    }
                    subtract ++;
                    index ++;
                    if(index == 4) index = 0;
                    cout << array1[i][j] << " ";
                }
                cout << endl;
            }
        }
        TestCase--;
    }
    return 0 ;
}

/*
3
4
6
8

16 2 3 13  
5 11 10 8  
9 7 6 12  
4 14 15 1  

32 29 4 1 24 21  
30 31 2 3 22 23  
12 9 17 20 28 25  
10 11 18 19 26 27  
13 16 36 33 5 8  
14 15 34 35 6 7  

64 2 3 61 60 6 7 57  
9 55 54 12 13 51 50 16  
17 47 46 20 21 43 42 24  
40 26 27 37 36 30 31 33  
32 34 35 29 28 38 39 25  
41 23 22 44 45 19 18 48  
49 15 14 52 53 11 10 56  
8 58 59 5 4 62 63 1 
*/

            // for(int i=0; i<row_col; ++i)
            // {
            //     for(int j=0; j<row_col; ++j)
            //     {
            //         array1[i][j] = subtract;
            //         array2[i][j] = maxNum - subtract;
            //         subtract ++;
            //     }
            // }

            // int row = 0;
            // for(int j=0; j<row_col/4 ; ++j)
            // {
            //     row = 0;
            //     for(int i=j*4; i < row_col ;++i)
            //     {   
            //         if(j==0)
            //         {
            //             array1[row][i] = array2[row][i];
            //             array1[i][row_col-row-1] = array2[i][row_col-row-1];
            //             row++;
            //         }
            //         else
            //         { // 반대 만들어라
            //             array1[row][i] = array2[row][i];
            //             array1[i][row] = array2[i][row];
            //             array1[i][row_col-row-1] = array2[i][row_col-row-1];
            //             array1[row_col-j-i][row_col-i-1] = array2[row_col-j-i][row_col-i-1];
            //             row++;
            //         }
            //     }
            // }





            // for(int i=0; i<row_col; ++i)
            // {
            //     for(int j=0; j<row_col; ++j)
            //     {
            //         if(j%4 == index || j%4 == 3-index) 
            //         {
            //             array1[i][j] = maxNum - subtract; // 00
            //             // array1[row_col-1-i][row_col-1-j] = subtract; // 77
            //         }
            //         else
            //         {
            //             array1[i][j] = subtract;
            //             // array1[row_col-1-i][row_col-1-j] = maxNum - subtract;
            //         } 
                
            //         subtract ++;
            //     }
            //     index ++;
            //     if(index == 3) index = 0;
            // }
