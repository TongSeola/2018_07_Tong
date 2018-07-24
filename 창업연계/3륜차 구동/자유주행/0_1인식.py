#########################################################################
# 20171618
#########################################################################

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
# declare the pins of 16, 18, 22, 40, 32 in the Rapberry Pi
# as the control pins of 5-way trackinmg sensor in order to
# control direction
#
#  leftL2    leftL1     center     rightL1     rightL2
#   16         18         22         40           32
#
# led turns on (1) : trackinmg sensor led detects white playground
# led turns off(0) : trackinmg sensor led detects black line

# leftmostled off : it means that moving object finds black line
#                   at the position of leftmostled
#                   black line locates below the leftmostled of the moving object
#
# leftlessled off : it means that moving object finds black line
#                   at the position of leftlessled
#                   black line locates below the leftlessled of the moving object
#
# centerled off : it means that moving object finds black line
#                   at the position of centerled
#                   black line locates below the centerled of the moving object
#
# rightlessled off : it means that moving object finds black line
#                   at the position of rightlessled
#                   black line locates below the rightlessled  of the moving object
#
# rightmostled off : it means that moving object finds black line
#                   at the position of rightmostled
#                   black line locates below the rightmostled of the moving object
# =======================================================================

leftL2 = 16
leftL1 = 18
center = 22
rightL1 = 40
rightL2 = 32

# =======================================================================
# because the connetions between 5-way tracking sensor and Rapberry Pi has been
# established, the GPIO pins of Rapberry Pi
# such as leftmostled, leftlessled, centerled, rightlessled, and rightmostled
# should be clearly declared whether their roles of pins
# are output pin or input pin
# since the 5-way tracking sensor data has been detected and
# used as the input data, leftmostled, leftlessled, centerled, rightlessled, and rightmostled
# should be clearly declared as input
#
# =======================================================================

GPIO.setup(leftL2, GPIO.IN)
GPIO.setup(leftL1, GPIO.IN)
GPIO.setup(centerL, GPIO.IN)
GPIO.setup(rightL1, GPIO.IN)
GPIO.setup(rightL2, GPIO.IN)

#========================================================================
# L1     L2    Center    R1    R2
#========================================================================

L1 = GPIO.input(leftL1)
L2 = GPIO.input(leftL2)
Center = GPIO.input(centerL)
R1 = GPIO.input(rightL1)
R2 = GPIO.input(rightL2)

led_list = [L1, L2, Center, R1, R2]

# ======================================================================
# led's number of cases
# ======================================================================

def makeColorList(led_list):
    for color in led_list :
        color_list = []
        if color == 0 :
            color_list.append('B')
        else:
            color_list.append('W')
    return color_list

def numberOfCases(colorList) :
    if colorList[:] == ['W', 'W', 'W', 'W', 'W']:
        state = 'outOfLine'

    elif colorList[:] == ['W', 'W', 'W', 'W', 'B']:
        state = 'rightSide'

    elif colorList[:] == ['W', 'W', 'W', 'B', 'B']:
        state = 'rightSide'

    elif colorList[:] == ['B', 'W', 'W', 'W', 'W']:
        state = 'leftSide'

    elif colorList[:] == ['B', 'B', 'W', 'W', 'W']:
        state = 'leftSide'

    elif colorList[:] == ['W', 'W', 'B', 'B', 'B']:
        state = 'inLine'

    elif colorList[:] == ['B', 'B', 'B', 'W', 'W']:
        state = 'inLine'

    elif colorList[:] == ['W', 'B', 'B', 'W', 'W']:
        state = 'inLine'

    elif colorList[:] == ['W', 'W', 'B', 'B', 'W']:
        state = 'inLine'

    elif colorList[:] == ['W', 'B', 'B', 'B', 'W']:
        state = 'inLine'

    elif colorList[:] == ['W', 'W', 'B', 'W', 'W']:
        state = 'inLine'

    elif colorList[:] == ['B', 'B', 'B', 'B', 'B']:
        state = 'final'

    return state

# =======================================================================
# GPIO.input(leftmostled) method gives the data obtained from leftmostled
# leftmostled returns (1) : leftmostled detects white playground
# leftmostled returns (0) : leftmostled detects black line
#
#
# GPIO.input(leftlessled) method gives the data obtained from leftlessled
# leftlessled returns (1) : leftlessled detects white playground
# leftlessled returns (0) : leftlessled detects black line
#
# GPIO.input(centerled) method gives the data obtained from centerled
# centerled returns (1) : centerled detects white playground
# centerled returns (0) : centerled detects black line
#
# GPIO.input(rightlessled) method gives the data obtained from rightlessled
# rightlessled returns (1) : rightlessled detects white playground
# rightlessled returns (0) : rightlessled detects black line
#
# GPIO.input(rightmostled) method gives the data obtained from rightmostled
# rightmostled returns (1) : rightmostled detects white playground
# rightmostled returns (0) : rightmostled detects black line
#
# =======================================================================


try:
    while True:
        print("leftmostled  detects black line(0) or white ground(1): " + str(GPIO.input(leftL1)))
        print("leftlessled  detects black line(0) or white ground(1): " + str(GPIO.input(leftL2)))
        print("centerled    detects black line(0) or white ground(1): " + str(GPIO.input(centerL)))
        print("rightlessled detects black line(0) or white ground(1): " + str(GPIO.input(rightL1)))
        print("rightmostled detects black line(0) or white ground(1): " + str(GPIO.input(rightL2)))
        sleep(1)

except KeyboardInterrupt:
    GPIO.cleanup()
