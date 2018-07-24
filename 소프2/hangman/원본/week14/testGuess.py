import unittest

from guess import Guess

class TestGuess(unittest.TestCase):

    def setUp(self):
        self.g1 = Guess('default')

    def tearDown(self):
        pass

# eatu + dfl
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
        self.assertFalse(self.g1.guess('i'))
        self.assertFalse(self.g1.guess(' '))
        self.assertTrue(self.g1.guess('a'))
        self.assertTrue(self.g1.guess('t'))
        self.assertTrue(self.g1.guess('ul'))
        self.assertFalse(self.g1.guess('10'))
        self.assertTrue(self.g1.guess('d'))
        self.assertTrue(self.g1.guess('f'))
        self.assertTrue(self.g1.guess('u'))
        self.assertTrue(self.g1.guess('l'))


if __name__ == '__main__':
    unittest.main()
