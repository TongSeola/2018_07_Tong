# import GPIO library
import RPi.GPIO as GPIO

from time import sleep

# set GPIO warnings as flase
GPIO.setwarnings(False)

# set up GPIO mode as BOARD
GPIO.setmode(GPIO.BOARD)

# =======================================================================
# REVERSE function to control the direction of motor in reverse
# Set the motor's true / false value to go forward, opposite
# =======================================================================

forward0 = True
forward1 = False

backward0 = not forward0
backward1 = not forward1

# =======================================================================
# declare the pins of 12, 11, 35 in the Rapberry Pi
# as the left motor control pins in order to control left motor
# left motor needs three pins to be controlled

# declare the pins of 15, 13, 37 in the Rapberry Pi
# as the right motor control pins in order to control right motor
# right motor needs three pins to be controlled
# =======================================================================

MotorLeft_A = 12
MotorLeft_B = 11
MotorLeft_PWM = 35

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
    else :
        print('Config Error')

def motor(x, Motor_A, Motor_B):
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
# create pwm object to control the speed of left or right motor
# =======================================================================
LeftPwm = GPIO.PWM(MotorLeft_PWM, 100)
RightPwm = GPIO.PWM(MotorRight_PWM, 100)

#=======================================================================
# make function to set speed motor
#=======================================================================

def setSpeed(speed) :


# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward without any limitation of running_time
# =======================================================================

def go_forward_any(speed):
   # setSpeed(speed)
    motor(forward0, MotorRight_A, MotorRight_B)
    motor(forward1, MotorLeft_A, MotorLeft_B)

# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward without any limitation of running_time
# =======================================================================

def go_backward_any(speed):
    # setSpeed(speed)
    motor(backward0, MotorRight_A, MotorRight_B)
    motor(backward1, MotorLeft_A, MotorLeft_B)

# =======================================================================
#  go_forward_any method has been generated for the three-wheeled moving
#  objec to go forward with the limitation of running_time
# =======================================================================

def go_forward(speed, running_time):
    motor(forward0, MotorRight_A, MotorRight_B)
    motor(forward1, MotorLeft_A, MotorLeft_B)
    time.sleep(running_time)
    stop()

# =======================================================================
#  go_backward_any method has been generated for the three-wheeled moving
#  objec to go backward with the limitation of running_time
# =======================================================================

def go_backward(speed, running_time):
    motor(backward0, MotorRight_A, MotorRight_B)
    motor(backward1, MotorLeft_A, MotorLeft_B)
    time.sleep(running_time)
    stop()


# =======================================================================
# define the stop module
# =======================================================================
def stop():
    pwm_low()

def pwm_setup():
    LeftPwm.start(0)
    RightPwm.start(0)

def pwm_low():
    GPIO.output(MotorLeft_PWM, GPIO.LOW)
    GPIO.output(MotorRight_PWM, GPIO.LOW)
    LeftPwm.ChangeDutyCycle(0)
    RightPwm.ChangeDutyCycle(0)
    GPIO.cleanup()

#############################################################################

# =======================================================================
# perform right swing turn of 90 degree
# =======================================================================
def rightSwingTurn(speed, running_time):
    # set the left motor to go fowrard
    leftmotor(forward0)
    # leftmotor(forward1)

    # set the left motor pwm to be ready to go forward
    GPIO.output(MotorLeft_PWM, GPIO.HIGH)

    # set the right motor pwm to be ready to stop
    # Turn Off Right PWM
    GPIO.output(MotorRight_PWM, GPIO.LOW)
    # set the speed of the left motor to go fowrard
    LeftPwm.ChangeDutyCycle(speed)
    # set the speed of the right motor to stop
    RightPwm.ChangeDutyCycle(0)
    # set the running time of the left motor to go fowrard
    time.sleep(running_time)

# =======================================================================
# perform left swing turn of 90 degree
# =======================================================================
def leftSwingTurn(speed, running_time):
    # set the left motor pwm to be ready to stop
    # Turn Off Left PWM
    GPIO.output(MotorLeft_PWM, GPIO.LOW)

    # set the right motor to go fowrard
    rightmotor(forward0)

    # set the right motor pwm to be ready to go forward
    GPIO.output(MotorRight_PWM, GPIO.HIGH)

    # set the speed of the left motor to stop
    LeftPwm.ChangeDutyCycle(0)
    # set the speed of the right motor to go fowrard
    RightPwm.ChangeDutyCycle(speed)
    # set the running time of the right motor to go fowrard
    time.sleep(running_time)

# =======================================================================
# perform right point turn of 90 degree  # student assignment (1)
# ======================================================================

def rightPointTurn(speed, running_time):  # student assignment (1)

# =======================================================================
# perform left point turn of 90 degree   # student assignment (2)
# ======================================================================

def leftPointTurn(speed, running_time):  # student assignment (2)