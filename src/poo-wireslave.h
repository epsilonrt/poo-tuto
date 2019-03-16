#pragma once

#include <Arduino.h>
#include <Wire.h>

// I2c Slave Class
class WireSlave {
  public:
    WireSlave (byte slaveAddress, TwoWire & bus = Wire);
    bool write (byte dataAddress, const byte *values, byte len);
    bool write (byte dataAddress, byte value);
    bool write (const byte *values, byte len);
    bool write (byte value);
    byte read (byte dataAddress, byte *values, byte len);
    byte read (byte dataAddress);
    byte read (byte *values, byte len);
    byte read();
    inline byte address() const {
      return m_address;
    }
    inline void setAddress (byte slaveAddress) {
      m_address = slaveAddress;
    }
private:
    TwoWire & m_bus;
    byte m_address;
};
