import math
n = int(input("number="))

def make_squre(n,m) :
    ''' 주어진 n(세로),m(가로)수의 사각형 * 찍어내기'''

    for i in range (n) : #세로개수
        for j in range (m) : # 가로개수
            # end=""를 적으면 다음줄이 아닌 옆에 다음 print문이 적힘
            print ("*",end="")
        # 가로개수의 프린트 이후 enter역활
        print ()

def find_divisor(n) :
    '''주어진 수(n)가 약수인지 확인하는 함수 '''

    #sqrt()함수는 math의 내장함수로 루트를 씌운다(제곱근찾기?) int로 소수점 내림처리됨
    a = int(math.sqrt(n))

    for i in range (2,a+1) :
        if n%i==0 :
            print("약수 아님")
            break
    print ("약수")

def find_joha(n) :
    '''주어진수(n)에 대하여 조화수열의 합을 ouput하는 함수'''
    sum = 0
    for i in range (1,n) :
        sum=+1/i
    return sum

print("약수판별 : ",end="")
find_divisor(n)
print("조화수열 : ",find_joha(n))
print("정사각형 만들기 : ")
make_squre(n,n)