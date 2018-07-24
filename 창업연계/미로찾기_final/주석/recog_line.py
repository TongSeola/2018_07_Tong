# =======================================================================
# this code is for object to recognize and show line status
# =======================================================================
# latest modification on 9.Dec.2017
# =======================================================================
# import GPIO library and time module
# =======================================================================
import RPi.GPIO as GPIO
import time

# =======================================================================
#  set GPIO warnings as false
# =======================================================================
GPIO.setwarnings(False)

# =======================================================================
# set up GPIO mode as BOARD
# =======================================================================
GPIO.setmode(GPIO.BOARD)

# =======================================================================
#  leftL2    leftL1     center     rightL1     rightL2
#   16         18         22         40           32
# =======================================================================

leftL2 = 16                  #D
leftL1 = 18                  #B
centerL = 22                 #A
rightL1 = 40                 #C
rightL2 = 32                 #E

#========================================================================
# setup - senser
#========================================================================

GPIO.setup(leftL2, GPIO.IN)
GPIO.setup(leftL1, GPIO.IN)
GPIO.setup(centerL, GPIO.IN)
GPIO.setup(rightL1, GPIO.IN)
GPIO.setup(rightL2, GPIO.IN)

#========================================================================
# L2     L1    Center    R1    R2
#========================================================================
def get_01():
'''Show status of recognition sensor by list'''
    L2 = GPIO.input(leftL2)
    L1 = GPIO.input(leftL1)
    Center = GPIO.input(centerL)
    R1 = GPIO.input(rightL1)
    R2 = GPIO.input(rightL2)

    led_list = [L2, L1, Center, R1, R2]
    return led_list

# Distribute sensor recognition results
inLine = [[1,1,0,1,1], [1,0,0,1,1], [1,1,0,0,1],[1,0,0,0,1]]
left = [[0,1,1,1,1], [0,0,1,1,1],[1,0,1,1,1]]
right = [[1,1,1,1,0], [1,1,1,0,0],[1,1,1,0,1]]
rightTurn = [[0,0,0,0,0], [1,1,0,0,0],[1,0,0,0,0]]
leftTurn = [[0,0,0,1,1], [0,0,0,0,1]]

def line_status(led_list) :
''' Show status depending on recognized line
    led_list is status of sensor'''

    if led_list in inLine:
        status = "inLine"

    elif led_list in left :
        status = "left"

    elif led_list in right :
        status ="right"

    elif led_list in rightTurn :
        status = "right turn"

    elif led_list in leftTurn :
        status = "left or straight"

    elif led_list == [1,1,1,1,1] :
        status = "Uturn"

    else:
        status = "???"

    return status
