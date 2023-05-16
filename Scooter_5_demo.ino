

//----------------------------------------------------------------
//-- Mark Rowland
//-- Troop 605 Robotics Merit Badge

#include <NewPing.h>
#include <VarSpeedServo.h>


const int DEBUG = true;
const int WALK_MODE = true;
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

///////////////////////////////////////////////////////////////////
//-- Select the Robot Letter                                     //
///////////////////////////////////////////////////////////////////
#define ROBOT_1

#ifdef ROBOT_A
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 70;
const int RIGHT_WHEEL_FORWARD = 83;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
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

const int RIGHT_WHEEL_FAST = 75;
const int RIGHT_WHEEL_FORWARD = 85;
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
const int RIGHT_LEG_TILT = 70;
const int RIGHT_LEG_DOWN = 115;
const int RIGHT_LEG_EXTEND = 130;
const int LEFT_LEG_UP = 150;
const int LEFT_LEG_TILT = 90;
const int LEFT_LEG_DOWN = 50;
const int LEFT_LEG_EXTEND = 30;
#endif
#ifdef ROBOT_E
const int SLOW_SPEED = 20;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 60;
const int RIGHT_WHEEL_FORWARD = 75;
const int RIGHT_WHEEL_STOP = 84;
const int RIGHT_WHEEL_BACKWARD = 95;
const int LEFT_WHEEL_FAST = 130;
const int LEFT_WHEEL_FORWARD = 100;
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
const int RIGHT_WHEEL_FORWARD = 85;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 120;
const int LEFT_WHEEL_FORWARD = 96;
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
const int RIGHT_WHEEL_STOP = 89;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 120;
const int LEFT_WHEEL_FORWARD = 110;
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

const int RIGHT_WHEEL_FAST = 65;
const int RIGHT_WHEEL_FORWARD = 80;
const int RIGHT_WHEEL_STOP = 90;
const int RIGHT_WHEEL_BACKWARD = 100;
const int LEFT_WHEEL_FAST = 115;
const int LEFT_WHEEL_FORWARD = 118;
const int LEFT_WHEEL_STOP = 92;
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
const int SLOW_SPEED = 30;
const int DEFAULT_SPEED = 40;
const int FAST_SPEED = 200;

const int RIGHT_WHEEL_FAST = 68;
const int RIGHT_WHEEL_FORWARD = 73;
const int RIGHT_WHEEL_STOP = 89;
const int RIGHT_WHEEL_BACKWARD = 96;
const int LEFT_WHEEL_FAST = 107;
const int LEFT_WHEEL_FORWARD = 97;
const int LEFT_WHEEL_STOP = 88;
const int LEFT_WHEEL_BACKWARD = 81;

