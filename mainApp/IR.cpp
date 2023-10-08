#include "IR.h"
#include <Arduino.h>

int angle = 100;
bool curve = false;
int state;  // ( -1 >>>>>>>>>> left ) ( 0 >>>>>>>>>> forward )  ( -1 >>>>>>>>>> right )


int getState(void) {
  return state;
}

bool is90(void) {
  if (digitalRead(ir1) == 0 && digitalRead(ir2) == 0 && digitalRead(ir3) == 0 && digitalRead(ir4) == 0 && digitalRead(ir5) == 0 && digitalRead(ir6) == 0 && digitalRead(ir7) == 0 && digitalRead(ir8) == 0) {
    return false;
  }
  if (digitalRead(ir1) == 0 && digitalRead(ir2) == 0 && digitalRead(ir3) == 0 && digitalRead(ir4) == 0 && digitalRead(ir6) == 1 && digitalRead(ir7) == 1 && digitalRead(ir8) == 1) {
    return true;
  }
  if (digitalRead(ir1) == 1 && digitalRead(ir2) == 1 && digitalRead(ir3) == 1 && digitalRead(ir5) == 0 && digitalRead(ir6) == 0 && digitalRead(ir7) == 0 && digitalRead(ir8) == 0) {
    return true;
  }
  return false;
}

unsigned int getAngel(void) {
  // stay as you are >>>>>>||<<<<<<
  // turn left
  if (digitalRead(ir6) == 0 || digitalRead(ir7) == 0 || digitalRead(ir8) == 0) {
    state = -1;
    if (angle > 70) {
      angle -= 10;
      return angle;
    }
  }
  // turn right
  else if (digitalRead(ir2) == 0 || digitalRead(ir3) == 0 || digitalRead(ir1) == 0) {
    state = 1;
    if (angle < 130) {
      angle += 10;
      return angle;
    }
  } else if (digitalRead(ir4) == 0 && digitalRead(ir5) == 0 || (digitalRead(ir4) == 0 && digitalRead(ir5) == 0 && digitalRead(ir3) == 0 && digitalRead(ir6) == 1)
             || (digitalRead(ir5) == 0 && digitalRead(ir4) == 0 && digitalRead(ir6) == 0 && digitalRead(ir3) == 1)) {
    state = 0;
    return angle;
  }
  return angle;
}