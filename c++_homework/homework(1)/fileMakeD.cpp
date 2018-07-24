#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int testCase;
    fin >> testCase;
    
    while(testCase >0)
    {
        int space=0;
        // 가로 세로길이를 받아오기
        fin >> space;
        
        // +개수를 담당
        int midl = 1;
        // 다이아몬드의 왼쪽 오른쪽을 나눈다
        int star = (space - midl)/2;

        // +만 출력되는 줄이 되기 전 위에 출력값
        while (midl !=space)
        {
            // 사각형틀을 만드는 *을 출력 +을 기준으로 왼쪽을 출력            
            for(int i=0; i < star; i++)
            {
                cout << "*";
            }
            // 다이아몬드를 만드는 +를 출력 
            for(int j=0; j < midl; j++)
            {
                cout << "+";
            }
            // 사각형틀을 만드는 *을 출력 +을 기준으로 오른쪽을 출력            
            for(int k=0; k < star; k++)
            {
                cout << "*";
            }
            // *의 개수가 줄어야 하므로
            star--;
            cout << endl;
            // 양옆에 +가 추가 되므로 2를 늘린다
            midl +=2;
        }

        // +만 출력되는 줄
        for(int t=0; t<space; t++)
        {
            cout << "+";
        }
        cout << endl;

        // 양옆에 +가 줄어든다 
        midl = midl -2;
        // 1로 초기화
        star = 1;
        // +개수가 0개 출력되기 전에 끝낸다
        while (midl > 0)
        {            
            for(int i=0; i < star; i++)
            {
                cout << "*";
            }
            for(int j=0; j < midl; j++)
            {
                cout << "+";
            }
            for(int k=0; k < star; k++)
            {
                cout << "*";
            }
            star++;
            cout << endl;
            
            midl -=2;
        }
        testCase--;
    }
    return 0;
}