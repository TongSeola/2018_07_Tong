#include<iostream>
#include<fstream>
#include<math.h>
#include <stdlib.h> 
using namespace std;

int main()
{// 사각형과 점사이의 직선거리& 택시거리 구하기
    fstream fin;
    fin.open("input.txt");
    int testCase = 0;
    
    fin >> testCase;
    while (testCase > 0 )
    {
        int x1,y1,x2,y2;
        int x,y;
        double direction;
        double rightD;

        fin >> x1 >> y1 >> x2 >> y2;
        fin >> x >> y;

        if(x1 <= x && x <=x2)
        {
            if( y1 <= y && y <=y2)
            {
                rightD = 0;
            }
            if ( y < y1) { rightD = y1-y;}
            if ( y > y2) { rightD = y-y2;}

            direction = pow(rightD,2);
            cout << " x사이 y밖" << endl;
        }
        else
        {
             if (y1 <= y && y <=y2)
             {
                 if(x < x1) { rightD = x1-x;}
                 if(x > x2) { rightD = x-x2;}

                 direction = pow(rightD,2);
                 cout << " y사이 x밖" << endl;
             }
             else
             {
                 int A, B, C, D;
                 //점과 꼭짓점 사이 길이 제곱으로 나타내기
                 A = pow(x1-x,2) + pow(y1-y,2);
                 B = pow(x2-x,2) + pow(y2-y,2);
                 C = pow(x1-x,2) + pow(y2-y,2);
                 D = pow(x2-x,2) + pow(y1-y,2);

                int Min[5] = {A,B,C,D};

                int min=A;
                int recog=0;
                for (int i=1; i < 4; i++)
                {
                    if(Min[i] < min)
                    {
                        min = Min[i];
                        recog = i;
                    }
                }

                 direction = min;
        
                 if (recog==0) {rightD = abs(x1-x)+ abs(y1-y);}
                 if (recog==1) {rightD = abs(x2-x)+ abs(y2-y);}
                 if (recog==2) {rightD = abs(x1-x)+ abs(y2-y);}
                 if (recog==3) {rightD = abs(x2-x)+ abs(y1-y);}

                 cout << "꼭짓점 이용" << endl;

             }
        }

        cout << direction <<" "<< rightD << endl;

        testCase--;
    }
    return 0;
}