# import GPIO library
import RPi.GPIO as GPIO

import time

# set GPIO warnings as flase
GPIO.setwarnings(False)

# set up GPIO mode as BOARD
GPIO.setmode(GPIO.BOARD)

# =========================================================

trig=33
echo=31

#ultrasonic sensor setting
GPIO.setup(trig,GPIO.OUT)
GPIO.setup(echo,GPIO.IN)

def getDistance():
    GPIO.output(trig,False)
    time.sleep(0.5)
    GPIO.output(trig,True)
    time.sleep(0.00001)
    GPIO.output(trig,False)
    while GPIO.input(echo)==0:
        pulse_start=time.time()
    while GPIO.input(echo)==1:
        pulse_end=time.time()
    pulse_duration=pulse_end-pulse_start
    distance=pulse_duration*17000
    distance=round(distance,2)
    return distance

# ==========================================================
forward0 = True
forward1 = False
backward0 = not forward0
backward1 = not forward1

MotorLeft_A = 12
MotorLeft_B = 11
MotorLeft_PWM = 35

MotorRight_A = 15
MotorRight_B = 13
MotorRight_PWM = 37

GPIO.setup(MotorLeft_A, GPIO.OUT)
GPIO.setup(MotorLeft_B, GPIO.OUT)
GPIO.setup(MotorLeft_PWM, GPIO.OUT)


GPIO.setup(MotorRight_A, GPIO.OUT)
GPIO.setup(MotorRight_B, GPIO.OUT)
GPIO.setup(MotorRight_PWM, GPIO.OUT)


LeftPwm = GPIO.PWM(MotorLeft_PWM, 100)
RightPwm = GPIO.PWM(MotorRight_PWM, 100)

# =======================================================

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

def go_forward_any(speed):

    # set the left motor to go forward
    leftmotor(forward0)
    # GPIO.output(MotorLeft_A,GPIO.HIGH)
    # GPIO.output(MotorLeft_B,GPIO.LOW)

    # ------------------------------------------------------------
    # if you have different direction, you need to change HIGH to LOW
    # in MotorLeft_A and MotorLeft_B
    # or use leftmotor(forward1)
    # ------------------------------------------------------------
    # leftmotor(forward1)


    GPIO.output(MotorLeft_PWM, GPIO.HIGH)

    # set the right motor to go forward
    rightmotor(forward0)
    # GPIO.output(MotorRight_A,GPIO.LOW)
    # GPIO.output(MotorRight_B,GPIO.HIGH)

    # ------------------------------------------------------------
    # if you have different direction, you need to change HIGH to LOW
    # in MotorLeft_A and MotorLeft_B
    # or use rightmotor(forward1)
    # ------------------------------------------------------------
    # rightmotor(forward1)


    GPIO.output(MotorRight_PWM, GPIO.HIGH)
    # set the speed of the left motor to go forward
    LeftPwm.ChangeDutyCycle(speed)
    # set the speed of the right motor to go forward
    RightPwm.ChangeDutyCycle(speed)
    # set the running time of the left motor to go forward

# ==============================================================================

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

# =============================================================================

def rightSwingTurn(speed, running_time):

    # set the left motor to go fowrard
    leftmotor(forward0)
    #leftmotor(forward1)

    # set the left motor pwm to be ready to go forward
    GPIO.output(MotorLeft_PWM,GPIO.HIGH)

    # set the right motor pwm to be ready to stop
    # Turn Off Right PWM
    GPIO.output(MotorRight_PWM,GPIO.LOW)
    # set the speed of the left motor to go fowrard
    LeftPwm.ChangeDutyCycle(speed)
    # set the speed of the right motor to stop
    RightPwm.ChangeDutyCycle(0)
    # set the running time of the left motor to go fowrard
    time.sleep(running_time)

def rightPointTurn(speed, running_time):

    # set the left motor to go fowrard
    leftmotor(forward0)
    #leftmotor(forward1)

    # set the left motor pwm to be ready to go forward
    GPIO.output(MotorLeft_PWM,GPIO.HIGH)

    # set the right motor pwm to be ready to stop
    # Turn Off Right PWM
    GPIO.output(MotorRight_PWM,GPIO.LOW)
    # set the speed of the left motor to go fowrard
    LeftPwm.ChangeDutyCycle(speed)
    # set the speed of the right motor to stop
    RightPwm.ChangeDutyCycle(speed*(-1))
    # set the running time of the left motor to go fowrard
    time.sleep(running_time)

# ==============================================================================

dis = 17
obstacle = 1

# when obstacle=1, the power and
# running time of the first turn
SwingPr = 5  # student assignment (8)
SwingTr = 0.2  # student assignment (9)
turnspeed = 0.2


try:
    while True:
        # ultra sensor replies the distance back
        distance = getDistance()
        print('distance= ', distance)

        # when the distance is above the dis, moving object forwards
        if (distance > dis):
            go_forward_any(turnspeed)
            print('obstacle=', obstacle)

        # when the distance is below the dis, moving object stops
        else:
            if obstacle ==1 :
                rightSwingTurn(SwingPr,SwingTr)
                # stop and wait 1 second
                time.sleep(1)
                obstacle +=1
            elif obstacle ==2 :
                rightPointTurn(SwingPr,SwingTr)
                time.sleep(1)
                obstacle+=1
            else :
                stop()


            ########################################################
            ### please continue the code or change the above code
            ### # student assignment (10)
            ########################################################


# when the Ctrl+C key has been pressed,
# the moving object will be stopped

except KeyboardInterrupt:
    pwm_low()