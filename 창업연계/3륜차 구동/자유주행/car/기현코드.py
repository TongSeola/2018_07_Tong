# =======================================================================
# import GPIO library and time module
# =======================================================================

import RPi.GPIO as GPIO
import time

# =====================================================================
# declare the pins of 33, 31 in the Rapberry Pi
# these pins are control ultrasonic sensor
# ultrasonic sensor needs two pins to be controlled
# ultrasonic sensor setting
# ====================================================================

GPIO.setmode(GPIO.BOARD)
trig=33
echo=31

GPIO.setup(trig,GPIO.OUT)
GPIO.setup(echo,GPIO.IN)

# =======================================================================
# activate ultrasonic sensor to measure the distance
# ======================================================================

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

get_distance = recog_obs.get_Distacne()
print('distance= ',get_distance)

def evasion() :

    # Swing Turn 's angle
    right_turn_speed = 50
    right_turn_time = 0.4

    # Point Turn 's angle
    left_turn_speed = 30
    left_turn_time = 0.4

    # The speed that the executor wants
    speed = 43
    go_time = 1.5

    try:
        go_turn_stop.rightSwingTurn(right_turn_speed, right_turn_time)
        time.sleep(1)

        go_turn_stop.go_forward(speed,go_time)

        go_turn_stop.leftSwingTurn(left_turn_speed, left_turn_time)
        time.sleep(1)
        WB = recog_line.get_01()

        while recog_line.numberOfCases(WB) != 'inLine' :
            go_turn_stop.go_forward_any(speed)
        else :
            time.sleep(1)
            break

    except :
        pass
