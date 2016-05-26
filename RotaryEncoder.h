//Code originally from http://www.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino

#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include "Arduino.h"

class RotaryEncoder
{

public:
	// Initialize
  RotaryEncoder(byte aPin, byte bPin); 
  
  //Call at setup
  //void begin(void);
  
  //Call as often as possible.
  void update(void);
  
  //Returns current counter value
  long read(void);
  
  //Resets counter to zero
  void reset(void);
  
private:
  byte a_pin;
  byte b_pin;
  byte old_AB;
  long counter;
};

#endif


