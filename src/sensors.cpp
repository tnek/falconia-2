/**
 * Sensor Functions
 * ~~~~~~~~~~~~~~~~~
 */
#include <Arduino.h>
#include "sensors.h"

DHT22 dht(DHT_PIN);
/*
 * Reads the humidity from the DHT Humidty Sensor.
 * However, it can only be called once every 2 seconds by the nature of the 
 * sensor.
 */
float humidity(void) 
{
    switch(dht.readData())
    {
        case DHT_ERROR_NONE:
            return dht.getHumidity();
            break;
        case DHT_BUS_HUNG:
            Serial.println("BUS Hung ");
            break;
        case DHT_ERROR_NOT_PRESENT:
            Serial.println("Not Present ");
            break;
        case DHT_ERROR_ACK_TOO_LONG:
            Serial.println("ACK time out ");
            break;
        case DHT_ERROR_SYNC_TIMEOUT:
            Serial.println("Sync Timeout ");
            break;
        case DHT_ERROR_DATA_TIMEOUT:
            Serial.println("Data Timeout ");
            break;
        case DHT_ERROR_TOOQUICK:
            Serial.println("Polled too quick ");
            break;
    }
    return 0;
}

/* 
 * Reads the moisture from the hand-made sensor. This is achieved by sending a
 * signal to one wire, and reading it from the other in order to calculate the
 * resistance between the two wires.
 */
int moisture(void)
{
    int reading = analogRead(MOIST_RPIN);
    if (reading <= 0) {
        return 0;
    }
    return reading;
}

/*
 * Reads the distance sensor, and returns the distance of the closest object.
 *     As the sensor can occasionally have strange readings due to 
 * inconsistencies, we take 10 readings, and use the median of those 10 readings
 * as our approximation of distance. In order to find median, quicksort was 
 * implemented.
 */
void _qsort(int *array, int length)
{
    if (length < 2) return;

    int pivot = array[length / 2];
    int *l = array, *r = array + length - 1;
    while (l <= r) {
        if (*l < pivot) {
            l++;
            continue;
        }
        if (*r > pivot) {
            r--;
            continue;
        }
        int t = *l;
        *l++ = *r;
        *r-- = t;
    }
    _qsort(array, r - array + 1);
    _qsort(l, array + length - l);
}

float distance(void) 
{
    int vals[10];
    for (int i = 0; i <= 10; i++) {
        vals[i] = (int) pulseIn(DISTANCE_PIN, HIGH);
    }
    _qsort(vals, 10);
    return (float) vals[5] / 147;
}

/*
 * Formats the humidity reading for the LCD screen, and writes it to said LCD
 * screen.
 */
void print_humidity(float reading) 
{
    lcd.setCursor(0, 0);
    lcd.print("Humidity:        ");
    lcd.setCursor(10, 0);
    lcd.print(reading);
    lcd.print("%");
}

/*
 * Formats the moisture reading for the LCD screen, and writes it to said LCD
 * screen.
 */
void print_moisture(int moisture) 
{
    lcd.setCursor(0, 1);
    lcd.print("Taking Moisture ");
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("Moisture:       ");
    lcd.setCursor(10, 1);
    lcd.print(moisture);
}



/**
 *
 * Operational Functions
 * ~~~~~~~~~~~~~~~~~~~~~~
 */

/*
 * Operates all of the sensors, and writes them to the LCD screen.
 */
unsigned long lstime = millis();
void sensors(void) 
{
    if (millis() - lstime > 2000) {
        float humidity_reading = humidity();
        int moisture_reading = moisture();
        if (humidity_reading != 0) 
        {
            print_humidity(humidity_reading);
            print_moisture(moisture_reading);
            if (EEPROM_ENABLED) {
                store(humidity_reading, moisture_reading);
            }
        }
    }
}

void sensors_init(void)
{
    pinMode(DISTANCE_PIN, INPUT);
    Servo moist_arm;
    pinMode(MOIST_RPIN, INPUT);
    moist_arm.attach(MOIST_APIN);
}
