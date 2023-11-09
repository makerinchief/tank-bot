#include "datatypes.h"

//Left Side
// d1, d2, enA
const int LEFT_PWM = 6;
const int LEFT_A = 7;
const int LEFT_B = 8;

//Right Side
// d3, d4, enB
const int RIGHT_PWM = 5;
const int RIGHT_A = 4;
const int RIGHT_B = 3;

void motors_init() {
  pinMode(LEFT_PWM, OUTPUT);
  pinMode(LEFT_A, OUTPUT);
  pinMode(LEFT_B, OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  pinMode(RIGHT_A, OUTPUT);
  pinMode(RIGHT_B, OUTPUT);
}

void move_tank(char dir, int l_spd, int r_spd) {
  switch (dir) {

    case 's':
      motors_stop();
      break;

    case 'f':
      motors_left_forward(l_spd);
      motors_right_forward(r_spd);
      break;

    case 'b':
      motors_left_backward(l_spd);
      motors_right_backward(r_spd);
      break;

    case 'l':
      motors_left_backward(l_spd);
      motors_right_forward(r_spd);
      break;

    case 'r':
      motors_left_forward(l_spd);
      motors_right_backward(r_spd);
      break;

    default:
      motors_stop();
      break;

  }
}

//Use this to test the motor directions
void motors_test(int motor_speed, int motor_time) {

  motors_forward(motor_speed);
  delay(motor_time);

  motors_stop();
  delay(motor_time);

  motors_backward(motor_speed);
  delay(motor_time);

  motors_stop();
  delay(motor_time);

  motors_left(motor_speed);
  delay(motor_time);

  motors_stop();
  delay(motor_time);

  motors_right(motor_speed);
  delay(motor_time);

  motors_stop();
  delay(motor_time);

}

// CORE FUNCTIONS

//  If you are having issues with your Tank Bot's motor direction matching the
//  Controller Bot's joysticks, double check your wiring or try switching the HIGH and LOW values
//  in the digitalWrite() statements below.

//                         !!WARNING!!
//   Never set a motor's A and B pins to HIGH at the same time!
//              !!WILL CAUSE MOTOR DRIVER FAILURE!!

//Functions for each set of motors

void motors_forward(int motor_speed) {
  Serial.println("FORWARD");
  motors_left_forward(motor_speed);
  motors_right_forward(motor_speed);
}

void motors_backward(int motor_speed) {
  Serial.println("BACKWARD");
  motors_left_backward(motor_speed);
  motors_right_backward(motor_speed);
}

void motors_left(int motor_speed) {
  Serial.println("LEFT");
  motors_left_backward(motor_speed);
  motors_right_forward(motor_speed);
}

void motors_right(int motor_speed) {
  Serial.println("RIGHT");
  motors_left_forward(motor_speed);
  motors_right_backward(motor_speed);
}

void motors_stop() {
  Serial.println("STOP");
  motors_left_stop();
  motors_right_stop();
}

void motors_left_forward(int motor_speed) {
  analogWrite(LEFT_PWM, motor_speed);
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, HIGH);
}

void motors_left_backward(int motor_speed) {
  analogWrite(LEFT_PWM, motor_speed);
  digitalWrite(LEFT_A, HIGH);
  digitalWrite(LEFT_B, LOW);
}

void motors_left_stop() {
  analogWrite(LEFT_PWM, 0);
  digitalWrite(LEFT_A, LOW);
  digitalWrite(LEFT_B, LOW);
}

void motors_right_forward(int motor_speed) {
  analogWrite(RIGHT_PWM, motor_speed);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, HIGH);

}

void motors_right_backward(int motor_speed) {
  analogWrite(RIGHT_PWM, motor_speed);
  digitalWrite(RIGHT_A, HIGH);
  digitalWrite(RIGHT_B, LOW);
}

void motors_right_stop() {
  analogWrite(RIGHT_PWM, 0);
  digitalWrite(RIGHT_A, LOW);
  digitalWrite(RIGHT_B, LOW);
}
