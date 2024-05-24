tcs3200 tcs(COLOR_0, COLOR_1, COLOR_2, COLOR_3, COLOR_OUT);

void readColorSensor() {
  const int samples = 5;
  long sumRed = 0, sumGreen = 0, sumBlue = 0, sumWhite = 0;

  for (int i = 0; i < samples; i++) {
    sumRed += tcs.colorRead('r');
    sumGreen += tcs.colorRead('g');
    sumBlue += tcs.colorRead('b');
    sumWhite += tcs.colorRead('c');
  }

  int avgRed = sumRed / samples;
  int avgGreen = sumGreen / samples;
  int avgBlue = sumBlue / samples;
  int avgWhite = sumWhite / samples;
  

  Serial.print("Average Color Sensor Readings: ");
  Serial.print(" R= ");
  Serial.print(avgRed);
  Serial.print(" G= ");
  Serial.print(avgGreen);
  Serial.print(" B= ");
  Serial.print(avgBlue);
  Serial.print(" W(clear)= ");
  Serial.println(avgWhite);
  delay(100);

  if(avgRed>20&&avgGreen>15) {
    WiFiDrv::analogWrite(27, 0);
    WiFiDrv::analogWrite(25,255);
    WiFiDrv::analogWrite(26,255);
  }
  else if (avgRed>15) {
    WiFiDrv::analogWrite(26,255);
    WiFiDrv::analogWrite(25,0);
    WiFiDrv::analogWrite(27,0);
  }
  else if (avgGreen>15){
    WiFiDrv::analogWrite(25,255);
    WiFiDrv::analogWrite(27,0);
    WiFiDrv::analogWrite(26,0);
  }
  else if (avgBlue>15) {
    WiFiDrv::analogWrite(27,255);
    WiFiDrv::analogWrite(26,0);
    WiFiDrv::analogWrite(25,0);
  }


}