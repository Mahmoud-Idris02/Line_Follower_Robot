#include "..\Headers\UltraSonic.h"

unsigned int ReadyToGo(void) {
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);

  long duration = pulseIn(Echopin, HIGH);
  int distance = (duration * 0.0343) / 2;

  if (distance >= SafeDistance) { return 1; }

  return 0;
}