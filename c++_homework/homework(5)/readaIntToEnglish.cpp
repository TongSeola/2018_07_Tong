#include <iostream>
#include <fstream>
using namespace std;
/*
먼저 몇자리 숫자인지 구한다
2 012 358 750
Two [Billion] Twelve [Million] Three Hundred Fifty Eight [Thousand] 
Seven Hundred Fifty 
뒤에서 부터 3개씩 끝는다

*/

void InputThings(unsigned int* inputNum, int* None)
{
    // inputNum = 들어온 숫자 None = 숫자의 한자릿씩 저장하는 배열
    None[0] = *inputNum%100;
    *inputNum = *inputNum/100;
    None[1] = *inputNum%10;
    *inputNum = *inputNum/10;

    // cout << None[1] << " " << None[0] << endl;
}

void printNone(int* None, string* ele1, string* ele2, string* ele3, string* ele4, string* str)
{
    if (None[1] > 0)
    {
        *str += ele1[None[1]-1] + "_" + ele4[0] + "_";
    }

    if (0 < None[0] && None[0] < 10)
    {
        *str += ele1[None[0]-1];
    }
    else if ( 10 <= None[0] && None[0] < 20)
    {
        // Ten ~ Ninety
        *str += ele2[None[0]-10];
    }
    else if( None[0] >= 20)
    {
        int index10 = None[0]/10 - 2; //10의 자리
        int index1 = None[0]%10 -1;   // 1의 자리
        if(index1 < 0 && index10 >= 0) *str += ele3[index10];
        else if (index1 < 0 && index10 < 0) *str = *str;
        else  *str += ele3[index10] + "_" + ele1[index1];
    }
    else
    {
    }
}

void printElse(int* Thousand, string* ele1, string* ele2, string*ele3, string* ele4, const int index, string* str)
{
    if (Thousand[1] > 0)
    {
        *str += ele1[Thousand[1]-1] + "_" + ele4[0] + "_";
    }

    if (0 < Thousand[0] && Thousand[0] < 10)
    {
        *str += ele1[Thousand[0]-1] + "_" + ele4[index] + "_";
    }
    else if ( 10 <= Thousand[0] && Thousand[0] < 20)
    {
        // Ten ~ Ninety
        *str += ele2[Thousand[0]-10] + "_" + ele4[index] + "_";
    }
    else if( Thousand[0] >= 20)
    {
        int index10 = Thousand[0]/10 - 2; //10의 자리
        int index1 = Thousand[0]%10 -1;   // 1의 자리
        // cout << index10 << " " << index1 << endl;
        if (index1 < 0 && index10 >= 0) *str += ele3[index10] + "_" + ele4[index] + "_";
        // else if (index1 > 0 && index10 < 0) *str += ele1[index1] + "_" + ele4[index] + "_";
        else if (index1 < 0 && index10 < 0) *str = *str;
        else *str += ele3[index10] + "_" + ele1[index1] + "_" + ele4[index] + "_";
    }
    else
    {
        if(Thousand[1] > 0)
        {
            *str += ele4[index] + "_";
        }
    }

}

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while (TestCase > 0 )
    {
        unsigned int inputNum = 0;
        string str = "";
        fin >> inputNum;

        unsigned int Number = inputNum;
        // cout << Number << endl;

        int length = 0;
        while (inputNum > 0)
        {
            inputNum = inputNum/10;
            length ++;
        }
        // cout << length << endl;

        inputNum = Number;
        unsigned int* pinputNum = &inputNum;

        int Billion[2] = {0, };
        int Million[2] = {0, };
        int Thousand[2] = {0, };
        int None[2] = {0, };
         
        string ele1[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string ele2[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string ele3[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string ele4[] = {"Hundred", "Thousand", "Million", "Billion"};

        if ( 0 == length)
        {
            cout << "Zero" << endl;
        }
        else if ( 0 < length && length < 4)
        {
            InputThings(pinputNum, None);

            printNone(None, ele1, ele2, ele3, ele4, &str);

        }
        else if (4 <= length && length < 6)
        {
            InputThings(pinputNum, None);
            InputThings(pinputNum, Thousand);
            
            printElse(Thousand, ele1, ele2, ele3, ele4, 1, &str);
            printNone(None, ele1, ele2, ele3, ele4, &str);
        }
        else if ( 6<= length && length < 9)
        {
            InputThings(pinputNum, None);
            InputThings(pinputNum, Thousand);
            InputThings(pinputNum, Million);
            
            printElse(Million, ele1, ele2, ele3, ele4, 2, &str);
            printElse(Thousand, ele1, ele2, ele3, ele4, 1, &str);
            printNone(None, ele1, ele2, ele3, ele4, &str);
        }
        else
        {
            InputThings(pinputNum, None);
            InputThings(pinputNum, Thousand);
            InputThings(pinputNum, Million);
            InputThings(pinputNum, Billion);
            
            printElse(Billion, ele1, ele2, ele3, ele4, 3, &str);
            printElse(Million, ele1, ele2, ele3, ele4, 2, &str);
            printElse(Thousand, ele1, ele2, ele3, ele4, 1, &str);
            printNone(None, ele1, ele2, ele3, ele4, &str);
        }
        
        const int strLen = str.length();
        for(int i=0; i < strLen-1; i++)
        {
            cout << str[i];
        }
        if (str[strLen-1] != '_')
        {
            cout << str[strLen-1] << endl;
        }
        else
        {
            cout << endl;
        }
        TestCase --;
    }
    return 0;
}

/*
4 
111 
2012358750 
1234567000 
2000000002 

One_Hundred_Eleven 
Two_Billion_Twelve_Million_Three_Hundred_Fifty_Eight_Thousand_Seven_Hundred_Fifty 
One_Billion_Two_Hundred_Thirty_Four_Million_Five_Hundred_Sixty_Seven_Thousand 
Two_Billion_Two 
*/