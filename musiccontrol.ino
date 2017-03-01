#include "Keyboard.h"
int footpaddle = 2;
int buttonState = 0;
int prevState = LOW;
int leftprevPot = 0;
int rightprevPot = 0;
int upprevPot = 0;
int downprevPot = 0;
int randomprevPot = 0;

void setup() {
  //Serial.begin(9600); // initialize serial communications
  pinMode(footpaddle, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  Keyboard.begin(); //initial control over the keyboard
}

void loop() {
  //key press '2' (paddle) works
  buttonState = digitalRead(footpaddle);
  //Serial.println(buttonState);
  if (buttonState == 0 && prevState == 1) {
    //Serial.println("pressed");
    Keyboard.press('2');
  } else {
    Keyboard.releaseAll();
  }
  prevState = buttonState;
  delay(1);

  //key press '4' works
  int leftPot = analogRead(A1) / 4;  // read the input pin
  //  Serial.print("left");
  //  Serial.println(leftPot);
  //  Serial.print("leftprevPot");
  //  Serial.println(leftprevPot);
  if (leftPot < 20 && leftprevPot > 20) {
    Keyboard.press('4');
    //Serial.println(leftPot);
  } else {
    Keyboard.releaseAll();
  }
  leftprevPot = leftPot;
  delay(50);
  
  //key press '3'
  int rightPot = analogRead(A2) / 4;
  //Serial.print("right");
  //Serial.println(rightPot);
  //Serial.print("rightprevPot");
  //Serial.println(rightprevPot);
  if (rightPot == 0 && rightprevPot > 0) {
    Keyboard.press('3');
    Serial.println("right pressed");
  } else {
    Keyboard.releaseAll();
  }
  rightprevPot = rightPot;
  delay(50);       // slight delay to stabilize the ADC

  //key press '5' works
  //int upPot = analogRead(A2) / 4; // remap the pot value to fit in 1 byte
  int upPot = digitalRead(5);
  //Serial.print("Up" );
  //Serial.println(upPot);
  //Serial.print("upprevPot");
  //Serial.println(upprevPot);
  if (upPot ==0 && upprevPot > 0) {
    Keyboard.press('5');
  } else {
    Keyboard.releaseAll();
  }
  upprevPot = upPot;
  delay(50);

  //key press '1' works
  int downPot = digitalRead(4);
  Serial.print("Down ");
  Serial.println(downPot);
  Serial.print("downprevPot");
  Serial.println(downprevPot);
  if (downPot == 0 && downprevPot > 0) {
    Keyboard.press('1');
    Serial.println(downPot);
  } else {
    Keyboard.releaseAll();
  }
  downprevPot = downPot;
  delay(50);

  //key press '6' works
  int randomPot = analogRead(A0) / 4;
  //Serial.print("Random ");
  //Serial.println(randomPot);
  if (randomPot == 0 && randomprevPot > 0) {
    Keyboard.press('6');
    //Serial.println(randomPot);
  } else {
    Keyboard.releaseAll();
  }
  randomprevPot = randomPot;
  delay(50);
}
