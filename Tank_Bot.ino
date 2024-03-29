/*
  Tank Bot
  Justin C Kirk

  Makerinchief 
  www.makerinchief.com
  info@makerinchief.com

  Please read README.md for details
  
*/

#include "datatypes.h"

unsigned long tank_current = 0;
unsigned long tank_previous = 0;
long tank_interval = 100;

ControllerPacket controller_data;
TankBotData tank_data;

void setup() {
  Serial.begin(115200);

  motors_init();

  if (!radio_init()) {
    Serial.println("!NO RADIO FOUND!");
    motors_stop();
  }
}

void loop() {

  tank_current = millis();

  if (tank_current - tank_previous > tank_interval) {

    TankBotPacket _packet = radio_get_tank_packet();

    char tank_direction = _packet.direction;
    int l_spd = _packet.left_speed;
    int r_spd = _packet.right_speed;

    Serial.print("L SPD: ");
    Serial.print(l_spd);
    Serial.print(" R SPD: ");
    Serial.print(r_spd);
    Serial.print(" DIR: ");
    Serial.println(tank_direction);

    move_tank(tank_direction, l_spd, r_spd);
    tank_previous = tank_current;
  }
}

void control_tank() {

}

// SCRIPTS
void obstacle_advoidance(int motor_speed, int object_distance) {

  //Get distance of any objects in front
  int distance = ultrasonic_get_distance();

  if (distance > object_distance) {
    motors_forward(motor_speed);
  }

  else if (distance <= object_distance) {
    motors_stop();
    delay(250);
    motors_backward(motor_speed);
    delay(500);
    motors_stop();
    delay(100);
    motors_left(motor_speed);
    delay(500);
  }
}
