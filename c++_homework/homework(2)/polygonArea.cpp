#include<iostream>
#include<fstream>
using namespace std;

int main()
{// 주어진 점으로 만들어진 다각형의 넓이 구하고 점이 시계방향(-1)반시계방향(1)인지 구하기
    fstream fin;
    fin.open("input.txt");
    int testCase = 0;
    
    fin >> testCase;
    while (testCase > 0 )
    {
        int sum=0;
        int direction;
        int numberOfCorner;
        fin >> numberOfCorner;

        int lastonemoreX, lastonemoreY;
        int x1, y1;
        fin >> x1 >> y1;
        lastonemoreX = x1;
        lastonemoreY = y1;
        while (numberOfCorner > 1)
        {
            int x2,y2;
            fin >> x2 >> y2;

            sum += (x1+x2)*(y2-y1);
            x1 = x2;
            y1 = y2;

            numberOfCorner--;
        }

        sum += (x1+lastonemoreX)*(lastonemoreY-y1);

        if(sum < 0)
        {
            sum = sum*(-1);
            direction = -1;
        }
        else 
        { 
            direction = 1;
        }

        cout << sum << " " << direction << endl;
        testCase--;
    }
    return 0;
}