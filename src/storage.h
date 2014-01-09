/*
 * Switch to enable EEPROM
 * EEPROM has a limited number of writes available to it, so, if not necessary, 
 * want to avoid writing to it.
 */

#ifndef _STORAGE_H
    #define _STORAGE_H
    #define EEPROM_ENABLED 0
    void store(float humidity, int moisture);
    double* fetch_packet(void);
    void print_data(void);
    void detect_serial(void);
    extern EEPROMClass EEPROM;
    #include "storage.cpp"
#endif
