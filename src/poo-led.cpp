#include <Arduino.h>
#include "poo-led.h"

Led::Led (int pin, bool activeState) : m_pin (pin), m_state (activeState) {}

void Led::begin () {

  pinMode (m_pin, OUTPUT);
  write (false);
}

bool Led::read() const {
  bool p = digitalRead (m_pin);

  return  m_state ? p : ! p;
}

void Led::write (bool on) {

  digitalWrite (m_pin, m_state ? on : ! on);
}

void Led::toggle() {

  write (!read());
}

int Led::pin() const {
  
  return m_pin;
}

bool Led::activeState() const {
  
  return m_state;
}
