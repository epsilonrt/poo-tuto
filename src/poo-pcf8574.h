#pragma once

#include "poo-wireslave.h"

class Pcf8574 : public WireSlave {
  public:
    Pcf8574 (uint8_t slaveAddress = 0x20, TwoWire & bus = Wire);
    ~Pcf8574();
    bool begin();
    bool setMode (uint8_t pinmodes);
    int mode () const;
    bool setMode (int pin, int pinmode);
    int mode (int pin) const;
    bool write (int pin, bool bit);
    bool read (int pin);

    bool write (uint8_t value);
    uint8_t read();

  protected:
    bool write();
    
  private:
    int m_mode;
    int m_out;
};
