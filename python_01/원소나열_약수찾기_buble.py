numberlist = [4,6,9,2,6,3,0,1]

def arrange_list(rangelist) :
    ''' 주어진 리스트(rangelist)의 원소를 크기순서로 정리한다
        buble함수로 '''

    for i in range (len(rangelist)) :
        for k in range (len(rangelist)-i-1) :
            if rangelist[k] > rangelist[k+1] :
                rangelist[k], rangelist[k+1] = rangelist[k+1], rangelist[k]
    return rangelist


import math
n = int(input("n="))

def find_divisor(num) :
    '''주어진 수(num)까지 약수를 프린트한다'''

    lootn = int(math.sqrt(num))
    # 리스트속에 받은 n보다 2개 많은 원소를 0으로 넣는다
    memo = [0 for i in range(num+2)]
    print("memo list : ",memo)

    # 1은 약수가 될 수 없으므로 2부터 시작한다
    for i in range(2,lootn+1) :
        if memo[i]==0 :
            j=2
            while i*j<num:
                memo[i*j]=1
                j+=1
    for i in range(2,num+1):
        if memo[i] ==0 :
            print(i)

find_divisor(n)

