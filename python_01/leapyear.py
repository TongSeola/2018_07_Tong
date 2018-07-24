i = int(input("which year? "))

if i%400==0 or i%4==0 and i%100!=0 :
    print ("one line : leapyear/윤년")
else : print("아무것도 아님 ㅋㅋㅋ")

# 위에 꺼라 똑같은 것인데 여러줄로 늘린거임
if i%400==0 :
    print ("not one line first : leapyear/윤년")
elif i%100==0 :
    # pass의 경우 완전히 밖으로 나오게 만듦
    # continue의 경우 다음 문으로 이어져서 나옴
    pass
elif i%4==0 :
    print("not one line second : leapyear/ 윤년")
else :
    pass

    
