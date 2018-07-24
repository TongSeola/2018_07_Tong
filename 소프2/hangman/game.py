from hangman import Hangman
from guess import Guess
from word import Word


def gameMain():
    '''게임 구동 과정'''

    # 파일에 있는 단어 정리 및 갯수 알려주기
    word = Word('aabbcc.txt')

    # 파일안에 있는 단어 랜덤적으로 가져온다.
    guess = Guess(word.randFromDB())

    # 처음에는 단어가 완성이 안돼있으니 False 출력
    finished = False

    # 목숨갯수(maxTries = 6)초기화
    hangman = Hangman()
    maxTries = hangman.getLife()

    # numTries(현재 남은 목숨갯수)가 6보다 크거나 같을 때가지 실행
    while guess.numTries < maxTries:

        # 시각적으로 행맨을 보여준다 (남은 목숨갯수에 맞게)
        # 6 -> 0
        display = hangman.get(maxTries - guess.numTries)
        print(display)
        guess.display()

        guessedChar = input('Select a letter: ')

        # 알파벳 한개만 적기 #
        if len(guessedChar) != 1:
            print('One character at a time!')
            continue
        # guessedChars는 이미적은 알파벳을 모아 놓은 곳
        if guessedChar in guess.guessedChars:
            print('You already guessed \"' + guessedChar + '\"')
            continue

        # 입력된 알파벳이 랜덤단어안에 있는지 확인
        # 단어가 완성 되었는지
        finished = guess.guess(guessedChar)
        if finished == True:
            break

    # 알파벳이 존재한다면 성공
    if finished == True:
        print('Success')

    # 만약 제안된 기회 안에 단어를 완성하지못했다면
    else:
        # 매달린 남자 보여주기
        print(hangman.get(0))
        #사용한 알파벳, 기회가용횟수, 실패
        print('word was [' + guess.secretWord + ']')
        print('guess [' + guess.currentStatus + ']')
        print('Fail')


if __name__ == '__main__':
    # game start!!
    gameMain()
