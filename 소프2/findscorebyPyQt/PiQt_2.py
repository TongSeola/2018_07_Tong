import pickle
import sys
from PyQt5.QtCore import pyqtSignal, QObject
from PyQt5.QtWidgets import (QWidget, QPushButton,
                             QHBoxLayout, QVBoxLayout, QApplication, QLabel,
                             QComboBox, QTextEdit, QLineEdit, QGridLayout)
from PyQt5.QtCore import Qt

class ScoreDB(QWidget):
    def __init__(self):
        super().__init__()

        self.initUI()
        self.dbfilename = 'assignment6.dat'
        self.scdb = []
        self.readScoreDB()
        self.showScoreDB()

    def initUI(self):
        # make button
        addButton = QPushButton("Add", self)
        belButton = QPushButton("Del", self)
        findButton = QPushButton("Find", self)
        incButton = QPushButton("Inc", self)
        showButton = QPushButton("show", self)

        addButton.clicked.connect(self.adddAction)
        belButton.clicked.connect(self.belAction)
        findButton.clicked.connect(self.findAction)
        incButton.clicked.connect(self.incAction)
        showButton.clicked.connect(self.showAction)

        # =======================================================
        # make label name
        name = QLabel('Name:')
        age = QLabel('Age:')
        score = QLabel('Score:')
        Amount = QLabel('Amount:')
        Result = QLabel('Result:')
        key = QLabel('Key:')

        # make label box
        self.nameEdit = QLineEdit()
        self.ageEdit = QLineEdit()
        self.scoreEdit= QLineEdit()
        self.AmountEdit = QLineEdit()
        self.ResultEdit = QTextEdit()

        self.keybox = QComboBox()
        #key정하는 박스 만들기
        self.keybox.addItem("Name")
        self.keybox.addItem("Age")
        self.keybox.addItem("Score")


        # ========================================================

        self.hbox1 = QHBoxLayout()
        #1번째 줄
        self.hbox1.addWidget(name)
        self.hbox1.addWidget(nameEdit,1)
        self.hbox1.addWidget(age)
        self.hbox1.addWidget(ageEdit,1)
        self.hbox1.addWidget(score)
        self.hbox1.addWidget(scoreEdit,1)

        self.hbox2 = QHBoxLayout()
        #2번째 줄
        self.hbox2.addStretch(1)
        self.hbox2.addStretch(1)
        self.hbox2.addWidget(Amount)
        self.hbox2.addWidget(AmountEdit,1)
        self.hbox2.addWidget(key)
        self.hbox2.addWidget(self.keybox)

        self.hbox3 = QHBoxLayout()
        # 3번째 줄
        self.hbox3.addStretch(1)
        self.hbox3.addWidget(addButton)
        self.hbox3.addWidget(belButton)
        self.hbox3.addWidget(findButton)
        self.hbox3.addWidget(incButton)
        self.hbox3.addWidget(showButton)

        self.hbox4 = QHBoxLayout()
        #4번째 줄
        self.hbox4.addWidget(Result)
        self.hbox4.addStretch(1)

        self.hbox5 = QHBoxLayout()
        #5번째 줄
        self.hbox5.addWidget(ResultEdit, 5)

        self.vbox = QVBoxLayout()
        #쌓기
        self.vbox.addLayout(self.hbox1)
        self.vbox.addLayout(self.hbox2)
        self.vbox.addLayout(self.hbox3)
        self.vbox.addLayout(self.hbox4)
        self.vbox.addLayout(self.hbox5)

        self.setLayout(self.vbox)

        self.setGeometry(300, 300, 500, 250)
        self.setWindowTitle('Assignment6')
        self.show()


        # ================================================================
    def closeEvent(self, event):

        self.writeScoreDB()

    def readScoreDB(self):
        try:
            fH = open(self.dbfilename, 'rb')
        except FileNotFoundError as e:
            self.scoredb = []
            return

        try:
            self.scoredb =  pickle.load(fH)
        except:
            pass
        else:
            pass
        fH.close()


    # write the data into person db
    def writeScoreDB(self):
        fH = open(self.dbfilename, 'wb')
        pickle.dump(self.scoredb, fH)
        fH.close()

    def showScoreDB(self):
        keystand = self.keybox.currentText()
        Print = ''
        for p in sorted(self.scoredb, key=lambda person: person[keystand]):
            for attr in sorted(p):
                Print += attr + "=" + p[attr]+ '\t'
            Print+= '\n'

        self.ResultEdit.setPlainText(Print)

    def adddAction(self):
        nametext = self.nameEdit.text()
        agetext = self.ageEdit.text()
        scoretext = self.scoreEdit.text()

        record = {'Name': nametext, 'Age': int(agetext), 'Score': int(scoretext)}
        self.scoredb += [record]

        self.showScoreDB()

    def delAction(self):
        nametext = self.nameEdit.text()

        for k in range(0, len(self.scoredb)):
            for p in (self.scoredb):
                if p['Name'] == nametext:
                    self.scoredb.remove(p)

        self.showScoreDB()

    def incAction(self):
        nametext = self.nameEdit.text()
        Amaunttext = self.AmountEdit.text()

        for p in self.scoredb:
            if p['Name'] == nametext:
                p['Score'] = str(int(p['Score']) + int(Amaunttext))

        self.showScoreDB()

    def findAction(self):
        keystand = self.keybox.currentText()
        nametext = self.nameEdit.text()
        dic_find =[]
        Print = ''
        for p in self.scoredb:
            if p['Name'] == nametext:
                dic_find += self.scoredb[p]

        for p in sorted(dic_find, key=lambda person: person[keystand]):
            for attr in sorted(p):
                Print += attr + "=" + p[attr]+ '\t'
            Print+= '\n'

        self.ResultEdit.setPlainText(Print)



if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = ScoreDB()
    sys.exit(app.exec_())
