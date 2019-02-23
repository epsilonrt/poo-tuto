#pragma once
#include "poo-switch.h"

class SwitchInt : public Switch {

  public:
    SwitchInt (int pin);
    void begin (unsigned debounce = 20);
    void begin (IsrSw isr, int edge = CHANGE, void * user_data = 0, unsigned debounce = 20);

  private:
    static void muxIsr (void * sw);
};
