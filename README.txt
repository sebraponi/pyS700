Example:
    #!/usr/bin/env python

    import pyS700 as GPIO

    #init module
    GPIO.init()
    
    #configure module
    GPIO.output_setcfg(GPIO.PIN#)
    GPIO.input_setcfg(GPIO.PIN#)
        
    #read the current GPIO configuration
    config = GPIO.getcfg(GPIO.PIN#)
    
    #set GPIO high
    GPIO.output(GPIO.PIN#, GPIO.HIGH)
    
    #set GPIO low
    GPIO.output(GPIO.PIN#, GPIO.LOW)
    
    #read input
    state = GPIO.input(GPIO.PIN#)
    
    #cleanup 
    GPIO.cleanup()
