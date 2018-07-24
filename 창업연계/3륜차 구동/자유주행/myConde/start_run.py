import evasion_obs
import go_turn_stop
import recog_obs
import recog_line
import setup

dis = 17  #20
speed = 20
time = 0.5

try:
    while True:
        # ultra sensor replies the distance back
        distance = recog_obs.get_Distance()
        print('distance= ', distance)

        # when the distance is above the dis, moving object forwards
        while (distance > dis):
            W_and_B = recog_line.get_01()
            if recog_line.numberOfCases(W_and_B) == 'inLine' :
                go_turn_stop.go_forward(speed, time)

            elif recog_line.numberOfCases(W_and_B) == 'leftSide' :
                go_turn_stop.right_PointTurn(speed, time)

            else :
                go_turn_stop.left_PointTurn(speed, time)

        else :
            evasion_obs.evasion()

except KeyboardInterrupt:
    go_turn_stop.pwm_low()
