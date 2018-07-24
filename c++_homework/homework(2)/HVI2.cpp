#include<iostream>
#include<fstream>
using namespace std;

int main()
{// 주어진 4개의 점이(2개씩 수평 수직으로 선분을 만든다) 서로 교차하는 지 접하는지 만나지 않는지 판별 
    fstream fin;
    fin.open("input.txt");
    int lineCount = 0;
    
    fin >> lineCount;
    while (lineCount > 0 )
    {
        int x1, x2, y1, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        int x3, x4, y3, y4;
        fin >> x3 >> y3 >> x4 >> y4;

        if (x1 == x2){
            //수직이다
            if ((x3 <= x1 && x1 <= x4 || x4 <= x1 && x1 <= x3)&&(y1 <= y3 && y3 <= y2 || y2 <= y3 && y3 <= y1)){
                //접하거나 완전교차
                if (x1 == x3 || x1 == x4){
                    //접한다
                    cout << 2 << endl;
                }
                else {
                    // 완전교차
                    cout << 1 << endl;
                }
            }
            else{
                //교차하지 않는다
                cout << 0 << endl;
            }
        }

        else{
            //수평이다
            if ((x1 <= x3 && x3 <= x2 || x2 <= x3 && x3 <= x1)&&(y3 <= y1 && y1 <= y4 || y4 <= y1 && y1 <= y3)){
                //접하거나 완전교차
                if(y1 == y3 || y1 == y4) {
                    // 접한다
                    cout << 2 << endl;
                }
                else{
                    //완전교차
                    cout << 1 << endl;
                }
            }
            else{
                //교차하지 않는다
                cout << 0 << endl;
            }

        }
        lineCount--;
    }

    return 0;
}