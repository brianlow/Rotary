/*
 * Rotary encoder library for Arduino.
 */

#ifndef Rotary_h
#define Rotary_h

#include "Arduino.h"

// Enable this to emit codes twice per step.
// #define HALF_STEP

// Values returned by 'process'
// No complete step yet.
#define DIR_NONE 0x0
// Clockwise step.
#define DIR_CW 0x10
// Counter-clockwise step.
#define DIR_CCW 0x20

class Rotary
{
  public:
    Rotary(char, char);
    unsigned char process();
    void begin(bool internalPullup=true, bool flipLogicForPulldown=false);
  
    inline unsigned char pin_1() const { return pin1; }
    inline unsigned char pin_2() const { return pin2; }
  private:
    unsigned char state;
    unsigned char pin1;
    unsigned char pin2;
    unsigned char inverter;
};

#endif
 
