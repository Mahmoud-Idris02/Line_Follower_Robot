#include "Move.h"
Servo servo;


void setServo() {
  servo.attach(degree, 500, 2400);
  servo.write(100);
}
void moveForward(void) {
  digitalWrite(forwardR, HIGH);
  digitalWrite(forwardL, HIGH);
  digitalWrite(backwardR, LOW);
  digitalWrite(backwardL, LOW);
  analogWrite(en1, leftSpeed);
  analogWrite(en2, RightSpeed);
}

void movebackward(void) {
  digitalWrite(forwardR, LOW);
  digitalWrite(forwardL, LOW);
  digitalWrite(backwardR, HIGH);
  digitalWrite(backwardL, HIGH);
  analogWrite(en1, 20);
  analogWrite(en2, 20);
}

void moveRight(unsigned int angle) {
  servo.write(angle);
  digitalWrite(forwardR, LOW);
  digitalWrite(forwardL, HIGH);
  digitalWrite(backwardR, HIGH);
  digitalWrite(backwardL, LOW);
  analogWrite(en1, leftSpeed + 170);
  analogWrite(en2, 70);
}

void moveLeft(unsigned int angle) {
  servo.write(angle);
  digitalWrite(forwardR, HIGH);
  digitalWrite(forwardL, LOW);
  digitalWrite(backwardR, LOW);
  digitalWrite(backwardL, HIGH);
  // analogWrite(en1, leftSpeed - 15);
  // analogWrite(en2,  RightSpeed + 70);
  analogWrite(en1, 50);
  analogWrite(en2, RightSpeed + 40);
}


void spinLeft(unsigned int angle) {
  servo.write(angle);
  digitalWrite(forwardR, HIGH);
  digitalWrite(forwardL, LOW);
  digitalWrite(backwardR, LOW);
  digitalWrite(backwardL, HIGH);
  analogWrite(en1, 0);
  analogWrite(en2, 0);
  delay(1000);
  analogWrite(en1, 160);
  analogWrite(en2, 160);
  delay(2500);
}
void spinRight(unsigned int angle) {
  servo.write(angle);
  digitalWrite(forwardR, LOW);
  digitalWrite(forwardL, HIGH);
  digitalWrite(backwardR, HIGH);
  digitalWrite(backwardL, LOW);
  analogWrite(en1, 0);
  analogWrite(en2, 0);
  delay(1000);
  analogWrite(en1, 160);
  analogWrite(en2, 160);
  delay(2500);
}

void bridge(void) {
  digitalWrite(forwardR, HIGH);
  digitalWrite(forwardL, HIGH);
  digitalWrite(backwardR, LOW);
  digitalWrite(backwardL, LOW);
  analogWrite(en1, leftSpeed + 40);
  analogWrite(en2, RightSpeed + 30);
  delay(5000);
  analogWrite(en1, leftSpeed - 20);
  analogWrite(en2, RightSpeed - 30);
  delay(2000);
}

void move(unsigned int angle, bool _90d, int state) {

  if (state == 0) {
    servo.write(angle);
    moveForward();

  } else if (state == 1) {
    if (_90d == true) {
      spinRight(angle);
    } else if (_90d == false) {
      moveRight(angle);
    }

  } else if (state == -1) {
    if (_90d == true) {
      spinLeft(angle);
    } else if (_90d == false) {
      moveLeft(angle);
    }
  }
}
void moveServo(unsigned int angle) {
  servo.write(angle);
}