# 한층(?)의 dirctory파일만 찾아준다
# queue를 활용하여서
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

dir_queue = queue.Queue()  #마지막것으로 찾기?
dir_queue.put("/home/")    

all_dirs =[]
while not dir_queue.empty():    #queue로 다 넘길때 까지 계속하기/다 읽기
    dir_name = dir_queue.get()
    all_dirs.append(dir_name)

    subdir_names = get_subdir(dir_name)
    for each in subdir_names :
        dir_queue.put(each)

print(all_dirs)

