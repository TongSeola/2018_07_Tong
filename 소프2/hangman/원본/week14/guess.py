class Guess:

    def __init__(self, word):

        # 랜덤적으로 뽑은 단어
        self.secretWord = word
        # 맞춘 문자 상태
        self.currentStatus = '_' * len(word)
        # 이제까지 사용된 알파벳이 들어가 있는 리스트
        self.guessedChars = {'e', 'n'}
        self.guess('')


    def guess(self, character):
        '''character은 집어 넣은 알파벳
        만약 뽑은 단어 안에 주어진 알파벳이 있다면 True 없으면 False'''

        # 입력된 알파벳 사용된 리스트에 넣기
        self.guessedChars |= {character}

        # 뽑은 단어 안에 알바벳이 존재하는지 검사
        if character not in self.secretWord:
            return False
        else:
            currentStatus = ''
            for c in self.secretWord:
                if c in self.guessedChars:
                    currentStatus += c
                else:
                    currentStatus += '_'
            # 문자 상태
            self.currentStatus = currentStatus

            return True


    def finished(self):
        if self.currentStatus == self.secretWord:
            return True
        else:
            return False


    def displayCurrent(self):

        guessWord = ''
        for c in self.currentStatus:
            guessWord += (c + ' ')
        return guessWord


    def displayGuessed(self):

        guessed = ''
        for c in sorted(list(self.guessedChars)):
            guessed += (c + ' ')
        return guessed
