#include "poo-pcf8574led.h"

Pcf8574Led::Pcf8574Led (Pcf8574 & ctrl, int pin) :
  Led (false), m_ctrl (ctrl), m_pin (pin) {}

void Pcf8574Led::begin () {

  m_ctrl.setMode (m_pin, OUTPUT);
  write (false);
}

void Pcf8574Led::write (bool on) {

  m_ctrl.write (m_pin, activeState() ? on : ! on);
}

bool Pcf8574Led::read() const {
  bool p = m_ctrl.read (m_pin);

  return  activeState() ? p : ! p;
}

int Pcf8574Led::pin() const {

  return m_pin;
}

Pcf8574 & Pcf8574Led::controller() {

  return m_ctrl;
}
