#include <Arduino.h>
#include "poo-chaser-switch.h"

ChaserSwitch::ChaserSwitch (Led leds[], int nofLeds) :
  Chaser (leds, nofLeds),
  m_buttons (0)
{}

ChaserSwitch::ChaserSwitch (Led leds[], int nofLeds, Switch buttons[]) :
  Chaser (leds, nofLeds),
  m_buttons (buttons)
{}

void ChaserSwitch::begin () {
  Chaser::begin();
  if (m_buttons) {

  }
}

void ChaserSwitch::poll() {

  if (m_buttons) {

  }

  Chaser::poll();
}
