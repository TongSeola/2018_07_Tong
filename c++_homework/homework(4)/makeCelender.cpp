#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while(TestCase > 0)
    {
        int Year;
        int Month;
        fin >> Year >> Month;

        int dates = 0;
        bool Yyear = false; // 주어진 년도가 윤년인지 확인 true - 윤년
        if(Year%4 == 0 )
        {
            Yyear = true;
            if(Year%100 == 0)
            {
                Yyear = false;
                if (Year%400 == 0)
                {
                    Yyear = true;
                }
            } 
        }
        int years = 1582; // 기준에서 몇개인지
        int countY = 0; // 윤년갯수 세기
        for ( years ; years < Year ; years++)
        {
            if(years%4 == 0 )
            {
                countY++;
                if(years%100 == 0)
                {
                    countY--;
                    if(years%400 == 0)
                    {
                        countY++;
                    }
                } 
            }
            dates +=1;
        }

        // 365일 - 1 366일 - 2
        dates += (countY + 4); // 요일수 정하기 -> 0인경우 금요일 -> +4
        dates = dates%7;
        // cout << "년까지 계산 : " << dates << endl;
        // cout << "요일은 : " << dates << endl;

        int howManyDays = 0;
        // 30일-2 31일-3 29일-1 28일-0
        if(Yyear)
        {
            // cout << "윤달입니다" << endl;
            // 2월 29일
            if(Month==1 || Month==3 || Month==5 || Month==7 || Month==8 || Month==10 || Month==12)
                howManyDays = 31;
            else if (Month == 2)
                howManyDays = 29;
            else    
                howManyDays = 30;
            for(int i=1 ; i < Month; i++)
            {
                if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) 
                {
                    dates +=3;
                }
                else if (i==2)
                {
                    dates +=1;
                }
                else
                {
                    dates +=2;
                }
            }
            dates = dates%7;
        }
        else
        {
            //2월 28일
            if(Month==1 || Month==3 || Month==5 || Month==7 || Month==8 || Month==10 || Month==12)
                howManyDays = 31;
            else if (Month == 2)
                howManyDays = 28;
            else    
                howManyDays = 30;
            for(int i=1 ; i < Month; i++)
            {
                if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) 
                {
                    dates +=3;
                }
                else if (i==2)
                {
                    dates +=0;
                }
                else
                {
                    dates +=2;
                }
            }
            dates = dates%7;
        }
        // cout << "달까지 계산 : " << dates << endl;
        dates = (dates+1)%7;

        int days = howManyDays + dates;
        while (days%7 != 0)
        {
            days ++;
        }

        const int len = days;
        int* pArray = new int[len];
        for(int i=0; i<len; i++)
        {
            pArray[i] = 0;
        }
// 확인
        int index = 0;
        // for(int j=0; j < (len+1)/7; j++)
        // {
        //     for(int i=0; i < 7; i++)
        //     {
        //         cout << pArray[index] << " ";
        //         index ++;
        //     }
        //     cout << endl;
        // }

        for(int i = (howManyDays+dates-1) ; i > (dates-1) ; i--)
        {
            // cout << "넣을 장소" << i << "넣을 숫자" << howManyDays << endl;
            pArray[i] = howManyDays;
            howManyDays--;
        }
// cout << "=============달력 ================================" << endl;
        cout << Year << " " << Month << endl;
        index = 0;
        for(int j=0; j < (len+1)/7; j++)
        {
            for(int i =0; i < 7; i++)
            {
                cout << pArray[index] << " ";
                index ++;
            }
            cout << endl;
        }
// cout << "=============NEXT ================================" << endl;

        delete[] pArray;
        TestCase--;
    }
    return 0;
}

/*
1582 1
0 0 0 0 0 1 2 
3 4 5 6 7 8 9
10 11 12 13 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 30
31 0 0 0 0 0 0
2003 9
0 1 2 3 4 5 6
7 8 9 10 11 12 13
14 15 16 17 18 19 20
21 22 23 24 25 26 27
28 29 30 0 0 0 0
99999 12
0 0 0 1 2 3 4
5 6 7 8 9 10 11
12 13 14 15 16 17 18
19 20 21 22 23 24 25
26 27 28 29 30 31 0 
*/