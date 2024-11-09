/**
RGB LED Example
Description: RGB Wheel Example

Author: Yeseong Kang (kkds002@yonsei.ac.kr)
Date Created: 2024-11-08
Last Updated: 2024-11-08

**/

#define RED 11
#define GREEN 10
#define BLUE 9
#define SPEED 10

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  for(int i = 0; i < 256; i++){
    analogWrite(RED, 255-i);
    analogWrite(GREEN, i);
    analogWrite(BLUE, 0);
    delay(SPEED);
  }

  for(int i = 0; i < 256; i++){
    analogWrite(RED, 0);
    analogWrite(GREEN, 255-i);
    analogWrite(BLUE, i);
    delay(SPEED);
  }

  for(int i = 0; i < 256; i++){
    analogWrite(RED, i);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 255);
    delay(SPEED);
  }

  for(int i = 0; i < 256; i++){
    analogWrite(RED, 255);
    analogWrite(GREEN, i);
    analogWrite(BLUE, 255);
    delay(SPEED);
  }

  for(int i = 0; i < 256; i++){
    analogWrite(RED, 255);
    analogWrite(GREEN, 255-i);
    analogWrite(BLUE, 255-i);
    delay(SPEED);
  }
}
