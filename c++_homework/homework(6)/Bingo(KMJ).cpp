#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(void){
    ifstream fin;
    fin.open("input.txt");
    int line;
    fin >> line;
    for(int i = 0; i < line; i++)
    { 
        int table = 0, num = 0, cnt = 0;
        int bingo[5][5] ={0,};
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                fin >> table;
                bingo[i][j] = table;
            }
        }
        int guess = 0, zero = 0;
        while(cnt < 75)
        {
            if(guess != 0)
            {
                fin >> num;
                ++cnt;
                continue;
            }
            fin >> num;
            ++cnt;

            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                   if(bingo[i][j] == num)
                   {
                       bingo[i][j] = 0;
                   }
                }
            }
            for(int j=0; j<5; j++) { //가로
                if(bingo[j][0]==0) {
                    ++zero;
                    for(int k=1; k<5; k++) {
                        if(bingo[j][k]==0) {
                            ++zero;
                        }
                        else {
                            break;
                        }
                    }
                }
                if(zero==5) {
                    break;
                }
                else {
                    zero = 0;
                }
            }
            if(zero==5) {
                guess = cnt;
            }

            for(int j=0; j<5; j++) { //세로
                if(bingo[0][j]==0) {
                    ++zero;
                    for(int k=1; k<5; k++) {
                        if(bingo[k][j]==0) {
                            ++zero;
                        }
                        else {
                            break;
                        }
                    }
                }
                if(zero==5) {
                    break;
                }
                else {
                    zero = 0;
                }
            }
            if(zero==5) {
                guess = cnt;
            }

            for(int j=0; j<5; j++) { //왼쪽 대각선
                if(bingo[j][j] == 0) {
                    ++zero;
                }
                else {
                    break;
                }
            }
            if(zero==5) {
                guess = cnt;

            }
            else {
                zero = 0;
            }
            for(int j=4; j>=0; j--) { //오른쪽 대각선
                if(bingo[4-j][j] == 0) {
                    zero += 1;
                }
                else {
                    break;
                }
            }
            if(zero==5) {
                guess = cnt;
            }
            else {
                zero = 0;
            }
            

            if((bingo[0][0]== 0)&&(bingo[0][4]==0)&&(bingo[4][0]==0)&&(bingo[4][4]==0)) //각 꼭지점
            {
                guess = cnt;
            }
        }
        cout << guess << endl;
    }
}