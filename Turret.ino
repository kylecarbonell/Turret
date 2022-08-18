#include <Servo.h>
#include <cvzone.h>

#define SERVO_PIN 9
#define VRX_PIN A0

int xVal;
Servo servo;

SerialData data(1,1);
int vals[1];

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO_PIN);
  data.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(VRX_PIN);
  xVal = map(xVal, 0, 1023, 0, 180);
  
  //delay(20);

  data.Get(vals);
  servo.write(vals[0]);

  
}
