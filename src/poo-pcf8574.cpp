#include "poo-pcf8574.h"

// -----------------------------------------------------------------------------
//
//                            Pcf8574 class
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
Pcf8574::Pcf8574 (uint8_t slaveAddress, TwoWire & bus) :
  WireSlave (slaveAddress, bus), m_mode (0xFF), m_out (0)  {
}

// -----------------------------------------------------------------------------
Pcf8574::~Pcf8574() {
  WireSlave::write (0xFF);
}

// -----------------------------------------------------------------------------
bool Pcf8574::write () {
  return WireSlave::write (m_mode | (~m_mode & m_out));
}

// -----------------------------------------------------------------------------
bool Pcf8574::write (uint8_t value) {
  m_out = value & ~m_mode;
  return write();
}

// -----------------------------------------------------------------------------
uint8_t Pcf8574::read() {
  return (WireSlave::read() & m_mode) | (m_out & ~m_mode);
}

// -----------------------------------------------------------------------------
bool Pcf8574::begin () {
  return write();
}

// -----------------------------------------------------------------------------
bool Pcf8574::setMode (uint8_t pinmodes) {
  pinmodes = ~pinmodes;

  if (pinmodes != m_mode) {
    m_mode = pinmodes;
    return write();
  }
  return true;
}

// -----------------------------------------------------------------------------
int Pcf8574::mode () const {
  return (unsigned) ~m_mode;
}

// -----------------------------------------------------------------------------
bool Pcf8574::setMode (int pin, int pinmode) {

  if ( (pin < 8) &&
       ( (pinmode == OUTPUT) || (pinmode == INPUT) || (pinmode == INPUT_PULLUP))) {
    uint8_t pinmodes = mode();

    if (pinmode == OUTPUT) {

      pinmodes |= (1 << pin);
    }
    else {

      pinmodes &= ~ (1 << pin);
    }
    return setMode (pinmodes);
  }
  return false;
}

// -----------------------------------------------------------------------------
int Pcf8574::mode (int pin) const {

  if (pin < 8) {

    if ( (1 << pin) & m_mode) {
      return INPUT;
    }
    return OUTPUT;
  }
  return -1;
}

// -----------------------------------------------------------------------------
bool Pcf8574::write (int pin, bool value) {

  if (pin < 8) {
    if (mode (pin) == OUTPUT) {
      if (value) {
        m_out |= 1 << pin;
      }
      else {

        m_out &= ~ (1 << pin);
      }
      return write();
    }
  }
  return false;
}

// -----------------------------------------------------------------------------
bool Pcf8574::read (int pin) {
  if (pin < 8) {

    return ( (1 << pin) & read()) != 0;
  }
  return false;
}
