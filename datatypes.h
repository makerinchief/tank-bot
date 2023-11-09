#ifndef DATATYPES_H
#define DATATYPES_H

typedef struct SensorValues {
  int distance;
};

typedef struct ControllerPacket {
  int16_t left_x;
  int16_t left_y;
  int16_t left_b;
  int16_t right_x;
  int16_t right_y;
  int16_t right_b;
};

typedef struct TankBotPacket {
  char direction;
  int16_t left_speed;
  int16_t right_speed;  
};

typedef struct TankBotData {
  char direction;
  int16_t left_speed;
  int16_t right_speed;
};

#endif
