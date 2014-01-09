/*
 * rover.cpp 
 * ~~~~~~~~~~
 * A rover for collecting data of humidity of the area, as well as testing the
 * moisture of soil in the area.
 *
 *  Kent Ma
 *  Block Y
 */
#include <Arduino.h>
#include "rover.h"

/*
 * LCD Pins
 *    Digital Pins 2, 4, 6, 7, 10
 *    Analog Pins 2 (Digital 16), 3 (Digital 17)
 */
LiquidCrystal lcd(2, 4, 6, 7, 10, 16, 17);

/*
 * The first 10 or so seconds of using the sensors returns inaccurate values as
 * the sensors initialize. As such, we have a 10 second splash screen to help
 * avoid inaccurate data.
 *
 * :func:`_count` prints the number on the position of the screen for the 
 * countdown on the splash screen.
 */
void _count(int x) {
    lcd.setCursor(8,1);
    lcd.print(x);
}

void calibrate_countdown(void) 
{
    lcd.print("Starting rover");
    lcd.display();
    for (int i = 5; i > 0; i--) {
        _count(i*2 - 1);
        delay(1000);
        _count(i*2 - 2);
        humidity();
        moisture();
        delay(1000);
    }
    lcd.clear();
}

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    movement_init();
    sensors_init();
    if (COUNTDOWN_ENABLED) {
        calibrate_countdown();
    }

    detect_serial();
    path();
} 

void loop()
{
    sensors();
    delay(2000);
}
