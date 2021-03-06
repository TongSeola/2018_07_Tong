######################################################################
### Date: 2017/10/5
### file name: go_any.py
### Purpose: this code has been generated for the three-wheeled moving
###         object to go forward or backward without time limit
######################################################################

# import GPIO library
import RPi.GPIO as GPIO

import time

# set GPIO warnings as flase
GPIO.setwarnings(False)

# set up GPIO mode as BOARD
GPIO.setmode(GPIO.BOARD)

# =======================================================================
# Set the motor's true / false value to go forward.
# Set the motor's true / false value to go opposite.
# =======================================================================
forward0 = True
forward1 = False
backward0 = not forward0
backward1 = not forward1

# =======================================================================
# declare the pins of 12, 11, 35 in the Rapberry Pi
# as the left motor control pins in order to control left motor
# left motor needs three pins to be controlled
# =======================================================================
MotorLeft_A = 12
MotorLeft_B = 11
MotorLeft_PWM = 35

# =======================================================================
# declare the pins of 15, 13, 37 in the Rapberry Pi
# as the right motor control pins in order to control right motor
# right motor needs three pins to be controlled
# =======================================================================
MotorRight_A = 15
MotorRight_B = 13
MotorRight_PWM = 37

# ===========================================================================
# Control the DC motor to make it rotate clockwise, so the car will
# move forward.
# if you have different direction, you need to change HIGH to LOW
# or LOW to HIGH,in MotorLeft_A
# and LOW to HIGH or HIGH to LOW in MotorLeft_B
# if you have different direction, you need to change HIGH to LOW
# or LOW to HIGH in MotorLeft_A
# and LOW to HIGH or HIGH to LOW in MotorLeft_B
# ===========================================================================

'''def leftmotor(x):
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
        print('Config Error')'''

def motor(x, Motor_A, Motor_B):
    #set motor to move low and high
    if x == 'True':
        GPIO.output(Motor_A, GPIO.LOW)
        GPIO.output(Motor_B, GPIO.HIGH)
    elif x == 'False':
        GPIO.output(Motor_A, GPIO.HIGH)
        GPIO.output(Motor_B, GPIO.LOW)
    else:
        print('Config Error')


# =======================================================================
# because the connetions between motors (left motor) and Rapberry Pi has been
# established, the GPIO pins of Rapberry Pi
# such as MotorLeft_A, MotorLeft_B, and MotorLeft_PWM
# should be clearly declared whether their roles of pins
# are output pin or input pin
# =======================================================================

GPIO.setup(MotorLeft_A, GPIO.OUT)
GPIO.setup(MotorLeft_B, GPIO.OUT)
GPIO.setup(MotorLeft_PWM, GPIO.OUT)

# =======================================================================
# because the connetions between motors (right motor) and Rapberry Pi has been
# established, the GPIO pins of Rapberry Pi
# such as MotorLeft_A, MotorLeft_B, and MotorLeft_PWM
# should be clearly declared whether their roles of pins
# are output pin or input pin
# =======================================================================

GPIO.setup(MotorRight_A, GPIO.OUT)
GPIO.setup(MotorRight_B, GPIO.OUT)
GPIO.setup(MotorRight_PWM, GPIO.OUT)

# =======================================================================
# create left pwm object to control the speed of left motor
# create right pwm object to control the speed of right motor
# =======================================================================

LeftPwm = GPIO.PWM(MotorLeft_PWM, 100)
RightPwm = GPIO.PWM(MotorRight_PWM, 100)

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward without any limitation of running_time
# =======================================================================

def go_forward_any(speed):
    # to go forward to gain speed
    motor(forward0, MotorRight_A, MotorRight_B)
    motor(forward1, MotorLeft_A, MotorLeft_B)
    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)

# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward without any limitation of running_time
# =======================================================================

def go_backward_any(speed):
    # to go backward to gain speed
    motor(backward0, MotorRight_A, MotorRight_B)
    motor(backward1, MotorLeft_A, MotorLeft_B)
    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward with the limitation of running_time
# =======================================================================

def go_forward(speed, running_time):
    # to go foward with speed and running time

    #set motor to go forward
    motor(forward0, MotorRight_A, MotorRight_B)
    motor(forward1, MotorLeft_A, MotorLeft_B)
    #set speed
    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)
    #set running time
    time.sleep(running_time)

# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward with the limitation of running_time
# =======================================================================

def go_backward(speed, running_time):
    # to go backward with speed and running time

    #set motor to go back
    motor(backward0, MotorRight_A, MotorRight_B)
    motor(backward1, MotorLeft_A, MotorLeft_B)
    #set speed
    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)
    #set running time
    time.sleep(running_time)

# =======================================================================
# define the stop module
# =======================================================================
def stop():
    # the speed of left motor will be set as LOW
    GPIO.output(MotorLeft_PWM, GPIO.LOW)
    # the speed of right motor will be set as LOW
    GPIO.output(MotorRight_PWM, GPIO.LOW)
    # left motor will be stopped with function of ChangeDutyCycle(0)
    LeftPwm.ChangeDutyCycle(0)
    # left motor will be stopped with function of ChangeDutyCycle(0)
    RightPwm.ChangeDutyCycle(0)


def pwm_setup():
    LeftPwm.start(0)
    RightPwm.start(0)


def pwm_low():
    GPIO.output(MotorLeft_PWM, GPIO.LOW)
    GPIO.output(MotorRight_PWM, GPIO.LOW)
    LeftPwm.ChangeDutyCycle(0)
    RightPwm.ChangeDutyCycle(0)
    GPIO.cleanup()