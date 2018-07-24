
def find_big_small (list) :
    '''list안에 있는 숫자 원소 중 가장 크고 작은 수를 알려준다'''
    big = list[0]
    small = list[0]

    for i in list :
        if big <= i :
            big = i
        else :
            continue
        if small >= i :
            small =i
        else :
            continue

    print("The big one is : ",big)
    print("The small one is : ",small)

print("enter 5 number!")
list_5 =[]
for num in range(5) :
    number = int(input("Enter the number : "))
    list_5.append(number)

find_big_small(list_5)

