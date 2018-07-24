######################################################################
# 20171618 Dong_Seola 's code
# this for_back_ward.py file is
# to control raspberry car's go forward and backward
# to motor stop or setup 0
######################################################################

# =======================================================================
# import GPIO library and time module
# =======================================================================

import RPi.GPIO as GPIO
import time


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

# =======================================================================
# set Both wheel to move by GPIO
# =======================================================================

GPIO.setup(MotorLeft_A,GPIO.OUT)
GPIO.setup(MotorLeft_B,GPIO.OUT)
GPIO.setup(MotorLeft_PWM,GPIO.OUT)

GPIO.setup(MotorRight_A,GPIO.OUT)
GPIO.setup(MotorRight_B,GPIO.OUT)
GPIO.setup(MotorRight_PWM,GPIO.OUT)

# =======================================================================
# create left and right pwm object to control the speed of left motor
# The speed is between 0 and 100
# =======================================================================

LeftPwm=GPIO.PWM(MotorLeft_PWM,100)
RightPwm=GPIO.PWM(MotorRight_PWM,100)

# ===========================================================================
# Control the DC motor to make it rotate clockwise,
# so the car will move forward.
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

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward without any limitation of running_time
# =======================================================================

def go_forward_any(speed):

    leftmotor(forward0)
    GPIO.output(MotorLeft_PWM, GPIO.HIGH)

    rightmotor(forward0)
    GPIO.output(MotorRight_PWM, GPIO.HIGH)

    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)



# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward without any limitation of running_time
# =======================================================================

def go_backward_any(speed):

    leftmotor(backward0)
    GPIO.output(MotorLeft_PWM, GPIO.HIGH)

    rightmotor(backward0)
    GPIO.output(MotorRight_PWM, GPIO.HIGH)

    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward with the limitation of running_time
# =======================================================================

def go_forward(speed, running_time):

    leftmotor(forward0)
    GPIO.output(MotorLeft_PWM, GPIO.HIGH)

    rightmotor(forward0)
    GPIO.output(MotorRight_PWM, GPIO.HIGH)

    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)

    time.sleep(running_time)
    stop()

# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward with the limitation of running_time
# =======================================================================

def go_backward(speed, running_time):

    leftmotor(backward0)
    GPIO.output(MotorLeft_PWM, GPIO.HIGH)

    rightmotor(backward0)
    GPIO.output(MotorRight_PWM, GPIO.HIGH)

    LeftPwm.ChangeDutyCycle(speed)
    RightPwm.ChangeDutyCycle(speed)

    time.sleep(running_tim)
    stop()


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
    # left and right motor pwm will set 0 to be stable
    LeftPwm.start(0)
    RightPwm.start(0)

# if there is unexpected occurrence
def pwm_low():
    GPIO.output(MotorLeft_PWM, GPIO.LOW)
    GPIO.output(MotorRight_PWM, GPIO.LOW)
    LeftPwm.ChangeDutyCycle(0)
    RightPwm.ChangeDutyCycle(0)
    GPIO.cleanup()