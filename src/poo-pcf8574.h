#pragma once

#include "poo-wireslave.h"

class Pcf8574 : public WireSlave {
  public:
    Pcf8574 (byte slaveAddress = 0x20, TwoWire & bus = Wire);
    
    bool begin();
    bool setMode (byte pinmodes);
    int mode () const;
    bool setMode (int pin, int pinmode);
    int mode (int pin) const;
    bool write (int pin, bool bit);
    bool read (int pin);

    bool write (byte value);
    byte read();

  protected:
    bool write();
    
  private:
    byte m_mode;
    byte m_out;
};
