//----------------------------------------------------------------
//-- Mark Rowland
//-- Troop 605 Robotics Merit Badge

#include <NewPing.h>
#include <VarSpeedServo.h>
#include <string.h>

const int DEBUG = true;
const int LEFT_FOOT_PIN = 2;  //Arduino PIN connection
const int RIGHT_FOOT_PIN = 3;
const int LEFT_LEG_PIN = 4;
const int RIGHT_LEG_PIN = 5;
const int SONIC_TRIGGER_PIN = 8;  // Arduino pin tied to trigger pin on the ultrasonic sensor.
const int SONIC_ECHO_PIN = 9;     // Arduino pin tied to echo pin on the ultrasonic sensor.

const int MAX_DISTANCE = 200;              // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int COLLISION_DISTANCE = 40;         // in centimeters
const int NA = 50; //Not Apllicable

///////////////////////////////////////////////////////////////////
//-- Select the Robot Letter                                     //
///////////////////////////////////////////////////////////////////
#define ROBOT_L

#ifdef ROBOT_A
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 110;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 5;
const int RIGHT_LEG_TILT = 60;
const int RIGHT_LEG_DOWN = 100;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 150;
const int LEFT_LEG_TILT = 80;
const int LEFT_LEG_DOWN = 50;
const int LEFT_LEG_EXTEND = 20;
#endif
#ifdef ROBOT_B
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 83;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 97;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 75;

const int RIGHT_LEG_UP = 5;
const int RIGHT_LEG_TILT = 60;
const int RIGHT_LEG_DOWN = 95;
const int RIGHT_LEG_EXTEND = 120;
const int LEFT_LEG_UP = 165;
const int LEFT_LEG_TILT = 100;
const int LEFT_LEG_DOWN = 55;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_C
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 85;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 105;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 95;
const int LEFT_WHEEL_STOP = 89;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 80;
const int RIGHT_LEG_DOWN = 110;
const int RIGHT_LEG_EXTEND = 135;
const int LEFT_LEG_UP = 150;
const int LEFT_LEG_TILT = 90;
const int LEFT_LEG_DOWN = 40;
const int LEFT_LEG_EXTEND = 15;
#endif
#ifdef ROBOT_D
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 120;
const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 75;
const int RIGHT_LEG_DOWN = 115;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 150;
const int LEFT_LEG_TILT = 85;
const int LEFT_LEG_DOWN = 50;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_E
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 60;
const int RIGHT_WHEEL_FORWARD = 78;
const int RIGHT_WHEEL_STOP = 84;
const int RIGHT_WHEEL_BACKWARD = 95;
const int LEFT_WHEEL_FAST = 130;
const int LEFT_WHEEL_FORWARD = 110;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 60;
const int RIGHT_LEG_DOWN = 95;
const int RIGHT_LEG_EXTEND = 120;
const int LEFT_LEG_UP = 150;
const int LEFT_LEG_TILT = 80;
const int LEFT_LEG_DOWN = 50;
const int LEFT_LEG_EXTEND = 10;
#endif
#ifdef ROBOT_F
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 83;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 120;
const int LEFT_WHEEL_FORWARD = 95;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 80;
const int RIGHT_LEG_DOWN = 115;
const int RIGHT_LEG_EXTEND = 140;
const int LEFT_LEG_UP = 150;
const int LEFT_LEG_TILT = 80;
const int LEFT_LEG_DOWN = 50;
const int LEFT_LEG_EXTEND = 20;
#endif
#ifdef ROBOT_G
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 75;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 89;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 50;
const int RIGHT_LEG_DOWN = 100;
const int RIGHT_LEG_EXTEND = 120;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 85;
const int LEFT_LEG_DOWN = 50;
const int LEFT_LEG_EXTEND = 20;
#endif
#ifdef ROBOT_H
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 95;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 100;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 170;
const int LEFT_LEG_TILT = 100;
const int LEFT_LEG_DOWN = 80;
const int LEFT_LEG_EXTEND = 20;
#endif
#ifdef ROBOT_I
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 75;
const int RIGHT_WHEEL_FORWARD = 84;
const int RIGHT_WHEEL_STOP = 89;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 97;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 100;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 85;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_J
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 89;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 100;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 85;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_K
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 89;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 100;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 85;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_L
const int SLOW_SPEED = 30;
const int DEFAULT_SPEED = 50;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 65;
const int RIGHT_WHEEL_FORWARD = 78;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 95;
const int LEFT_WHEEL_STOP = 88;
const int LEFT_WHEEL_BACKWARD = 76;

