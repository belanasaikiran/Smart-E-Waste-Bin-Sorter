#include <Servo.h>

#define BIT_RATE 9600
#define ATCH_PIN 9 
#define INIT_POS 90

Servo m_servo;

void setup() {
  Serial.begin(BIT_RATE);   
  m_servo.attach(ATCH_PIN);
  m_servo.write(INIT_POS);
}

void pivot() {
  
  while(Serial.available() != 0 ) {
    continue;
  }
  
  int select = Serial.parseInt();

  switch (select) {
    case 1:
      m_servo.write(35);
      delay(1250);
      m_servo.write(INIT_POS);
      break;
    case 2:
      m_servo.write(145);
      delay(1250);
      m_servo.write(INIT_POS);
      break;
  }

  while(Serial.available() > 0) {
    char c = Serial.read(); 
    if (c == '\n' || c == '\r') continue;
  }
}

void loop() {
  pivot();
}