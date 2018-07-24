from hangman import Hangman
from guess import Guess
from word import Word


def gameMain():
    word = Word('words.txt')
    guess = Guess(word.randFromDB())

    finished = False
    hangman = Hangman()
    maxTries = hangman.getLife()

    while guess.numTries < maxTries:

        # 목숨??
        display = hangman.get(maxTries - guess.numTries)
        print(display)
        guess.display()

        guessedChar = input('Select a letter: ')
        # 알파벳 한개만 적기
        if len(guessedChar) != 1:
            print('One character at a time!')
            continue
        # guessedChars는 이미적은 알파벳을 모아 놓은 곳
        if guessedChar in guess.guessedChars:
            print('You already guessed \"' + guessedChar + '\"')
            continue

        # 적은 알파벳이 랜덤적으로 고른/전체다 맞췄는지? 단어안에 있는지 확인
        finished = guess.guess(guessedChar)
        if finished == True:
            break

    # 알파벳이 존재한다면 성공
    if finished == True:
        print('Success')
    else:
        print(hangman.get(0))
        print('word [' + guess.secretWord + ']')
        print('guess [' + guess.currentStatus + ']')
        print('Fail')


if __name__ == '__main__':
    gameMain()
