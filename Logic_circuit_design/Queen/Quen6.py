def solution(input):
    Length_ele = int(input[0])  # 첫번째 수 = 몇자리 바이너리로 만들지 결정
    Elements = int(input[1])  # 몇개의 숫자가 들어올지

    # 앞에서 사용되는 두개의 정수를 제외한 것들을 새로운 리스트에 넣을려고 함
    listLen = len(input) - 2
    used = []  # 사용한것
    pEpi = []  # 사용하지 않은 것
    pNepi = []  # 사용한 이후 - 붙인 것
    pastedpNepi = []
    pastedpEpi = []
    ppastedN = []
    ppastedE = []

    # 바이너리 값으로 numList에 넣는다
    for i in range(listLen):
        if (i == " " or i == ""):
            # 엔터는 제외한다
            continue
        # 바이너리 숫자로 바꾼 이후 앞의 0b는 뺀다(int -> bin -> string)
        intnum = int(input[2 + i])
        num = str(bin(intnum))
        num = num[2:]

        # 이후 모두 같은 길이로 맞춰 준다
        lenNum = len(num)
        num = "0" * (Length_ele - lenNum) + num  # 앞에 부족한 만큼 0 넣기
        pEpi.append(num)  # 리스트에 넣는다

    distingExit = 1  # 곁치는 것이 있었는지 확인
    diffpEpipNepi = 0  # 몇번째 돌아간건지
    while distingExit != 0:
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''

        ppastedE = pastedpEpi
        pastedpEpi = pEpi

        lenpNepi = len(pEpi) - 1  # 현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        # 초기화
        pEpi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi):
            ele1 = pastedpEpi[location]
            if ele1 == '[]':
                # 예외처리
                continue
            else:
                # 뒤에 것들을 차례대로 검사한다
                for index in range(location + 1, lenpNepi + 1):
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

                        if binNum not in pEpi:
                            pEpi.append(binNum)
                            # print("append binNum : ", binNum)
                            # else :
                            # pEpi.remove(binNum)
                            # pNepi.append(binNum)

                    else:
                        if ele1 not in used:
                            if ele1 not in pastedpEpi:
                                pNepi.append(ele1)
                        if ele2 not in used:
                            if ele2 not in pastedpEpi:
                                pNepi.append(ele2)

                        if ele1 not in used:
                            used.append(ele1)
                        if ele2 not in used:
                            used.append(ele2)

        barindexList1 = []
        barindexList2 = []
        for ele in pastedpEpi:
            for i in range(Length_ele):
                if ele[i] == '-':
                    barindexList1.append(i)
                    barindexList2.append(i)
        di = 0
        for i in range(0, len(barindexList1)):
            for j in range(i + 1, len(barindexList2)):
                if i == barindexList2[j]:
                    # 같은 곳의 - 가 있다.
                    di = 1

        if distingExit == 1:
            # 병합이 한개도 이루어지지 않았다.
            if diffpEpipNepi < 2:
                if di == 0:
                    pNepi = []
                    pEpi = pastedpEpi
                else:
                    pNepi = pastedpEpi
                    pEpi = []
            else:
                pEpi = pastedpEpi
            distingExit = 0
        else:
            diffpEpipNepi = diffpEpipNepi + 1
            # 병합이 한개 이상 발생하였다.
            distingExit = 1

    # 오름차순으로 정렬하자
    EupgoList = []
    NupgoList = []
    for i in range((2 ** Length_ele - 1) * 2 + 1):
        EupgoList.append(-1)
        NupgoList.append(-1)

    # print("pEpi len : ", len(pEpi))
    for ele in pEpi:
        index = 0
        for i in range(Length_ele):
            if ele[i] == '-':
                index = index + 2 * (2 ** (Length_ele - i - 1))
            else:
                index = index + int(ele[i]) * (2 ** (Length_ele - i - 1))
        EupgoList[index] = ele
        # print("Epi : ", ele)

    # print("pNepi len : ", len(pNepi))
    for ele in pNepi:
        index = 0
        for i in range(0, Length_ele):
            if ele[i] == "-":
                index = index + 2 * (2 ** (Length_ele - i - 1))
            elif ele[i] == '1':
                index = index + 1 * (2 ** (Length_ele - i - 1))
        if (NupgoList[index] != -1):
            NupgoList.insert(index, ele)
        else:
            NupgoList[index] = ele
            # print("Nepi : ", ele)

    finalList = []
    # print(EupgoList, " ", NupgoList)
    finalList.append("EPI")
    for ele in EupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    finalList.append("NEPI")
    for ele in NupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    print(finalList)
    print()

    answer = finalList
    return answer






