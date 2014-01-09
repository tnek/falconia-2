#ifndef _MOVEMENT_H
    #define _MOVEMENT_H
    /*
     * Motors for the driving of the rover. These pins are used by the Arduino
     * motor shield. Pin A on the shield uses Digital 3, 9, and 12, while Pin B on 
     * the shield uses Digital 8, 11, 13. We use Pin A for the left motor (LM), and 
     * Pin B for the right motor (RM)
     *
     * PWM Pins - Digital 3, 11
     *     These pins control the speed of the motor by writing an analog value from
     *     0 to 255, 0 being off and 255 being at maximum power.
     * 
     * DIR Pins - Digital 12, 13
     *     These pins control the direction of the motor -- sending a HIGH signal
     *     moves the motor in one direction, while a LOW signal reverses the motor 
     *     to spin in another direction. For convenience, we define moving forward
     *     (FRWD) as HIGH, while backwards (BACK) as LOW.
     *
     * BRAKE Pins - Digital 8, 9
     *     These pins can be used to brake the motor - sending a HIGH signal to them
     *     brakes its corresponding motor. This differs from sending a 0 signal to
     *     the PWM pin, as it also stops the motor, rather than letting it slow down
     *     by cutting power.
     */
    #define FRWD HIGH
    #define BACK LOW
    
    #define PWM_LM 3
    #define DIR_LM 12
    #define BRAKE_LM 9
    
    #define PWM_RM 11
    #define DIR_RM 13
    #define BRAKE_RM 8
    
    /* 
     * Turn value for roughly 90 degrees 
     */
    #define TURN_VAL 1000
    
    void forward(void);
    void back(void);
    void turn_right(void);
    void turn_left(void);
    void go(void);
    void path(void);
    void movement_init(void);
    
    #include "movement.cpp"
#endif
