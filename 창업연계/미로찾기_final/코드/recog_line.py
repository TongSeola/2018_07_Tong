import RPi.GPIO as GPIO

GPIO.setwarnings(False)

GPIO.setmode(GPIO.BOARD)


leftL2 = 18 
leftL1 = 16 
centerL = 22 
rightL1 = 40 
rightL2 = 32 

GPIO.setup(leftL2, GPIO.IN)
GPIO.setup(leftL1, GPIO.IN)
GPIO.setup(centerL, GPIO.IN)
GPIO.setup(rightL1, GPIO.IN)
GPIO.setup(rightL2, GPIO.IN)

def get_01():
    L2 = GPIO.input(leftL2)
    L1 = GPIO.input(leftL1)
    Center = GPIO.input(centerL)
    R1 = GPIO.input(rightL1)
    R2 = GPIO.input(rightL2)

    led_list = [L1, L2, Center, R1, R2]
    return led_list

def numberOfCases(led_list) :
    if led_list[:] == [1, 1, 1, 1, 1]:
        state = 'outOfLine'

    elif led_list[:] == [1, 1, 1, 1, 0]:
        state = 'leftSide'

    elif led_list[:] == [1, 1, 1, 0, 0]:
        state = 'inLine'

    elif led_list[:] == [0, 1, 1, 1, 1]:
        state = 'rightSide'

    elif led_list[:] == [0, 0, 1, 1, 1]:
        state = 'inSide'

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