#================================================================
def solution(input):
    Length_ele = int(input[0])  # 첫번째 수 = 몇자리 바이너리로 만들지 결정
    Elements = int(input[1])  # 몇개의 숫자가 들어올지

    # 앞에서 사용되는 두개의 정수를 제외한 것들을 새로운 리스트에 넣을려고 함
    listLen = len(input) - 2
    used = []  # 사용한것
    pEpi = []  # 사용하지 않은 것
    pNepi = []  # 사용한 이후 - 붙인 것
    pastedpNepi = []
    pastedpEpi = []
    ppastedN = []
    ppastedE = []

    # 바이너리 값으로 numList에 넣는다
    for i in range(listLen):
        if (i == " " or i == ""):
            # 엔터는 제외한다
            continue
        # 바이너리 숫자로 바꾼 이후 앞의 0b는 뺀다(int -> bin -> string)
        intnum = int(input[2 + i])
        num = str(bin(intnum))
        num = num[2:]

        # 이후 모두 같은 길이로 맞춰 준다
        lenNum = len(num)
        num = "0" * (Length_ele - lenNum) + num  # 앞에 부족한 만큼 0 넣기
        pEpi.append(num)  # 리스트에 넣는다

    distingExit = 1  # 곁치는 것이 있었는지 확인
    diffpEpipNepi = 0  # 몇번째 돌아간건지
    while distingExit != 0:
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''

        ppastedE = pastedpEpi
        pastedpEpi = pEpi

        lenpNepi = len(pEpi) - 1  # 현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        # 초기화
        pEpi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi):
            ele1 = pastedpEpi[location]
            if ele1 == '[]':
                # 예외처리
                continue
            else:
                # 뒤에 것들을 차례대로 검사한다
                for index in range(location + 1, lenpNepi + 1):
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

                        if binNum not in pEpi:
                            pEpi.append(binNum)
                            # print("append binNum : ", binNum)
                            # else :
                            # pEpi.remove(binNum)
                            # pNepi.append(binNum)

                    else:
                        if ele1 not in used:
                            if ele1 not in pastedpEpi:
                                pNepi.append(ele1)
                        if ele2 not in used:
                            if ele2 not in pastedpEpi:
                                pNepi.append(ele2)

                        if ele1 not in used:
                            used.append(ele1)
                        if ele2 not in used:
                            used.append(ele2)

        barindexList1 = []
        barindexList2 = []
        for ele in pastedpEpi:
            for i in range(Length_ele):
                if ele[i] == '-':
                    barindexList1.append(i)
                    barindexList2.append(i)
        di = 0
        for i in range(0, len(barindexList1)):
            for j in range(i + 1, len(barindexList2)):
                if i == barindexList2[j]:
                    # 같은 곳의 - 가 있다.
                    di = 1

        if distingExit == 1:
            # 병합이 한개도 이루어지지 않았다.
            if diffpEpipNepi < 2:
                if di == 0:
                    pNepi = []
                    pEpi = pastedpEpi
                else:
                    pNepi = pastedpEpi
                    pEpi = []
            else:
                pEpi = pastedpEpi
            distingExit = 0
        else:
            diffpEpipNepi = diffpEpipNepi + 1
            # 병합이 한개 이상 발생하였다.
            distingExit = 1

    # 오름차순으로 정렬하자
    EupgoList = []
    NupgoList = []
    for i in range((2 ** Length_ele - 1) * 2 + 1):
        EupgoList.append(-1)
        NupgoList.append(-1)

    # print("pEpi len : ", len(pEpi))
    for ele in pEpi:
        index = 0
        for i in range(Length_ele):
            if ele[i] == '-':
                index = index + 2 * (2 ** (Length_ele - i - 1))
            else:
                index = index + int(ele[i]) * (2 ** (Length_ele - i - 1))
        EupgoList[index] = ele

    for ele in pNepi:
        index = 0
        for i in range(0, Length_ele):
            if ele[i] == "-":
                index = index + 2 * (2 ** (Length_ele - i - 1))
            elif ele[i] == '1':
                index = index + 1 * (2 ** (Length_ele - i - 1))
        print(ele, " index is : ", index)
        if NupgoList[index] != -1:
            while (True):
                getEle = NupgoList[index]
                getIndex = 0
                for t in range(0, Length_ele):
                    if getEle[t] == "-":
                        getIndex = getIndex + 2 * (2 ** (Length_ele - t - 1))
                    elif getEle[t] == '1':
                        getIndex = getIndex + 1 * (2 ** (Length_ele - t - 1))
                if (getIndex == index):
                    break;
                else:
                    index = index + 1
            NupgoList.insert(index, ele)
        else:
            NupgoList[index] = ele

    finalList = []
    print(EupgoList, " ", NupgoList)
    finalList.append("EPI")
    for ele in EupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    finalList.append("NEPI")
    for ele in NupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    print(finalList)
    print()

    answer = finalList
    return answerdef solution(input):
    Length_ele = int(input[0]) #첫번째 수 = 몇자리 바이너리로 만들지 결정
    Elements = int(input[1]) #몇개의 숫자가 들어올지

    #앞에서 사용되는 두개의 정수를 제외한 것들을 새로운 리스트에 넣을려고 함
    listLen = len(input)-2
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
        intnum = int(input[2+i])
        num = str(bin(intnum))
        num = num[2:]

        # 이후 모두 같은 길이로 맞춰 준다
        lenNum = len(num)
        num = "0"*(Length_ele-lenNum) + num #앞에 부족한 만큼 0 넣기
        pEpi.append(num) #리스트에 넣는다

    distingExit = 1 # 곁치는 것이 있었는지 확인
    diffpEpipNepi = 0 # 몇번째 돌아간건지
    while distingExit != 0 :
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''

        ppastedE = pastedpEpi
        pastedpEpi = pEpi

        lenpNepi = len(pEpi)-1 #현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        #초기화
        pEpi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi) :
            ele1 = pastedpEpi[location]
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

                        if binNum not in pEpi :
                            pEpi.append(binNum)
                            # print("append binNum : ", binNum)
                        # else :
                            # pEpi.remove(binNum)
                            # pNepi.append(binNum)

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

        barindexList1 = []
        barindexList2 = []
        for ele in pastedpEpi:
            for i in range(Length_ele) :
                if ele[i] =='-' :
                    barindexList1.append(i)
                    barindexList2.append(i)
        di = 0
        for i in range(0,len(barindexList1)) :
            for j in range(i+1,len(barindexList2)) :
                if i == barindexList2[j] :
                    # 같은 곳의 - 가 있다.
                    di = 1


        if distingExit == 1 :
            # 병합이 한개도 이루어지지 않았다.
            if diffpEpipNepi < 2:
                if di == 0 :
                    pNepi = []
                    pEpi = pastedpEpi
                else :
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
    for i in range((2**Length_ele -1)*2+1) :
        EupgoList.append(-1)
        NupgoList.append(-1)

    # print("pEpi len : ", len(pEpi))
    for ele in pEpi :
        index = 0
        for i in range(Length_ele) :
            if ele[i] == '-' :
                index = index + 2*(2**(Length_ele-i-1))
            else :
                index = index + int(ele[i])*(2**(Length_ele-i-1))
        EupgoList[index] = ele

    for ele in pNepi:
        index = 0
        for i in range(0,Length_ele) :
            if ele[i] == "-" :
                index = index + 2*(2**(Length_ele-i-1))
            elif ele[i] == '1' :
                index = index + 1*(2**(Length_ele-i-1))
        print(ele, " index is : ", index)
        if NupgoList[index] != -1 :
            while(True) :
                getEle = NupgoList[index]
                getIndex = 0
                for t in range(0,Length_ele) :
                    if getEle[t] == "-" :
                        getIndex = getIndex + 2*(2**(Length_ele-t-1))
                    elif getEle[t] == '1' :
                        getIndex = getIndex + 1*(2**(Length_ele-t-1))
                if(getIndex == index) :
                    break
                else :
                    index = index+1
            NupgoList.insert(index, ele)
        else :
            NupgoList[index] = ele

    finalList = []
    print(EupgoList, " ", NupgoList)
    finalList.append("EPI")
    for ele in EupgoList :
        if ele == -1 :
            continue
        else:
            finalList.append(ele)

    finalList.append("NEPI")
    for ele in NupgoList :
        if ele == -1 :
            continue
        else:
            finalList.append(ele)

    print(finalList)
    print()

    answer = finalList
    return answer


