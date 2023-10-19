#include "..\Headers\IR.h"
#include <Arduino.h>

int angle;


unsigned int getAngel(void) {
  /* if (digitalRead(ir4) != 0 || digitalRead(ir5) != 0) {
    if (digitalRead(ir6) == 0 || digitalRead(ir7) == 0 || digitalRead(ir8) == 0) {
      // To the Right
      if (angle > 72 && digitalRead(ir5) != 0) {
        angle -= 2;
        delay(20);
        return angle;
      }

    } else if (digitalRead(ir1) == 0 || digitalRead(ir2) == 0 || digitalRead(ir3) == 0) {
      // To the left
      if (angle < 118 && digitalRead(ir4) != 0) {
        angle += 2;
        delay(20);
        return angle;
      }
    }
  } else if (digitalRead(ir4) == 0 && digitalRead(ir5) == 0) {
    // Serial.println(angle);
    // back to the center
    if (angle > 96) {
      angle = -2;
      delay(500);
      return angle;
    } else if (angle < 96) {
      angle = +2;
      // Serial.println(angle);
      delay(500);
      return angle;
    }
  }


  return 96;
  */
  if ((digitalRead(ir4) == 0) && (digitalRead(ir5) == 0)) {
    if (angle > 96) {
      angle -= 2;
      delay(20);
      return angle;
    } else if (angle < 96) {
      angle += 2;
      delay(20);
      return angle;
    }
  } else if ((digitalRead(ir6) == 0) || (digitalRead(ir7) == 0) || (digitalRead(ir8) == 0)) {
    angle += 2;
    delay(20);
    return angle;
  } else if ((digitalRead(ir6) == 0) || (digitalRead(ir7) == 0) || (digitalRead(ir8) == 0)) {
    angle -= 2;
    delay(20);
    return angle;
  }
  return angle;
}
