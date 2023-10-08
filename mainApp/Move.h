#ifndef MOVE_H
#define MOVE_H

#include <Servo.h>
#include <Arduino.h>

#define en1 6
#define en2 5
#define forwardR A1
#define forwardL A0
#define backwardL A2
#define backwardR A3
#define degree 11
/*
  
  **** speeds that works with normal track ****
    L   |   R
    50      85
  **** speeds that works with the bridge ****
    L   |   R
    100     135
    80  |   115


*/


#define leftSpeed 65
#define RightSpeed 100


void setServo();
void moveForward(void);
void movebackward(void);
void move(unsigned int angle, bool _90d, int state);
void moveRight(unsigned int angle);
void moveLeft(unsigned int angle);
void spinLeft(unsigned int angle);
void spinWrite(unsigned int angle);
void bridge(void);
void moveServo(unsigned int angle);

#endif