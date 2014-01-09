#ifndef _STORAGE_H
    #define _STORAGE_H
    #include <EEPROM.h>
    #include <LiquidCrystal.h>
    #include "flags.h"
    extern LiquidCrystal lcd;
    extern EEPROMClass EEPROM;
    void store(float humidity, int moisture);
    double* fetch_packet(void);
    void print_data(void);
    void detect_serial(void);
#endif
