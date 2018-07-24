import recog_line
import go_turn_stop
import time

def evasion() :

    # Swing Turn 's angle
    right_turn_speed = 50
    right_turn_time = 0.4

    # Point Turn 's angle
    left_turn_speed = 20
    left_turn_time = 0.4

    # The speed that the executor wants
    speed_high = 43
    speed_low = 1.5

    try:

        go_turn_stop.rightSwingTurn(right_turn_speed, right_turn_time)
        time.sleep(1)

        while recog_line.get_01() == [0, 0, 0, 0, 0] :
            go_turn_stop.rightRoundTurn(speed_high, speed_low)

        go_turn_stop.leftSwingTurn(left_turn_speed, left_turn_time)
        # go_turn_stop.go_forward(speed,go_time)
        #
        # go_turn_stop.leftSwingTurn(left_turn_speed, left_turn_time)
        # time.sleep(1)
        #
        # WB = recog_line.get_01()
        #
        # while [ True for x in WB if x==0]:
        #     break
        #
        # else :
        #     go_turn_stop.forward_any(speed, go_time)
        #     time.sleep(0.1)

    except :
        pass
