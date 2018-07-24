#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int testCase;
    fin >> testCase;
    
    while(testCase > 0)
    {
        int cases=0;
        fin >> cases;
        
        int sum=0;
        for(int i=0; i <cases; i++)
        {
            int number;
            fin >> number;
            sum +=number;
        }
        cout << sum << endl;
        testCase--;
    }
    return 0;
}