const int RIGHT_LEG_UP = 10;
const int RIGHT_LEG_TILT = 60;
const int RIGHT_LEG_DOWN = 90;
const int RIGHT_LEG_EXTEND = 120;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 110;
const int LEFT_LEG_DOWN = 65;
const int LEFT_LEG_EXTEND = 35;
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
const int RIGHT_LEG_TILT = 65;
const int RIGHT_LEG_DOWN = 90;
const int RIGHT_LEG_EXTEND = 120;
const int LEFT_LEG_UP = 160;
const int LEFT_LEG_TILT = 95;
const int LEFT_LEG_DOWN = 60;
const int LEFT_LEG_EXTEND = 30;
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
const int LEFT_WHEEL_FORWARD = 105;
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
  wheelsStop(0);
}
void wheelsFastForward(int duration) {
  leftWheel.write(LEFT_WHEEL_FAST, NA, false);
  rightWheel.write(RIGHT_WHEEL_FAST, NA, false);
  delay(duration);
}
void wheelsBackward(int duration) {
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, false);
  delay(duration);
  wheelsStop(0);
}
void wheelsRight(int duration) {
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  delay(duration);
  wheelsStop(0);
}
void wheelsLeft(int duration) {
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, false);
  delay(duration);
  wheelsStop(0);
}
void feetDown(int duration) {
  leftLeg.write(LEFT_LEG_DOWN, FAST_SPEED, false);
  rightLeg.write(RIGHT_LEG_DOWN, FAST_SPEED, false);
  leftLeg.wait();
  rightLeg.wait();
  delay(duration);
}
void feetUp(int duration) {
  leftLeg.write(LEFT_LEG_UP, FAST_SPEED, false);
  rightLeg.write(RIGHT_LEG_UP, FAST_SPEED, false);
  leftLeg.wait();
  rightLeg.wait();
  delay(duration);
}
void wheelsStop(int duration) {
  rightWheel.write(RIGHT_WHEEL_STOP, NA, false);
  leftWheel.write(LEFT_WHEEL_STOP, NA, false);
  leftWheel.wait();
  rightWheel.wait();
  delay(duration);
}
///////////////////////////////////////////////////////////////////
//-- Walking Routines  ------------------------------------------//
///////////////////////////////////////////////////////////////////
void findNewDirection() {
  int distance;
  do {
    wheelsLeft(100);
    delay(200);
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
  leftWheel.write(LEFT_WHEEL_FAST, NA, false);
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  delay(duration);
  wheelsStop(0);
}
void glideRight(int duration) {
  feetDown(200);
  rightWheel.write(RIGHT_WHEEL_FAST, NA, false);
  leftWheel.write(LEFT_WHEEL_BACKWARD, NA, false);
  delay(duration);
  wheelsStop(0);
}
void glideTilt(int steps) {
  feetDown(200);
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  rightWheel.write(RIGHT_WHEEL_BACKWARD, NA, false);
  for (int i = 0; i < steps; i++) {
    leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_TILT, DEFAULT_SPEED, true);
    rightLeg.wait();
    delay(200);
    feetDown(0);
    rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, false);
    leftLeg.write(LEFT_LEG_TILT, DEFAULT_SPEED, true);
    leftLeg.wait();
    delay(200);
    feetDown(200);
  }
  delay(200);
  wheelsStop(0);
}
void leftPirouette(int duration, int toeExtend) {
  rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, false);
  leftLeg.write(LEFT_LEG_TILT, DEFAULT_SPEED, false);
  rightLeg.wait();
  leftLeg.wait();
  if (toeExtend) {
    rightLeg.write(RIGHT_LEG_EXTEND, DEFAULT_SPEED, true);
    delay(200);
  }
  leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
  delay(duration);
  leftWheel.write(LEFT_WHEEL_STOP, NA, true);
}
void rightPirouette(int duration, int toeExtend) {
  leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, false);
  rightLeg.write(RIGHT_LEG_TILT, DEFAULT_SPEED, false);
  leftLeg.wait();
  rightLeg.wait();
  if (toeExtend) {
    leftLeg.write(LEFT_LEG_EXTEND, DEFAULT_SPEED, true);
    delay(200);
  }
  rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
  delay(duration);
  rightWheel.write(RIGHT_WHEEL_STOP, NA, true);
}
void pirouette(int duration) {
  feetDown(200);
  leftPirouette(duration, true);
  feetDown(0);
  rightPirouette(duration, true);
  feetDown(0);
}
void tilt(int steps) {
  feetDown(200);
  for (int i = 0; i < steps; i++) {
    leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_TILT, DEFAULT_SPEED, true);
    leftLeg.wait();
    delay(500);
    feetDown(200);
    rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, false);
    leftLeg.write(LEFT_LEG_TILT, DEFAULT_SPEED, true);
    rightLeg.wait();
    delay(500);
    feetDown(200);
  }
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
  feetDown(0);
  for (int i = 0; i < steps; i++) {
    leftPirouette(600, true);
    feetDown(200);
    rightPirouette(600, true);
    feetDown(200);
  }
}
void spinRight(int steps) {
  feetDown(200);
  rightLeg.write(RIGHT_LEG_UP, DEFAULT_SPEED, true);
  for (int i = 0; i < steps; i++) {
    rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
    leftWheel.write(LEFT_WHEEL_FORWARD, NA, true);
    delay(500);
  }
  feetDown(200);
}
void spinLeft(int steps) {
  feetDown(200);
  leftLeg.write(LEFT_LEG_UP, DEFAULT_SPEED, true);
  for (int i = 0; i < steps; i++) {
    leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
    rightWheel.write(RIGHT_WHEEL_FORWARD, NA, true);
    delay(500);
  }
  feetDown(200);
}
void walkForward(int steps) {
  feetDown(200);
  for (int i = 0; i < steps; i++) {
    rightLeg.write(RIGHT_LEG_EXTEND, FAST_SPEED, false);
    leftLeg.write(LEFT_LEG_TILT, FAST_SPEED, true);
    leftWheel.write(LEFT_WHEEL_FORWARD, NA, false);
    delay(400);
    leftWheel.write(LEFT_WHEEL_STOP, NA, true);
    delay(100);
    feetDown(100);
    leftLeg.write(LEFT_LEG_EXTEND, FAST_SPEED, false);
    rightLeg.write(RIGHT_LEG_TILT, FAST_SPEED, true);
    rightWheel.write(RIGHT_WHEEL_FORWARD, NA, false);
    delay(450);
    rightWheel.write(RIGHT_WHEEL_STOP, NA, false);
    delay(100);
    feetDown(100);
  }
  delay(100);
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
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
  //testLegs();exit(0);
  //feetUp(200);
  //for(int i=0;i<20;i++) wheelsLeft(200);
  //for(int i=0;i<20;i++) wheelsRight(200); exit(0);
  
  int distance, rightDistance, leftDistance;
  int count = 0;
  if (WALK_MODE) {
    jump(6);
    glideForward(2000);
    glideLeft(2000);
    spinRight(5);
    glideRight(2000);
    spinLeft(5);
    pirouette(2000);
    tilt(5);
    glideTilt(6);
    strutForward(2);
    walkForward(6);
  }
  feetUp(200);
  do {
    delay(400);
    distance = sonar("Main");
    if (distance < COLLISION_DISTANCE) {
      Serial.println("COLLISION");
      count = 0;
      wheelsBackward(400);
      delay(500);
      wheelsRight(300);
      delay(500);
      rightDistance = sonar("Right");
      wheelsLeft(500);
      delay(500);
      leftDistance = sonar("Left");
      if ((rightDistance > leftDistance) && (rightDistance > COLLISION_DISTANCE)) {
        wheelsRight(500);
        delay(400);
      } else if (leftDistance < COLLISION_DISTANCE) {
        Serial.println("find new direction");
        findNewDirection();
      }
    } else if ((distance < MAX_DISTANCE / 2) || (count < 10)) {
      wheelsForward(1000);
    } else if (SHOW_MODE && (count > 15)) {
      wheelsStop(200);
      switch (random(9)) {
        case 0: glideForward(500); break;
        case 1: glideRight(300); glideLeft(300); break;
        case 2: tilt(3); break;
        case 3: leftPirouette(1000, true); break;
        case 4: rightPirouette(1000, true); break;
        case 5: strutForward(3); break;
        case 6: jump(5); break;
        case 7: spinLeft(3); break;
        case 8: spinRight(3); break;
        default: walkForward(4);
      }
      count = 0;
      feetUp(200);
    } else {
      wheelsFastForward(600);
    }
    ++count;
    Serial.print("Loop ");
    Serial.println(count);
  } while (true);
  detachServos();
  exit(0);
}