#=============================================
def binToInt(string, length):
    for i in range(0, length):
        if string[i] == "-":
            index = index + 2 * (2 ** (length - i - 1))
        elif string[i] == '1':
            index = index + 1 * (2 ** (lenght - i - 1))
    return index


def solution(input):
    Length_ele = int(input[0])  # 첫번째 수 = 몇자리 바이너리로 만들지 결정
    Elements = int(input[1])  # 몇개의 숫자가 들어올지
    usedIndex = []
    for i in range(Elements):
        usedIndex.append(0)

    # 앞에서 사용되는 두개의 정수를 제외한 것들을 새로운 리스트에 넣을려고 함
    listLen = len(input) - 2
    used = []  # 사용한것
    pEpi = []  # 사용하지 않은 것
    pNepi = []  # 사용한 이후 - 붙인 것
    pastedpNepi = []
    pastedpEpi = []
    ppastedN = []
    ppastedE = []

    # 바이너리 값으로 numList에 넣는다
    for i in range(listLen):
        if (i == " " or i == ""):
            # 엔터는 제외한다
            continue
        # 바이너리 숫자로 바꾼 이후 앞의 0b는 뺀다(int -> bin -> string)
        intnum = int(input[2 + i])
        num = str(bin(intnum))
        num = num[2:]

        # 이후 모두 같은 길이로 맞춰 준다
        lenNum = len(num)
        num = "0" * (Length_ele - lenNum) + num  # 앞에 부족한 만큼 0 넣기
        pEpi.append(num)  # 리스트에 넣는다

    distingExit = 1  # 곁치는 것이 있었는지 확인
    diffpEpipNepi = 0  # 몇번째 돌아간건지
    while distingExit != 0:
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''

        ppastedE = pastedpEpi
        pastedpEpi = pEpi

        lenpNepi = len(pEpi) - 1  # 현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        # 초기화
        pEpi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi):
            ele1 = pastedpEpi[location]
            if ele1 == '[]':
                # 예외처리
                continue
            else:
                # 뒤에 것들을 차례대로 검사한다
                for index in range(location + 1, lenpNepi + 1):
                    ele2 = pastedpEpi[index]
                    diff = 0
                    if ele2 == '[]':
                        continue

                    for i in range(Length_ele):
                        if ele1[i] != ele2[i]:
                            diff = diff + 1

                    if diff == 1:
                        distingExit += 1

                        intEle1 = binToInt(ele1, Length_ele)
                        intEle2 = binToInt(ele2, Lenght_ele)
                        usedIndex[intEle1] = usedIndex[intEle1] + 1
                        usedIndex[intEle2] = usedIndex[intEle2] + 1
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

                        if binNum not in pEpi:
                            pEpi.append(binNum)
                            # print("append binNum : ", binNum)
                            # else :
                            # pEpi.remove(binNum)
                            # pNepi.append(binNum)

                    else:
                        if ele1 not in used:
                            if ele1 not in pastedpEpi:
                                pNepi.append(ele1)
                        if ele2 not in used:
                            if ele2 not in pastedpEpi:
                                pNepi.append(ele2)

                        if ele1 not in used:
                            used.append(ele1)
                        if ele2 not in used:
                            used.append(ele2)

        barindexList1 = []
        barindexList2 = []
        for ele in pastedpEpi:
            for i in range(Length_ele):
                if ele[i] == '-':
                    barindexList1.append(i)
                    barindexList2.append(i)
        di = 0
        for i in range(0, len(barindexList1)):
            for j in range(i + 1, len(barindexList2)):
                if i == barindexList2[j]:
                    # 같은 곳의 - 가 있다.
                    di = 1

        if distingExit == 1:
            # 병합이 한개도 이루어지지 않았다.
            if diffpEpipNepi < 2:
                if di == 0:
                    pNepi = []
                    pEpi = pastedpEpi
                else:
                    pNepi = pastedpEpi
                    pEpi = []
            else:
                pEpi = pastedpEpi
            distingExit = 0
        else:
            diffpEpipNepi = diffpEpipNepi + 1
            # 병합이 한개 이상 발생하였다.
            distingExit = 1

    # 오름차순으로 정렬하자
    EupgoList = []
    NupgoList = []
    for i in range((2 ** Length_ele - 1) * 2 + 1):
        EupgoList.append(-1)
        NupgoList.append(-1)

    # print("pEpi len : ", len(pEpi))
    for ele in pEpi:
        index = 0
        for i in range(Length_ele):
            if ele[i] == '-':
                index = index + 2 * (2 ** (Length_ele - i - 1))
            else:
                index = index + int(ele[i]) * (2 ** (Length_ele - i - 1))
        EupgoList[index] = ele

    for ele in pNepi:
        index = 0
        for i in range(0, Length_ele):
            if ele[i] == "-":
                index = index + 2 * (2 ** (Length_ele - i - 1))
            elif ele[i] == '1':
                index = index + 1 * (2 ** (Length_ele - i - 1))
        print(ele, " index is : ", index)
        if NupgoList[index] != -1:
            while (True):
                getEle = NupgoList[index]
                getIndex = 0
                for t in range(0, Length_ele):
                    if getEle[t] == "-":
                        getIndex = getIndex + 2 * (2 ** (Length_ele - t - 1))
                    elif getEle[t] == '1':
                        getIndex = getIndex + 1 * (2 ** (Length_ele - t - 1))
                if (getIndex == index):
                    break
                else:
                    index = index + 1
            NupgoList.insert(index, ele)
        else:
            NupgoList[index] = ele

    finalList = []
    print(EupgoList, " ", NupgoList)
    finalList.append("EPI")
    for ele in EupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    finalList.append("NEPI")
    for ele in NupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    print(finalList)
    print()

    answer = finalList
    return answer



