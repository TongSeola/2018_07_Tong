import time


import RPi.GPIO as GPIO


GPIO.setmode(GPIO.BOARD)



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



GPIO.output(MotorLeft_A, GPIO.HIGH)

GPIO.output(MotorLeft_B, GPIO.LOW)

GPIO.output(MotorLeft_PWM, GPIO.HIGH)



GPIO.output(MotorRight_A, GPIO.HIGH)

GPIO.output(MotorRight_B, GPIO.LOW)

GPIO.output(MotorRight_PWM, GPIO.HIGH)



LeftPwm = GPIO.PWM(MotorLeft_PWM, 100)

RightPwm = GPIO.PWM(MotorRight_PWM, 100)



# sensor init

leftmostled = 16

leftlessled = 18

centerled = 22

rightlessled = 40

rightmostled = 32



GPIO.setup(leftmostled, GPIO.IN)

GPIO.setup(leftlessled, GPIO.IN)

GPIO.setup(centerled, GPIO.IN)

GPIO.setup(rightlessled, GPIO.IN)

GPIO.setup(rightmostled, GPIO.IN)



trig=33
echo=31

GPIO.setup(trig,GPIO.OUT)
GPIO.setup(echo,GPIO.IN)


def get_Distance():

    GPIO.output(trig,False)
    time.sleep(0.2)

    GPIO.output(trig,True)
    time.sleep(0.00001)

    GPIO.output(trig,False)

    # get time when the distance between the sensor and the obstacle is 0.
    while GPIO.input(echo) == 0 :
        pulse_start = time.time()

    # get time when the distance between the sensor and the obstacle is 1.
    while GPIO.input(echo) ==1 :
        pulse_end = time.time()

    # get time when car meet obstacle
    pulse_duration=pulse_end-pulse_start
    distance=pulse_duration*17000
    distance=round(distance,2)

    return distance


# core code

def go(leftSpeed, rightSpeed):

    LeftPwm.start(leftSpeed*2)

    RightPwm.start(rightSpeed*2)

#     time.sleep(0.0001)





def stop():

    LeftPwm.ChangeDutyCycle(0)

    RightPwm.ChangeDutyCycle(0)





result = [

    ['01111', 20, 0],

    ['00111', 20, 5],

    ['00011', 20, 7.5],

    ['10111', 20, 9],

    ['10011', 20, 14],

    ['11110', 0, 20],

    ['11100', 5, 20],

    ['11000', 7.5, 20],

    ['11101', 9, 20],

    ['11001', 14, 20],

    ['11011', 20, 20],

    ['10001', 20, 20]

]



try:

    while True:

        get_distance = get_Distacne()
        print('distance= ', get_distance)

        sensor = [

            str(GPIO.input(leftmostled)),

            str(GPIO.input(leftlessled)),

            str(GPIO.input(centerled)),

            str(GPIO.input(rightlessled)),

            str(GPIO.input(rightmostled))

        ]



        print(sensor)



        inputStream = "".join(sensor)



        for idx in range(len(result)):

            if inputStream == result[idx][0]:

                #print(result[idx])

                go(result[idx][2], result[idx][1])

                break

                pass

            pass

#         stop()

#         time.sleep(2)



except KeyboardInterrupt:

    GPIO.output(MotorLeft_PWM, GPIO.LOW)

    GPIO.output(MotorRight_PWM, GPIO.LOW)

    LeftPwm.ChangeDutyCycle(0)

    RightPwm.ChangeDutyCycle(0)

    GPIO.cleanup()