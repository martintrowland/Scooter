

//----------------------------------------------------------------
//-- Mark Rowland
//-- Troop 605 Robotics Merit Badge

#include <NewPing.h>
#include <VarSpeedServo.h>

const int DEBUG = true;
const int WALK_MODE = false;
const int SHOW_MODE = false;

const int LEFT_WHEEL_PIN = 2;  //Arduino PIN connection
const int RIGHT_WHEEL_PIN = 3;
const int LEFT_LEG_PIN = 4;
const int RIGHT_LEG_PIN = 5;
const int SONIC_TRIGGER_PIN = 8;  // Arduino pin tied to trigger pin on the ultrasonic sensor.
const int SONIC_ECHO_PIN = 9;     // Arduino pin tied to echo pin on the ultrasonic sensor.

const int MAX_DISTANCE = 200;       // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int COLLISION_DISTANCE = 40;  // in centimeters
const int SHUTDOWN_TIMER = 10000;

const int NA = 50;  //Not Apllicable
const int SLOW_SPEED = 25;
const int MED_SPEED = 50;
const int FAST_SPEED = 120;

const int LEFT_WHEEL_FAST = 120;
const int LEFT_WHEEL_FORWARD = 105;
const int LEFT_WHEEL_STOP = 90;
const int LEFT_WHEEL_BACKWARD = 80;
const int RIGHT_WHEEL_FAST = 68;
const int RIGHT_WHEEL_FORWARD = 78;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;

const int RIGHT_LEG_UP = 0;
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 92;
const int RIGHT_LEG_EXTEND = 120;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 100;
const int LEFT_LEG_DOWN = 75;
const int LEFT_LEG_EXTEND = 40;

