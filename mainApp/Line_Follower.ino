// main app
#include "UltraSonic.h"
#include "Move.h"
#include "IR.h"



void setup() {
  Serial.begin(9600);

  // Ultrasonic Pins
  pinMode(Trigpin, OUTPUT);
  pinMode(Echopin, INPUT);

  // H-bridge Pins
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(forwardR, OUTPUT);
  pinMode(backwardR, OUTPUT);
  pinMode(forwardL, OUTPUT);
  pinMode(backwardL, OUTPUT);
  digitalWrite(forwardR, LOW);
  digitalWrite(backwardR, LOW);
  digitalWrite(forwardL, LOW);
  digitalWrite(backwardL, LOW);

  // Servo Attach
  setServo();


  // IR Pins
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
  pinMode(ir6, INPUT);
  pinMode(ir7, INPUT);
  pinMode(ir8, INPUT);
}

void loop() {
  while (ReadyToGo()) {

    unsigned int angle = getAngel();
    bool _90d = is90();
    int state = getState();
    move(angle, _90d, state);
  }
}
