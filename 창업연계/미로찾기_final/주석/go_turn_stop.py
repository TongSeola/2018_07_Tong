# =======================================================================
# this code is for defining functions - go_forward, stop, and turn modules
# =======================================================================
# latest modification on 9.Dec.2017
# =======================================================================
# import GPIO library and time module
# =======================================================================

import RPi.GPIO as GPIO
import time

# ======================================================================
# import setup to get pins and True or False
# The motor set to go
# The import motor module to move
# ======================================================================
import setup

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward without any limitation of running_time
# =======================================================================

def go_forward(speed):
''' move forward
    speed is motor move speed(0~100)'''
    # set left and right motor to move forward
    setup.leftmotor(setup.forward0)
    setup.rightmotor(setup.forward0)
    # set speed of motors to move forward
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

# =======================================================================
# define the stop module
# =======================================================================

def stop():
'''stop the motor'''
    # the speed of left motor will be set as LOW
    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)
    # the speed of right motor will be set as LOW
    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)
    # left motor will be stopped with function of ChangeDutyCycle(0)
    setup.Left_Pwm.ChangeDutyCycle(0)
    # left motor will be stopped with function of ChangeDutyCycle(0)
    setup.Right_Pwm.ChangeDutyCycle(0)


def pwm_setup():
'''set and initialize pwm'''
    # left and right motor pwm will set 0 to be stable
    setup.Left_Pwm.start(0)
    setup.Right_Pwm.start(0)

def pwm_low():
'''stop the motor and initialize'''
    stop()
    GPIO.cleanup()

# =======================================================================
# perform right swing turn of 90 degree
# =======================================================================
def right_turn(speed, running_time):
'''Only the left wheel move forward to right turn
   speed is turn speed
   running_time is the time the wheel move'''

    # set the left motor to go fowrard
    setup.leftmotor(setup.forward0)
    # set the left motor pwm to be ready to go forward
    GPIO.output(setup.Motor_Left_PWM,GPIO.HIGH)

    # set the right motor pwm to be ready to stop
    # Turn Off Right PWM
    GPIO.output(setup.Motor_Right_PWM,GPIO.LOW)

    # set the speed of the left motor to go fowrard
    setup.Left_Pwm.ChangeDutyCycle(speed)
    # set the speed of the right motor to stop
    setup.Right_Pwm.ChangeDutyCycle(0)

    # set the running time of the left motor to go fowrard
    time.sleep(running_time)


def right_turn2(speed, running_time):
'''Move the left wheel forward and Turn the right wheel backward to right turn
   speed is turn speed
   running_time is the time the wheels move'''

    # set the left motor and pwm to move forward 
    setup.leftmotor(setup.forward0)
    GPIO.output(setup.Motor_Left_PWM,GPIO.HIGH)
    # set the right motor and pwm to move backward
    setup.rightmotor(setup.backward0)
    GPIO.output(setup.Motor_Right_PWM,GPIO.LOW)
    # set the speed of the left and right motor
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)
    # set the running time of the motors to move
    time.sleep(running_time)


# =======================================================================
# perform left swing turn of 90 degree
# =======================================================================
def left_turn(speed, running_time):
'''Only the right wheel move forward to left turn
   speed is turn speed
   running_time is the time the wheel move'''

    # set the left motor pwm to be ready to stop
    # Turn Off Left PWM
    GPIO.output(setup.Motor_Left_PWM,GPIO.LOW)

    # set the right motor to go fowrard
    setup.rightmotor(setup.forward0)
    # set the right motor pwm to be ready to go forward
    GPIO.output(setup.Motor_Right_PWM,GPIO.HIGH)

    # set the speed of the left motor to stop
    setup.Left_Pwm.ChangeDutyCycle(0)
    # set the speed of the right motor to go fowrard
    setup.Right_Pwm.ChangeDutyCycle(speed)

    # set the running time of the right motor to go fowrard
    time.sleep(running_time)

def left_turn2(speed, running_time):
'''Move the right wheel forward and Turn the left wheel backward to left turn
   speed is turn speed
   running_time is the time the wheels move'''

    # set the right motor and pwm to move forward 
    setup.rightmotor(setup.forward0)
    GPIO.output(setup.Motor_Right_PWM,GPIO.HIGH)
    # set the left motor and pwm to move backward
    setup.leftmotor(setup.backward0)
    GPIO.output(setup.Motor_Left_PWM,GPIO.LOW)
    # set the speed of the left and right motor
    setup.Right_Pwm.ChangeDutyCycle(speed)
    setup.Left_Pwm.ChangeDutyCycle(speed)
    # set the running time of the motors to move
    time.sleep(running_time)



