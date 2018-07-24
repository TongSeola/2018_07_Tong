#include <iostream>
#include <fstream>
using namespace std;
// Y M D
// 1582<= Y <=99999, 1<=M<=12, 1<=D<=31
// 1582년 1월 1일 = 금요일 =5
// 일요일-0 월요일-1 ... 토요일-6

int main()
{
    fstream fin;
    fin.open("input.txt");
    int TestCase = 0;
    fin >> TestCase;

    while(TestCase > 0)
    {
        int Year = 0;
        int Month = 0;
        int Day = 0;
        int dates = 0;

        fin >> Year >> Month >> Day;
        // cout << "년 : " << Year << " 달 : " << Month << " 일 : " << Day << endl;

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

        // 30일-2 31일-3 29일-1 28일-0
        if(Yyear)
        {
            // cout << "윤달입니다" << endl;
            // 2월 29일
            for(int i=1 ; i < Month; i++)
            {
                if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) 
                    dates +=3;
                else if (i==2)
                    dates +=1;
                else
                    dates +=2;
            }
            dates = dates%7;
        }
        else
        {
            //2월 28일
            for(int i=1 ; i < Month; i++)
            {
                if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12) 
                    dates +=3;
                else if (i==2)
                    dates +=0;
                else
                    dates +=2;
            }
            dates = dates%7;
        }
        // cout << "달까지 계산 : " << dates << endl;
        dates += Day;
        dates = dates%7;

        cout << dates << endl;

        TestCase--;
    }
    return 0;
}

/*
2
0
6
5
*/