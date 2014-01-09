#ifndef _ROVER_H
    #define _ROVER_H
    #include <stdio.h>
    #include <Arduino.h>
    #include <LiquidCrystal.h>

    /*
     * Switch to enable the calibration countdown.
     * This can be disabled for testing purposes, but generally should be enabled
     * when actually running the rover.
     */
    #ifndef COUNTDOWN_ENABLED
        #define COUNTDOWN_ENABLED 1
    #endif
    
    /*
     * LCD Pins
     *    Digital Pins 2, 4, 6, 7, 10
     *    Analog Pins 2 (Digital 16), 3 (Digital 17)
     */
    LiquidCrystal lcd(2, 4, 6, 7, 10, 16, 17);
    
    #include "movement.h"
    #include "storage.h"
    #include "sensors.h"
    
    void count(int x);
    void calibrate_countdown(void);
    void setup();
    void loop();
    
    #include "rover.cpp"
#endif
