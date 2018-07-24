# queque를 활용하여서 노트북에 있는 txt파일 찾기
# dir_queue.put(여기부분을 수정하명 범위 조정 가능)

import os
import queue   #queue-대기줄 순서대로 읽어/조사 준다/한다? 구현방법은 다양하다. 

def get_subdir(path) :
    try :
        dirfiles =os.listdir(path)
    except PermissionError:  #권한에 맞지 않게 나오면 none으로 뜸
        return  #그래서 여기다가 [] 집어 넣으시오!

    subdir_list = []
    for each in dirfiles :
        full_name =path +each
        if os.path.isdir(full_name):
            subdir_list.append(full_name +"/")
        return subdir_list

def get_txt(dir_queue) :
    while not dir_queue.empty():
        txt_name = dir_queue.get()
        all_txts.append(txt_name)

        for each in all_txts :
            if all_txts[-4:0] == '.txt' :
                txt_queue.put(each)
            else :
                pass
    return (txt_queue)

dir_queue = queue.Queue()  #생성하기 
dir_queue.put("/home/")    
txt_queue = queue.Queue()

all_txts=[]
all_dirs =[]
while not dir_queue.empty():    #queue로 다 넘길때 까지 계속하기/다 읽기
    dir_name = dir_queue.get()
    all_dirs.append(dir_name)

    subdir_names = get_subdir(dir_name)
    for each in subdir_names :
        dir_queue.put(each)

    get_txt(dir_queue)

print(all_dirs)
print(all_txts)

a=[1, 2, 3, 4, 5]
b=[]
c=[]
for each in a :
    if each<4 :
        b.append(each)
    else:
        c.append(each)
print(b, c)


#슬라이싱-> string[-4,:] .txt 찾기  ".txt" in string
#if 디렉토리 찾기/추가
#else txt 찾기 
