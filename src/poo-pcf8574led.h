#pragma once

#include "poo-led.h"
#include "poo-pcf8574.h"

class Pcf8574Led : public Led {
  public:
    Pcf8574Led (Pcf8574 & ctrl, int pin);
    void begin ();
    bool read() const;
    void write (bool on);
    int pin() const;
    Pcf8574 & controller();

    size_t size () const { return sizeof(Pcf8574Led); }
    
  private:
    Pcf8574 & m_ctrl;
    int m_pin;
};
