#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    int testCase;
    fin >> testCase;
    
    while (testCase >0)
    {
        int row=0;
        fin >> row;
        
        int howmany =0;
        for(int i=1; i <(row+1); i++)
        {
            howmany +=i;
        }
        
        for(int k=1; k < (row+1); k++)
        {
            int plus = row-1;
            int j=k;
            for (int t=0; t<k; t++)
            {
                cout << j << " ";
                j = j+plus;
                plus -=1;
            }
            cout << endl;
        }
        //cout << endl;
        testCase--;
    }
    return 0;
}