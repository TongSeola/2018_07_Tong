# ===========================================================================
# This code is the Main Module, operating raspberry car according to other modules
# ===========================================================================
# latest modification on 9.Dec.2017
# ===========================================================================
# import other raspberry car modules
# ===========================================================================
import maze_move
# go_right()  go_left()  U_turn()
import go_turn_stop
# go_forward(speed)  stop()  pwm_setup()  right_turn(speed, running_time)  left_turn(speed, running_time)
import setup
# rightmotor(forward)  leftmotor(forward)
import recog_line
# get_01()  line_status(led_list)
import time
# sleep(time)

# Set motor to move
go_turn_stop.pwm_setup()

# line tracing speed and time
speed =55
turn_speed = 70
turn_time = 0.07

try:
    while True :
	# show line status and kinds
        status = recog_line.get_01()
        line = recog_line.line_status(status)
        print(status," : ",line)
	
	# operate raspberry car depending on line status
        if line == "inLine":
            go_turn_stop.go_forward(speed)

        elif line == "right" :
            go_turn_stop.right_turn(turn_speed, turn_time)

        elif line == "left" :
            go_turn_stop.left_turn(turn_speed, turn_time)

        elif line == "Uturn":
            maze_move.U_turn()

        elif line == "right turn" :
            maze_move.go_right()

        elif line == "left or straight" :
            maze_move.go_left()

        else:
            pass
        
# if code is error, the object should stop
except :
    go_turn_stop.pwm_low()
    print("pwm becomes low")
