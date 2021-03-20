#include <Wire.h>

int x = 0;

void setup() {
  Wire.begin(0x05);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);

}

void receiveEvent(int howMany) {
  while (1 < Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
  x = Wire.read();
  Serial.println(x);
}

void requestEvent() {
  Wire.write("hello "); // respond with message of 6 bytes
  Wire.write (x);
  // as expected by master
}