#===================================================================
def binToInt(string, length):
    index = 0
    for i in range(0, length):
        if string[i] == "-":
            index = index + 2 * (2 ** (length - i - 1))
        elif string[i] == '1':
            index = index + 1 * (2 ** (length - i - 1))
    return index


def solution(input):
    Length_ele = int(input[0])  # 첫번째 수 = 몇자리 바이너리로 만들지 결정
    Elements = int(input[1])  # 몇개의 숫자가 들어올지
    usedIndex = []
    for i in range(999):
        usedIndex.append(0)

    # 앞에서 사용되는 두개의 정수를 제외한 것들을 새로운 리스트에 넣을려고 함
    used = []  # 사용한것
    pEpi = []  # 사용하지 않은 것
    pNepi = []  # 사용한 이후 - 붙인 것
    pastedpNepi = []
    pastedpEpi = []
    ppastedN = []
    ppastedE = []

    # 바이너리 값으로 numList에 넣는다
    for i in range(Elements):
        if (i == " " or i == ""):
            # 엔터는 제외한다
            continue
        # 바이너리 숫자로 바꾼 이후 앞의 0b는 뺀다(int -> bin -> string)
        intnum = int(input[2 + i])
        num = str(bin(intnum))
        num = num[2:]

        # 이후 모두 같은 길이로 맞춰 준다
        lenNum = len(num)
        num = "0" * (Length_ele - lenNum) + num  # 앞에 부족한 만큼 0 넣기
        pEpi.append(num)  # 리스트에 넣는다

    distingExit = 1  # 곁치는 것이 있었는지 확인
    diffpEpipNepi = 0  # 몇번째 돌아간건지
    while distingExit != 0:
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''

        ppastedE = pastedpEpi
        pastedpEpi = pEpi

        lenpNepi = len(pEpi) - 1  # 현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        # 초기화
        pEpi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi):
            ele1 = pastedpEpi[location]
            if ele1 == '[]':
                # 예외처리
                continue
            else:
                # 뒤에 것들을 차례대로 검사한다
                for index in range(location + 1, lenpNepi + 1):
                    ele2 = pastedpEpi[index]
                    diff = 0
                    if ele2 == '[]':
                        continue

                    for i in range(Length_ele):
                        if ele1[i] != ele2[i]:
                            diff = diff + 1

                    if diff == 1:
                        distingExit += 1

                        intEle1 = binToInt(ele1, Length_ele)
                        intEle2 = binToInt(ele2, Length_ele)
                        usedIndex[intEle1] = usedIndex[intEle1] + 1
                        usedIndex[intEle2] = usedIndex[intEle2] + 1

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

                        if binNum not in pEpi:
                            pEpi.append(binNum)

                    else:
                        if ele1 not in used:
                            if ele1 not in pastedpEpi:
                                pNepi.append(ele1)
                        if ele2 not in used:
                            if ele2 not in pastedpEpi:
                                pNepi.append(ele2)

                        if ele1 not in used:
                            used.append(ele1)
                        if ele2 not in used:
                            used.append(ele2)

        barindexList1 = []
        barindexList2 = []
        for ele in pastedpEpi:
            for i in range(Length_ele):
                if ele[i] == '-':
                    barindexList1.append(i)
                    barindexList2.append(i)
        di = 0
        for i in range(0, len(barindexList1)):
            for j in range(i + 1, len(barindexList2)):
                if i == barindexList2[j]:
                    # 같은 곳의 - 가 있다.
                    di = 1

        if distingExit == 1:
            # 병합이 한개도 이루어지지 않았다.
            if diffpEpipNepi < 2:
                if di == 0:
                    pNepi = []
                    pEpi = pastedpEpi
                else:
                    pNepi = pastedpEpi
                    pEpi = []
            else:
                pEpi = pastedpEpi
            distingExit = 0
        else:
            diffpEpipNepi = diffpEpipNepi + 1
            # 병합이 한개 이상 발생하였다.
            distingExit = 1

    # 오름차순으로 정렬하자
    EupgoList = []
    NupgoList = []
    for i in range((2 ** Length_ele - 1) * 2 + 1):
        EupgoList.append(-1)
        NupgoList.append(-1)

    # print("pEpi len : ", len(pEpi))
    for ele in pEpi:
        index = 0
        for i in range(Length_ele):
            if ele[i] == '-':
                index = index + 2 * (2 ** (Length_ele - i - 1))
            else:
                index = index + int(ele[i]) * (2 ** (Length_ele - i - 1))
        EupgoList[index] = ele

    for ele in pNepi:
        index = 0
        index = binToInt(ele, Length_ele)
        if NupgoList[index] != -1:
            while (True):
                getEle = NupgoList[index]
                getIndex = 0
                getIndex = binToInt(getEle, Length_ele)
                if (getIndex == index):
                    break
                else:
                    index = index + 1
            NupgoList.insert(index, ele)
        else:
            NupgoList[index] = ele

    finalList = []
    print(EupgoList, " ", NupgoList)
    finalList.append("EPI")
    for ele in EupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    finalList.append("NEPI")
    for ele in NupgoList:
        if ele == -1:
            continue
        else:
            finalList.append(ele)

    print(finalList)
    print()

    answer = finalList
    return answer

