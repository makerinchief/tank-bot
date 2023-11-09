#include "datatypes.h"

//NRFLite is used to make communication easy
//https://github.com/dparson55/NRFLite
#include <SPI.h>
#include <NRFLite.h>

NRFLite tank_radio;
ControllerPacket controller_packet;
TankBotPacket tank_packet;

const static uint8_t TANK_BOT_ID = 0;
const static uint8_t RADIO_CE = 10;
const static uint8_t RADIO_CSN = 9;

//Interval to check if controller is in range
unsigned long range_check_current = 0;
long range_check_interval = 500;

bool radio_init() {
  return tank_radio.init(TANK_BOT_ID, RADIO_CE, RADIO_CSN);
}

struct TankBotPacket radio_get_tank_packet() {

  if (tank_radio.hasData()) {
    range_check_current = millis();
    tank_radio.readData(&tank_packet);
    return tank_packet;
  }

  if (millis() - range_check_current > range_check_interval) {
    Serial.println("Radio out of range...");
    range_check_current = millis();
    tank_packet.direction = 's';
    tank_packet.left_speed = 0;
    tank_packet.right_speed = 0;
    return tank_packet;
  }
}

struct ControllerPacket radio_get_joysticks_packet() {
  if (tank_radio.hasData()) {
    range_check_current = millis();
    tank_radio.readData(&controller_packet);
    return controller_packet;
  }

  if (millis() - range_check_current > range_check_interval) {
    Serial.println("Radio out of range...");
    controller_packet.left_x = 0;
    controller_packet.left_y = 0;
    controller_packet.left_b = 0;
    controller_packet.right_x = 0;
    controller_packet.right_y = 0;
    controller_packet.right_b = 0;
    range_check_current = millis();
    return controller_packet;
  }
}
