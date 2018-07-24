import evasion_obs
import go_turn_stop
import recog_obs
import recog_line
import setup
import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
go_turn_stop.pwm_setup()

dis = 20
speed_go = 50
time_go = 0.1
speed_turn = 40
time_turn = 0.1

try:
    while True:

        get_distance = recog_obs.get_Distance()
        print('distance= ',get_distance)

        if (get_distance > dis):

            W_and_B = recog_line.get_01()
            print(W_and_B)

            if recog_line.numberOfCases(W_and_B) == 'inLine' :
                go_turn_stop.go_forward(speed_go,time_go)
                print("inLine")

            elif recog_line.numberOfCases(W_and_B) == 'leftSide' :
                while W_and_B[2] != 0 :
                    go_turn_stop.rightSwingTurn(speed_turn, time_turn)
                    break
                
            elif recog_line.numberOfCases(W_and_B) == "final" : 
                go_turn_stop.stop()
                print("stop")
                break
            
            else :
                while W_and_B[2] != 0 :
                    go_turn_stop.leftSwingTurn(speed_turn, time_turn)
                    break
               
        else :
            evasion_obs.evasion()

except KeyboardInterrupt:
    go_turn_stop.pwm_low()
