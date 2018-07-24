#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include "MyTriangle.h" 
using namespace std; 

int main() 
{ 
    ifstream inStream; 
    int numTestCases; 
    inStream.open("input.txt"); 
    if (inStream.fail()) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    } 
    inStream >> numTestCases; 
    
    for(int i=0; i<numTestCases; i++) 
    { 
        int p1x, p1y, p2x, p2y, p3x, p3y; 
        int qx, qy; 
        inStream >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y; 
        inStream >> qx >> qy; 

        MyPoint p1(p1x, p1y); 
        MyPoint p2(p2x, p2y);
        MyPoint p3(p3x, p3y); 
        MyPoint q(qx, qy); 

        MyTriangle tri(p1, p2, p3); 

        if(tri.getArea2() == 0) 
            cout << "0" << endl; 
        else 
        {
            // 만든 삼각현의 면적의 2개의 수
            cout << tri.getArea2() << " "; 
            // 정-1 직각-2 이등-3 일반-4 / 직각-1 둔각-2 예각-3 
            cout << tri.getType1() << " " << tri.getType2() << " "; 
            // 마지막점이 내부-1 면-2 외부-3
            if(tri.isInside(q)) 
                cout << "1" << endl; 
            else if(tri.isOnBoundary(q)) 
                cout << "2" << endl; 
            else if(tri.isOutside(q)) 
                cout << "3" << endl; 
        } 
    } 
    inStream.close(); 
    return 0;
}