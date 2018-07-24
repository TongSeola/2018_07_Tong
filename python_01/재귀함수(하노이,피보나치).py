
def add (thing) :
    "0부터 input받은 thing까지 더한 값이 output으로 나오는 함수"
    pluse_number=0
    for i in range (1,thing+1) :
        pluse_number = pluse_number+i
    return pluse_number

thing = int(input("add k="))
print ("0~",thing,"add is : ",add(thing))

##################################################################################

def H(m) :
    '''하노이탑을 옮기기위한 최소로 움직이는 번수
       m을 input받으면 m에 대한 하노이탑수가 ouput된다'''
    if m==1 :
        return 1
    else :
        return 2*H(m-1) + 1

m=int(input("hanoitop m ="))
print("Hanoitop number of ",m," is : ",H(m))

################################################################################33

def fibonachi(n) :
    '''재귀함수(recursive)를 이용하여 피보나치 수열을 만듦
       n을 input받으면 n에 대한 피보나치수가 output된다'''
    if (n==1) or (n==2) :
        return 1
    else :
        return fibonachi(n-1) + fibonachi(n-2)

n = int(input("fibonachi n ="))
print ("Input number is : ",n,"\nAnd output number is : ",fibonachi(n))
