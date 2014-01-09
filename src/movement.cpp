/** 
 * Movement Functions
 * ~~~~~~~~~~~~~~~~~~~
 */
#include <Arduino.h>
#include "movement.h"

/*
 * Self-explanatory functions for moving the rover
 */
void forward(void)
{
    digitalWrite(DIR_RM, FRWD);
    digitalWrite(DIR_LM, FRWD);
}

void back(void)
{
    digitalWrite(DIR_LM, BACK);
    digitalWrite(DIR_RM, BACK);
}

void turn_right(void)
{
    digitalWrite(DIR_RM, BACK);
    digitalWrite(DIR_LM, FRWD);
}

void turn_left(void)
{
    digitalWrite(DIR_RM, FRWD);
    digitalWrite(DIR_LM, BACK);
}

void go(void)
{
    analogWrite(PWM_RM, 255);
    analogWrite(PWM_LM, 255);
}

/*
 * Merely cuts off power to the motors -- does not truly stop them.
 * TODO: Implement brakes
 */
void stahp(void) 
{
    analogWrite(PWM_RM, 0);
    analogWrite(PWM_LM, 0);
}

void path(void)
{
    go();
    forward();
    delay(10000);
    
    turn_right();
    delay(TURN_VAL);
    forward();
    delay(5000);
    
    turn_right();
    delay(TURN_VAL);
    forward();
    delay(10000);
    
    stahp();
}

void movement_init(void)
{
    pinMode(PWM_RM, OUTPUT);
    pinMode(DIR_RM, OUTPUT);
    pinMode(PWM_LM, OUTPUT);
    pinMode(DIR_LM, OUTPUT);
}
