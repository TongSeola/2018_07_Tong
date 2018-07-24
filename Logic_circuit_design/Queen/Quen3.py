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
    pastedpNepi = []
    pastedpEpi = []
    ppastedN = []
    ppastedE = []

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
    diffpEpipNepi = 0 # 몇번째 돌아간건지
    while distingExit != 0 :
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''

        ppastedE = pastedpEpi
        pastedpEpi = pEpi

        nowpEpi = pEpi

        lenpNepi = len(pEpi)-1 #현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        #초기화
        pEpi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi) :
            ele1 = nowpEpi[location]
            if ele1 == '[]':
                #예외처리
                continue
            else:
                #뒤에 것들을 차례대로 검사한다
                for index in range(location+1, lenpNepi+1) :
                    ele2 = pastedpEpi[index]
                    diff = 0
                    if ele2 == '[]':
                        continue

                    for i in range(Length_ele):
                        if ele1[i] != ele2[i]:
                            diff = diff + 1

                    if diff == 1:
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
                        # print("Make binNum : ",ele1, " ", ele2, "->", binNum)
                        if binNum not in pEpi :
                            pEpi.append(binNum)

                    else:
                        if ele1 not in used :
                            if ele1 not in pastedpEpi:
                                pNepi.append(ele1)
                        if ele2 not in used :
                            if ele2 not in pastedpEpi:
                                pNepi.append(ele2)

                        if ele1 not in used :
                            used.append(ele1)
                        if ele2 not in used :
                            used.append(ele2)

        if distingExit == 1 :
            # 병합이 한개도 이루어지지 않았다.
            # 1이면 pEpi로 들어간다
            if diffpEpipNepi < 2:
                pNepi = pastedpEpi
                pEpi = []
            else :
                pEpi = pastedpEpi
            distingExit = 0
        else :
            diffpEpipNepi = diffpEpipNepi + 1
            # 병합이 한개 이상 발생하였다.
            distingExit = 1


    #오름차순으로 정렬하자
    EupgoList =[]
    NupgoList = []
    for i in range((2**Length_ele -1)*2) :
        EupgoList.append(-1)
        NupgoList.append(-1)

    for ele in pEpi :
        index = 0
        for i in range(Length_ele) :
            if ele[i] == '-' :
                index = index + 2*(2**(Length_ele-i-1))
            else :
                index = index + int(ele[i])*(2**(Length_ele-i-1))
        EupgoList[index] = ele

    for ele in pNepi :
        index = 0
        for i in range(Length_ele) :
            if ele[i] == '-' :
                index = index + 2*(2**(Length_ele-i-1))
            else :
                index = index + int(ele[i])*(2**(Length_ele-i-1))
        NupgoList[index] = ele

    finalList = []
    finalList.append("pEpi")
    for ele in EupgoList :
        if ele == -1 :
            continue
        else:
            finalList.append(ele)

    finalList.append("pNepi")
    for ele in NupgoList :
        if ele == -1 :
            continue
        else:
            finalList.append(ele)

    print("Final List is : ",finalList)
    print()

    inputs = input("Please input just int : ")
    print()
