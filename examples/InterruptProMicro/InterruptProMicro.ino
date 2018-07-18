/*
    Rotary Encoder - Interrupt Example 
    This is the same as "Interrupt.ino" but works
    the Pro Micro from Sparkfun which uses the 
    Atmega32U4 microcontroller.  This controller
    does not have the PCIE2 or PCMSK2 registers used in the
    Interrupt example.  Instead these are moved
    to the PCIE0 and PCMSK0 registers instead.

    These registers support interrupts on Pro Micro
    pins 8, 9, 10 or 11.  This example wires the encoder
    to pins 8 and 9.

    Note that the interrupt vector also changes to
    correspond to the PCIE0 interrupt.
    
    The circuit:
    * encoder pin A to Arduino pin 8
    * encoder pin B to Arduino pin 9
    * encoder ground pin to ground (GND)
*/

#include <Rotary.h>

Rotary r = Rotary(8, 9);

void setup() {
  Serial.begin(9600);
  PCICR |= (1 << PCIE0);
  PCMSK0 |= (1 << PCINT4) | (1 << PCINT5);
  sei();
}

void loop() {

}

ISR(PCINT0_vect) {
  unsigned char result = r.process();
  if (result == DIR_NONE) {
    // do nothing
  }
  else if (result == DIR_CW) {
    Serial.println("ClockWise");
  }
  else if (result == DIR_CCW) {
    Serial.println("CounterClockWise");
  }
}
