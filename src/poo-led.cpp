#include "poo-led.h"

Led::Led (bool activeState) : m_state (activeState) {}

Led::~Led() = default;

Led * Led::arrayItem (int i, Led * array) {
  char * p = array ? (char *) array : (char *) this;
  p +=  size() * i;
  return (Led*) p;
}
