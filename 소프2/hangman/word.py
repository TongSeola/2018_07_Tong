import random
# 파일을 읽고 난수를 발생싴켜서 임의의 원소선택(단어선택) + 반환

class Word:

    def __init__(self, filename):

        self.words = []
        f = open(filename, 'r')
        # 한줄식 읽기 (행별로)
        lines = f.readlines()
        f.close()

        self.count = 0
        for line in lines:
            # 오른쪽 공백 없애기
            word = line.rstrip()
            self.words.append(word)
            self.count += 1

        # 총 단어의 갯수 알려주기
        print('%d words in DB' % self.count)


    def test(self):
        '''이건 왜 있는지 아직도 의문'''
        return 'default'


    def randFromDB(self):
        '''난수 발생하게 하여 임의의 단어 찾기'''
        r = random.randrange(self.count)
        return self.words[r]
