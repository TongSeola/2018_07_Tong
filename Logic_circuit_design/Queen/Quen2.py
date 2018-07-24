inputs = input("Please input just int : ")
print()

while(inputs != "end") :
    '''end라고 입력하기 전가지 계속한다'''

    ListInput = inputs.split(" ") #enter를 기준으로 나눈다

    Length_ele = int(ListInput[0]) #첫번째 수 = 몇자리 바이너리로 만들지 결정
    Elements = int(ListInput[1]) #몇개의 숫자가 들어올지

    #앞에서 사용되는 두개의 정수를 제외한 것들을 새로운 리스트에 넣을려고 함
    listLen = len(ListInput)-2
    used = [] # 사용한것
    pEpi = [] # 사용하지 않은 것
    pNepi = [] # 사용한 이후 - 붙인 것

    # 바이너리 값으로 numList에 넣는다
    for i in range(listLen) :
        if(i == " " or i == "") :
            # 엔터는 제외한다
            continue
        # 바이너리 숫자로 바꾼 이후 앞의 0b는 뺀다(int -> bin -> string)
        intnum = int(ListInput[2+i])
        num = str(bin(intnum))
        num = num[2:]

        # 이후 모두 같은 길이로 맞춰 준다
        lenNum = len(num)
        num = "0"*(Length_ele-lenNum) + num #앞에 부족한 만큼 0 넣기
        pEpi.append(num) #리스트에 넣는다

    print("binary list is : ", pEpi)
    print()

    distingExit = 1 # 곁치는 것이 있었는지 확인
    # diffpEpipNepi = 0 # 몇번째 돌아간건지
    while distingExit != 0 :
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''
        # print("[",diffpEpipNepi, "]" , " pEpi : ", pEpi)
        # print("[",diffpEpipNepi, "]" ," pNepi : ", pNepi)

        # diffpEpipNepi = diffpEpipNepi + 1
        # 혹시 모르니 따로 저장해 둔다
        pastedpEpi = pEpi
        # pastedpNepi = pNepi

        nowpEpi = pEpi

        lenpNepi = len(pEpi)-1 #현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        #초기화
        pEpi = []
        # pNepi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi) :
            ele1 = nowpEpi[location]
            if ele1 == '[]':
                #예외처리
                continue
            else:
                #뒤에 것들을 차례대로 검사한다
                for index in range(location+1, lenpNepi+1) :
                    #위의 것이랑 같게 로테이션 된다
                    ele2 = nowpEpi[index]
                    diff = 0
                    if ele2 == '[]':
                        continue

                    for i in range(Length_ele):
                        if ele1[i] != ele2[i]:
                            diff = diff + 1

                    if diff == 1:
                        # 1개가 다른것이 발견되면 distingExit를 증가 시킨다 = 2가 된다
                        distingExit += 1

                        # 사용한것들은 used 넣기
                        if ele1 not in used:
                            used.append(ele1)
                        if ele2 not in used:
                            used.append(ele2)

                        # -를 붙여서 pEpi에 넣기
                        binNum = ""
                        for i in range(Length_ele):
                            if ele1[i] == ele2[i]:
                                binNum += ele1[i]
                            else:
                                binNum += '-'
                        # print("find binNum : ", binNum)
                        if binNum not in pEpi :
                            # print("E append : ", binNum)
                            pEpi.append(binNum)

                    else:
                        # 전에 pEpi에 들어간거로 사용된지 확인 후
                        # 사용하지 않았으며 pNepi로 넣는다.
                        if (ele1 not in used) and (ele1 not in pNepi) and (ele1 not in pEpi):
                            # print("N append : ", ele1)
                            pNepi.append(ele1)
                        if (ele2 not in used) and (ele2 not in pNepi) and (ele2 not in pEpi):
                            # print("N append: ", ele2)
                            pNepi.append(ele2)

        # 첫번째 for문 끝내고
        # 만약 1곳만 겹치는것이 한개도 없는 경우
        # 이전의 것을 가져온다 pNepi / pEpi
        if distingExit == 1 :
            distingExit = 0
            # pNepi = pastedpNepi
            # pEpi = pastedpEpi
        else :
            distingExit = 1

    print("final used : ", used)
    print("final pEpi : ", pEpi)
    print("final pNepi : ", pNepi)
    print()

    inputs = input("Please input just int : ")
    print()
