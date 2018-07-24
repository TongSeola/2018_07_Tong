# ===========================================================================
# this code is for defining functions for controlling object in maze path
# ===========================================================================
# latest modification on 9.Dec.2017
# ===========================================================================
# import other modules to get line status and control object
# ===========================================================================
import go_turn_stop
# go_forward(speed)  stop()  pwm_setup()  right_turn(speed, running_time)  left_turn(speed, running_time)
import recog_line
# get_01()  line_status(led_list)
# ===========================================================================
# import time module
# ===========================================================================
import time
# sleep(time)

# back wheel go to turning point
forward_speed = 28
forward_time =0.6

# turn speed and time
turn_speed = 45
turn_time1 = 0.2      #about 70 angle
turn_time2 = 0.05     #find line

def go_right() :
''' function needed to move object right'''
    # Continue until the rear wheel is at the crossroads
    go_turn_stop.go_forward(forward_speed)
    time.sleep(forward_time)
    print("go forward")

    # at first, turn 70 degree
    go_turn_stop.right_turn2(turn_speed, turn_time1)

    # second, give plus turn to move more accurate
    while recog_line.get_01()[2] != 0:
        go_turn_stop.right_turn2(turn_speed, turn_time2)
        print("right turn")


def go_left() :
''' function needed for moving object left and giving recognized line status'''
    # Continue until the rear wheel is at the crossroads
    go_turn_stop.go_forward(forward_speed)
    time.sleep(forward_time)

    # Output sensor recognition result
    status = recog_line.get_01()
    print("this is ", status)

    if status == [1, 1, 1, 1, 1] :
        # at first, turn 70 degree
        go_turn_stop.left_turn2(turn_speed, turn_time1)
        while recog_line.get_01()[1] != 0:
            # second, give plus turn to move more accurate
            go_turn_stop.left_turn2(turn_speed, turn_time2)
	    print("left turn")
    else :
	# return nothing, because when we use 'if', 'break' sometimes operate oddly
	return

def U_turn() :
''' function needed to do u-turn when the object meets Dead-end path'''
    # Move forward a little
    go_turn_stop.go_forward(forward_speed)
    time.sleep(0.5)

    # at first, turn 130 degree
    go_turn_stop.right_turn2(turn_speed, turn_time1)

    while recog_line.get_01()[2] != 0:
	# second, give plus turn to move more accurate
        go_turn_stop.right_turn2(turn_speed, turn_time2)
        print("U turn")
