#include "poo-wireslave.h"

// -----------------------------------------------------------------------------
//
//                            WireSlave class
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
WireSlave::WireSlave (uint8_t slaveAddress, TwoWire & bus) :
  m_bus (bus), m_address (slaveAddress)  {
}

// -----------------------------------------------------------------------------
uint8_t WireSlave::read (uint8_t dataAddress, uint8_t *values, uint16_t len) {
  uint8_t readBytes = 0;
  m_bus.beginTransmission (m_address); // transmit to device
  m_bus.write (dataAddress);       // sends one uint8_t
  m_bus.endTransmission (false);   // repeat start transmitting
  readBytes += m_bus.requestFrom (m_address, len);   // request bytes from slave device
  while (m_bus.available()) { // slave may send less than requested
    *values++ = m_bus.read();    // receive a uint8_t as character
  }
  return readBytes;
}

// -----------------------------------------------------------------------------
uint8_t WireSlave::read (uint8_t dataAddress) {
  uint8_t data = 0xFF;
  this->read (dataAddress, &data, 1);
  return data;
}

// -----------------------------------------------------------------------------
uint8_t WireSlave::read (uint8_t *values, uint16_t len) {
  uint8_t readBytes = 0;
  m_bus.beginTransmission (m_address); // transmit to device
  readBytes += m_bus.requestFrom (m_address, len);   // request bytes from slave device
  while (m_bus.available()) { // slave may send less than requested
    *values++ = m_bus.read();    // receive a uint8_t as character
  }
  return readBytes;
}

// -----------------------------------------------------------------------------
uint8_t WireSlave::read () {
  uint8_t data = 0xFF;
  this->read (&data, 1);
  return data;
}

// -----------------------------------------------------------------------------
bool WireSlave::write (uint8_t dataAddress, const uint8_t *values, uint16_t len) {
  m_bus.beginTransmission (m_address); // transmit to device
  m_bus.write (dataAddress);       // sends one uint8_t
  m_bus.write (values, len);  // sends data bytes
  return (m_bus.endTransmission() == 0);    // stop transmitting
}

// -----------------------------------------------------------------------------
bool WireSlave::write (uint8_t dataAddress, uint8_t value) {
  return this->write (dataAddress, &value, 1);
}

// -----------------------------------------------------------------------------
bool WireSlave::write (const uint8_t *values, uint16_t len) {
  m_bus.beginTransmission (m_address); // transmit to device
  m_bus.write (values, len);  // sends data bytes
  return (m_bus.endTransmission() == 0);    // stop transmitting
}

// -----------------------------------------------------------------------------
bool WireSlave::write (uint8_t value) {
  return this->write (&value, 1);
}
