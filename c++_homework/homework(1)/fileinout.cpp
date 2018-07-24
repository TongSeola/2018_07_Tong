#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream fin;
    fin.open("input.txt");
    int lineCount = 0;
    
    fin >> lineCount;
    while (lineCount > 0 )
    {
        
        int val1;
        int val2;
        fin >> val1;
        fin >> val2;

        int first = val1 + val2;
        int second = val1 - val2;
        int third;
        int fourth = val1 * val2;
        int fifth = val1/val2;
        int sixth = val1 % val2;
        int seventh;
        int eight;
        
        if (second > 0) 
        {
            third = second;
            seventh = val1;
        }
        else
        { 
            third = second *(-1);
            seventh = val2;
        }
        
        if (second == 0) 
        {
            eight = 1;
        }else{ eight = 0;}
        
        int result[8] = {first, second, third, fourth, fifth, sixth, seventh, eight};
        
        for(int j=0; j <8; j++)
        {
            cout << result[j] << " ";
        }

        lineCount--;
        cout << endl;
    }
    return 0;
}