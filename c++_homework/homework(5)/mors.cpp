#include <iostream>
#include <fstream>
using namespace std;
/*
A = .-
B = -...
C = -.-.
D = -..
E = .
F = ..-.
G = --.
H = ....
I = ..
J = .---
K = -.-
L = .-..
M = --
N = -.
0 = ---
P = .--.
Q = --.-
R = .-.
S = ...
T = -
U = ..-
V = ...-
W = .--
X = -..-
Y = -.--
Z = --..
*/
string morsToString(string* AtoZ, string* aToz, string mors)
{
    for(int i=0; i < 26; i++)
    {
        if (mors.compare(AtoZ[i])==0)
        {
            return aToz[i]; 
        }
    }
    return "#";
}

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;
    while (TestCase > 0)
    {
        string AtoZ[] = {".-", "-...", "-.-.", "-..", ".", 
        "..-.", "--.", "....", "..", ".---", 
        "-.-", ".-..", "--", "-.", "---", 
        ".--.", "--.-", ".-.", "...", "-", 
        "..-", "...-", ".--", "-..-", "-.--", 
        "--.."};
        string aToz[] = {"A", "B", "C", "D", "E", 
        "F", "G", "H", "I","J", 
        "K", "L", "M", "N","O", 
        "P", "Q", "R", "S","T", 
        "U", "V", "W", "X","Y", 
        "Z"};

        string mors = "";
        fin >> mors;
        // cout << mors << endl;

        const int lenMors = mors.length();
        string MORS = "";

        string arrayInput = "";
        for(int i=0; i < lenMors; i++)
        {
            if( mors.at(i) == '|' )
            {
                // cout << arrayInput << endl;
                string str = morsToString(AtoZ, aToz, arrayInput);
                MORS += str;
                arrayInput = "";
            }
            else if ( mors.at(i) == '#')
            {
                // cout << arrayInput << endl;
                string str = morsToString(AtoZ, aToz, arrayInput);
                MORS += str;
                MORS += "_";
                arrayInput = "";
            }
            else
            {
                arrayInput += mors[i];
            }
        }

        MORS += morsToString(AtoZ, aToz, arrayInput);
        cout << MORS << endl;
        TestCase --;
    }
    return 0;
}
/*
3 
-.-.|.-|-#.-|-.|-..#-..|---|--.#..-.|..|--.|....|-
-.-.#.--.|.-.|---|--.|.-.|.-|--|--|..|-.|--.#.-..|.-|-.|--.|..-|.-|--.|. 
-.-.

CAT_AND_DOG_FIGHT 
C_PROGRAMMING_LANGUAGE 
C
*/