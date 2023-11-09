//Ultrasonic sensor
const int TRIGGER_PIN = 15;
const int ECHO_PIN = 14;
const float SPEED_OF_SOUND = 0.034; // m/s

void ultrasonic_init() {
  // Ultrasonic Sensor
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

int ultrasonic_get_distance() {

  //Send a sound pulse
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  //Get the time the sounds takes to echo back
  int duration = pulseIn(ECHO_PIN, HIGH);
  
  //Distance is duration scaled for the speed of sound 
  // and halved (only want distance of one trip)
  int distance = duration * SPEED_OF_SOUND / 2;
  
  //Return the distance in CM
  return distance;
}
