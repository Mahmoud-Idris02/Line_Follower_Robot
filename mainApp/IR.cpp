#include "IR.h"
#include <Arduino.h>

int angle = 100;
bool curve = false;
int state ; // ( -1 >>>>>>>>>> left ) ( 0 >>>>>>>>>> forward )  ( -1 >>>>>>>>>> right )


int getState(void){
  return state ;
}

bool is90(void) {
  if (digitalRead(ir1) == 0 && digitalRead(ir2) == 0 && digitalRead(ir3) == 0 && digitalRead(ir4) == 0 && digitalRead(ir5) == 0 && digitalRead(ir6) == 0 && digitalRead(ir7) == 0 && digitalRead(ir8) == 0){
    return false;
  }
  if(digitalRead(ir1) == 0 && digitalRead(ir2) == 0 && digitalRead(ir3) == 0 && digitalRead(ir4) == 0 && digitalRead(ir5) == 0 && digitalRead(ir6) == 1 && digitalRead(ir7) == 1 && digitalRead(ir8) == 1){
    return true ;
  }
  if(digitalRead(ir1) == 1 && digitalRead(ir2) == 1 && digitalRead(ir3) == 1 &&  digitalRead(ir4) == 0 && digitalRead(ir5) == 0 && digitalRead(ir6) == 0 && digitalRead(ir7) == 0 && digitalRead(ir8) == 0  ){
    return true ;
  }
  return false;
}

// unsigned int getAngel(void) {

//   // removed "|| (digitalRead(ir8) == 0)" " (digitalRead(ir1) == 0) ||"
//   // if(angle <= 90 && angle >= 86 && (digitalRead(ir4) == 0 || digitalRead(ir5) == 0)){
//   //   state = 0;
//   //   if(digitalRead(ir3) == 0){angle += 2; delay(5);}
//   //   else if(digitalRead(ir6) == 0){angle -= 2; delay(5);}
//   //   return angle;
//   // }
//   if(angle == 64 && digitalRead(ir4) == 0 && digitalRead(ir3) == 0){
//     state = 0;
//     // angle = 88;
//     return angle;
//   }
//   else if(angle == 112 && digitalRead(ir5) == 0 && digitalRead(ir6) == 0){
//     state = 0;
//     // angle = 88;
//     return angle;
//   }
//   // if ( (angle == 64|| angle == 112 ) && digitalRead(ir4) == 0 && digitalRead(ir5) == 0 && (digitalRead(ir3) == 0 || digitalRead(ir6) == 0 )) {
//   //   Serial.println(angle);
//   //   // back to the center
//   //   state = 0;
//   //   angle = 88;
//   //   return angle;
//   // }
//   if ( (digitalRead(ir2) == 0) || (digitalRead(ir3) == 0) || (digitalRead(ir6) == 0) || (digitalRead(ir7) == 0) ) {


//     // removed "digitalRead(ir8) == 0 ||" to avoid the edges 
//     if ( digitalRead(ir6) == 0 && digitalRead(ir7) == 0 && digitalRead(ir3) == 1 && digitalRead(ir2) == 1) {
//       // To the left
//       state = -1 ; 

//       if (angle > 50) {
//         angle -= 4;
//         // delay(5);
//         return angle;
//       }
//     } 
//     else if (digitalRead(ir6) == 0 && angle != 112 && angle != 64) {
//       // To the left
//       state = 0 ; 

//       if (angle > 98) {
//         angle -= 2;
//         // delay(5);
//         return angle;
//       }
//     }
//     // removed "digitalRead(ir1) == 0 ||""  to avoid the edges 
//     if ( digitalRead(ir2) == 0 && digitalRead(ir3) == 0 && digitalRead(ir6) == 1 && digitalRead(ir7) == 1) {
//       // To the right
//       state = 1 ;

//       if (angle < 150) {
//         angle += 4;
//         // delay(5);
//         return angle;
//       }
//     }
//     else if (digitalRead(ir3) == 0 && angle != 112 && angle != 64) {
//       // To the right
//       state = 0 ;
//       if (angle < 102) {
//         angle += 2;
//         // delay(5);
//         return angle;
//       }
//     }
//   }
//   return angle;
// }

unsigned int getAngel(void){
  if(digitalRead(ir4)== 0 && digitalRead(ir5) == 0 ){return angle ;} // stay as you are >>>>>>||<<<<<<
  // turn left 
  else if (digitalRead(ir6) == 0 || digitalRead(ir7) == 0 || digitalRead(ir8) == 0 ){
    if(angle > 70){
      angle--;
      return angle ;
    }
  } // turn right
  else if(digitalRead(ir2) == 0 || digitalRead(ir3) == 0 || digitalRead(ir1) == 0 ){
    if(angle < 130){
      angle++;
      return angle ;
    }
  }
  return angle ;
}