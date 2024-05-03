// hey there is code in here!!!
#include <tcs3200.h>
#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

#define IR_1 4
#define IR_2 7
#define IR_3 8
#define IR_4 12

unsigned long colorSensorMillis = 0;
unsigned long irSensorMillis = 0; // Timer to track the last report of teh IR sensors

void setup() {
// put your setup code here, to run once:

// Setup Infrared Pins
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Get the current run time in milliseconds
  unsigned long currentMillis = millis();

  // Check the states of the IR sensors every 500ms
  if (currentMillis - irSensorMillis >=500) {
    irSensorMillis = currentMillis;
    readInfrared();
  }

  // Read the color sensor
  if (currentMillis - colorSensorMillis >= 250) {
    colorSensorMillis = currentMillis;
    readColorSensor();
  }
}
