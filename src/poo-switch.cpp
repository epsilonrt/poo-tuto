#include "poo-switch.h"

Switch::Switch (int pin) :
  m_pin (pin),
  m_state (false),
  m_changed (false),
  m_isr (0),
  m_edge (CHANGE),
  m_debounce (0),
  m_lastEdge (0),
  m_udata (0)
{}

void Switch::begin (IsrSw isr, int edge, void * user_data, unsigned debounce) {

  m_isr = isr;
  m_edge = edge;
  m_udata = user_data;
  begin (debounce);
}

void Switch::begin (unsigned debounce) {

  m_debounce = debounce;

  pinMode (m_pin, INPUT_PULLUP);
  m_lastEdge = millis();
}

bool Switch::read() {

  m_changed = false;
  return m_state;
}

bool Switch::stateChanged() const {

  return m_changed;
}

unsigned Switch::debounce() const {

  return m_debounce;
}

int Switch::edge() const {

  return m_edge;
}

int Switch::pin() const {

  return m_pin;

}

void * Switch::userData() const {

  return m_udata;
}

bool Switch::poll() {

  unsigned long t = millis();
  unsigned long dt = t - m_lastEdge;

  bool s =  ! digitalRead (m_pin);

  if (dt > m_debounce) {

    m_lastEdge = t;
    if (s != m_state) {
      int edge =  s > m_state ? RISING : FALLING;

      m_state = s;
      m_changed = true;

      if ( ( (m_edge == CHANGE) || (m_edge == edge)) && (m_isr)) {

        m_isr (m_udata);
      }
    }
  }
  return m_changed;
}
