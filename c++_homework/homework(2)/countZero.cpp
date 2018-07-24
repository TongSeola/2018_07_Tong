#include<iostream>
#include<fstream>
using namespace std;

void CountTwo(int multi, int* pcountTwo, int* pothers){
    
    while (multi%2 !=0){
            multi = multi/2;
            (*pcountTwo)++;
            cout << "2로 나눈이후 : " << multi << endl;
    }
    *pothers =multi;
}

void CountFive(int multi, int* pcountFive, int* pothers){
    
    while (multi%5 !=0){
            multi = multi/5;
            (*pcountFive)++;
            cout << "5로 나눈이후 : " << multi << endl;
    }
    *pothers = multi;
    cout << "남은 값들 : " << multi << endl;
}

int main()
{//주어진 수들을 곱한 후 0이 아닌 마지막 수 + 총 0의 개수 구하기
    fstream fin;
    fin.open("input.txt");
    int lineCount = 0;
    
    fin >> lineCount;
    while (lineCount > 0 )
    {
        int howManyNumber=0;
        fin >> howManyNumber;

        int countZero = 0;
        int countTwo = 0;
        int* pcountTow = &countTwo;
        int countFive = 0;
        int* pcountFive = &countFive;
        int collect =1;
        int towFivemiss = 0;


        while(howManyNumber > 0){
            int multi=1;
            fin >> multi;
            cout << "받는 수 : " << howManyNumber << endl;

            int others;
            int* pothers = &others;

            CountTwo(multi, pcountTow, pothers);
            CountFive(others, pcountFive, pothers);

            collect *= others;
            collect = collect%10;
            cout << "남은 값들곱의 마지막 값 : " << collect << endl;
        }


        if(countFive < countTwo) {
            countZero = countFive;
            towFivemiss = countTwo- countFive;

            cout << "10의 갯수 : " << countZero << endl;
            for (int i=0; i < towFivemiss; i++){
                collect *= 2;
                collect = collect%10;
                cout << "남은 값들의 곲의 마지막 값 : " << collect << endl;
            }
        }
        else { 
            countZero = countTwo;
            towFivemiss = countFive - countTwo;

            cout << "10의 갯수 : " << countZero << endl;
            for (int i=0; i < towFivemiss; i++){
                collect *= 5;
                collect = collect%10;
                cout << "남은 값들의 곲의 마지막 값 : " << collect << endl;
            }
        }

        cout << collect%10 << " " << countZero << endl;

        lineCount--;
    }

    return 0;
}