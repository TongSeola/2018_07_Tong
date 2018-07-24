# =======================================================================
# import GPIO library module
# =======================================================================

import RPi.GPIO as GPIO

# =======================================================================
# Set the motor's true / false value to go forward.
# Set the motor's true / false value to go opposite(backward).
# =======================================================================

forward0 = True
backward0 = False

# =======================================================================
# declare the pins of 12, 11, 35 in the Rapberry Pi
# as the left motor control pins in order to control left motor
# left motor needs three pins to be controlled
# =======================================================================

Motor_Left_A = 12
Motor_Left_B = 11
Motor_Left_PWM = 35

# =======================================================================
# declare the pins of 15, 13, 37 in the Rapberry Pi
# as the right motor control pins in order to control right motor
# right motor needs three pins to be controlled
# =======================================================================

Motor_Right_A = 15
Motor_Right_B = 13
Motor_Right_PWM = 37

# =======================================================================
# set Both wheel to move by GPIO
# =======================================================================
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

GPIO.setup(Motor_Left_A,GPIO.OUT)
GPIO.setup(Motor_Left_B,GPIO.OUT)
GPIO.setup(Motor_Left_PWM,GPIO.OUT)

GPIO.setup(Motor_Right_A,GPIO.OUT)
GPIO.setup(Motor_Right_B,GPIO.OUT)
GPIO.setup(Motor_Right_PWM,GPIO.OUT)

# =======================================================================
# create left and right pwm object to control the speed of left motor
# The speed is between 0 and 100
# =======================================================================

GPIO.output(Motor_Left_PWM, GPIO.HIGH)
GPIO.output(Motor_Right_PWM, GPIO.HIGH)
Left_Pwm=GPIO.PWM(Motor_Left_PWM,100)
Right_Pwm=GPIO.PWM(Motor_Right_PWM,100)

# ===========================================================================
# Control the DC motor to make it rotate clockwise,
# so the car will move
# ===========================================================================

def leftmotor(forward):
''' Drive left wheel
    if forward is True, move forward
    if forward is False, move backward '''

    if forward == True:
        GPIO.output(Motor_Left_A, GPIO.HIGH)
        GPIO.output(Motor_Left_B, GPIO.LOW)
    elif forward == False:
        GPIO.output(Motor_Left_A, GPIO.LOW)
        GPIO.output(Motor_Left_B, GPIO.HIGH)
    else:
        print('Config Error')

def rightmotor(forward):
''' Drive right wheel
    if forward is True, move forward
    if forward is False, move backward '''

    if forward == True:
        GPIO.output(Motor_Right_A, GPIO.LOW)
        GPIO.output(Motor_Right_B, GPIO.HIGH)
    elif forward == False:
        GPIO.output(Motor_Right_A, GPIO.HIGH)
        GPIO.output(Motor_Right_B, GPIO.LOW)
    else:
        print('Config Error')
