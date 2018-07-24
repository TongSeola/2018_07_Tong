import recog_line
import go_turn_stop
import time

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
        go_turn_stop.right_SwingTurn(right_turn_speed, right_turn_time)
        time.sleep(1)

        go_turn_stop.go_forward(speed,go_time)

        go_turn_stop.right_PointTurn(left_turn_speed, left_turn_time)
        time.sleep(1)
        WB = recog_line.get_01()

        while recog_line.numberOfCases(WB) != 'inLine' :
            go_turn_stop.just_go_forward(speed)
        else :
            time.sleep(1)
            break

    except :
        pass