const int RIGHT_LEG_UP = 1;
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 100;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 85;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_1
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 88;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 87;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 20;
const int RIGHT_LEG_TILT = 65;
const int RIGHT_LEG_DOWN = 90;
const int RIGHT_LEG_EXTEND = 120;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 95;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_2
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 89;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 95;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 60;
const int RIGHT_LEG_DOWN = 90;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 100;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 20;
#endif
#ifdef ROBOT_4
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 110;
const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 95;
const int RIGHT_LEG_EXTEND = 140;
const int LEFT_LEG_UP = 170;
const int LEFT_LEG_TILT = 100;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 30;
#endif
NewPing Sonar(SONIC_TRIGGER_PIN, SONIC_ECHO_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.
VarSpeedServo leftWheel, rightWheel, leftLeg, rightLeg;
///////////////////////////////////////////////////////////////////
//-- DIAGNOSTICS       ------------------------------------------//
///////////////////////////////////////////////////////////////////
void wheelsUp() {
  leftLeg.write(LEFT_LEG_UP, SLOW_SPEED, true);
  rightLeg.write(RIGHT_LEG_UP, SLOW_SPEED, true);
}
void testWheelsForward() {
  Serial.println("Right Wheel Turn");
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, true);
  delay(5000);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
  Serial.println("Left Wheel Turn");
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, true);
  delay(5000);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);

  Serial.println("Both Wheels Forward");
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, true);
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, true);
  delay(5000);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
}
void testWheelsFastForward() {
  Serial.println("Right Wheel Turn");
  rightWheel.write(RIGHT_WHEEL_FAST, NA, true);
  delay(5000);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
  Serial.println("Left Wheel Turn");
  leftWheel.write(LEFT_WHEEL_FAST, NA, true);
  delay(5000);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);

  Serial.println("Both Wheels Fast Forward");
  rightWheel.write(RIGHT_WHEEL_FAST, NA, true);
  leftWheel.write(LEFT_WHEEL_FAST, NA, true);
  delay(5000);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
}
void testWheelsBackward() {
  Serial.println("Right Wheel Turn");
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, true);
  delay(5000);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
  Serial.println("Left Wheel Turn");
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, true);
  delay(5000);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);

  Serial.println("Both Wheels Backward");
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, true);
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, true);
  delay(5000);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
}
void testLegs() {
  Serial.println("Right Leg Extend");
  rightLeg.write(RIGHT_LEG_EXTEND, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Right Leg down");
  rightLeg.write(RIGHT_LEG_DOWN, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Right Leg tilt");
  rightLeg.write(RIGHT_LEG_TILT, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Right Leg up");
  rightLeg.write(RIGHT_LEG_UP, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Left Leg Extend");
  leftLeg.write(LEFT_LEG_EXTEND, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Left Leg Down");
  leftLeg.write(LEFT_LEG_DOWN, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Left Leg Tilt");
  leftLeg.write(LEFT_LEG_TILT, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Left Leg Up");
  leftLeg.write(LEFT_LEG_UP, SLOW_SPEED, true);
  delay(2000);
}
void findStop() {
  Serial.println("Find Right Wheel Stop");
  for (int i = 87; i < 93; i++) {
    Serial.println(i);
    rightWheel.write(i, NA, true);
    delay(3000);
  }
  Serial.println("Find Left Wheel Stop");
  for (int i = 87; i < 93; i++) {
    Serial.println(i);
    leftWheel.write(i, NA, true);
    delay(3000);
  }
}
void setLegsPosScrews() {
  leftLeg.write(160, SLOW_SPEED, true);
  rightLeg.write(10, SLOW_SPEED, true);
}
///////////////////////////////////////////////////////////////////
//-- Basic Routines    ------------------------------------------//
///////////////////////////////////////////////////////////////////
int sonar(const char *label) {
  int Distance = Sonar.ping_cm();
  if (Distance == 0) {
    Distance = MAX_DISTANCE;
  }
  if (DEBUG) {
    Serial.print(label);
    Serial.print(" Ping: ");
    Serial.print(Distance);
    Serial.println("cm");
  }
  return Distance;
}
void attachServos() {
  leftWheel.attach(LEFT_FOOT_PIN);
  rightWheel.attach(RIGHT_FOOT_PIN);
  leftLeg.attach(LEFT_LEG_PIN);
  rightLeg.attach(RIGHT_LEG_PIN);
}
void detachServos() {
  leftWheel.detach();
  rightWheel.detach();
  leftLeg.detach();
  rightLeg.detach();
}

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);  // Open serial monitor at 115200 baud to see ping results.
  Serial.println("Initialization");
  attachServos();
  leftLeg.write(LEFT_LEG_UP, SLOW_SPEED, false);
  rightLeg.write(RIGHT_LEG_UP, SLOW_SPEED, true);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
  delay(3000);
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
  int distance;
  int x, y;
  do {
    Serial.println("Scooter Diagnostics");
    Serial.println("1 Test Sonar");
    Serial.println("2 Wheels Forward");
    Serial.println("3 Wheels Fast Forward");
    Serial.println("4 Wheels Backward");
    Serial.println("5 Leg Extensions");
    Serial.println("6 Find Wheel Stop");
    Serial.println("7 set Legs Position Screw");

    while (!Serial.available());
    x = Serial.read();
    Serial.println(x);
    switch (x) {
      case '1':
        for (y = 1; y < 20; y++) {
          distance = sonar("TestSonar");
          delay(1000);
        }
        break;
      case '2':
        Serial.println("WheelsForward");
        testWheelsForward();
        break;
      case '3':
        Serial.println("WheelsFastForward");
        testWheelsFastForward();
        break;
      case '4':
        Serial.println("WheelsBackward");
        testWheelsBackward();
        break;
      case '5':
        Serial.println("TestLegs");
        testLegs();
        break;
      case '6':
        findStop();
        break;
      case '7':
        Serial.println("Set Leg Position to Max upright");
        setLegsPosScrews();
        break;
      default:
        break;
    }
  } while (true);
}