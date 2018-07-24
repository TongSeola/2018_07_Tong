#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
 
int main()
{
	fstream fin;
	fin.open("input.txt");
	
	int TestCase = 0;
	fin >> TestCase;
 
	while (TestCase > 0)
	{
	    int zerone = -1;
	    fin >> zerone;
	    
	    int data = -1;
        fin >> data;
        const int originData = data;
        // cout << data << endl;
        
        int binArray[33] = {0, };
        int hamingArray[33] = {0, };
        
        if(zerone == 0)
        {
            int len = 1; // len = 해밍수의 길이
            for(int i=1; data > 0; i++)
            {
                int binary = data%2;
                if(len==1) len ++;
                if(len==2) len ++;
                if(len==4) len ++;
                if(len==8) len ++;
                if(len==16)len ++;
                hamingArray[len] = binary; // 1 2 4 8 16을(0넣음) 제외한 곳에 차례대로 이진수 넣음
                data /= 2;
                len ++;
            }

            bool b1 = false;
            bool b2 = false;
            bool b4 = false;
            bool b8 = false;
            bool b16 = false;
            int countOne1 = 0;
            int countOne2 = 0;
            int countOne4 = 0;
            int countOne8 = 0;
            int countOne16 = 0;
            for(int i =1; i < len; i++)
            {
                b1 = !b1;
                if(i%2 == 0)
                {
                    b2 = !b2;
                    if(i%4 == 0)
                    {
                        b4 = !b4;
                        if(i%8 == 0)
                        {
                            b8 = !b8;
                            if(i%16 == 0)
                            {
                                b16 = !b16;
                }}}}
                
                if(hamingArray[i] == 1)
                {
                    if(i==1 && b1) countOne1 --;
                    if(i==2 && b2) countOne2 --;
                    if(i==4 && b4) countOne4 --;
                    if(i==8 && b8) countOne8 --;
                    if(i==16 && b16) countOne16 --;
                    if(b1) countOne1 ++;
                    if(b2) countOne2 ++;
                    if(b4) countOne4 ++;
                    if(b8) countOne8 ++;
                    if(b16) countOne16 ++;
                }
            }
            // cout << countOne1 << " " << countOne2 << " " << countOne4 << " " << countOne8 << " " << countOne16 << endl;

            if(countOne1%2 == 0) hamingArray[1] = 0;
	        else hamingArray[1] = 1;

	        if(countOne2%2 == 0) hamingArray[2] = 0;
	        else hamingArray[2] = 1;

	        if(countOne4%2 == 0) hamingArray[4] = 0;
	        else hamingArray[4] = 1;

	        if(countOne8%2 == 0) hamingArray[8] = 0;
	        else hamingArray[8] = 1;

	        if(countOne16%2 == 0) hamingArray[16] = 0;
	        else hamingArray[16] = 1;

            int result = 0;
            for(int i=1; i < len; i++)
            {
                result += hamingArray[i]*pow(2,(i-1));
            }
            cout << result << endl;
        }
// =====================================================================
        if(zerone == 1)
        {
            int len = 1;
            // len = 해밍수의 길이
            for(int i=1; data > 0; i++)
            {
                int binary = data%2;
                hamingArray[i] = binary;
                data /= 2;
                len ++;
            }
            // for(int i=1; i<len; i++) 
            // {
            //     if (i%2 == 0) cout << " ";
            //     cout << hamingArray[i];
            // }
            // cout << endl;

            bool b1 = false;
            bool b2 = false;
            bool b4 = false;
            bool b8 = false;
            bool b16 = false;
            int countOne1 = 0;
            int countOne2 = 0;
            int countOne4 = 0;
            int countOne8 = 0;
            int countOne16 = 0;
            for(int i =1; i < len; i++)
            {
                b1 = !b1;
                if(i%2 == 0)
                {
                    b2 = !b2;
                    if(i%4 == 0)
                    {
                        b4 = !b4;
                        if(i%8 == 0)
                        {
                            b8 = !b8;
                            if(i%16 == 0)
                            {
                                b16 = !b16;
                }}}}
                
                if(hamingArray[i] == 1)
                {
                    // if(i==1 && b1) countOne1 --;
                    // if(i==2 && b2) countOne2 --;
                    // if(i==4 && b4) countOne4 --;
                    // if(i==8 && b8) countOne8 --;
                    // if(i==16 && b16) countOne16 --;
                    if(b1) countOne1 ++;
                    if(b2) countOne2 ++;
                    if(b4) countOne4 ++;
                    if(b8) countOne8 ++;
                    if(b16) countOne16 ++;
                }

                // if(binArray[1] == 1) countOne1 ++;
                // if(binArray[2] == 1) countOne2 ++;
                // if(binArray[4] == 1) countOne4 ++;
                // if(binArray[8] == 1) countOne8 ++;
                // if(binArray[16] ==1) countOne16 ++;
            }
            // cout << "count things : " << countOne1 << " " << countOne2 << " " << countOne4 << " " << countOne8 << " " << countOne16 << endl;
            
            int index = 0; // 짝수가 아닌경우 index 증가
            if(countOne1%2 != 0) index +=1;
            if(countOne2%2 != 0) index +=2;
            if(countOne4%2 != 0) index +=4;
            if(countOne8%2 != 0) index +=8;
            if(countOne16%4 !=0) index +=16;
            // cout << index << " : " << hamingArray[index] <<  endl;
            
            if(hamingArray[index] == 0) hamingArray[index] = 1;
            else if(hamingArray[index] == 1) hamingArray[index] = 0;
            // cout << index << " : " << hamingArray[index] <<  endl;

            int result = 0;
            int powCount = 0;
            for (int i=1; i < len; i++)
            {
                if (i !=1 && i!=2 && i!=4 && i!=8 && i!=16)
                {
                    result += hamingArray[i]*pow(2,powCount);
                    powCount ++;
                }
            }
            cout << result << endl;
        }

		TestCase --;
	}
	return 0;
}
/*
3
0 47367638
1 1515773369
1 1482218937

1515773369
47367638
47367638
*/
