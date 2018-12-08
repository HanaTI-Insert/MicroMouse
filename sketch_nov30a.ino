/*
  ButtonMouseControl

  For Leonardo and Due boards only.

  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

  Hardware:
  - five pushbuttons attached to D2, D3, D4, D5, D6

  The mouse movement is always relative. This sketch reads four pushbuttons,
  and uses them to set the movement of the mouse.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 15 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ButtonMouseControl
*/

#include "Mouse.h"

/*
  ButtonMouseControl
 
 Controls the mouse from five pushbuttons on an Arduino Leonardo or Micro.
 
 Hardware:
 * 5 pushbuttons attached to D2, D3, D4, D5, D6
 
 
 The mouse movement is always relative. This sketch reads 
 four pushbuttons, and uses them to set the movement of the mouse.
 
 WARNING:  When you use the Mouse.move() command, the Arduino takes
 over your mouse!  Make sure you have control before you use the mouse commands.
 
 created 15 Mar 2012
 modified 27 Mar 2012
 by Tom Igoe
 
 this code is in the public domain
 
 */

// set pin numbers for the five buttons:
const int upButton = 2;     
const int downButton = 3;        
const int leftButton = 4;
const int rightButton = 5;
const int mouseButton = 6;

int range = 5;              // output range of X or Y movement; affects movement speed
int responseDelay = 10;     // response delay of the mouse, in ms


void setup() {
  // initialize the buttons' inputs:
  pinMode(upButton, INPUT);       
  pinMode(downButton, INPUT);       
  pinMode(leftButton, INPUT);       
  pinMode(rightButton, INPUT);       
  pinMode(mouseButton, INPUT);
  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  for (int i=0; i <= 5; i++){
    Mouse.move(range, range, 0);
    delay(responseDelay);
  }
  Mouse.click(MOUSE_LEFT);
  for (int i=0; i <= 5; i++){
    Mouse.move(range, -range, 0);
    delay(responseDelay);
  }
  Mouse.click(MOUSE_LEFT);
  for (int i=0; i <= 5; i++){
    Mouse.move(-range, -range, 0);
    delay(responseDelay);
  }
  Mouse.click(MOUSE_LEFT);
  for (int i=0; i <= 5; i++){
    Mouse.move(-range, range, 0);
    delay(responseDelay);
  }
  Mouse.click(MOUSE_LEFT);
}
