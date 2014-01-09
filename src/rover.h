#ifndef _ROVER_H
    #define _ROVER_H
    #include <stdio.h>
    #include <LiquidCrystal.h>

    void count(int x);
    void calibrate_countdown(void);
    void setup();
    void loop();

    #include "movement.h"
    #include "storage.h"
    #include "sensors.h"
    #include "flags.h"
#endif
