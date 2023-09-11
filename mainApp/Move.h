#ifndef MOVE_H
#define MOVE_H

#include <Servo.h>
#include <Arduino.h>

#define en1 6
#define en2 5
#define forward A1
#define backward A2
#define degree 13


void setServo();
void moveForward(void);
void movebackward(void);
void move(unsigned int angle);
void moveRight(unsigned int angle);
void moveLeft(unsigned int angle);

#endif