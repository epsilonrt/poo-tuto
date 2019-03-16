#include <Arduino.h>
#include "poo-chaser-switch.h"

ChaserSwitch::ChaserSwitch (Led * leds, int nofLeds) :
  Chaser (leds, nofLeds),
  m_buttons (0),
  m_min_delay (100),
  m_max_delay (1000),
  m_step_delay (100),
  m_handler (0)
{}

ChaserSwitch::ChaserSwitch (Led * leds, int nofLeds, Switch buttons[]) :
  ChaserSwitch (leds, nofLeds) {

  m_buttons = buttons;
}

void ChaserSwitch::begin () {

  Chaser::begin();
  if (m_buttons) {

    m_buttons[0].begin (onHandler, RISING, this);
    m_buttons[1].begin (senseHandler, RISING, this);
    m_buttons[2].begin (delayHandler, RISING, this);
  }
}

void ChaserSwitch::poll() {

  if (m_buttons) {

    for (int i = 0; i < nofButtons; i++) {

      m_buttons[i].poll();
    }
  }
  Chaser::poll();
}

int ChaserSwitch::minDelay() const {

  return m_min_delay;
}

int ChaserSwitch::maxDelay() const {

  return m_max_delay;
}

int  ChaserSwitch::stepDelay() const {

  return m_step_delay;
}

void ChaserSwitch::setStepDelay (int value) {

  m_step_delay = value;
}

void ChaserSwitch::setMinDelay (int value) {

  m_min_delay = value;
}

void ChaserSwitch::setMaxDelay (int value) {

  m_max_delay = value;
}

void ChaserSwitch::setChangedHandler (ChaserSwitch::ChangedHandler handler) {

  m_handler = handler;
}

ChaserSwitch::ChangedHandler ChaserSwitch::changedHandler() const {
  return m_handler;
}

void ChaserSwitch::callChangedHandler() {
  if (m_handler) {
    m_handler (*this);
  }
}

// static
void  ChaserSwitch::onHandler (void * chaser_ptr) {
  ChaserSwitch & c = *reinterpret_cast<ChaserSwitch *> (chaser_ptr);

  c.setOn (!c.on());
  c.callChangedHandler();
}

// static
void  ChaserSwitch::senseHandler (void * chaser_ptr) {
  ChaserSwitch & c = *reinterpret_cast<ChaserSwitch *> (chaser_ptr);

  c.setSense (c.sense() == Right ? Left : Right);
  c.callChangedHandler();
}

// static
void  ChaserSwitch::delayHandler (void * chaser_ptr) {
  ChaserSwitch & c = *reinterpret_cast<ChaserSwitch *> (chaser_ptr);
  int d = c.delay();

  d += c.stepDelay();
  if (d > c.maxDelay()) {
    d = c.minDelay();
  }
  c.setDelay (d);
  c.callChangedHandler();
}
