import random

class Word:

    def __init__(self, filename):

        self.words = []
        f = open(filename, 'r')
        lines = f.readlines()
        f.close()

        self.count = 0
        for line in lines:
            word = line.rstrip() #오른쪽 공백 없애기
            self.words.append(word)
            self.count += 1

        print('%d words in DB' % self.count)


    def test(self):
        return 'default'


    def randFromDB(self):
        '''난수 발생하게 하여 임의의 단어 찾기'''

        r = random.randrange(self.count)
        return self.words[r]
