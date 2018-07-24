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
        pNepi.append(num) #리스트에 넣는다

    print("binary list is : ", pNepi)
    print()

    distingExit = 1 # 곁치는 것이 있었는지 확인
    diffpEpipNepi = 0 # 몇번째 돌아간건지
    while distingExit != 0 :
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''
        diffpEpipNepi = diffpEpipNepi + 1
        # 혹시 모르니 따로 저장해 둔다
        pastedpEpi = pEpi
        pastedpNepi = pNepi

        nowpNepi = pNepi

        lenpNepi = len(pNepi)-1 #현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        #초기화
        pEpi = []
        pNepi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi) :
            ele1 = nowpNepi[location]
            if ele1 == '[]':
                #예외처리
                continue
            else:
                #뒤에 것들을 차례대로 검사한다
                for index in range(location+1, lenpNepi+1) :
                    #위의 것이랑 같게 로테이션 된다
                    ele2 = nowpNepi[index]
                    diff = 0
                    if ele2 == '[]':
                        continue

                    for i in range(Length_ele):
                        if ele1[i] != ele2[i]:
                            diff = diff + 1

                    if diff == 1:
                        binNum = ""
                        for i in range(Length_ele):
                            if ele1[i] == ele2[i]:
                                binNum += ele1[i]
                            else:
                                binNum += '-'

                        #1개가 다른것이 발견되면 distingExit를 증가 시킨다 = 2가 된다
                        distingExit += 1

                        if binNum not in pNepi :
                            pNepi.append(binNum)

                        if ele1 not in used:
                            used.append(ele1)
                        if ele2 not in used:
                            used.append(ele2)

                    else:
                        if ele1 not in used:
                            if ele1 not in pEpi:
                                pEpi.append(ele1)
                        if ele2 not in used:
                            if ele2 not in pEpi:
                                pEpi.append(ele2)

        # 첫번째 for문 끝내고
        # 만약 1곳만 겹치는것이 한개도 없는 경우
        # 이전의 것을 가져온다 pNepi / pEpi
        if distingExit == 1 :
            distingExit = 0
            pNepi = pastedpNepi
            pEpi = pastedpEpi
        else :
            distingExit = 1

        for ele in pEpi :
            # print("존재의 요소 : ", ele)
            if ele in used :
                # print("Delete : ", ele)
                pEpi.remove(ele)
# 왜 다 안지워 지는 지 모르겠다

        print("used : ", used)
        print("pEpi : ", pEpi)
        print("pNepi : ", pNepi)
        print()

    # 최종 출력
    for ele in pEpi:
        # print("존재의 요소 : ", ele)
        if ele in used:
            # print("Delete : ", ele)
            pEpi.remove(ele)

    print("몇번 검사했는지", diffpEpipNepi)
    if diffpEpipNepi <= 2 :
        print("final used : ", used)
        print("final pEpi : ", pEpi)
        print("final pNepi : ", pNepi)
    else :
        # 여러번 병합?이 진행된 경우
        print("final used : ", used)
        print("final pEpi : ", pNepi)
        print("final pNepi : ", pEpi)
    print()

    inputs = input("Please input just int : ")
    print()


    # numList = []
    # 바이너리 에서 1의 갯수가 몇재인지에 따라 나누어서 리스트에 넣는다
    # zeroList = []
    # oneList = []
    # twoList = []
    # threeList = []
    # fourList = []
    # fiveList = []
    # sixList = []
    #
    # for binStr in numList :
    #     count = 0
    #     #1의 갯수를 센다
    #     for i in range(Length_ele) :
    #         if(binStr[i] == '1'):
    #             count = count+1
    #
    #     if count == 0 :
    #         zeroList.append(binStr)
    #     elif count == 1 :
    #         oneList.append(binStr)
    #     elif count == 2 :
    #         twoList.append(binStr)
    #     elif count == 3 :
    #         threeList.append(binStr)
    #     elif count == 4 :
    #         fourList.append(binStr)
    #     elif count == 5 :
    #         fiveList.append(binStr)
    #     else:
    #         sixList.append(binStr)
    #
    # # print ("0개 리스트: ", zeroList)
    # # print ("1개 리스트: ", oneList)
    # # print ("2개 리스트: ", twoList)
    # # print ("3개 리스트: ", threeList)
    # # print ("4개 리스트: ", fourList)
    # # print ("5개 리스트: ", fiveList)
    # # print ("6개 리스트: ", sixList)
    # #여기 까지가 나누기
    #
    # #한칸씩 밀려서 넣는다 실제 존재 보다 1개 적게 만들기
    # pEpi1 = [zeroList, oneList, twoList, threeList, fourList, fiveList]
    # pEpi2 = [oneList, twoList, threeList, fourList, fiveList, sixList]
    #
    # for location in range(Length_ele) :
    #     for ele1 in pEpi1[location] :
    #         if ele1 == '[]' :
    #             continue
    #         else :
    #             for ele2 in pEpi2[location] :
    #                 diff = 0
    #                 if ele2 =='[]' :
    #                     continue
    #                 # print("ele1 = ", ele1)
    #                 # print("ele2 = ", ele2)
    #                 # 두개의 원소의 다른 곳이 1곳만 있는 것 찾아내기 (한곳만 다르면 diff=1 다르면 diff !=1)
    #                 for i in range(Length_ele) :
    #                     if ele1[i] != ele2[i] :
    #                         diff = diff +1
    #                 # 만약 1곳 만 다르다면 다른 곳에 - 넣고 바뀌었다고 말해주기
    #                 if diff == 1 :
    #                     binNum = ""
    #                     for i in range(Length_ele) :
    #                         if ele1[i] == ele2[i] :
    #                             binNum += ele1[i]
    #                         else:
    #                             binNum += '-'
    #
    #                     pNepi.append(binNum)
    #                     #이전에 사용한 적이 없다면 사용했다고 알려라(리스트에 넣는다)
    #                     if ele1 not in used :
    #                         used.append(ele1)
    #                     if ele2 not in used :
    #                         used.append(ele2)
    #
    #                 else :
    #                     # 만약 두개의 원소가 다르다면
    #                     # 이전에 사용하지 않았다면
    #                     if ele1 not in used :
    #                         if ele1 not in pEpi:
    #                             pEpi.append(ele1)
    #                     if ele2 not in used :
    #                         if ele2 not in pEpi :
    #                             pEpi.append(ele2)
    #
    # for ele_pE in pEpi :
    #     if ele_pE in used :
    #         pEpi.remove(ele_pE)
    #
    # print("1단계 합친 후 used : ", used)
    # print("1단계 합친 후 pEpi : ", pEpi)
    # print("1단계 합친 후 pNepi : ", pNepi)
    # print()