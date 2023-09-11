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
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  digitalWrite(forward, LOW);
  digitalWrite(backward, LOW);

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
    Serial.print(angle);
    Serial.println(" ");
    move(angle);
  }
}
