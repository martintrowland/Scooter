//----------------------------------------------------------------
//-- Mark Rowland
//-- Troop 605 Robotics Merit Badge

#include <NewPing.h>
#include <VarSpeedServo.h>

const int DEBUG = true;
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
const int SLOW_SPEED = 20;
const int MED_SPEED = 40;
const int FAST_SPEED = 200;

const int LEFT_WHEEL_FORWARD = 100;
const int LEFT_WHEEL_STOP = 89;
const int LEFT_WHEEL_BACKWARD = 80;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_DOWN = 90;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_DOWN = 75;

NewPing Sonar(SONIC_TRIGGER_PIN, SONIC_ECHO_PIN, MAX_DISTANCE);  // NewPing setup of pins and maximum distance.
VarSpeedServo leftWheel, rightWheel, leftLeg, rightLeg;
///////////////////////////////////////////////////////////////////
//-- DIAGNOSTICS       ------------------------------------------//
///////////////////////////////////////////////////////////////////
void testLegs() {
  Serial.println("Right Leg down");
  rightLeg.write(RIGHT_LEG_DOWN, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Right Leg up");
  rightLeg.write(RIGHT_LEG_UP, SLOW_SPEED, true);
  delay(2000);
  Serial.println("Left Leg Down");
  leftLeg.write(LEFT_LEG_DOWN, SLOW_SPEED, true);
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
  do {
    wheelsLeft(200);
    delay(500);
  } while (sonar("FindNewDirection") < 1.5 * COLLISION_DISTANCE);
}
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);  // Open serial monitor at 115200 baud to see ping results.
  attachServos();
  leftLeg.write(LEFT_LEG_UP, FAST_SPEED, true);
  rightLeg.write(RIGHT_LEG_UP, FAST_SPEED, true);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
  delay(3000);
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
  int distance, rightDistance, leftDistance;
  int count = 0;
  Serial.println("Start");
  do {
    distance = sonar("Main");
    if (distance < COLLISION_DISTANCE) {
      Serial.println("COLLISION");
      wheelsStop(0);
      wheelsBackward(400);
      wheelsRight(400);
      rightDistance = sonar("Right");
      wheelsLeft(600);
      leftDistance = sonar("Left");
      if ((rightDistance > leftDistance) && (rightDistance > COLLISION_DISTANCE)) {
        wheelsRight(700);
      } else if (leftDistance < COLLISION_DISTANCE) {
        Serial.println("find new direction");
        findNewDirection();
      }
    }
    wheelsForward(800);
  } while (++count < SHUTDOWN_TIMER);
  detachServos();
  exit(0);
}
