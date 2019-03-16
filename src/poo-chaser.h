#pragma once

#include "poo-led.h"

class Chaser {

  public:
    enum Sense {
      Right,
      Left
    };
    Chaser (Led * leds, int nofLeds);
    void begin ();
    void poll();
    int delay() const;
    void setDelay (int d);
    bool on() const;
    void setOn (bool o);
    Sense sense() const;
    void setSense (Sense s);

  private:
    Led * m_leds;
    int m_nofleds;
    int m_led;
    bool m_on;
    Sense m_sense;
    int m_delay;
    unsigned long m_lastStep;
};
