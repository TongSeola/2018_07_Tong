#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int testCase;
    fin >> testCase;
    while( testCase > 0)
    {
        int getnumbercase=0;
        fin >> getnumbercase;

        int result =1;
        for (int i=0; i< getnumbercase; i++)
        {
            int mult =0;
            fin >> mult;
            mult = mult%10;
            result *= mult;
            result = result%10;

        }
        int numberfinal = result%10;

        cout << numberfinal << endl;
        testCase--;
    }
    return 0;
}