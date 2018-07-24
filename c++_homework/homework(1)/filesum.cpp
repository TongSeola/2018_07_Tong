#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");
    
    int lineCount;
    
    fin >> lineCount;
    while (lineCount >0)
    {
        int val1;
        int val2;
        int sum=0;
        fin >> val1;
        fin >> val2;
        
        for( val1; val1 < (val2+1); )
        {
            sum +=val1;
            val1++;
        }
        
        cout << sum << endl;
        lineCount--;
    }
    return 0;
}