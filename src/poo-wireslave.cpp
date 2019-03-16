#include "poo-wireslave.h"

// -----------------------------------------------------------------------------
//
//                            WireSlave class
//
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
WireSlave::WireSlave (byte slaveAddress, TwoWire & bus) :
  m_bus (bus), m_address (slaveAddress)  {
}

// -----------------------------------------------------------------------------
byte WireSlave::read (byte dataAddress, byte *values, byte len) {
  byte readBytes = 0;
  m_bus.beginTransmission (m_address); // transmit to device
  m_bus.write (dataAddress);       // sends one byte
  m_bus.endTransmission (false);   // repeat start transmitting
  readBytes += m_bus.requestFrom (m_address, len);   // request bytes from slave device
  while (m_bus.available()) { // slave may send less than requested
    *values++ = m_bus.read();    // receive a byte as character
  }
  return readBytes;
}

// -----------------------------------------------------------------------------
byte WireSlave::read (byte dataAddress) {
  byte data = 0xFF;
  this->read (dataAddress, &data, 1);
  return data;
}

// -----------------------------------------------------------------------------
byte WireSlave::read (byte *values, byte len) {
  byte readBytes = 0;
  m_bus.beginTransmission (m_address); // transmit to device
  readBytes += m_bus.requestFrom (m_address, len);   // request bytes from slave device
  while (m_bus.available()) { // slave may send less than requested
    *values++ = m_bus.read();    // receive a byte as character
  }
  return readBytes;
}

// -----------------------------------------------------------------------------
byte WireSlave::read () {
  byte data = 0xFF;
  this->read (&data, 1);
  return data;
}

// -----------------------------------------------------------------------------
bool WireSlave::write (byte dataAddress, const byte *values, byte len) {
  m_bus.beginTransmission (m_address); // transmit to device
  m_bus.write (dataAddress);       // sends one byte
  m_bus.write (values, len);  // sends data bytes
  return (m_bus.endTransmission() == 0);    // stop transmitting
}

// -----------------------------------------------------------------------------
bool WireSlave::write (byte dataAddress, byte value) {
  return this->write (dataAddress, &value, 1);
}

// -----------------------------------------------------------------------------
bool WireSlave::write (const byte *values, byte len) {
  m_bus.beginTransmission (m_address); // transmit to device
  m_bus.write (values, len);  // sends data bytes
  return (m_bus.endTransmission() == 0);    // stop transmitting
}

// -----------------------------------------------------------------------------
bool WireSlave::write (byte value) {
  return this->write (&value, 1);
}
