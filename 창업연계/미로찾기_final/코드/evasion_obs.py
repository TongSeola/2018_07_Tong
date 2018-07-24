import recog_line
import go_turn_stop
import time

def evasion() :

    right_turn_speed = 50
    right_turn_time = 0.4

    left_turn_speed = 20
    left_turn_time = 0.4

    go_speed = 5
    go_time = 1

    try:

        go_turn_stop.rightSwingTurn(right_turn_speed, right_turn_time)
        time.sleep(1)

        go_turn_stop.go_forward(go_speed,go_time)

        go_turn_stop.leftSwingTurn(left_turn_speed, left_turn_time)

        while recog_line.get_01()[4] != 0 :
            go_turn_stop.go_forward_any(go_speed)

        while recog_line.get_01()[2] != 0 :
            go_turn_stop.leftSwingTurn(left_turn_speed, left_turn_time)
        
    except :
        pass
