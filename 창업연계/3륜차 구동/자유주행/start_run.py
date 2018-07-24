import evasion_obs
import go_turn_stop
import recog_obs
import recog_line
import setup
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
go_turn_stop.pwm_setup()

dis = 17  #20
speed = 20
time = 0.5

try:
    while True:
        # ultra sensor replies the distance back
        get_distance = recog_obs.get_Distacne()
        print('distance= ',get_distance)

        # when the distance is above the dis, moving object forwards
        while (get_distance > dis):
            W_and_B = recog_line.get_01()
            if recog_line.numberOfCases(W_and_B) == 'inLine' :
                go_turn_stop.go_forward(speed, time)

            elif recog_line.numberOfCases(W_and_B) == 'leftSide' :
                go_turn_stop.rightSwingTurn(speed, time)

            else :
                go_turn_stop.leftSwingTurn(speed, time)

        else :
            evasion_obs.evasion()

except KeyboardInterrupt:
    go_turn_stop.pwm_low()
