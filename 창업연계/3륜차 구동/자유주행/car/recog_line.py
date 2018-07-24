
# =======================================================================
# import GPIO library and time module
# =======================================================================
import RPi.GPIO as GPIO
from time import sleep

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

leftL2 = 16 #1
leftL1 = 18 #2
centerL = 22 #3
rightL1 = 40 #4
rightL2 = 32 #5

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
    L2 = GPIO.input(leftL2)
    L1 = GPIO.input(leftL1)
    Center = GPIO.input(centerL)
    R1 = GPIO.input(rightL1)
    R2 = GPIO.input(rightL2)

    led_list = [L1, L2, Center, R1, R2]
    return led_list

# ======================================================================
# led's number of cases
# ======================================================================

def numberOfCases(led_list) :
    if led_list[:] == [1, 1, 1, 1, 1]:
        state = 'outOfLine'

    elif led_list[:] == [1, 1, 1, 1, 0]:
        state = 'leftSide'

    elif led_list[:] == [1, 1, 1, 0, 0]:
        state = 'leftSide'

    elif led_list[:] == [0, 1, 1, 1, 1]:
        state = 'rightSide'

    elif led_list[:] == [0, 0, 1, 1, 1]:
        state = 'rightSide'

    elif led_list[:] == [1, 1, 0, 0, 0]:
        state = 'inLine'

    elif led_list[:] == [0, 0, 0, 1, 1]:
        state = 'inLine'

    elif led_list[:] == [1, 0, 0, 1, 1]:
        state = 'inLine'

    elif led_list[:] == [1, 1, 0, 0, 1]:
        state = 'inLine'

    elif led_list[:] == [1, 0, 0, 0, 1]:
        state = 'inLine'

    elif led_list[:] == [1, 1, 0, 1, 1]:
        state = 'inLine'

    elif led_list[:] == [1, 0, 1, 1, 1]:
        state = 'inLine'

    elif led_list[:] == [1, 1, 1, 0, 1]:
        state = 'inLine'

    elif led_list[:] == [0, 0, 0, 0, 0]:
        state = 'final'

    else :
        state = "outOfLine"

    return state
