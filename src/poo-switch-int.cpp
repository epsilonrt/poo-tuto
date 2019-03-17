#ifdef __unix__
#include "poo-switch-int.h"

SwitchInt::SwitchInt (int pin) : Switch (pin) {}

void SwitchInt::begin (IsrSw isr, int edge, void * user_data, unsigned debounce) {

  Switch::begin (isr, edge, user_data, debounce);
  attachInterrupt (pin(), muxIsr, CHANGE, this);
}

void SwitchInt::begin (unsigned debounce) {

  Switch::begin (debounce);
  attachInterrupt (pin(), muxIsr, CHANGE, this);
}

// static
void SwitchInt::muxIsr (void * data) {
  Switch & sw = *reinterpret_cast<Switch *> (data);

  sw.poll();
}

#endif
