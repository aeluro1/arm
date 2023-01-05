#include <Arduino.h>

#include <Servo.h>
// #include <ros.h>
// #include <std_msgs/UInt16.h>

// ros::NodeHandle nh;

Servo SERVO_ROLL;
Servo SERVO_PITCH;
Servo SERVO_ROLL2;


void moveTo(Servo s, int pos) {
  Serial.println("Current: " + s.read());
  Serial.println("New: " + pos);
  s.write(pos);
}

void moveAll(int pos) {
    moveTo(SERVO_ROLL, pos);
    moveTo(SERVO_PITCH, pos);
    moveTo(SERVO_ROLL2, pos);
}

void setup() {
  SERVO_ROLL.attach(2, 500, 2500);
  SERVO_PITCH.attach(3, 500, 2500);
  SERVO_ROLL2.attach(4, 500, 2500);
  Serial.begin(9600);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 10) {
    moveAll(pos);
    delay(500);
  }
  moveAll(90);
  delay(10000);

  

  // if (Serial.available() > 0) {
  //   Serial.print(Serial.available());
  //   String val = Serial.readString();
  //   val.trim();
  //   Serial.println("Value: " + val);
  //   Serial.println("Conv:" + std::stoi(val));
  // }
  // moveTo(SERVO_ROLL, 0);
  // moveTo(SERVO_PITCH;servo_pitch, 0);
  // delay(1000);
}
