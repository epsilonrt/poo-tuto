#include <Arduino.h>
#include "poo-chaser.h"

Chaser::Chaser (Led * leds, int nofLeds) :
  m_leds (leds),
  m_nofleds (-nofLeds),
  m_led (0),
  m_on (true),
  m_sense (Right),
  m_delay (100),
  m_lastStep(0)
{}

void Chaser::begin () {

  if (m_nofleds < 0) {
    m_nofleds = -m_nofleds;
    for (int i = 0; i < m_nofleds; i++) {
      m_leds[i].begin ();
    }
    m_led = 0;
    m_leds[m_led].toggle();
    m_lastStep = millis();
  }
}

void Chaser::poll() {

  if ( (m_nofleds > 0) && (m_on)) {
    unsigned long t = millis();
    long dt = t - m_lastStep;

    if (dt > m_delay) {

      m_lastStep = t;
      m_leds[m_led].toggle();
      m_led += (m_sense == Right ? 1 : -1);
      if (m_led >= m_nofleds) {
        m_led = 0;
      }
      else if (m_led < 0) {
        m_led = m_nofleds - 1;
      }
      m_leds[m_led].write (true);
    }
  }
}

int Chaser::delay() const {
  return m_delay;
}

void Chaser::setDelay (int d) {
  m_delay = d;
}

bool Chaser::on() const {
  return m_on;
}

void Chaser::setOn (bool o) {
  m_on = o;
}

Chaser::Sense Chaser::sense() const {
  return m_sense;
}

void Chaser::setSense (Sense s) {
  m_sense = s;
}
