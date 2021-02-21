#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}


void loop() {
  int okunanDeger = analogRead(A15);
  float derece = (okunanDeger / 1024.0) * 500;
  int derece1 = (int)derece;
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(derece1);
  Wire.endTransmission();    // stop transmitting
  delay(1000);
  
}
