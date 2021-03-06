/*
8개의 정수가 입력되고 앞의 4개가 1개 선분의 xy가 된다
-100 ~ 100

교차하지 않으면 0 완전교차 1 불완전 교차 2(교차점이 꼭짓점 or 1점 이상이 일치)

삼각형 면적 구하기를 이용하면 쉽겠다.
위면 양수 아래면 음수 선분에 있으면 0

5 
0 0 4 4 0 10 10 0 
0 0 10 10 0 10 10 0 
0 0 10 10 0 10 5 5 
0 0 5 5 10 0 5 5 
0 0 10 10 5 5 15 15 

0 
1 
2 
2 
2 
*/

/*
삼각형
앞의 3개는 삼각형
(2차원 점 선분교차 삼각형 면적 삼각형 종류 이용)

삼각형을 못만든 경우 0 
만들 수 있는 경우 삼각형면적의 2배 수 출력 
/ 정-1 직각-2 이등-3 일반-4 
/ 직각-1 둔각-2 예각-3 
/마지막점이 내부-1 면-2 외부-3

5 
-1 -1 0 0 1 1 1 1 
0 0 5 0 0 5 2 2 
0 0 5 0 -5 5 0 5 
1 1 3 2 2 3 3 2 
0 0 5 0 0 5 4 0

0 
25 2 1 1 
25 4 2 3 
3 3 3 2 
25 2 1 2
*/

/*
디지털 시계
-10000 ~10000

3 
01:59PM 1 
01:59PM -1 
01:59PM 1000 

02:00PM  
01:58PM  
06:39AM 
*/

/*
2차원 점
직선거리 : 빼기의 제곱 각 더하고 루트 씌우기
직각거리 : 빼기의 각 더하기(절댓값)

두점의 위치가 같은 경우 - 1
그렇지 않은 경우 -0
직선거리의 제곱 출력 / 직각 거리 출력
첫번째 점의 xy바꾼 것과의 직선거리 제곱 출력 / 지각거리 출력

3 
1 2 1 2 
4 3 2 1 
2 -3 3 7 

1 0 0 2 2 
0 8 4 2 2 
0 101 11 50 10 
*/