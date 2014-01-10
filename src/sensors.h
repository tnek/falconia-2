#ifndef _SENSORS_H
    #define _SENSORS_H
    #include <DHT22.h>
    #include <Servo.h>
    #include <LiquidCrystal.h>
    #include <EEPROM.h>
    #include "flags.h"
    
    extern LiquidCrystal lcd;
    extern EEPROMClass EEPROM;
    extern void store(float humidity_reading, int moisture_reading);

    /*
     * DHT Humidity Sensor
     *    Digital 17 (Analog 3) is the pin used for the DHT Humidity Sensor
     */
    #define DHT_PIN 18
    
    /* 
     * Moisture Sensor Pins
     *    Analog 1 is the pin to read voltage.
     */
    #define MOIST_RPIN 1
    
    /*
     * Servo Arm to manipulate the Moisture Sensor
     *    Digital 19 is the pin used.
     */
    #define MOIST_APIN 19
    
    /*
     * Distance Sensor - LV MaxSonar-EZ
     *     Digital n is the pin used.
     * Disabled for now: it is likely that this won't be needed.
     */
    //#define DISTANCE_PIN 5
    
    float humidity(void);
    int moisture(void);
    void _qsort(int *array, int length);
    float distance(void);
    void print_humidity(float reading);
    void print_moisture(int moisture);
    
    void sensors(void);
    void sensors_init(void);
    
#endif
