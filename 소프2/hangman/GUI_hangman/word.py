import random

class Word:

    def __init__(self, filename):

        self.words = []
        f = open(filename, 'r')
        lines = f.readlines()
        f.close()

        self.count = 0
        for line in lines:
            word = line.rstrip()
            self.words.append(word)
            self.count += 1

        print('%d words in DB' % self.count)


    def test(self):
        return 'default'


    def randFromDB(self):
        lenght =1000000000
        while lenght > 10 :
            r = random.randrange(self.count)
            world = self.words[r]
            lenght =len(world)

        return world
