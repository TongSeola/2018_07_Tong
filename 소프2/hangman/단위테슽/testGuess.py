import unittest

from guess import Guess

class TestGuess(unittest.TestCase):

    def setUp(self):
        self.g1 = Guess('default')

    def tearDown(self):
        pass

    def testInit(self):
        self.assertEqual(self.g1.secretWord,'default')
        self.assertEqual(self.g1.currentStatus, '_e_____')
        self.assertEqual(self.g1.guessedChars,{'', 'n', 'e'})
        self.assertTrue(self.g1.guess(''))

    def testDisplayCurrent(self):
        # 기본 적으로 e가 들어가 았다.
        self.assertEqual(self.g1.displayCurrent(), '_ e _ _ _ _ _ ')
        # 존재하지 않는 알파벳 넣었을 경우
        self.g1.guess('i')
        self.assertEqual(self.g1.displayCurrent(), '_ e _ _ _ _ _ ')
        self.g1.guess(' ')
        self.assertEqual(self.g1.displayCurrent(), '_ e _ _ _ _ _ ')
        self.g1.guess('a')
        self.assertEqual(self.g1.displayCurrent(), '_ e _ a _ _ _ ')
        self.g1.guess('t')
        self.assertEqual(self.g1.displayCurrent(), '_ e _ a _ _ t ')
        # 이미 적은 값을 적은 경우
        self.g1.guess('t')
        self.assertEqual(self.g1.displayCurrent(), '_ e _ a _ _ t ')
        # 2개 이상의 문자를 한번에 적은 경우
        self.g1.guess('ul')
        self.assertEqual(self.g1.displayCurrent(), '_ e _ a _ _ t ')
        # 알파벳이 아닌 숫자를 넣은 경우
        self.g1.guess('10')
        self.assertEqual(self.g1.displayCurrent(), '_ e _ a _ _ t ')
        # 나머지 문자 완성
        self.g1.guess('d')
        self.assertEqual(self.g1.displayCurrent(), 'd e _ a _ _ t ')
        self.g1.guess('f')
        self.assertEqual(self.g1.displayCurrent(), 'd e f a _ _ t ')
        self.g1.guess('u')
        self.assertEqual(self.g1.displayCurrent(), 'd e f a u _ t ')
        self.g1.guess('l')
        self.assertEqual(self.g1.displayCurrent(), 'd e f a u l t ')



    def testDisplayGuessed(self):
        self.assertEqual(self.g1.displayGuessed(), ' e n ')
        self.g1.guess('i')
        self.assertEqual(self.g1.displayGuessed(), ' e i n ')
        self.g1.guess(' ')
        self.assertEqual(self.g1.displayGuessed(), '   e i n ')
        self.g1.guess('a')
        self.assertEqual(self.g1.displayGuessed(), '   a e i n ')
        self.g1.guess('t')
        self.assertEqual(self.g1.displayGuessed(), '   a e i n t ')
        self.g1.guess('ul')
        self.assertEqual(self.g1.displayGuessed(), '   a e i n t ul ')
        self.g1.guess('10')
        self.assertEqual(self.g1.displayGuessed(), '   10 a e i n t ul ')
        self.g1.guess('d')
        self.assertEqual(self.g1.displayGuessed(), '   10 a d e i n t ul ')
        self.g1.guess('f')
        self.assertEqual(self.g1.displayGuessed(), '   10 a d e f i n t ul ')
        self.g1.guess('u')
        self.assertEqual(self.g1.displayGuessed(), '   10 a d e f i n t u ul ')
        self.g1.guess('l')
        self.assertEqual(self.g1.displayGuessed(), '   10 a d e f i l n t u ul ')

    def testGuess(self):
        self.assertEqual(self.g1.guessedChars,{'','n','e'})
        self.assertEqual(self.g1.currentStatus, '_e_____')
        self.assertFalse(self.g1.guess('i'))
        self.assertEqual(self.g1.guessedChars, {'i','','n','e'})
        self.assertEqual(self.g1.currentStatus, '_e_____')
        self.assertFalse(self.g1.guess(' '))
        self.assertEqual(self.g1.guessedChars, {' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, '_e_____')
        self.assertTrue(self.g1.guess('a'))
        self.assertEqual(self.g1.guessedChars, {'a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, '_e_a___')
        self.assertTrue(self.g1.guess('t'))
        self.assertEqual(self.g1.guessedChars, {'t','a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, '_e_a__t')
        self.assertTrue(self.g1.guess('ul'))
        self.assertEqual(self.g1.guessedChars, {'ul','t','a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, '_e_a__t')
        self.assertFalse(self.g1.guess('10'))
        self.assertEqual(self.g1.guessedChars, {'10','ul','t','a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, '_e_a__t')
        self.assertTrue(self.g1.guess('d'))
        self.assertEqual(self.g1.guessedChars, {'d','10','ul','t','a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, 'de_a__t')
        self.assertTrue(self.g1.guess('f'))
        self.assertEqual(self.g1.guessedChars, {'f','d','10','ul','t','a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, 'defa__t')
        self.assertTrue(self.g1.guess('u'))
        self.assertEqual(self.g1.guessedChars, {'u','f','d','10','ul','t','a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, 'defau_t')
        self.assertTrue(self.g1.guess('l'))
        self.assertEqual(self.g1.guessedChars, {'l','u','f','d','10','ul','t','a',' ','i','','n','e'})
        self.assertEqual(self.g1.currentStatus, 'default')

    def testFinished(self):
        self.g1.currentStatus = 'de'
        self.assertFalse(self.g1.finished())
        self.g1.currentStatus = 'default'
        self.assertTrue(self.g1.finished())


if __name__ == '__main__':
    unittest.main()
