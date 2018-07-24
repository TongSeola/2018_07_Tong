#########################################################################
# 20171618 Dong_Seola 's code
# this star_run.py file is Executable code
#########################################################################

# =======================================================================
#  define your variables and find out each value of variables
#  eg) dis and obstacle
# =======================================================================

dis = 17  # 20
obstacle = 0  # how many times does the car meet

# Swing Turn 's angle
SwingPr1 = 30
SwingTr1 = 0.4
# Point Turn 's angle
SwingPr2 = 50
SwingTr2 = 0.4
# The speed that the executor wants
speed = 43

# =======================================================================
# import GPIO library and time module
# =======================================================================
import RPi.GPIO as GPIO
import time

# =======================================================================
# set up GPIO mode as BOARD
# set GPIO warnings as flase
# =======================================================================

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

# =======================================================================
# import getDistance() method in the high-came
# =======================================================================
import high_came

# getDistance()

# =======================================================================
# import swing_point method
# =======================================================================
import swing_point_turn

# left_motor(x)   #right_motor(x)  - set right and left motor to move
# rightSwingTurn(speed, runningtime) - rihgt wheel is stop
# leftSwingTurn(speed, runningtime) - left wheel is stop
# rightPointTurn(speed, runningtime) - right wheel go back
# leftPointTurn(speed, runningtime) - left wheel go back

# =======================================================================
# import go_forward_any(), go_backward_any(), stop(), LeftPwm(),
# RightPwm(), pwm_setup(), and pwm_low() methods in the module of go_any
# =======================================================================
import for_back_ward

# leftmotor(x)   #rightmotor(x) - set right and left motor to move
# go_forward_any(speed) - go forward while other stimulation
# go_backward_any(speed) - go backward while other stimulation
# go_forward(speed, running_time) - go forward while running time
# go_backward(speed, running_time) - go backward while running time

# pwm_setup() - get pwm 0 both wheel
# pwm_low() - if there is unexpected occurrence
# stop() - get pwm to stop

# =======================================================================
# setup and initilaize the left motor and right motor
# =======================================================================

for_back_ward.pwm_setup()

# ========================================================================
#  to perform the start_run with import
#  eg) go for,back ward and trun swing,point
# ========================================================================

try:
    while True:
        # ultra sensor replies the distance back
        distance = high_came.getDistance()
        print('distance= ', distance)

        # when the distance is above the dis, moving object forwards
        if (distance > dis):
            if obstacle == 0 or 1:
                for_back_ward.go_forward_any(speed)
                print('obstacle=', obstacle)
            else:
                for_back_ward.go_forward(speed, 2)

        # when the distance is below the dis
        else:
            # stop and wait 1 second
            for_back_ward.stop()
            time.sleep(1)
            # Swing right turn
            if obstacle == 0:
                swing_point_turn.leftPointTurn(SwingPr1, SwingTr1)
                time.sleep(1)
                obstacle += 1
            # Poin right trun
            elif obstacle == 1:
                swing_point_turn.leftSwingTurn(SwingPr2, SwingTr2)
                time.sleep(1)
                obstacle += 1



# when the Ctrl+C key has been pressed,
# the moving object will be stopped
except KeyboardInterrupt:
    for_back_ward.pwm_low()
