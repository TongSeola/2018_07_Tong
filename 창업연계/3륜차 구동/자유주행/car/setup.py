# =======================================================================
# import GPIO library module
# =======================================================================

import RPi.GPIO as GPIO

# =======================================================================
# Set the motor's true / false value to go forward.
# Set the motor's true / false value to go opposite(backward).
# =======================================================================

forward0 = True
forward1 = False

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

Left_Pwm=GPIO.PWM(MotorLeft_PWM,100)
Right_Pwm=GPIO.PWM(MotorRight_PWM,100)

# ===========================================================================
# Control the DC motor to make it rotate clockwise,
# so the car will move
# ===========================================================================

def leftmotor(x):
    if x == True:
        GPIO.output(MotorLeft_A, GPIO.HIGH)
        GPIO.output(MotorLeft_B, GPIO.LOW)
    elif x == False:
        GPIO.output(MotorLeft_A, GPIO.LOW)
        GPIO.output(MotorLeft_B, GPIO.HIGH)
    else:
        print('Config Error')

def rightmotor(x):
    if x == True:
        GPIO.output(MotorRight_A, GPIO.LOW)
        GPIO.output(MotorRight_B, GPIO.HIGH)
    elif x == False:
        GPIO.output(MotorRight_A, GPIO.HIGH)
        GPIO.output(MotorRight_B, GPIO.LOW)
    else:
        print('Config Error')
