/**
HC-SR04P Example
Description: Calculate the distance from the object using an ultrasonic sensor.

Author: Yeseong Kang (kkds002@yonsei.ac.kr)
Date Created: 2024-11-07
Last Updated: 2024-11-07

**/

#define TRIG 9 // Output
#define ECHO 8 // Input

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  long duration, dist;

  digitalWrite(TRIG, LOW); // TRIG init
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  dist = (340*duration/10000)/2; // 초음파의 속도 340m/s * 왕복에 걸린 시간/ cm 단위로 변환(10000) / 편도로 변환(2)

  Serial.print(dist);
  Serial.println(" cm");

  delay(500);
}
