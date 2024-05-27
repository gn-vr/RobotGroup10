// hey there is code in here!!!
#include <tcs3200.h>
#include <WiFiNINA.h>
#define COLOR_0 A0
#define COLOR_1 A1
#define COLOR_2 A2
#define COLOR_3 A3
#define COLOR_OUT A4

#define IR_1 4
#define IR_2 7
#define IR_3 8
#define IR_4 12

#define MOTOR_PIN1 3
#define MOTOR_PIN2 5
#define MOTOR_PIN3 6
#define MOTOR_PIN4 9

#define TRIG_PIN 10
#define ECHO_PIN 11

#define LED_R 25
#define LED_G 26
#define LED_B 27


unsigned long colorSensorMillis = 0;
unsigned long irSensorMillis = 0; // Timer to track the last report of the IR sensors
unsigned long ultrasonicSensorMillis = 0;
// Get the current run time in milliseconds
unsigned long currentMillis;

// State Logic
String currentState = "Null";
String oldCurrentState = "Null";

String turnDirection = "";
String lastTurnDirection = "";
bool isTurning = false;
bool wallDetected = false;

int currentDistance = 10;


// Test motor control
void motorTest() {
  motorControl(255, 255);
  delay(1000);
  motorControl(0, 0);
  delay(100);
  motorControl(255, -255);
  delay(500);
  motorControl(0,0);
  delay(100);
  Serial.println("Motor code is running!");
}

void setup() {
// put your setup code here, to run once:

// Setup Infrared Pins
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);
  pinMode(IR_4, INPUT);

  // Setup Motor Pins
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PIN3, OUTPUT);
  pinMode(MOTOR_PIN4, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Setup onboard RGB LED pins
  
  WiFiDrv::pinMode(LED_R, OUTPUT);
  WiFiDrv::pinMode(LED_G, OUTPUT);
  WiFiDrv::pinMode(LED_B, OUTPUT);
  

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Get the current run time in milliseconds
  currentMillis = millis();

  // Check the states of the IR sensors every 500ms
  if (currentMillis - irSensorMillis >=20) {
    irSensorMillis = currentMillis;
    readInfrared();
  }

  // Read the color sensor
  
  if (currentMillis - colorSensorMillis >=20) {
    colorSensorMillis = currentMillis;
    readColorSensor();
  }

  // Read the infrared sensor

   if (currentMillis - ultrasonicSensorMillis >=20) {
    ultrasonicSensorMillis = currentMillis;
    readUltrasonicSensor();
  }

robotLogic();
  
}
