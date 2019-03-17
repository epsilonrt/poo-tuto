#pragma once

#include <Arduino.h>
#include <Wire.h>

// I2c Slave Class
class WireSlave {
  public:
    WireSlave (uint8_t slaveAddress, TwoWire & bus = Wire);
    bool write (uint8_t dataAddress, const uint8_t *values, uint16_t len);
    bool write (uint8_t dataAddress, uint8_t value);
    bool write (const uint8_t *values, uint16_t len);
    bool write (uint8_t value);
    uint8_t read (uint8_t dataAddress, uint8_t *values, uint16_t len);
    uint8_t read (uint8_t dataAddress);
    uint8_t read (uint8_t *values, uint16_t len);
    uint8_t read();
    inline uint8_t address() const {
      return m_address;
    }
    inline void setAddress (uint8_t slaveAddress) {
      m_address = slaveAddress;
    }
private:
    TwoWire & m_bus;
    uint8_t m_address;
};
