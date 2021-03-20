#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

byte x = 0;

void loop() {
  Wire.beginTransmission(0x05);
  Wire.write("x is ");
  Wire.write(x);
  Wire.endTransmission();

  Wire.requestFrom(8, 6);    // request 6 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
  }

  x++;
  delay(500);
}
