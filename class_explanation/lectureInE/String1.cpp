//sprintf_s()
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string a = "Hello T";
    cout << a << endl;
    a += " my name is Seola";
    cout << a << endl;
    // char szTest[] = "I Love NeN";
    // char szBuf[32] = {0,}; // 길이(버퍼)의 제안으로 []안의 숫자를 잘 생각해야 함
    // printf_s("%s\n", szTest); // I Love NeN
    // // cout << szTest <<endl;

    // sprintf_s(szBuf, "%s Next!!", szTest);
    // // szBuf = szTest+" Next!";
    // printf_s("%s\n", szBuf); // I Love NeN Next!!
    // // cout << szBuf << endl;

    // char szTest2[] = "I am programmer";
    // strcpy_s(szTest2, szTest);
    // printf_s("%s\n", szTest2); // I Love NeN

    // std::string strAddTest = strTest;
    // strAddTest += "Add Test"; //길이(버퍼)를 마음대로 늘릴 수 있다
    // int strlen = strAddTest.length(); //문자열의 길이를 받아 올 수 있다
    // printf_s("%s\n", strAddTest.c_str());
    return 0;
}

