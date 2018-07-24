#include <iostream>
#include <fstream>
using namespace std;

void deletMiddle (int* pIndex, int* array, const int len)
{
    for(int i=0; i < len; i++)
    {
        if (i==*pIndex)
        {
            array[i] = -1;
        }
    }

    *pIndex = *pIndex/2;
}

int main()
{
    // int index = 5;
    // int* pIndex = &index;
    // const int len = 10;
    // int array[] = {0,1,2,3,4,5,6,7,8,9};

    // deletMiddle(pIndex, array, len);

    // for(int i=0; i < len; i++)
    // {
    //     cout << "["<< i << "] : " << array[i] << endl;
    // }

    // cout << index << endl;

    // string str = "";
    // str += "Hello";
    // cout << str << endl;

    // string str1 = "Hello";
    // string str2 = "Hello";
    // if (str1.compare("Hello") == 0)
    // cout << "Same Same" << endl;
    // else cout << "NOB" << endl;

    int num = 19;
    cout << num%10 << endl;
    return 0;
}