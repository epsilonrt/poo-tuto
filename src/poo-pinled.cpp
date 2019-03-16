#include <Arduino.h>
#include "poo-pinled.h"

PinLed::PinLed (int pin, bool activeState) : Led (activeState), m_pin (pin) {}

void PinLed::begin () {

  pinMode (m_pin, OUTPUT);
  write (false);
}

bool PinLed::read() const {
  bool p = digitalRead (m_pin);

  return  activeState() ? p : ! p;
}

void PinLed::write (bool on) {

  digitalWrite (m_pin, activeState() ? on : ! on);
}

int PinLed::pin() const {

  return m_pin;
}
