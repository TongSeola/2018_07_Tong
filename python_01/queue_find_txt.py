# queque를 활용하여서 노트북에 있는 txt파일 찾기
# dir_queue.put(여기부분을 수정하명 범위 조정 가능)

import os
import queue

def identify_dir(path):
    try :
        dirfiles = os.listdir(path)
    except PermissionError:
        return
    subdir_list = []
    for each in dirfiles :
        full_name = path + each
        if os.path.isdir(full_name) :
            subdir_list.append(full_name +"/")
        else :
            pass
    return subdir_list    

def identify_txt(start):
    try :
        dirfiles = os.listdir(start)
    except PermissionError:
        return
    subtxt_list = []
    for each in dirfiles :
        if os.path.splitext(each)[1] == '.txt' :
            subtxt_list.append(each +"/")
        else :
            pass
    return subtxt_list    

dir_queue = queue.Queue()
dir_queue.put("/home/dongseola/바탕화면/rhk/")

all_dirs = []
all_txts = []
while not dir_queue.empty():
    dir_name = dir_queue.get() #의미를 모르겠음 
    all_dirs.append(dir_name)
    all_txts.append(dir_name)
    
    subdir_names = identify_dir(dir_name)
    txt_=identify_txt(dir_name)
    for each in subdir_names :
        dir_queue.put(each)
    for each in txt_ :
        all_txts.append(each) #왜 txt_queue이 list라는 건지...

print(all_txts)
