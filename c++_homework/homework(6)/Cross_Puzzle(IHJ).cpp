#include <iostream>
#include <fstream>

using namespace std;

int SearchWord(string str);
int main(){
    ifstream fin;
    fin.open("input.txt");
    int testCases;
    fin >> testCases;
    for(int i =0; i<testCases; ++i)
    {
        char gameArray[100][100] ={'\0',};
        int r, c;
        fin >> r >> c;
        for(int row=0; row<r; row++){
            for(int col=0; col<c; col++){
                fin >> gameArray[row][col];
            }
        }
        int wordCases;
        string wordArray[100] ={"\0",};
        int wordCom[100] = {0,};
        int u[100] = {0,};
        int v[100] = {0,};
        fin >> wordCases;
        for(int word=0; word<wordCases; word++)
        {
            fin >> wordArray[word];
            for(int rows=0; rows<r; rows++)
            {
                for(int cols=0; cols<c; cols++)
                {
                    int row = rows;
                    int col = cols;
                    int index =0; 
                    if(wordCom[word] != 0) continue;
                    if(wordArray[word][index] == gameArray[row][col])
                    {   
                        u[word] = row; v[word] =col;
                        while(wordArray[word][index++] == gameArray[row][col] && 0<= row ){row--;}
                        if(index-1==wordArray[word].length()) {wordCom[word] = 1; continue;}
                        else{ index=0; col = cols; row = rows;}
                        
                        while(wordArray[word][index++] == gameArray[row][col]&& 0<=row && col <c){row--; col++;}
                        
                        if(index-1==wordArray[word].length()) { wordCom[word] = 2; continue;}
                        else{index=0; col = cols; row = rows;}

                        while(wordArray[word][index++] == gameArray[row][col] && col <c){col++;}
                        if(index-1==wordArray[word].length()) {wordCom[word] = 3; continue;}
                        else{index=0; col = cols; row = rows;}

                        while(wordArray[word][index++] == gameArray[row][col] && row<r && col <c){row++; col++;}
                        if(index-1==wordArray[word].length()) {wordCom[word] = 4; continue; }
                        else{index=0; col = cols; row = rows;}
                        
                        while(wordArray[word][index++] == gameArray[row][col] && row<r){row++;}
                        if(index-1==wordArray[word].length()) {wordCom[word] = 5; continue;}
                        else{index=0; col = cols; row = rows;}

                        while(wordArray[word][index++] == gameArray[row][col]&& row<r && 0<=col){row++; col--;}
                        if(index-1==wordArray[word].length()) {wordCom[word] = 6; continue;}
                        else{index=0; col = cols; row = rows;}

                        while(wordArray[word][index++] == gameArray[row][col]&& 0<=col ){col--;}
                        if(index-1==wordArray[word].length()) {wordCom[word] = 7; continue;}
                        else{index=0; col = cols; row = rows;}

                        while(wordArray[word][index++] == gameArray[row][col] && 0<=row && 0<=col){row--; col--;}
                        if(index-1==wordArray[word].length()) {wordCom[word] = 8; continue;}

                    }
                    
                } 
            }
        }
        for(int word=0; word<wordCases; word++)
        {
            if(wordCom[word] ==0){ cout << wordCom[word]-1<< endl;}
            else{
                cout << u[word]+1 << " " << v[word]+1 << " "<<wordCom[word]-1 <<endl;
            }
        }
    }
    fin.close();
    return 0;
}
