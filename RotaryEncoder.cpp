//Code originally from http://www.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino

#include "Arduino.h"
#include "RotaryEncoder.h"

char enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};

RotaryEncoder::RotaryEncoder(byte aPin, byte bPin)
{
	this->counter = 0;
	this->old_AB = 0;
	this->a_pin = aPin;
	this->b_pin = bPin;
}

//Call as often as possible.
void RotaryEncoder::update(void)
{
  this->old_AB <<= 2;
  this->old_AB |= digitalRead(a_pin);
  this->old_AB |= digitalRead(b_pin) << 1;
  this->counter += ( enc_states[( this->old_AB & 0x0f )]);
}
  
long RotaryEncoder::read(void)
{
  return counter;
}

void RotaryEncoder::reset(void)
{
  counter = 0;
}