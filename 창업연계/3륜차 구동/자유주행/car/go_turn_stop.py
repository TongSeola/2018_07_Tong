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

def go_forward_any(speed):

    setup.leftmotor(setup.forward0)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    setup.rightmotor(setup.forward0)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward with the limitation of running_time
# =======================================================================

def go_forward(speed, running_time):

    setup.leftmotor(setup.forward0)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    setup.rightmotor(setup.forward0)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

    time.sleep(running_time)
    stop()

# =======================================================================
# define the stop module
# =======================================================================

def stop():
    # the speed of left motor will be set as LOW
    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)
    # the speed of right motor will be set as LOW
    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)
    # left motor will be stopped with function of ChangeDutyCycle(0)
    setup.Left_Pwm.ChangeDutyCycle(0)
    # left motor will be stopped with function of ChangeDutyCycle(0)
    setup.Right_Pwm.ChangeDutyCycle(0)


def pwm_setup():
    # left and right motor pwm will set 0 to be stable
    setup.Left_Pwm.start(0)
    setup.Right_Pwm.start(0)

# if there is unexpected occurrence
def pwm_low():
    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)
    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)
    setup.Left_Pwm.ChangeDutyCycle(0)
    setup.Right_Pwm.ChangeDutyCycle(0)
    GPIO.cleanup()

# =======================================================================
# perform right swing turn of 90 degree
# =======================================================================
def rightSwingTurn(speed, running_time):

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

# =======================================================================
# perform left swing turn of 90 degree
# =======================================================================
def leftSwingTurn(speed, running_time):

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

# =======================================================================
# round turn
# =======================================================================
def rightRoundTurn(speed_high, speed_low):

    # set the right motor to go fowrard
    setup.rightmotor(setup.forward0)

    # set the left motor to go fowrard
    setup.leftmotor(setup.forward0)

    # set the left motor pwm to be ready to go forward
    GPIO.output(setup.Motor_Left_PWM,GPIO.HIGH)

    # set the right motor pwm to be ready to stop
    # Turn Off Right PWM
    GPIO.output(setup.Motor_Right_PWM,GPIO.HIGH)

    # set the speed of the left motor to go fowrard
    setup.Left_Pwm.ChangeDutyCycle(speed_low)
    # set the speed of the right motor to stop
    setup.Right_Pwm.ChangeDutyCycle(speed_high)


