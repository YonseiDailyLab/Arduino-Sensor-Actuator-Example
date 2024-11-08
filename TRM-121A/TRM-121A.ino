/**
TRM-121A Example
Description: TRM-121A Digital Radar Module example.
             This example is a code that detects the speed of an object.

Author: Yeseong Kang (kkds002@yonsei.ac.kr)
Date Created: 2024-11-07
Last Updated: 2024-11-07

**/
#define SIG 11 // 센서 SOUT 핀

int v; // 속도
int max_v; // 최대 속도

void setup() {
  Serial.begin(9600); // 시리얼 모드 설정
  pinMode(SIG, INPUT);
}

void loop() {
  unsigned long t; // 주기
  double freq; // 주파수
  char s[20]; // 시리얼 출력 버퍼

  max_v = 0;

  // 주기 측정: HIGH 및 LOW 신호의 합을 사용
  t = pulseIn(SIG, HIGH, 1000000) + pulseIn(SIG, LOW, 1000000); // 타임아웃을 1초(1,000,000µs)로 설정

  // 주파수 및 속도 계산 (t가 유효한 경우에만)
  if (t > 100 && t < 1000000) { // 주기의 합이 100µs 이상, 1초 미만일 경우만 계산
    freq = 1e6 / t; // 주파수 계산 (마이크로초를 초로 변환하여 사용)
    v = int((freq) / 44.0); // 속도 측정
    max_v = max(v, max_v); // 속도의 Max값 측정
    sprintf(s, "%3d km/h", max_v); // 출력 버퍼에 값 저장
    Serial.println(s); // Serial 출력
  } else {
    Serial.println("Error: Invalid period detected"); // 유효하지 않은 주기일 경우
  }

  delay(500); // Delay 500ms
}