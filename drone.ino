#include <NanitLib.h>

byte buzzerPin = P12_2;
byte forwardRightEnginePin = P1_3;
byte backRightEnginePin = P1_4;
byte forwardLeftEnginePin = P12_3;
byte backLeftEnginePin = P12_4;
byte triggerPin = P6_1;
byte echoPin = P6_4;

void setup() {
  Nanit_Base_Start();
  pinMode(MOTOR_ENABLE, OUTPUT);
  digitalWrite(MOTOR_ENABLE, 1);
  pinMode(buzzerPin, OUTPUT);
  pinMode(forwardRightEnginePin, OUTPUT);
  pinMode(backRightEnginePin, OUTPUT);
  pinMode(forwardLeftEnginePin, OUTPUT);
  pinMode(backLeftEnginePin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  if(distance() < 30) {
    stop();
    tone(buzzerPin, 880);
  } else {
    moveForward();
    noTone(buzzerPin);
  }
  delay(100);
}

int distance(){
    digitalWrite(triggerPin, 1);
    delayMicroseconds(60);
    digitalWrite(triggerPin, 0);
    return pulseIn(echoPin, 1) / 58;
}

void moveForward() {
  digitalWrite(forwardRightEnginePin, 1);
  digitalWrite(backRightEnginePin, 0);
  digitalWrite(forwardLeftEnginePin, 1);
  digitalWrite(backLeftEnginePin, 0);
}

void stop() {
  digitalWrite(forwardRightEnginePin, 0);
  digitalWrite(backRightEnginePin, 0);
  digitalWrite(forwardLeftEnginePin, 0);
  digitalWrite(backLeftEnginePin, 0);
}
