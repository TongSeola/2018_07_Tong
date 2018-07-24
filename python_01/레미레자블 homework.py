# txt파일을 읽은 후 그 안에 들어 있는 각 문자가 몇개씩 들어있는지 확인하는 작업

# 파일을 읽어 온다
file = open('remi.txt', 'r')
# 읽어온 파일에서 모든 문자를 소문자로 부꾼 후 .을 지운다
list_file_1 = file.read().lower().replace(".","")
# 이 후 '을 지운후 띄어쓰기를 기준(split)으로 리스트에 넣는다.
list_file = list_file_1.replace("'","").split()

dic = {} # 몇개 들어 있는지 카운트를 세기 위한 딕션어리 // 키=문자 갯수=값
vlist=[]

for each in list_file:
    '''파일속의 모든 문자들이 들어있는 리스트에서 차례대로 원소들을 가져온다
       만약 원소가 없을 시 : 새로운 키를 생성하면서 값으로 1을 부여한다
       만약 이미 원소에 대한 키가 있을 시 기존에 있는 값을 가져온 후 1을 더한다.'''
    dic[each] = dic.get(each, 0) + 1

for k in dic:
    ''' dic에서 키와 그에 대응하는 값을 가져와서
        [키,값]의 형태로 만든후 새로운 리스트(vlist)에 넣는다'''
    vlist.append([k,dic[k]])

# vlist에 들어 있는 원소를 값이 큰 순서대로 나열하기 위해 하는 작업
dic_to_list=sorted(vlist,key=lambda l:l[1],reverse=True)

for list in dic_to_list :
    print(list)


