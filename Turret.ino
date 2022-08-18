#include <Servo.h>
#include <cvzone.h>

#define SERVO_PIN 9
#define VRX_PIN A0

int xVal;
Servo servo;

SerialData data(1,1);
int vals[1];

void turn(int vals){
  servo.write(vals);
  delay(20);
  servo.write(vals-180);
  
}

void shoot() {
  digitalWrite(9, HIGH);
//  digitalWrite(11, HIGH);
//  digitalWrite(6, HIGH);
  delay(10000); 
  digitalWrite(9, LOW);
//  digitalWrite(11, LOW);
//  digitalWrite(6, LOW);
}

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO_PIN);
  data.begin();
}

void loop() {
  // put your main code here, to run repeatedly:

  //Code to move gun and servos on gears
//  xVal = analogRead(VRX_PIN);
//  xVal = map(xVal, 0, 1023, 0, 180);
  
  

//Code for face detection and shooting
  data.Get(vals);
  Serial.println(vals[0]);
  if(vals[0] == 0){
    servo.write(180);
    delay(100);
    servo.write(0);
  }
  else{
    Serial.println("Working");
  }
  

  delay(20);
}
