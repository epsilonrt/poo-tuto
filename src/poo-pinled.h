#pragma once

#include "poo-led.h"

class PinLed : public Led {
  public:
    PinLed (int pin, bool activeState = true);
    void begin ();
    bool read() const;
    void write (bool on);
    int pin() const;

    size_t size () const { return sizeof(PinLed); }
  private:
    int m_pin;
};
