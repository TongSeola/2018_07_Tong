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
        int rowcol = 0;
        fin >> rowcol;
        int star = rowcol-1;

        for(int i=0 ; i < rowcol ; i++)
        {
            int center = (rowcol-1)/2;

            // 가운데 x축 만들기
            if(i==center)
            {
                for(int t=0; t < rowcol; t++)
                {
                    if(t==center)
                    {
                        cout << "O";
                    }
                    else
                    {
                        cout << "+" ;
                    }
                }
                star--;
            }
            // 대각전으로* 출력
            else
            {
                for(int t=0; t < rowcol; t++)
                {
                    if(t==center)
                    {
                        cout << "I";
                    }
                    else if(t == star)
                    {
                        cout << "*";
                    }
                    else 
                    {
                        cout << ".";
                    }
                }    
                star--;
            }
            cout << endl;
        }

       testCase--;
    }
    return 0;
}