#==================================================================
def binToInt(string, length):
    index = 0
    for i in range(0, length):
        if string[i] == "-":
            index = index + 2*(10**(length - i - 1))
        elif string[i] == '1':
            index = index + (10 ** (length - i - 1))
    return index


def solution(input):
    Length_ele = int(input[0])  # 첫번째 수 = 몇자리 바이너리로 만들지 결정
    Elements = int(input[1])  # 몇개의 숫자가 들어올지
    usedIndex = []
    for i in range(99999):
        usedIndex.append(0)

    # 앞에서 사용되는 두개의 정수를 제외한 것들을 새로운 리스트에 넣을려고 함
    used = []  # 사용한것
    pEpi = []  # 사용하지 않은 것
    pNepi = []  # 사용한 이후 - 붙인 것
    pastedpEpi = []

    # 바이너리 값으로 numList에 넣는다
    for i in range(Elements):
        if (i == " " or i == ""):
            # 엔터는 제외한다
            continue
        # 바이너리 숫자로 바꾼 이후 앞의 0b는 뺀다(int -> bin -> string)
        intnum = int(input[2 + i])
        num = str(bin(intnum))
        num = num[2:]

        # 이후 모두 같은 길이로 맞춰 준다
        lenNum = len(num)
        num = "0" * (Length_ele - lenNum) + num  # 앞에 부족한 만큼 0 넣기
        pEpi.append(num)  # 리스트에 넣는다

    distingExit = 1  # 곁치는 것이 있었는지 확인
    diffpEpipNepi = 0  # 몇번째 돌아간건지
    while distingExit != 0:
        '''첫번째 돌때 0으로 초기화 되면(-를 넣지 않은 경우) 끝낸다'''

        pastedpEpi = pEpi
        lenpNepi = len(pEpi) - 1  # 현재 pNepi길이에 대해 1개 적게 길이 넣어 놓기

        # 초기화
        pEpi = []

        # 하나씩 뒤에서 부터 검사하기
        for location in range(lenpNepi):
            ele1 = pastedpEpi[location]
            if ele1 == '[]':
                # 예외처리
                continue
            else:
                # 뒤에 것들을 차례대로 검사한다
                for index in range(location + 1, lenpNepi + 1):
                    ele2 = pastedpEpi[index]
                    diff = 0
                    if ele2 == '[]':
                        continue

                    for i in range(Length_ele):
                        if ele1[i] != ele2[i]:
                            diff = diff + 1

                    if diff == 1:
                        # 몇개를 병합했는지 알려줌(1==한개도 못함)
                        distingExit += 1
                        # 병합했을 때 사용한 수의 자릿수를 증가시킨다
                        intEle1 = binToInt(ele1, Length_ele)
                        intEle2 = binToInt(ele2, Length_ele)
                        usedIndex[intEle1] = usedIndex[intEle1] + 1
                        usedIndex[intEle2] = usedIndex[intEle2] + 1
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

                        if binNum not in pEpi:
                            pEpi.append(binNum)


                    else:
                        if ele1 not in used:
                            if ele1 not in pastedpEpi:
                                pNepi.append(ele1)
                        if ele2 not in used:
                            if ele2 not in pastedpEpi:
                                pNepi.append(ele2)

                        if ele1 not in used:
                            used.append(ele1)
                        if ele2 not in used:
                            used.append(ele2)

        barindexList1 = []
        barindexList2 = []
        for ele in pastedpEpi:
            for i in range(Length_ele):
                if ele[i] == '-':
                    barindexList1.append(i)
                    barindexList2.append(i)
        di = 0
        for i in range(0, len(barindexList1)):
            for j in range(i + 1, len(barindexList2)):
                if i == barindexList2[j]:
                    # 같은 곳의 - 가 있다.
                    di = 1

        if distingExit == 1:
            # 병합이 한개도 이루어지지 않았다.
            if diffpEpipNepi < 2:
                if di == 0:
                    pNepi = []
                    pEpi = pastedpEpi
                else:
                    pNepi = pastedpEpi
                    pEpi = []
            else:
                pEpi = pastedpEpi
            distingExit = 0
        else:
            diffpEpipNepi = diffpEpipNepi + 1
            # 병합이 한개 이상 발생하였다.
            distingExit = 1

    # 오름차순으로 정렬하자
    EupgoList = []
    NupgoList = []
    print("pEpi : ", pEpi)
    print("pNepi : ", pNepi)
    if len(pEpi) > 0 :
        EupgoList.append(pEpi[0])
        for j in range(1,len(pEpi)):
            ele = pEpi[j]
            index = binToInt(ele, Length_ele)
            # EupgoList[index] = ele
            for i in range(0, len(EupgoList)) :
                if binToInt(EupgoList[i], Length_ele) < index and i==len(EupgoList)-1 :
                    # 맨 끝에 넣는다
                    EupgoList.append(ele)
                    print(ele)
                    break
                elif index < binToInt(EupgoList[i], Length_ele) and i==0 :
                    # 맨 앞에 넣는다
                    EupgoList.insert(0, ele)
                    print(ele)
                elif binToInt(EupgoList[i], Length_ele) < index and i !=len(EupgoList)-1 :
                    continue
                elif index < binToInt(EupgoList[i], Length_ele) and i!=0:
                    EupgoList.insert(i, ele)
                    print(ele)
                    break

    if len(pNepi) > 0 :
        NupgoList.append(pNepi[0])
        # print("append 0 : ", NupgoList)
        for ele in pNepi:
            if ele == pNepi[0] :
                continue
            # print("Ele : ", ele)
            index = binToInt(ele, Length_ele)
            # print("index : ", index)
            for i in range(0,len(NupgoList)) :
                if binToInt(NupgoList[i], Length_ele) < index and i==len(NupgoList)-1 :
                    # 맨 끝에 넣는다
                    NupgoList.append(ele)
                    print(ele)
                    break
                elif index < binToInt(NupgoList[i], Length_ele) and i==0 :
                    # 맨 앞에 넣는다
                    NupgoList.insert(0, ele)
                    print(ele)
                elif binToInt(NupgoList[i], Length_ele) < index and i !=len(NupgoList)-1 :
                    continue
                elif index < binToInt(NupgoList[i], Length_ele) and i!=0:
                    NupgoList.insert(i, ele)
                    print(ele)
                    break

    finalList = []
    finalList.append("EPI")
    for ele in EupgoList:
        finalList.append(ele)

    finalList.append("NEPI")
    for ele in NupgoList:
        finalList.append(ele)

    print(finalList)
    print()

    answer = finalList
    return answer
