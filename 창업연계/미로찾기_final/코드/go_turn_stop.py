import RPi.GPIO as GPIO
import time
import setup


def go_forward_any(speed):

    setup.leftmotor(setup.forward0)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    setup.rightmotor(setup.forward0)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

def go_forward(speed, running_time):

    setup.leftmotor(setup.forward0)
    GPIO.output(setup.Motor_Left_PWM, GPIO.HIGH)

    setup.rightmotor(setup.forward0)
    GPIO.output(setup.Motor_Right_PWM, GPIO.HIGH)

    setup.Left_Pwm.ChangeDutyCycle(speed)
    setup.Right_Pwm.ChangeDutyCycle(speed)

    time.sleep(running_time)
    stop()

def stop():

    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)

    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)

    setup.Left_Pwm.ChangeDutyCycle(0)

    setup.Right_Pwm.ChangeDutyCycle(0)


def pwm_setup():

    setup.Left_Pwm.start(0)
    setup.Right_Pwm.start(0)


def pwm_low():
    GPIO.output(setup.Motor_Left_PWM, GPIO.LOW)
    GPIO.output(setup.Motor_Right_PWM, GPIO.LOW)
    setup.Left_Pwm.ChangeDutyCycle(0)
    setup.Right_Pwm.ChangeDutyCycle(0)
    GPIO.cleanup()

def rightSwingTurn(speed, running_time):

    setup.leftmotor(setup.forward0)

    GPIO.output(setup.Motor_Left_PWM,GPIO.HIGH)
    GPIO.output(setup.Motor_Right_PWM,GPIO.LOW)

    setup.Left_Pwm.ChangeDutyCycle(speed)

    setup.Right_Pwm.ChangeDutyCycle(0)

    time.sleep(running_time)



def leftSwingTurn(speed, running_time):

    GPIO.output(setup.Motor_Left_PWM,GPIO.LOW)

    setup.rightmotor(setup.forward0)

    GPIO.output(setup.Motor_Right_PWM,GPIO.HIGH)

    setup.Left_Pwm.ChangeDutyCycle(0)

    setup.Right_Pwm.ChangeDutyCycle(speed)

    time.sleep(running_time)



def rightRoundTurn(speed_high, speed_low):

    setup.rightmotor(setup.forward0)

    setup.leftmotor(setup.forward0)

    GPIO.output(setup.Motor_Left_PWM,GPIO.HIGH)

    GPIO.output(setup.Motor_Right_PWM,GPIO.HIGH)


    setup.Left_Pwm.ChangeDutyCycle(speed_low)

    setup.Right_Pwm.ChangeDutyCycle(speed_high)


