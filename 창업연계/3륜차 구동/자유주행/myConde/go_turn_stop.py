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

def just_go_forward(speed):

    # set left motor to go forward by GPIO and motor_module
    setup.motor(setup.forward0, setup.Motor_Left_A, setup.Motor_Left_B)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    # set right motor to go forward by GPIO and motor_module
    setup.motor(setup.forward1, setup.Motor_Right_A, setup.Motor_Right_B)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    # set left and right Pwm to get speed
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward without any limitation of running_time
# =======================================================================

def just_go_backward(speed):

    # set left motor to go backward by GPIO and motor_module
    setup.motor(setup.backward0, setup.Motor_Left_A, setup.Motor_Left_B)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    # set right motor to go backward by GPIO and motor_module
    setup.motor(setup.backward1, setup.Motor_Right_A, setup.Motor_Right_B)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    # set left and right Pwm to get speed
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward with the limitation of running_time
# =======================================================================

def go_forward(speed, running_time):

    # set left motor to go forward by GPIO and motor_module
    setup.motor(setup.forward0, setup.Motor_Left_A, setup.Motor_Left_B)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    # set right motor to go forward by GPIO and motor_module
    setup.motor(setup.forward1, setup.Motor_Right_A, setup.Motor_Right_B)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    # set left and right Pwm to get speed
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

    # stop motor after running_time
    time.sleep(running_time)
    stop()

# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward with the limitation of running_time
# =======================================================================

def go_backward(speed, running_time):

    # set left motor to go backward by GPIO and motor_module
    setup.motor(setup.backward0, setup.Motor_Left_A, setup.Motor_Left_B)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    # set right motor to go backward by GPIO and motor_module
    setup.motor(setup.backward1, setup.Motor_Right_A, setup.Motor_Right_B)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    # set left and right Pwm to get speed
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

    # stop motor after running_time
    time.sleep(running_time)
    stop()


# =======================================================================
# define the stop module
# =======================================================================

def stop():
    # the speed of left and right motor will be set as LOW
    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)
    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)
    # left and right motor will be stopped with function of ChangeDutyCycle(0)
    setup.Left_Pwm.ChangeDutyCycle(0)
    setup.Right_Pwm.ChangeDutyCycle(0)


def pwm_setup():
    # left and right motor pwm will set 0 to be stable
    setup.Left_Pwm.start(0)
    setup.Right_Pwm.start(0)

# if there is unexpected occurrence
def pwm_low():
    #make motor as LOW and stop
    stop()
    # set GPIO clear
    GPIO.cleanup()

# =======================================================================
# perform right swing turn of 90 degree
# Turn right with left motor(go forward)
# =======================================================================

def right_SwingTurn(speed, running_time):

    # set the left motor and pwm to go forwrard
    setup.motor(setup.forward0, setup.Motor_Left_A, setup.Motor_Left_B)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    # set the right motor pwm to stop = turn off
    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)

    # set the speed of the left motor to go forward
    setup.Left_Pwm.ChangeDutyCycle(speed)
    # set the speed of the right motor to stop
    setup.Right_Pwm.ChangeDutyCycle(0)

    # set the running time of the left motor to go forward
    time.sleep(running_time)

# =======================================================================
# perform left swing turn of 90 degree
# Turn left with right motor(go forward)
# =======================================================================

def left_SwingTurn(speed, running_time):

    # set the left motor pwm to stop = turn off
    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)

    # set the right motor and pwm to go forward
    setup.motor(setup.forward0, setup.Motor_Right_A, setup.Motor_Right_B)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    # set the speed of the left motor to stop
    setup.Left_Pwm.ChangeDutyCycle(0)
    # set the spedd of the right motor to go forward
    setup.Right_Pwm.ChangeDutyCycle(speed)

    # set the running tiem of the right motor to go forward
    time.sleep(running_time)

# =======================================================================
# perform right point turn of 90 degree
# Turn right with left motor(forward) and right motor(backward)
# ======================================================================

def right_PointTurn(speed, running_time):

    # set the left motor and pwm to go forward
    setup.motor(setup.forward0, setup.Motor_Left_A, setup.Motor_Left_B)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    # set the right motor and pwm to go backward
    setup.motor(setup.backward1, setup.Motor_Right_A, setup.Motor_Right_B)
    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)

    # set the speed of the left and right motor to go
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

    # set the running time of the left and right motor
    time.sleep(running_time)

#=======================================================================
# perform left point turn of 90 degree
# Turn left with right motor(forward) and left motor(backward)
# ======================================================================

def left_PointTurn(speed, running_time):

    # set the left motor and pwm to go backward
    setup.motor(setup.bakward0, setup.Motor_Left_A, setup.Motor_Left_B)
    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)

    # set the right motor and pwm to go forward
    setup.motor(setup.forward1, setup.Motor_Right_A, setup.Motor_Right_B)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    # set the speed of the left and right motor to go
    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

    # set the running time of the left and right motor
    time.sleep(running_time)
