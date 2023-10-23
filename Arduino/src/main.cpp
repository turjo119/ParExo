#include <Arduino.h>
#include <Braccio.h>

/* Braccio servo motors*/
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

void setup(){
    Serial.begin(9600);
    // Declare Pin 3 as PWM output as servo motr on back(Type 1404) 
    //myservo.attach(3);
    
    //Initialize Braccio and set all servos to initial "safe postion"
    // M1: 90, M2: 0 and M3: 0
    Braccio.begin();
    delay(1000);
}

void loop(){


    //(step delay, M1, M2, M3, M4, M5, M6);

    //Set initial positions of Motors M1,M2 and M3
    //Braccio.ServoMovement(20,           45,  15, 0, 0, 0,  0);
    delay(500);

    // Move M3 for elbow joint by 90 degrees and return to initial position
    Braccio.ServoMovement(20,           45,  15, 90, 0, 0,  0);
    delay(3000);
    Braccio.ServoMovement(20,           45,  15, 0, 0, 0,  0);
    delay(3000);


    //Move M2, motor for shoulder joint by 60 degrees and return to initial position
    Braccio.ServoMovement(20,           45,  75, 0, 0, 0,  0);  
    delay(3000);
    Braccio.ServoMovement(20,           45,  15, 0, 0, 0,  0);
    delay(3000);


    //Move M1, motor for base-plate joint to 110 and return to 45 degrees 
    Braccio.ServoMovement(20,           110,  15, 0, 0, 0,  0);
    delay(3000);
    Braccio.ServoMovement(20,           45,  15, 0, 0, 0,  0);  
    delay(3000);

    /*More advanced tests*/
    //Move M3 60 degrees then M2 by 60 degrees and return to initial position
    Braccio.ServoMovement(20,           45,  15, 60, 0, 0,  0);
    delay(1000);
    Braccio.ServoMovement(20,           45,  75, 60, 0, 0,  0);
    delay(1000);
    Braccio.ServoMovement(20,           45,  15, 60, 0, 0,  0);
    delay(1000);
    Braccio.ServoMovement(20,           45,  15, 30, 0, 0,  0);
    delay(1000);
}