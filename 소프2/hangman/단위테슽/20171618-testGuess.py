import unittest
from hangman import Hangman



class Testhangman(unittest.TestCase):

    def setUp(self):
        self.g2 = Hangman()
    def testcurrentShape(self):
        self.assertEqual(self.g2.currentShape(), '''\
   ____
  |    |
  |
  |
  |
  |
 _|_
|   |______
|          |
|__________|\
''')
        self.g2.decreaseLife()
        self.assertEqual(self.g2.currentShape(), '''\
   ____
  |    |
  |    o
  |
  |
  |
 _|_
|   |______
|          |
|__________|\
''')
        self.g2.decreaseLife()
        self.assertEqual(self.g2.currentShape(), '''\
   ____
  |    |
  |    o
  |    |
  |    |
  |
 _|_
|   |______
|          |
|__________|\
''')
        self.g2.decreaseLife()
        self.assertEqual(self.g2.currentShape(), '''\
   ____
  |    |
  |    o
  |   /|
  |    |
  |
 _|_
|   |______
|          |
|__________|\
''')
        self.g2.decreaseLife()
        self.assertEqual(self.g2.currentShape(), '''\
   ____
  |    |
  |    o
  |   /|\\
  |    |
  |
 _|_
|   |______
|          |
|__________|\
''')
#         self.g2.decreaseLife()
#         self.assertEqual(self.g2.currentShape(), '''\
#    ____
#   |    |
#   |    o
#   |   /|\\
#   |    |
#   |   /
#  _|_
# |   |______
# |          |
# |__________|\
# ''')
        self.g2.decreaseLife()
        self.assertEqual(self.g2.currentShape(), '''\
   ____
  |    |
  |    o
  |   /|\\
  |    |
  |   / \\
 _|_
|   |______
|          |
|__________|\
''')

if __name__ == '__main__':
    unittest.main()
