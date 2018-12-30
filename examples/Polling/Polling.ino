/*
    Rotary Encoder - Polling Example
    
    The circuit:
    * encoder pin A to Arduino pin 2
    * encoder pin B to Arduino pin 3
    * encoder ground pin to ground (GND)
    
*/

#include <Rotary.h>

Rotary r = Rotary(2, 3);

void setup() {
  Serial.begin(9600);
  r.begin(true);
}

void loop() {
  unsigned char result = r.process();
  if (result) {
    Serial.println(result == DIR_CW ? "Right" : "Left");
  }
}