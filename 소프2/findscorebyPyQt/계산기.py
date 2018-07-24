import sys
from PyQt5.QtCore import *
from PyQt5.QtGui import *


# 창 정의
class Form(QDialog):
    # 창 초기화
    def __init__(self, parent=None):
        super().__init__(parent)
        self.old = ''
        self.new = '0'
        self.operator = ''

        layout = QGridLayout()
        self.label = QLabel()
        self.label.setText('<p align="right"><font size=30><b>' + self.new + '</b></font></p>')
        layout.addWidget(self.label, 0, 0, 1, 4)  # 0, 0 위치에서 행으로 1칸, 열로 4칸의 크기를 갖도록 함.
        # 버튼 생성과 위치 지정
        for index, value in enumerate(['7', '8', '9', '/', '4', '5', '6', '*', '1', '2', '3', '-', '0', '.', '=', '+']):
            button = QPushButton(value)
            layout.addWidget(button, index // 4 + 1, index % 4)

        self.setLayout(layout)
        self.setWindowTitle('계산기')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    form = Form()
    form.show()
    app.exec_()