NewPing Sonar(SONIC_TRIGGER_PIN, SONIC_ECHO_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.
VarSpeedServo leftWheel, rightWheel, leftLeg, rightLeg;

///////////////////////////////////////////////////////////////////
//-- Basic Routines for Wheel'ed Navigation                      //
///////////////////////////////////////////////////////////////////
// void testLegs()
// int sonar(const char *label) - Distance to obstacal in front measured in cm
// wheelsForward(int duration) 
// wheelsFastForward(int duration) 
// wheelsBackward(int duration) 
// wheelsRight(int duration) 
// wheelsLeft(int duration) 
// feetDown(int duration) 
// feetUp(int duration) 
// wheelsStop(int duration)
// 
// ----  The following Dance Moves Require Tuning of your Servo Values
//
// glideForward(int duration) 
// glideBackward(int duration) 
// glideLeft(int duration) 
// glideRight(int duration) 
// lideTilt(int steps) 
// leftPirouette(int duration, int toeExtend) 
// rightPirouette(int duration, int toeExtend) 
// pirouette(int duration) 
// tilt(int steps) 
// jump(int steps) 
// strutForward(int steps) 
// spinRight(int steps) 
// spinLeft(int steps) 
// walkForward(int steps) 
///////////////////////////////////////////////////////////////////
//-- Principal Loop                                              //
//    Edit Your code here                                        //
///////////////////////////////////////////////////////////////////
void loop() {
  int distance, rightDistance, leftDistance;
  int count = 0;
  jump(6);
  tilt(5);
  strutForward(2);
  feetUp(200);
  do {
    wheelsStop(0);
    while((distance = sonar("Main"))<COLLISION_DISTANCE){
      Serial.println("COLLISION");
      wheelsRight(200);
      delay(250);
    }
    wheelsFastForward(600);
    Serial.print("Loop ");
  } while (++count>200);
  detachServos();
  exit(0);
}

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);  // Open serial monitor at 115200 baud to see ping results.
  attachServos();
  wheelsStop(200);
  feetDown(200);
  delay(3000);
}
///////////////////////////////////////////////////////////////////
//-- Basic Routines    ------------------------------------------//
///////////////////////////////////////////////////////////////////
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
  Serial.println("Right Wheel Forward");
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, true);
  delay(5000);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
  Serial.println("Left Wheel Forward");
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, true);
  delay(5000);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
}
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
  leftWheel.attach(LEFT_WHEEL_PIN);
  rightWheel.attach(RIGHT_WHEEL_PIN);
  leftLeg.attach(LEFT_LEG_PIN);
  rightLeg.attach(RIGHT_LEG_PIN);
}
void detachServos() {
  leftWheel.detach();
  rightWheel.detach();
  leftLeg.detach();
  rightLeg.detach();
}
void wheelsForward(int duration) {
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
  delay(duration);
}
void wheelsFastForward(int duration) {
  leftWheel.write(LEFT_WHEEL_FAST, NA, false);
  rightWheel.write(RIGHT_WHEEL_FAST, NA, false);
  delay(duration);
}
void wheelsBackward(int duration) {
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, false);
  wheelsStop(duration);
}
void wheelsRight(int duration) {
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  wheelsStop(duration);
}
void wheelsLeft(int duration) {
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, false);
  wheelsStop(duration);
}
void feetDown(int duration) {
  delay(duration);
  leftLeg.write(LEFT_LEG_DOWN, FAST_SPEED, false);
  rightLeg.write(RIGHT_LEG_DOWN, FAST_SPEED, false);
  leftLeg.wait();
  rightLeg.wait();
}
void feetUp(int duration) {
  delay(duration);
  leftLeg.write(LEFT_LEG_UP, FAST_SPEED, false);
  rightLeg.write(RIGHT_LEG_UP, FAST_SPEED, false);
  leftLeg.wait();
  rightLeg.wait();
}
void wheelsStop(int duration) {
  delay(duration);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, false);
  leftWheel.write(LEFT_WHEEL_STOP, NA, false);
  leftWheel.wait();
  rightWheel.wait();
}
///////////////////////////////////////////////////////////////////
//-- Walking Routines  ------------------------------------------//
///////////////////////////////////////////////////////////////////
void findNewDirection() {
  int distance;
  do {
    wheelsLeft(200);
    delay(500);
    wheelsStop(0);
    distance = sonar("FindNewDirection");
  } while (distance < 1.5 * COLLISION_DISTANCE);
}
void glideForward(int duration) {
  feetDown(200);
  wheelsFastForward(duration);
}
void glideBackward(int duration) {
  feetDown(200);
  wheelsBackward(duration);
}
void glideLeft(int duration) {
  feetDown(200);
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  wheelsStop(duration);
}
void glideRight(int duration) {
  feetDown(200);
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, false);
  wheelsStop(duration);
}
void glideTilt(int steps) {
  feetDown(200);
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  for (int i = 0; i < steps; i++) {
    leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_TILT, SLOW_SPEED, true);
    leftLeg.wait();
    feetDown(200);
    rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, false);
    leftLeg.write(LEFT_LEG_TILT, SLOW_SPEED, true);
    rightLeg.wait();
    feetDown(200);
  }
  wheelsStop(200);
}
void leftPirouette(int duration, int toeExtend) {
  rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, false);
  leftLeg.write(LEFT_LEG_TILT, SLOW_SPEED, false);
  rightLeg.wait();
  leftLeg.wait();
  if (toeExtend) {
    rightLeg.write(RIGHT_LEG_EXTEND, SLOW_SPEED, true);
    delay(200);
  }
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  delay(duration);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
}
void rightPirouette(int duration, int toeExtend) {
  leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, false);
  rightLeg.write(RIGHT_LEG_TILT, SLOW_SPEED, false);
  leftLeg.wait();
  rightLeg.wait();
  if (toeExtend) {
    leftLeg.write(LEFT_LEG_EXTEND, SLOW_SPEED, true);
    delay(200);
  }
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
  delay(duration);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
}
void pirouette(int duration) {
  feetDown(200);
  leftPirouette(duration, true);
  delay(400);
  feetDown(200);
  rightPirouette(duration, true);
  feetDown(200);
}
void tilt(int steps) {
  feetDown(200);
  for (int i = 0; i < steps; i++) {
    leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_TILT, SLOW_SPEED, true);
    leftLeg.wait();
    feetDown(300);
    rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, false);
    leftLeg.write(LEFT_LEG_TILT, SLOW_SPEED, true);
    rightLeg.wait();
    feetDown(300);
  }
  feetDown(200);
}
void jump(int steps) {
  feetDown(200);
  for (int i = 0; i < steps; i++) {
    leftLeg.write(LEFT_LEG_EXTEND, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_EXTEND, FAST_SPEED, true);
    leftLeg.write(LEFT_LEG_DOWN, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_DOWN, FAST_SPEED, true);
  }
}
void strutForward(int steps) {
  feetDown(200);
  for (int i = 0; i < steps; i++) {
    leftPirouette(300, true);
    feetDown(100);
    rightPirouette(300, true);
    feetDown(100);
  }
  feetDown(100);
}
void spinRight(int steps) {
  feetDown(200);
  rightLeg.write(RIGHT_LEG_UP, MED_SPEED, true);
  for (int i = 0; i < steps; i++) {
    rightWheel.write(RIGHT_WHEEL_FORWARD, MED_SPEED, false);
    leftWheel.write(LEFT_WHEEL_FORWARD, NA, true);
    delay(200);
  }
  feetDown(200);
}
void spinLeft(int steps) {
  feetDown(200);
  leftLeg.write(LEFT_LEG_UP, MED_SPEED, true);
  for (int i = 0; i < steps; i++) {
    leftWheel.write(LEFT_WHEEL_FORWARD, MED_SPEED, false);
    rightWheel.write(RIGHT_WHEEL_FORWARD, NA, true);
    delay(200);
  }
  feetDown(200);
}
void walkForward(int steps) {
  feetDown(200);
  for (int i = 0; i < steps; i++) {
    rightLeg.write(RIGHT_LEG_EXTEND, FAST_SPEED, false);
    leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, true);
    leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
    delay(300);
    leftWheel.write(LEFT_WHEEL_STOP, NA, true);
    feetDown(50);
    leftLeg.write(LEFT_LEG_EXTEND, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, true);
    rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
    delay(450);
    rightWheel.write(RIGHT_WHEEL_STOP, NA, false);
    feetDown(50);
  }
  delay(100);
}
