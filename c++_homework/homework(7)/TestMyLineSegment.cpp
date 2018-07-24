#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include "MyLineSegment.h" 
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
        int x1, y1, x2, y2, x3, y3, x4, y4 ;
        inStream >> x1 >> y1 >> x2 >> y2;
        MyPoint Point1(x1, y1);
        MyPoint Point2(x2, y2);
        MyLineSegment firstLine(Point1, Point2);
        
        inStream >> x3 >> y3 >> x4 >> y4 ;
        MyPoint Point3(x3, y3);
        MyPoint Point4(x4, y4);
        MyLineSegment secondLine(Point3, Point4);

        if(firstLine.improperIntersection(secondLine) || secondLine.improperIntersection(firstLine)) cout << 0 << endl;
        else if(firstLine.properIntersection(secondLine) && secondLine.properIntersection(firstLine)) cout << 1 << endl;
        else cout << 2 << endl;
    } 
    inStream.close(); 
    return 0;
}

/*
8개의 정수가 입력되고 앞의 4개가 1개 선분의 xy가 된다
-100 ~ 100

교차하지 않으면 0 완전교차 1 불완전 교차 2(교차점이 꼭짓점 or 1점 이상이 일치)
0 
1 
2 
2 
2 
*/