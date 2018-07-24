#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int fracti = 2; // 소수 
    
    while (fracti <100)
    {
        // 다음 소수 구하기
        fracti++;
        for(int i=2; i < fracti; i++)
        {
            if(fracti%i == 0) //소수가 아니다
            {
                fracti++;
            }
        }
        cout << fracti << endl;
    }
    return 0;
}