import RPi.GPIO as GPIO

forward0 = True
forward1 = False

Motor_Left_A = 12
Motor_Left_B = 11
Motor_Left_PWM = 35

Motor_Right_A = 15
Motor_Right_B = 13
Motor_Right_PWM = 37

GPIO.setup(Motor_Left_A,GPIO.OUT)
GPIO.setup(Motor_Left_B,GPIO.OUT)
GPIO.setup(Motor_Left_PWM,GPIO.OUT)

GPIO.setup(Motor_Right_A,GPIO.OUT)
GPIO.setup(Motor_Right_B,GPIO.OUT)
GPIO.setup(Motor_Right_PWM,GPIO.OUT)

Left_Pwm=GPIO.PWM(Motor_Left_PWM,100)
Right_Pwm=GPIO.PWM(Motor_Right_PWM,100)

def leftmotor(x):
    if x == True:
        GPIO.output(Motor_Left_A, GPIO.HIGH)
        GPIO.output(Motor_Left_B, GPIO.LOW)
    elif x == False:
        GPIO.output(Motor_Left_A, GPIO.LOW)
        GPIO.output(Motor_Left_B, GPIO.HIGH)
    else:
        print('Config Error')

def rightmotor(x):
    if x == True:
        GPIO.output(Motor_Right_A, GPIO.LOW)
        GPIO.output(Motor_Right_B, GPIO.HIGH)
    elif x == False:
        GPIO.output(Motor_Right_A, GPIO.HIGH)
        GPIO.output(Motor_Right_B, GPIO.LOW)
    else:
        print('Config Error')
