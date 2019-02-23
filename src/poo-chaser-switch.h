#pragma once

#include "poo-chaser.h"
#include "poo-switch.h"

class ChaserSwitch : public Chaser {

  public:
    ChaserSwitch (Led leds[], int nofLeds);
    ChaserSwitch (Led leds[], int nofLeds, Switch buttons[]);
    void begin ();
    void poll();

  private:
    Switch * m_buttons;
};
