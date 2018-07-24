import recog_line
import go_turn_stop
import time
import recog_obs

def evasion() :

    right_turn_speed = 50
    short_time = 0.1

    left_turn_speed = 20
    long_time = 0.4

    go_speed = 5
    go_time = 1

    dis = 20
    try:

        get_distance = recog_obs.get_Distance()

        while get_distance > dis :
            go_turn_stop.rightSwingTurn(right_turn_speed, short_time)
            break

        go_turn_stop.go_forward(go_speed,go_time)

        go_turn_stop.leftSwingTurn(left_turn_speed, long_time)

        while recog_line.get_01()[4] != 0 :
            go_turn_stop.go_forward_any(go_speed)

        while recog_line.get_01()[2] != 0 :
            go_turn_stop.leftSwingTurn(left_turn_speed, short_time)
            break
        
    except :
        pass
