#!/usr/bin/env python

import pyS700 as GPIO
import time

test = GPIO.PD12

GPIO.init()    
GPIO.output_setcfg(test)
print "PD12:", GPIO.PD12

GPIO.output(test, GPIO.HIGH)
time.sleep(0.01)
GPIO.output(test, GPIO.LOW)

# GPIO.input_setcfg(GPIO.PB9)
# while True:
#     if GPIO.input(GPIO.PB9):
#        print "PB9: OK"

GPIO.cleanup()
