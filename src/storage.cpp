/**
 * storage.cpp 
 * ~~~~~~~~~~~~
 * Functions for storing the data collected by our rover using EEPROM.
 *
 * Kent Ma
 * Block Y
 */
#include <Arduino.h>
#include "storage.h"

/*
 * Writes the data collected to the EEPROM
 *
 *     The EEPROM of an Arduino Uno is able to store up to 512 bytes. In order 
 * to store the data we collected, we place the data into a packet. This packet 
 * contains a timestamp, humidity, and moisture.
 *
 * Each packet is 6 bytes:
 *
 *   0 1 2 3 4 5 
 *  +-+-+-+-+-+-+
 *  | A | B | C |
 *  +-+-+-+-+-+-+
 * 
 *   A: Timestamp - Time (in seconds) since the rover started running. It will
 *                  overflow at 65536. Both bytes are used for the same number.
 *
 *   B: Humidity  - Readings from the RHT03. The first byte is used for the
 *                  percentage, and the second byte is for the decimal point.
 *
 *   C: Moisture  - Readings from the moisture sensor.
 *
 */

int write_addr = 0;
void store(float humidity, int moisture)
{
    if (write_addr + 6 > 512) {
        write_addr = 0;
    }
    int current_time = (int) (millis() + 500) / 1000;
    EEPROM.write(write_addr++, current_time & 255);
    EEPROM.write(write_addr++, current_time & (255 << 8) >> 8);

    int humidity_num = humidity;
    int humidity_decimal = (humidity - (int) humidity) * 100;
    EEPROM.write(write_addr++, humidity_num);
    EEPROM.write(write_addr++, humidity_decimal);

    EEPROM.write(write_addr++, moisture & 255);
    EEPROM.write(write_addr++, moisture & (255 << 8) >> 8);
}

/*
 * Fetches an individual packet, and converts them back to their appropriate 
 * values, then places them into an array, which is organized as follows:
 *     { timestamp, humidity, moisture }
 */
int read_addr = 0;
double* fetch_packet(void) 
{
    if (read_addr + 6 > 512) {
        read_addr = 0;
    }
    double* data = (double*) malloc(sizeof(double) * 3);
    data[0] = EEPROM.read(read_addr++) << 8 | EEPROM.read(read_addr++);
    data[1] = EEPROM.read(read_addr++) + EEPROM.read(read_addr++) / 100;
    data[2] = EEPROM.read(read_addr++) << 8 | EEPROM.read(read_addr++);
    return data;
}

/*
 * Retrieves every packet in EEPROM Storage, and formats and prints it in a 
 * human-readable string.
 */
void print_data(void)
{
    double* data;
    char buffer[200];
    int i;
    for (i = 0; i < 512 / 6 / 3; i++) {
        data = fetch_packet();
        sprintf(buffer, "Time: %f Humidity: %f Moisture: %f", *(data++), 
                                                        *(data++), *(data++));
        Serial.println(buffer);
    }
    
}

/* 
 * Checks if the Serial monitor is present.
 * If the Serial Monitor is detected, the rover will dump all of the data on the
 * EEPROM to Serial.
 */

void detect_serial(void) 
{
    if (EEPROM_ENABLED && Serial) {
        lcd.setCursor(0, 0);
        lcd.print("Detected Serial:");
        lcd.setCursor(0, 1);
        lcd.print("Writing data...");
        print_data();
    }
}
