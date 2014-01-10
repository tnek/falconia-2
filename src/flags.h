#ifndef _FLAG_H
    #define _FLAG_H
    /*
     * Switch to enable the calibration countdown.
     * This can be disabled for testing purposes, but generally should be enabled
     * when actually running the rover.
     */
    #define COUNTDOWN_ENABLED 1

    /*
     * Switch to enable EEPROM.
     * As there is a write limit for the EEPROM, this can be disabled for
     * testing to preserve the life of the arduino, but should be enabled on a
     * legitimate run.
     */
    #define EEPROM_ENABLED 0
   
#endif
