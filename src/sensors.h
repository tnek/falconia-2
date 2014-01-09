#ifndef _STORAGE_H
    #include <Arduino.h>
    #include <DHT22.h>
    #include <Servo.h>
    #include <LiquidCrystal.h>
    
    /*
     * DHT Humidity Sensor
     *    Digital 17 (Analog 3) is the pin used for the DHT Humidity Sensor
     */
    #define DHT_PIN 18
    DHT22 dht(DHT_PIN);
    
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
    Servo moist_arm;
    
    /*
     * Distance Sensor - LV MaxSonar-EZ
     *    Digital 5 is the pin used.
     */
    #define DISTANCE_PIN 5
    #define _STORAGE_H 0
    
    float humidity(void);
    void _qsort(int *array, int length);
    float distance(void);
    void print_humidity(float reading);
    void print_moisture(int moisture);
    
    void sensors(void);
    void sensors_init(void);
    
#endif
