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
            int array1[50][50] = {0, };
            int array2[50][50] = {0, };
            int maxNum = row_col * row_col +1;
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
