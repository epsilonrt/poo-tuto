#pragma once
#include <Arduino.h>

class Switch {

  public:
    typedef void (* IsrSw) (void * user_data);

    Switch (int pin);
    void begin (unsigned debounce = 20);
    void begin (IsrSw isr, int edge = CHANGE, void * user_data = 0, unsigned debounce = 20);
    bool poll();
    bool read();
    bool stateChanged() const;
    void setDebounce (unsigned t);
    unsigned debounce() const;
    int edge() const;
    int pin() const;
    void * userData() const;

  private:
    int m_pin;
    bool m_state;
    bool m_changed;
    IsrSw m_isr;
    int m_edge;
    unsigned m_debounce;
    unsigned long m_lastEdge;
    void * m_udata;
};
