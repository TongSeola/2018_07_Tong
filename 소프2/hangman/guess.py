# 현재 맞춘 글자 상태 + 실패횟수 + 글자추측(있으면 기록, 없으면 실패횟수 증가)
# 모든 글자가 맞추었는지 아닌지

class Guess:

    def __init__(self, word):
        '''선택된 단어 선택한것 파라미터로 받음
        1. 단어의 길이에 알맞게 빈 '_' 만들기
        2. 입력한 알파벳 적어 넣을 리스트 초기화
        3. 실패한 기회 변수 선언'''

        #1
        self.secretWord = word
        self.randomword = [x for x  in word]
        self.currentStatus = '_ '*len(word)

        #2
        self.guessedChars = []

        #3
        self.numTries = 0


    def display(self):
        '''알아낸 글자들과 그 위치를 가리키는 데이터 화면에 출력
        + 실패한 횟수와 행맨 상태도 화면에 출력'''
        print("단어 완성 상태 : ", self.currentStatus)
        print("사용한 알파벳 : ", self.guessedChars)
        print("실패한 횟수 : " , self.numTries)

        pass


    def guess(self, character):
        '''입력한 알파벳을 파라미터로 받음
        0. 알파벳인지 검사 및 대문자 소문자 일괄통일
        1. 알파벳을 리스트(사용한)에 넣음
        2. 단어에 알파벳이 해당하지 않으면 실패횟수 증가
        3. 단어에 알파벳이 해당하면 그 위치에 넣기
        4. 모든 단어를 다 맞추었는지 확인'''

        #0
        if character.isalpha():
            character = character.lower()
        else:
            print ("알파벳을 입력해 주십시오")
            return

        #1
        self.guessedChars.append(character)

        #2,3
        while character in self.randomword :
            location = self.randomword.index(character)
            self.currentStatus = self.currentStatus[:location*2] + character +self.currentStatus[(location*2+1):]
            self.randomword[location] = ''
            #break
        else :
            self.numTries +=1

        #4
        if self.currentStatus.replace(" ","") == self.secretWord :
            finished = True
        else :
            finished = False

        return finished


