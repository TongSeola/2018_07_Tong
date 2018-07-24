a = int(input("a= "))
b = int(input("b= "))

def find_greates_common_divisor(a,b) :
    '''최대공약수를 알아내는 방법'''

    while (b!=0) : # if a=14 b=7
        x=a      #14
        a=b      #7 -> output
        b=x%b    #14%7=0

    return ("%d" %a)

print(find_greates_common_divisor(a,b))

