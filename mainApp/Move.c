#include "Move.h"
Servo servo;


void setServo() {
  servo.attach(degree);
  servo.write(96);
}
void moveForward(void) {
  digitalWrite(forward, HIGH);
  digitalWrite(backward, LOW);
  analogWrite(en1, 100);
  analogWrite(en2, 100);
}

void movebackward(void) {
  digitalWrite(forward, LOW);
  digitalWrite(backward, HIGH);
  analogWrite(en1, 20);
  analogWrite(en2, 20);
}


void moveRight(unsigned int angle) {
  servo.write(angle);
  digitalWrite(forward, HIGH);
  digitalWrite(backward, LOW);
  analogWrite(en1, 60);
  analogWrite(en2, 40);
}

void moveLeft(unsigned int angle) {
  servo.write(angle);
  digitalWrite(forward, HIGH);
  digitalWrite(backward, LOW);
  analogWrite(en1, 40);
  analogWrite(en2, 60);
}

void move(unsigned int angle) {
  if (angle > 96) {
    moveRight(angle);
  } else if (angle < 96) {
    moveLeft(angle);
  } else {
    servo.write(angle);
    moveForward();
  }
}