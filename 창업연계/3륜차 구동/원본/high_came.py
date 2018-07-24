######################################################################
# 20171618 Dong_Seola 's code
# The high_came.py file is
# to control ultrasonic sensor
######################################################################

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

trig=33
echo=31

GPIO.setup(trig,GPIO.OUT)
GPIO.setup(echo,GPIO.IN)

# =======================================================================
# activate ultrasonic sensor to measure the distance
# ======================================================================

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
